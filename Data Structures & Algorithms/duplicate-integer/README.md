# Duplicate Integer

**NeetCode:** [Duplicate Integer](https://neetcode.io/problems/duplicate-integer)
**Difficulty:** Easy | **Pattern:** Arrays / Hashing

---

## Problem

Given an integer array `nums`, return `true` if any value appears more than once, otherwise return `false`.

---

## Solution 1 — Unordered Map (`solution_unordered_map.cpp`)

### Approach
Use an `unordered_map` to count frequency. Return `true` the moment any element's count exceeds 0.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) average |
| **Space** | O(n) |

---

## Solution 2 — Ordered Map (`solution_ordered_map.cpp`)

### Approach
Same logic using `map` (Red-Black BST) instead of `unordered_map`.

### Complexity

| | Value |
|---|---|
| **Time** | O(n log n) — each lookup/insert is O(log n) |
| **Space** | O(n) |

---

## Comparison

| | `unordered_map` | `map` |
|---|---|---|
| Underlying structure | Hash table | Red-Black BST |
| Lookup / Insert | O(1) average | O(log n) |
| Preferred here? | ✅ Yes | ❌ Slower |

**Key Insight:** Order doesn't matter for duplicate detection — always prefer `unordered_map` for O(1) average ops.
