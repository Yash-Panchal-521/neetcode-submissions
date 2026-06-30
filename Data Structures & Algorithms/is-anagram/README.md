# Is Anagram

**NeetCode:** [Is Anagram](https://neetcode.io/problems/is-anagram)
**Difficulty:** Easy | **Pattern:** Arrays / Hashing

---

## Problem

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, otherwise return `false`.

---

## Solution 1 — Frequency Array (`solution_frequency_array.cpp`)

### Approach
Use a fixed `int count[26]` array. Increment for each char in `s`, decrement for each char in `t`. If all counts are zero at the end, they're anagrams.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) — fixed 26-element array |

### Key Insight
Incrementing for `s` and decrementing for `t` in the same loop cancels out matching characters. Any non-zero value means a character appeared a different number of times across the two strings. Note: only works for lowercase English letters — use a hash map for Unicode.

---

## Solution 2 — Sort (`solution_sort.cpp`)

### Approach
Sort both strings, then compare character by character. Anagrams produce identical sorted strings.

### Complexity

| | Value |
|---|---|
| **Time** | O(n log n) |
| **Space** | O(1) or O(n) depending on sort |

---

## Comparison

| | Frequency Array | Sort |
|---|---|---|
| Time | O(n) | O(n log n) |
| Space | O(1) | Varies |
| Handles Unicode? | ❌ Only a–z | ✅ Yes |
| Preferred? | ✅ Faster | ❌ Slower |
