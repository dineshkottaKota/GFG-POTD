# Max Score from Subarray Mins

## 🧩 Problem Statement

You are given an array `arr[]` of integers. For **every subarray of length ≥ 2**, calculate the **sum of the smallest and second smallest elements** in that subarray. Return the **maximum** such sum among all possible subarrays.

---

## ✅ Constraints

- 2 ≤ arr.size() ≤ 10⁵  
- 1 ≤ arr[i] ≤ 10⁶

---

## 📥 Input

An integer array `arr[]`

## 📤 Output

Return an integer — the maximum score among all subarrays as described.

---

## 🧪 Examples

### Example 1
**Input:**  
`arr = [4, 3, 5, 1]`  
**Output:**  
`8`  
**Explanation:**
- `[4, 3] → 3 + 4 = 7`
- `[4, 3, 5] → 3 + 4 = 7`
- `[4, 3, 5, 1] → 1 + 3 = 4`
- `[3, 5] → 3 + 5 = 8` ✅ Max
- ...

---

### Example 2
**Input:**  
`arr = [1, 2, 3]`  
**Output:**  
`5`  
**Explanation:**
- `[2, 3] → 2 + 3 = 5` ✅ Max
