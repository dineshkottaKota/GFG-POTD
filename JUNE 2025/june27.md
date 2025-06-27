# 📱 Mobile Numeric Keypad

## 📝 Problem Statement

Given an integer `n`, determine how many unique numeric sequences of length `n` can be formed by pressing buttons on a **mobile numeric keypad**. A move is valid only if you stay on the current key or move to a key that is **directly above, below, left, or right** (no diagonals).

You can start from **any digit**.

---

### ✅ Constraints:
- 1 ≤ n ≤ 15

---

## 📥 Input

- An integer `n` representing the length of the sequence.

## 📤 Output

- An integer denoting the total number of valid sequences.

---

## 🧪 Examples

### Example 1:
**Input:**  
`n = 1`  
**Output:**  
`10`  
**Explanation:**  
Each digit (0–9) forms a valid sequence of length 1.

---

### Example 2:
**Input:**  
`n = 2`  
**Output:**  
`36`  
**Explanation:**  
From each key, you can move to its adjacent keys or stay on it.  
Example:  
- From 0 → 0, 8  
- From 1 → 1, 2, 4  
- From 5 → 2, 4, 5, 6, 8  
Count all such valid 2-digit sequences.

---

## 🚀 Approach

1. Model the keypad as a graph where each digit has edges to its neighbors (including itself).
2. Use **dynamic programming** with:
   - `prev[i]`: number of sequences of length `l-1` ending at digit `i`
   - `curr[i]`: number of sequences of length `l` ending at digit `i`
3. For each digit `j`, sum over `prev[k]` for every neighbor `k` of `j`.
4. Repeat the process for `n` steps.
5. Sum all counts in `prev` to get the total sequences.

---

### Time Complexity:
- **O(n × 10 × 5)** ≈ O(n)

### Auxiliary Space:
- **O(10)** → Constant, just 2 arrays of size 10

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    int getCount(int n) {
        if (n == 1) return 10;

        vector<vector<int>> moves = {
            {0, 8},           // 0
            {1, 2, 4},        // 1
            {2, 1, 3, 5},     // 2
            {3, 2, 6},        // 3
            {4, 1, 5, 7},     // 4
            {5, 2, 4, 6, 8},  // 5
            {6, 3, 5, 9},     // 6
            {7, 4, 8},        // 7
            {8, 5, 7, 9, 0},  // 8
            {9, 6, 8}         // 9
        };

        vector<long long> prev(10, 1), curr(10);
        for (int i = 2; i <= n; i++) {
            fill(curr.begin(), curr.end(), 0);
            for (int j = 0; j <= 9; j++) {
                for (int k : moves[j]) {
                    curr[j] += prev[k];
                }
            }
            prev = curr;
        }

        long long total = 0;
        for (int i = 0; i <= 9; i++) total += prev[i];

        return (int)total;
    }
};
