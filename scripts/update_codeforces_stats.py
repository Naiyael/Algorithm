from __future__ import annotations

import datetime as dt
import json
import math
import pathlib
import urllib.parse
import urllib.request
from collections import Counter
from typing import Any


HANDLE = "qiushan233"
ROOT = pathlib.Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "assets" / "codeforces-stats.svg"


def api(method: str, **params: str) -> Any:
    query = urllib.parse.urlencode(params)
    url = f"https://codeforces.com/api/{method}?{query}"
    req = urllib.request.Request(url, headers={"User-Agent": "Algorithm README stats"})
    with urllib.request.urlopen(req, timeout=25) as response:
        payload = json.loads(response.read().decode("utf-8"))
    if payload.get("status") != "OK":
        raise RuntimeError(payload.get("comment", "Codeforces API error"))
    return payload["result"]


def esc(value: Any) -> str:
    return (
        str(value)
        .replace("&", "&amp;")
        .replace("<", "&lt;")
        .replace(">", "&gt;")
        .replace('"', "&quot;")
    )


def problem_key(submission: dict[str, Any]) -> str:
    problem = submission.get("problem", {})
    contest = problem.get("contestId", "gym")
    index = problem.get("index", "?")
    return f"{contest}-{index}"


def rank_color(rank: str) -> str:
    colors = {
        "newbie": "#8c8c8c",
        "pupil": "#2fb344",
        "specialist": "#03a89e",
        "expert": "#318ce7",
        "candidate master": "#aa00aa",
        "master": "#ff8c00",
        "international master": "#ff8c00",
        "grandmaster": "#e74c3c",
        "international grandmaster": "#e74c3c",
        "legendary grandmaster": "#e74c3c",
    }
    return colors.get(rank.lower(), "#57606a")


def heat_color(count: int) -> str:
    if count <= 0:
        return "#ebedf0"
    if count == 1:
        return "#9be9a8"
    if count == 2:
        return "#40c463"
    if count <= 4:
        return "#30a14e"
    return "#216e39"


def month_label_positions(start: dt.date, weeks: int) -> list[tuple[int, str]]:
    labels: list[tuple[int, str]] = []
    current_month = None
    for week in range(weeks):
        day = start + dt.timedelta(days=week * 7)
        if day.month != current_month:
            current_month = day.month
            labels.append((week, day.strftime("%b")))
    return labels


def build_svg(user: dict[str, Any], submissions: list[dict[str, Any]], ratings: list[dict[str, Any]]) -> str:
    today = dt.datetime.now(dt.timezone.utc).astimezone().date()
    start = today - dt.timedelta(days=364)
    start -= dt.timedelta(days=start.weekday())
    weeks = math.ceil(((today - start).days + 1) / 7)

    accepted_by_day: Counter[dt.date] = Counter()
    solved: set[str] = set()
    for submission in submissions:
        if submission.get("verdict") != "OK":
            continue
        created = dt.datetime.fromtimestamp(submission["creationTimeSeconds"], dt.timezone.utc).astimezone().date()
        accepted_by_day[created] += 1
        solved.add(problem_key(submission))

    rating = user.get("rating", "unrated")
    max_rating = user.get("maxRating", "unrated")
    rank = user.get("rank", "unrated")
    max_rank = user.get("maxRank", rank)
    avatar = user.get("titlePhoto", "")
    total_ac = sum(accepted_by_day.values())
    active_days = sum(1 for day, count in accepted_by_day.items() if start <= day <= today and count > 0)
    solved_total = len(solved)
    last_update = dt.datetime.now().strftime("%Y-%m-%d %H:%M")
    accent = rank_color(str(rank))

    rating_points = []
    if ratings:
        chart_x = 86
        chart_y = 242
        chart_w = 770
        chart_h = 78
        values = [item["newRating"] for item in ratings]
        lo = min(values + [1200])
        hi = max(values + [max(1500, int(max_rating) if isinstance(max_rating, int) else 1500)])
        if hi == lo:
            hi += 1
        for index, item in enumerate(ratings):
            x = chart_x + (chart_w * index / max(1, len(ratings) - 1))
            y = chart_y + chart_h - ((item["newRating"] - lo) / (hi - lo) * chart_h)
            rating_points.append(f"{x:.1f},{y:.1f}")
        latest_contest = esc(ratings[-1].get("contestName", "Latest contest"))
    else:
        chart_x = 86
        chart_y = 242
        chart_w = 770
        chart_h = 78
        lo = 0
        hi = 0
        latest_contest = "No rated contest yet"

    cell = 11
    gap = 3
    heat_x = 92
    heat_y = 432
    weekday_labels = [(1, "Mon"), (3, "Wed"), (5, "Fri")]

    rects = []
    snake_targets: list[tuple[int, dt.date, float, float]] = []
    for week in range(weeks):
        for weekday in range(7):
            day = start + dt.timedelta(days=week * 7 + weekday)
            if day > today:
                continue
            count = accepted_by_day[day]
            x = heat_x + week * (cell + gap)
            y = heat_y + weekday * (cell + gap)
            if count > 0:
                snake_targets.append((count, day, x + cell / 2, y + cell / 2))
            rects.append(
                f'<rect x="{x}" y="{y}" width="{cell}" height="{cell}" rx="2" '
                f'fill="{heat_color(count)}"><title>{day}: {count} accepted submissions</title></rect>'
            )

    month_labels = []
    for week, label in month_label_positions(start, weeks):
        x = heat_x + week * (cell + gap)
        month_labels.append(f'<text x="{x}" y="418" class="muted small">{label}</text>')

    weekday_text = []
    for weekday, label in weekday_labels:
        y = heat_y + weekday * (cell + gap) + 10
        weekday_text.append(f'<text x="48" y="{y}" class="muted small">{label}</text>')

    rating_polyline = ""
    if rating_points:
        point_dots = []
        for point in rating_points:
            x, y = point.split(",")
            point_dots.append(f'<circle cx="{x}" cy="{y}" r="3.5" fill="#fff" stroke="#f1c232" stroke-width="2"/>')
        rating_polyline = (
            f'<polyline points="{" ".join(rating_points)}" fill="none" stroke="#f1c232" '
            f'stroke-width="3" stroke-linecap="round" stroke-linejoin="round"/>'
            + "".join(point_dots)
        )

    snake_overlay = ""
    snake_targets.sort(key=lambda item: (item[0], item[1]))
    if len(snake_targets) >= 2:
        route = " ".join(
            f"{'M' if index == 0 else 'L'} {x:.1f} {y:.1f}"
            for index, (_, _, x, y) in enumerate(snake_targets)
        )
        duration = max(14, min(28, len(snake_targets) * 0.55))
        snake_overlay = f"""
<path d="{route}" class="snake-route"/>
<path d="{route}" class="snake-track">
  <animate attributeName="stroke-dashoffset" from="120" to="0" dur="{duration:.1f}s" repeatCount="indefinite"/>
</path>
<g class="snake-head">
  <animateMotion dur="{duration:.1f}s" repeatCount="indefinite" rotate="auto" path="{route}"/>
  <circle cx="0" cy="0" r="7" class="snake-face"/>
  <circle cx="-2.4" cy="-2.2" r="1.2" class="snake-eye"/>
  <circle cx="2.4" cy="-2.2" r="1.2" class="snake-eye"/>
  <path d="M -3 2 Q 0 4 3 2" class="snake-smile"/>
</g>
"""

    cards = [
        ("Current rating", rating, True),
        ("Max rating", max_rating, False),
        ("Rank", rank, True),
        ("Max rank", max_rank, False),
        ("Solved", solved_total, False),
        ("Active days", active_days, False),
    ]
    metric_cards = []
    for index, (label, value, colored) in enumerate(cards):
        x = 36 + index * 148
        value_class = "metric-value rank" if colored else "metric-value"
        metric_cards.append(
            f'<rect x="{x}" y="96" width="132" height="74" rx="8" class="metric-card"/>'
            f'<text x="{x + 16}" y="122" class="metric-label">{esc(label)}</text>'
            f'<text x="{x + 16}" y="153" class="{value_class}">{esc(value)}</text>'
        )

    return f"""<svg xmlns="http://www.w3.org/2000/svg" width="960" height="580" viewBox="0 0 960 580" role="img" aria-label="Codeforces statistics for {esc(HANDLE)}">
<style>
  .bg {{ fill: #ffffff; }}
  .shell {{ fill: #ffffff; stroke: #d0d7de; }}
  .soft {{ fill: #f6f8fa; stroke: #d8dee4; }}
  .metric-card {{ fill: #ffffff; stroke: #d8dee4; }}
  .title {{ font: 700 26px -apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif; fill: #24292f; }}
  .subtitle {{ font: 13px -apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif; fill: #6e7781; }}
  .section-title {{ font: 700 15px -apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif; fill: #24292f; }}
  .metric-label {{ font: 600 12px -apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif; fill: #57606a; }}
  .metric-value {{ font: 800 24px -apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif; fill: #24292f; }}
  .muted {{ font: 12px -apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif; fill: #6e7781; }}
  .small {{ font-size: 11px; }}
  .rank {{ fill: {accent}; }}
  .grid {{ stroke: #d8dee4; stroke-width: 1; }}
  .badge-bg {{ fill: {accent}; opacity: 0.14; }}
  .badge-text {{ font: 700 12px -apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif; fill: {accent}; }}
  .snake-route {{ fill: none; stroke: #1f883d; stroke-width: 2; stroke-linecap: round; stroke-linejoin: round; opacity: 0.14; }}
  .snake-track {{ fill: none; stroke: #1f883d; stroke-width: 4; stroke-linecap: round; stroke-linejoin: round; stroke-dasharray: 10 14; opacity: 0.28; }}
  .snake-face {{ fill: #1f883d; stroke: #ffffff; stroke-width: 2; }}
  .snake-eye {{ fill: #ffffff; }}
  .snake-smile {{ fill: none; stroke: #ffffff; stroke-width: 1.2; stroke-linecap: round; }}
</style>
<rect class="bg" width="960" height="580" rx="12"/>
<rect class="shell" x="18" y="18" width="924" height="544" rx="12"/>
<text x="36" y="58" class="title">Codeforces</text>
<text x="36" y="82" class="subtitle">@{esc(HANDLE)} · updated {esc(last_update)}</text>
<rect x="805" y="38" width="96" height="30" rx="15" class="badge-bg"/>
<text x="828" y="58" class="badge-text">{esc(rank)}</text>
{"".join(metric_cards)}
<rect class="soft" x="36" y="192" width="888" height="158" rx="10"/>
<text x="58" y="222" class="section-title">Contest rating trend</text>
<text x="230" y="222" class="muted">{latest_contest}</text>
<line x1="{chart_x}" y1="{chart_y + chart_h}" x2="{chart_x + chart_w}" y2="{chart_y + chart_h}" class="grid"/>
<line x1="{chart_x}" y1="{chart_y}" x2="{chart_x}" y2="{chart_y + chart_h}" class="grid"/>
<text x="{chart_x + chart_w + 12}" y="{chart_y + 5}" class="muted">{hi}</text>
<text x="{chart_x + chart_w + 12}" y="{chart_y + chart_h}" class="muted">{lo}</text>
{rating_polyline}
<rect class="soft" x="36" y="370" width="888" height="166" rx="10"/>
<text x="58" y="398" class="section-title">Daily accepted submissions</text>
<text x="260" y="398" class="muted">{total_ac} accepted submissions in visible history</text>
{"".join(month_labels)}
{"".join(weekday_text)}
{"".join(rects)}
{snake_overlay}
<text x="716" y="398" class="muted small">Less</text>
<rect x="754" y="388" width="11" height="11" rx="2" fill="#ebedf0"/>
<rect x="772" y="388" width="11" height="11" rx="2" fill="#9be9a8"/>
<rect x="790" y="388" width="11" height="11" rx="2" fill="#40c463"/>
<rect x="808" y="388" width="11" height="11" rx="2" fill="#30a14e"/>
<rect x="826" y="388" width="11" height="11" rx="2" fill="#216e39"/>
<text x="848" y="398" class="muted small">More</text>
<!-- Avatar source: {esc(avatar)} -->
</svg>
"""


def main() -> None:
    [user] = api("user.info", handles=HANDLE)
    submissions = api("user.status", handle=HANDLE)
    ratings = api("user.rating", handle=HANDLE)
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text(build_svg(user, submissions, ratings), encoding="utf-8")
    print(f"Wrote {OUTPUT}")


if __name__ == "__main__":
    main()
