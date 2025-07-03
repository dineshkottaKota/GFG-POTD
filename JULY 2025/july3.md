# Longest Substring with K Unique Characters

## 🧩 Problem Statement

Given a string `s` of lowercase alphabets and an integer `k`, find the length of the **longest substring** that contains **exactly `k` distinct characters**.  
If no such substring exists, return `-1`.

### ✅ Constraints:
- 1 ≤ s.length ≤ 10⁵  
- 1 ≤ k ≤ 26

---

## 📥 Input

- A string `s`
- An integer `k`

## 📤 Output

- An integer representing the length of the longest valid substring, or `-1`.

---

## 🧪 Examples

### Example 1:
**Input:**  
`s = "aabacbebebe"`, `k = 3`  
**Output:**  
`7`  
**Explanation:**  
Longest substring is `"cbebebe"` with 3 distinct characters.

---

### Example 2:
**Input:**  
`s = "aaaa"`, `k = 2`  
**Output:**  
`-1`  
**Explanation:**  
No substring with exactly 2 distinct characters exists.

---

## 🚀 Approach

We use a **sliding window** with a hash map to track character frequencies:

### Steps:
1. Use two pointers `i` and `j` to form a window.
2. Expand the window (`j++`) and count characters.
3. If the window has more than `k` distinct characters, shrink from the left (`i++`) until it has exactly `k`.
4. Track the maximum length where the window has **exactly `k` distinct characters**.

---

## ⏱️ Complexity

- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)` (since alphabet size is fixed)

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> mpp;
        int ans = -1, i = 0;
        for(int j = 0; j < s.size(); j++) {
            mpp[s[j]]++;
            while(mpp.size() > k) {
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            if(mpp.size() == k)
                ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
