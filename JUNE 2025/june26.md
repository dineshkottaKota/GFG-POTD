# 🎮 Game with String

## 📝 Problem Statement

Given a string `s` of lowercase alphabets and an integer `k`, remove exactly `k` characters from the string to **minimize its value**.

The **value** of the string is defined as the **sum of squares** of the frequencies of each distinct character.

---

### ✅ Constraints:
- 0 ≤ k ≤ s.length() ≤ 10⁵

---

## 📥 Input

- A string `s`
- An integer `k`

## 📤 Output

- The **minimum value** of the string after removing exactly `k` characters.

---

## 🧪 Examples

### Example 1:
**Input:**  
`s = "abbccc", k = 2`  
**Output:**  
`6`  
**Explanation:**  
- Remove two `'c'` → Frequencies: `a:1, b:2, c:1` → `1² + 2² + 1² = 6`  
- Another option: Remove one `'b'` and one `'c'` → Still results in `6`

---

### Example 2:
**Input:**  
`s = "aaab", k = 2`  
**Output:**  
`2`  
**Explanation:**  
- Remove two `'a'` → Frequencies: `a:1, b:1` → `1² + 1² = 2`

---

## 🚀 Approach

1. Count frequency of each character using a hash map.
2. Push all frequencies into a **max heap** (priority queue).
3. While `k > 0`, remove 1 from the highest frequency (i.e., reduce the most frequent character).
4. After `k` removals, compute the **sum of squares** of the remaining frequencies.

---

### Time Complexity:
- **O(n + k log n)**

### Auxiliary Space:
- **O(n)**

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    int minValue(string &s, int k) {
        unordered_map<char, int> mpp;
        for (char c : s) mpp[c]++;

        priority_queue<int> pq;
        for (auto it : mpp) pq.push(it.second);

        while (k-- && !pq.empty()) {
            int top = pq.top(); pq.pop();
            if (--top > 0) pq.push(top);
        }

        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top() * pq.top();
            pq.pop();
        }

        return ans;
    }
};
