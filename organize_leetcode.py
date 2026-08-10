#!/usr/bin/env python3
import json
import re
import subprocess
import time
from pathlib import Path
from urllib.request import Request, urlopen

ROOT = Path(".")
LEETCODE_URL = "https://leetcode.com/graphql"

QUERY = """
query question($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    topicTags {
      name
      slug
    }
  }
}
"""

# If a problem has multiple LeetCode tags, the first matching tag here
# decides its single primary folder.
PRIORITY = [
    ("dynamic-programming", "Dynamic Programming"),
    ("graph", "Graph"),
    ("tree", "Tree"),
    ("binary-tree", "Tree"),
    ("trie", "Trie"),
    ("union-find", "Union Find"),
    ("linked-list", "Linked List"),
    ("binary-search", "Binary Search"),
    ("backtracking", "Backtracking"),
    ("recursion", "Recursion"),
    ("greedy", "Greedy"),
    ("heap", "Heap"),
    ("priority-queue", "Heap"),
    ("monotonic-stack", "Stack"),
    ("stack", "Stack"),
    ("queue", "Queue"),
    ("sliding-window", "Sliding Window"),
    ("two-pointers", "Two Pointers"),
    ("prefix-sum", "Prefix Sum"),
    ("hash-table", "Hash Table"),
    ("sorting", "Sorting"),
    ("string", "String"),
    ("array", "Array"),
    ("matrix", "Matrix"),
    ("bit-manipulation", "Bit Manipulation"),
    ("math", "Math"),
    ("database", "SQL"),
    ("shell", "Shell"),
]

# Never touch your backend files or folders.
PROTECTED = {
    ".git",
    ".github",
    "node_modules",
    ".env",
    "package.json",
    "package-lock.json",
    "server.js",
    "README.md",
}

def get_slug(folder_name):
    # LeetHub uses names such as 0001-two-sum and 0070-climbing-stairs.
    match = re.match(r"^\d{1,5}-(.+)$", folder_name)
    return match.group(1) if match else None

def get_problem(slug):
    payload = json.dumps({
        "query": QUERY,
        "variables": {"titleSlug": slug}
    }).encode()

    request = Request(
        LEETCODE_URL,
        data=payload,
        headers={
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0",
            "Referer": "https://leetcode.com/",
        },
    )

    with urlopen(request, timeout=20) as response:
        data = json.load(response)

    return (data.get("data") or {}).get("question")

def choose_topic(tags):
    tag_slugs = {tag.get("slug") for tag in tags}
    for tag_slug, folder in PRIORITY:
        if tag_slug in tag_slugs:
            return folder
    return "Other"

def git_move(source, destination):
    destination.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run(
        ["git", "mv", str(source), str(destination)],
        check=True
    )

def main():
    problem_folders = []

    for path in ROOT.iterdir():
        if not path.is_dir():
            continue
        if path.name in PROTECTED:
            continue
        if path.name.startswith("."):
            continue
        if get_slug(path.name):
            problem_folders.append(path)

    problem_folders.sort(key=lambda path: path.name)

    print(f"Found {len(problem_folders)} LeetCode folders.")

    moved = 0
    skipped = 0

    for index, folder in enumerate(problem_folders, 1):
        slug = get_slug(folder.name)

        try:
            problem = get_problem(slug)

            if not problem:
                print(f"[{index}/{len(problem_folders)}] SKIP {folder.name}: not found")
                skipped += 1
                continue

            topic = choose_topic(problem.get("topicTags") or [])
            destination = ROOT / topic / folder.name

            if destination.exists():
                print(f"[{index}/{len(problem_folders)}] SKIP {folder.name}: already organized")
                skipped += 1
                continue

            print(f"[{index}/{len(problem_folders)}] {folder.name} -> {topic}")
            git_move(folder, destination)
            moved += 1

            # Small delay to avoid hammering LeetCode.
            time.sleep(0.4)

        except Exception as error:
            print(f"[{index}/{len(problem_folders)}] ERROR {folder.name}: {error}")
            skipped += 1

    print()
    print(f"Finished. Moved: {moved}, skipped/errors: {skipped}.")
    print("Review the changes before pushing.")

if __name__ == "__main__":
    main()
