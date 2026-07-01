# Longest Common Prefix

**NeetCode:** [Longest Common Prefix](https://neetcode.io/problems/longest-common-prefix)
**Difficulty:** Easy | **Pattern:** Strings

---

## Problem

Find the longest common prefix string among an array of strings. Return `""` if there is no common prefix.

---

## Solution — Horizontal Scan (`solution_horizontal_scan.cpp`)

### Approach
Start by assuming the first string is the common prefix. Compare it against each subsequent string, trimming it to only the matching leading characters. If the prefix becomes empty at any point, return `""` immediately.

### Algorithm
1. Set `prefix = strs[0]`.
2. For each remaining string:
   - If empty, return `""`.
   - Compare characters until a mismatch or end of either string.
   - Shrink `prefix` to the matched part.
   - If `prefix` is now empty, return `""`.
3. Return `prefix`.

### Complexity

| | Value |
|---|---|
| **Time** | O(n × m) where n = number of strings, m = length of shortest string |
| **Space** | O(m) for the prefix string |

### Key Insight
The prefix can only shrink as we compare more strings — it never grows. Early-exit when prefix is empty avoids unnecessary comparisons.

---

## Example Walkthrough

Input: `strs = ["flower", "flow", "flight"]`

| Step | Comparing prefix against | Matching chars | prefix after |
|---|---|---|---|
| 1 | start | — | `"flower"` |
| 2 | `"flow"` | `f`, `l`, `o`, `w` match; `"flower"[4]='e'` vs end of `"flow"` | `"flow"` |
| 3 | `"flight"` | `f`, `l` match; `"flow"[2]='o'` vs `"flight"[2]='i'` mismatch | `"fl"` |

Final result: `"fl"`

---

## Alternative Approaches

| Approach | Idea | Complexity |
|---|---|---|
| Vertical scan | Compare all strings at each index position | O(n × m) |
| Divide & conquer | Split array, find prefix of each half, merge | O(n × m) |
| Trie | Build trie, walk while each node has one child | O(n × m) build + O(m) query |
