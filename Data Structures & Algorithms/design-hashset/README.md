# Design HashSet

**NeetCode:** [Design HashSet](https://neetcode.io/problems/design-hashset)
**Difficulty:** Easy | **Pattern:** Design / Arrays

---

## Problem

Design a HashSet without using any built-in hash table libraries. Implement `add(key)`, `remove(key)`, and `contains(key)`.

---

## Solution — Linear Scan (`solution_linear_scan.cpp`)

### Approach
Store keys in a plain `vector<int>`. Every operation uses `std::find` to locate the key linearly.

### Algorithm
1. `add`: search for the key; if absent, push it onto the vector.
2. `remove`: search for the key; if present, erase it.
3. `contains`: search for the key; return whether it was found.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) per operation (linear scan) |
| **Space** | O(n) for stored keys |

### Key Insight
Same trade-off as Design HashMap: correctness over performance. A bucket-based design (`key % capacity` with chaining) would bring this down to O(1) average time.

---

## Example Walkthrough

Operations: `add(1)`, `add(2)`, `contains(1)`, `contains(3)`, `add(2)`, `remove(2)`, `contains(2)`

| Call | Internal `hashset` after call | Return |
|---|---|---|
| `add(1)` | `[1]` | — |
| `add(2)` | `[1, 2]` | — |
| `contains(1)` | `[1, 2]` | `true` |
| `contains(3)` | `[1, 2]` | `false` |
| `add(2)` | `[1, 2]` | — (already present, no duplicate added) |
| `remove(2)` | `[1]` | — |
| `contains(2)` | `[1]` | `false` |
