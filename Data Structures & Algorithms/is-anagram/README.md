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

## Example Walkthrough (Solution 1 — Frequency Array)

Input: `s = "anagram"`, `t = "nagaram"`

| Char processed | From | count array change | Non-zero slots after |
|---|---|---|---|
| `a` | s | `count['a']++` → 1 | a:1 |
| `n` | s | `count['n']++` → 1 | a:1, n:1 |
| `a` | s | `count['a']++` → 2 | a:2, n:1 |
| `g` | s | `count['g']++` → 1 | a:2, n:1, g:1 |
| `r` | s | `count['r']++` → 1 | a:2, n:1, g:1, r:1 |
| `a` | s | `count['a']++` → 3 | a:3, n:1, g:1, r:1 |
| `m` | s | `count['m']++` → 1 | a:3, n:1, g:1, r:1, m:1 |
| `n` | t | `count['n']--` → 0 | a:3, g:1, r:1, m:1 |
| `a` | t | `count['a']--` → 2 | a:2, g:1, r:1, m:1 |
| `g` | t | `count['g']--` → 0 | a:2, r:1, m:1 |
| `a` | t | `count['a']--` → 1 | a:1, r:1, m:1 |
| `r` | t | `count['r']--` → 0 | a:1, m:1 |
| `a` | t | `count['a']--` → 0 | m:1 |
| `m` | t | `count['m']--` → 0 | (all zero) |

All slots end at zero → return `true`.

---

## Comparison

| | Frequency Array | Sort |
|---|---|---|
| Time | O(n) | O(n log n) |
| Space | O(1) | Varies |
| Handles Unicode? | ❌ Only a–z | ✅ Yes |
| Preferred? | ✅ Faster | ❌ Slower |
