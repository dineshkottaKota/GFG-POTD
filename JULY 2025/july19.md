# 🔡 Count Unique Vowel Strings

## 🧩 Problem Statement

Given a string `s` consisting of only lowercase characters, count the number of unique vowel strings that can be formed by:

1. Picking **exactly one occurrence** of **each distinct vowel** in the string.
2. Then reordering those selected vowels.

---

### ✅ Constraints:

* 1 ≤ s.length() ≤ 10⁵
* s contains only lowercase English letters

---

## 📥 Input

* A string `s` consisting of lowercase characters.

---

## 📤 Output

* An integer representing the number of valid unique vowel strings that can be formed.

---

## 🧪 Examples

### Example 1:

**Input:**
`s = "aeeieeou"`
**Output:**
`480`
**Explanation:**
Vowel counts:

* `'a'` → 1
* `'e'` → 4
* `'i'` → 1
* `'o'` → 1
* `'u'` → 1

Total distinct vowels = 5
Ways to choose 1 occurrence of each = `1C1 × 4C1 × 1C1 × 1C1 × 1C1 = 4`
Ways to reorder = `5! = 120`
Final answer = `4 × 120 = 480`

---

## 🚀 Approach

1. Count frequency of each vowel in the string.
2. For each vowel, multiply the number of ways to choose one occurrence (which is just its frequency).
3. Multiply by the factorial of the number of distinct vowels (to account for all reorderings).

---

### ⏱️ Time Complexity:

* **O(n)** — iterate through the string once
* **O(1)** — only vowels are tracked (maximum of 5)

### 🧠 Space Complexity:

* **O(1)** — constant space for the vowel map

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    int vowelCount(string& s) {
        int n = s.length(), ans = 1;
        unordered_map<char, int> m;

        for (char x : s) { 
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                m[x]++;
        }

        if (m.size() == 0) return 0;

        // Multiply by factorial of number of distinct vowels
        for (int i = 1; i <= m.size(); ++i) 
            ans *= i;

        // Multiply by count of each vowel (ways to choose one occurrence)
        for (auto x : m)
            ans *= x.second;

        return ans;
    }
};
```

---

Let me know if you'd like the same explanation in Python or want to add modulo (`1e9+7`) for large inputs!
