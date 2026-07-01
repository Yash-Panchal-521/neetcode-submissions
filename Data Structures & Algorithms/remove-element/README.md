# Remove Element

**NeetCode:** [Remove Element](https://neetcode.io/problems/remove-element)
**Difficulty:** Easy | **Pattern:** Two Pointers

---

## Problem

Given an array `nums` and a value `val`, remove all occurrences of `val` in-place. Return the number of elements remaining that are not equal to `val`; the order of elements may be changed.

---

## Solution 1 — Two Pointers, Swap From End (`solution_two_pointers_swap.cpp`)

### Approach
Use a pointer `j` starting at the end of the array. Walk a pointer `i` from the front; whenever `nums[i] == val`, swap it with `nums[j]` and pull `j` inward (skipping any trailing values that already equal `val`). Finish with a pass to count remaining valid elements.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

### Key Insight
Swapping from the back avoids shifting the whole array on every removal, but the extra counting pass and edge-case handling around `j` make this more complex than it needs to be — Solution 2 achieves the same result more directly.

---

## Solution 2 — Two Pointers, In-Place Overwrite (`solution_two_pointers_overwrite.cpp`)

### Approach
Use a single write pointer `k`. Iterate through `nums`; whenever the current value isn't `val`, copy it into position `k` and advance `k`. `k` ends up as the count of valid elements.

### Algorithm
1. Initialize `k = 0`.
2. For each `num` in `nums`: if `num != val`, write it to `nums[k]` and increment `k`.
3. Return `k`.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

### Key Insight
A single forward pass with a write pointer is the cleanest form of in-place filtering — no swapping, no backward pointer bookkeeping, and no separate counting pass.

---

## Example Walkthrough (Solution 2 — In-Place Overwrite)

Input: `nums = [3, 2, 2, 3]`, `val = 3`

| i | num | num != val? | Action | nums after | k after |
|---|---|---|---|---|---|
| 0 | 3 | No | skip | `[3, 2, 2, 3]` | 0 |
| 1 | 2 | Yes | `nums[0] = 2`, k++ | `[2, 2, 2, 3]` | 1 |
| 2 | 2 | Yes | `nums[1] = 2`, k++ | `[2, 2, 2, 3]` | 2 |
| 3 | 3 | No | skip | `[2, 2, 2, 3]` | 2 |

Return `k = 2`. The first 2 elements (`[2, 2]`) are the valid remaining values — matches expected output.

---

## Comparison

| | Swap From End | In-Place Overwrite |
|---|---|---|
| Time | O(n) | O(n) |
| Space | O(1) | O(1) |
| Passes | 2 (swap + count) | 1 |
| Preferred? | ❌ More complex | ✅ Simpler, idiomatic |
