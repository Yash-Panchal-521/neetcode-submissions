# Anagram Groups

**NeetCode:** [Anagram Groups](https://neetcode.io/problems/anagram-groups)
**Difficulty:** Medium | **Pattern:** Arrays / Hashing

---

## Problem

Given an array of strings `strs`, group the anagrams together. Return the groups in any order.

---

## Solution 1 — Frequency Array (`solution_frequency_array.cpp`)

### Approach
Brute-force grouping without sorting. Repeatedly take the first remaining string as the "current" group leader, scan the rest for matches, and compare each candidate to it using a 26-slot character count array.

### Algorithm
1. While strings remain, pop the front string as `curr` and start a new group with it.
2. Scan the remaining strings; skip any whose length differs from `curr`.
3. For same-length candidates, build a `count[26]` array by incrementing for `curr`'s characters and decrementing for the candidate's.
4. If every slot ends at zero, the candidate is an anagram — move it into the group and erase it from the pool.
5. Repeat until the pool is empty.

### Complexity

| | Value |
|---|---|
| **Time** | O(n² · k) — n strings, k = average string length, due to repeated `erase` and scanning |
| **Space** | O(1) extra (26-slot array) plus output storage |

### Key Insight
The count-array cancellation trick (increment for one string, decrement for the other) avoids sorting each string, but the repeated linear scan and `vector::erase` make this quadratic in the number of strings — a hash map keyed by sorted string is asymptotically better (see Solution 2).

---

## Solution 2 — Hash Map (`solution_hashmap.cpp`)

### Approach
Sort each string to get a canonical key, then bucket strings into an `unordered_map<string, vector<string>>` by that key. Anagrams always sort to the same key.

### Algorithm
1. For each string, copy it and sort the copy's characters.
2. Use the sorted copy as a hash map key; push the original string into that key's bucket.
3. After processing all strings, collect the map's values as the final groups.

### Complexity

| | Value |
|---|---|
| **Time** | O(n · k log k) — n strings, sorting each of length k |
| **Space** | O(n · k) for the map |

### Key Insight
Sorting gives every anagram an identical signature "for free," turning grouping into a single hash map pass instead of pairwise comparisons.

---

## Example Walkthrough (Solution 2 — Hash Map)

Input: `strs = ["eat", "tea", "tan", "ate", "nat", "bat"]`

| String | Sorted Key | Map After Insert |
|---|---|---|
| `eat` | `aet` | `{aet: [eat]}` |
| `tea` | `aet` | `{aet: [eat, tea]}` |
| `tan` | `ant` | `{aet: [eat, tea], ant: [tan]}` |
| `ate` | `aet` | `{aet: [eat, tea, ate], ant: [tan]}` |
| `nat` | `ant` | `{aet: [eat, tea, ate], ant: [tan, nat]}` |
| `bat` | `abt` | `{aet: [eat, tea, ate], ant: [tan, nat], abt: [bat]}` |

Final groups (order may vary): `[["eat","tea","ate"], ["tan","nat"], ["bat"]]`

---

## Comparison

| | Frequency Array | Hash Map |
|---|---|---|
| Time | O(n² · k) | O(n · k log k) |
| Space | O(1) extra | O(n · k) |
| Scales well? | ❌ Quadratic in n | ✅ Yes |
| Preferred? | ❌ Slower | ✅ Standard approach |
