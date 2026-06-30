# Concatenation of Array

**NeetCode:** [Concatenation of Array](https://neetcode.io/problems/concatenation-of-array)
**Difficulty:** Easy | **Pattern:** Arrays

---

## Problem

Given an integer array `nums` of length `n`, return an array of length `2n` where the first `n` elements are `nums` and the last `n` elements are also `nums`.

---

## Solution 1 — Index Copy (`solution_index_copy.cpp`)

### Approach
Pre-allocate a `2n` array, then fill both halves in one pass by assigning `arr[i] = nums[i]` and `arr[i+n] = nums[i]`.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

### Key Insight
Pre-sizing the array avoids dynamic resizing. Direct index assignment is safer than calling `insert()` element-by-element inside a loop — that shifts elements on every call and corrupts the output.

---

## Solution 2 — Vector Insert (`solution_vector_insert.cpp`)

### Approach
Copy `nums` into a new vector, then prepend another copy of `nums` at the front using a single bulk `insert()` call.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

### Key Insight
`arr.insert(arr.begin(), nums.begin(), nums.end())` is a single bulk operation — clean and idiomatic C++. The key is doing it in one call, not element-by-element in a loop.
