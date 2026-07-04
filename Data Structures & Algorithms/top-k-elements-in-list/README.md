# Top K Frequent Elements

**NeetCode:** [Top K Elements in List](https://neetcode.io/problems/top-k-elements-in-list)
**Difficulty:** Medium | **Pattern:** Hash Map + Sorting / Bucket Sort

---

## Problem

Given an integer array `nums` and an integer `k`, return the `k` most frequently occurring elements, in any order.

---

## Solution 1 — Hash Map + Full Sort (`solution_frequency_sort.cpp`)

### Approach
Count each value's frequency with a hash map, dump the (value, count) pairs into a vector, then sort that vector by count descending. The first `k` entries are the answer.

### Algorithm
1. Build `mp[num]++` for every value in `nums`.
2. Copy all `(value, count)` pairs from `mp` into a vector `f`.
3. Sort `f` by count in descending order using a custom comparator.
4. Take the `value` from each of the first `k` pairs.

### Complexity

| | Value |
|---|---|
| **Time** | O(m log m), where m is the number of distinct values (sorting dominates) |
| **Space** | O(m) for the map and the pairs vector |

### Key Insight
Sorting the *entire* frequency list just to read off the top `k` does more work than necessary — the problem doesn't need the full ranking, only the top slice. Solution 2 (bucket sort) gets this down to O(n) by exploiting the fact that frequency is bounded by array length.

---

## Solution 2 — Bucket Sort by Frequency (`solution_bucket_sort.cpp`)

### Approach
Since no value can appear more than `nums.size()` times, frequency itself can be used as a bucket index. Create `nums.size() + 1` buckets; place each distinct value into `bucket[frequency]`. Then walk the buckets from the highest possible frequency down to 1, collecting values until `k` are gathered — no comparison-based sorting needed.

### Algorithm
1. Build `mp[num]++` for every value in `nums`, as before.
2. Create `bucket`, a vector of vectors sized `nums.size() + 1`.
3. For each `(value, count)` in `mp`, push `value` into `bucket[count]`.
4. Walk `j` from `bucket.size() - 1` down to `1`; for each non-empty bucket, add its values to the answer until the answer has `k` elements.
5. Return the answer.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) — building the map is O(n), bucket placement is O(m), and the bucket scan visits at most n+1 slots |
| **Space** | O(n) for the buckets and map |

### Key Insight
Bucket sort works here because frequency has a hard, known upper bound (`nums.size()`), which lets it replace comparison sorting with direct indexing — the classic trick for turning an O(m log m) counting problem into O(n).

---

## Example Walkthrough (Solution 2 — Bucket Sort)

Input: `nums = [1, 1, 1, 2, 2, 3]`, `k = 2`

**Step 1 — build frequency map:**

| num | mp after insert |
|---|---|
| 1 | `{1:1}` |
| 1 | `{1:2}` |
| 1 | `{1:3}` |
| 2 | `{1:3, 2:1}` |
| 2 | `{1:3, 2:2}` |
| 3 | `{1:3, 2:2, 3:1}` |

**Step 2 — place into buckets** (size = 6+1 = 7, indices 0–6):

| value | count | bucket[count] after push |
|---|---|---|
| 1 | 3 | `bucket[3] = [1]` |
| 2 | 2 | `bucket[2] = [2]` |
| 3 | 1 | `bucket[1] = [3]` |

**Step 3 — scan buckets from j=6 down to j=1, collecting until ans.size() == k=2:**

| j | bucket[j] | ans after |
|---|---|---|
| 6,5,4 | empty | `[]` |
| 3 | `[1]` | `[1]` |
| 2 | `[2]` | `[1, 2]` — size reached k, stop |

Final result: `[1, 2]` — the two most frequent values (`1` appears 3 times, `2` appears 2 times).

---

## Comparison

| | Full Sort | Bucket Sort |
|---|---|---|
| Time | O(m log m) | O(n) |
| Space | O(m) | O(n) |
| Preferred? | ⚠️ Simpler to write, slower | ✅ Optimal — no comparison sort needed |

## Common Mistake
Reaching for a general-purpose sort (`std::sort` with a comparator) feels natural but is asymptotically worse than necessary here. Whenever a count or frequency is bounded by a known small range (like array length), bucket/counting sort is worth considering before defaulting to a comparison sort.
