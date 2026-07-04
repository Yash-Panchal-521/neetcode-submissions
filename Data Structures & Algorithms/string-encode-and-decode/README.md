# Encode and Decode Strings

**NeetCode:** [String Encode and Decode](https://neetcode.io/problems/string-encode-and-decode)
**Difficulty:** Medium | **Pattern:** String Design (Length-Prefix Encoding)

---

## Problem

Design an `encode(strs)` function that packs a list of strings into a single string, and a `decode(s)` function that recovers the original list from that single string. The encoding must handle any characters inside the strings, including delimiters you choose yourself.

---

## Solution — Length-Prefix Encoding (`solution_length_prefix_encoding.cpp`)

### Approach
Instead of joining strings with a delimiter character (which breaks if a string contains that character), prefix each string with its own length followed by a separator (`#`). On decode, read digits until `#` to learn how many characters belong to the next chunk, then copy exactly that many characters — so the content of the string itself can never be misread as a delimiter.

### Algorithm

**`encode`:**
1. For each string `str` in the input list, append `to_string(str.length()) + "#" + str` to the running result.
2. Return the concatenated result.

**`decode`:**
1. Walk an index `i` through the encoded string.
2. Read characters into a buffer until hitting `#` — this buffer is the length of the next string (as text), parsed with `stoi`.
3. Skip past the `#`.
4. Copy exactly `len` characters starting at `i` into a new string, then advance `i` by `len`.
5. Push that string onto the result list and repeat until `i` reaches the end.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) for encode, O(n) for decode, where n is the total character count across all strings |
| **Space** | O(n) for the encoded string / decoded list |

### Key Insight
The length prefix makes the format self-describing — decode never needs to search for a delimiter inside the string content, because it already knows exactly how many characters to consume. This is what makes it safe even if a string contains `#` itself.

---

## Example Walkthrough

Input: `strs = ["ab", "c#d", ""]`

**Encode:**

| String | length#str appended | Result so far |
|---|---|---|
| `"ab"` | `"2#ab"` | `"2#ab"` |
| `"c#d"` | `"3#c#d"` | `"2#ab3#c#d"` |
| `""` | `"0#"` | `"2#ab3#c#d0#"` |

Encoded output: `"2#ab3#c#d0#"`

**Decode** (`s = "2#ab3#c#d0#"`):

| i | Reading | len | Extracted string | i after |
|---|---|---|---|---|
| 0 | `"2"` then `#` | 2 | `s[2..3]` = `"ab"` | 4 |
| 4 | `"3"` then `#` | 3 | `s[6..8]` = `"c#d"` | 9 |
| 9 | `"0"` then `#` | 0 | 0 chars copied → `""` | 11 |

Decoded result: `["ab", "c#d", ""]` — matches the original input, even though one string contained the delimiter `#`.

## Common Mistake
A naive approach that joins strings with a fixed delimiter (e.g. `str1 + "," + str2`) breaks the moment any string contains that delimiter character — `"c#d"` in the example above would get mis-split with a plain `#`-delimiter approach. Prefixing with length sidesteps the problem entirely, since decode never scans the string body for a separator.
