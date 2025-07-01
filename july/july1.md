# 🔡 Count Substrings with Exactly k-1 Distinct Characters

## 🧩 Problem Statement

Given a string `s` consisting of only lowercase alphabets and an integer `k`, find the **count of all substrings** of length `k` that have **exactly `k-1` distinct characters**.

---

### ✅ Constraints:
- 1 ≤ s.length() ≤ 10⁵  
- 2 ≤ k ≤ 27

---

## 📥 Input

- A string `s` of lowercase characters.
- An integer `k`.

## 📤 Output

- An integer representing the number of valid substrings of length `k` having exactly `k - 1` distinct characters.

---

## 🧪 Examples

### Example 1:
**Input:**  
`s = "abcc", k = 2`  
**Output:**  
`1`  
**Explanation:**  
Substrings of length 2: "ab", "bc", "cc"  
Only "cc" has exactly 1 distinct character → Valid count = 1

---

### Example 2:
**Input:**  
`s = "aabab", k = 3`  
**Output:**  
`3`  
**Explanation:**  
Substrings of length 3: "aab", "aba", "bab"  
All 3 substrings have 2 distinct characters → Valid count = 3

---

## 🚀 Approach

We use the **sliding window technique** with a hash map to track character frequencies in a window of size `k`.

### Steps:
1. Slide a window of size `k` across the string.
2. Use a hash map to count character frequencies.
3. For each window, if the number of distinct characters is `k - 1`, increment the answer.
4. Remove the leftmost character as the window moves.

---

### ⏱️ Time Complexity:
- **O(n)** — Each character is visited at most twice.

### 🧠 Space Complexity:
- **O(1)** — Maximum 26 lowercase characters in the map.

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    int substrCount(string &s, int k) {
        unordered_map<char, int> mpp;
        int n = s.size();
        if (n < k) return 0;

        int cnt = 0;
        int i = 0, j = 0;

        while (j < n) {
            // Expand window
            while (j != i + k && j < n) {
                mpp[s[j++]]++;
            }

            if (mpp.size() == k - 1) cnt++;

            // Shrink window
            mpp[s[i]]--;
            if (mpp[s[i]] == 0) mpp.erase(s[i]);
            i++;
        }

        return cnt;
    }
};
