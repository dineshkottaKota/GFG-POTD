# 🔍 Sum of Subarray Minimums using Monotonic Stack — Contribution Technique Explained

When a problem asks for **"sum of minimums over all subarrays"**, our first instinct might be brute-force. But that's not feasible for large arrays. Instead, let’s flip the problem and use the **contribution technique** powered by a **monotonic stack**.

---

## 📘 Problem Statement

Given an array of integers `arr[]`, return the **sum of the minimum element of every subarray**.

### Example

```cpp
Input:  arr = [3, 1, 2, 4]
Output: 17
```

**Explanation:**

All subarrays and their minimums:

```
[3]        → 3  
[3,1]      → 1  
[3,1,2]    → 1  
[3,1,2,4]  → 1  
[1]        → 1  
[1,2]      → 1  
[1,2,4]    → 1  
[2]        → 2  
[2,4]      → 2  
[4]        → 4  

Sum = 3 + 1 + 1 + 1 + 1 + 1 + 1 + 2 + 2 + 4 = 17
```

---

## ❌ Naive Approach

Generate all subarrays → O(n²)  
Find min for each subarray → O(n)  
**Total Time: O(n³)** — not acceptable for large input sizes.

---

## 💡 Key Insight — Contribution Technique

Instead of finding the minimum for each subarray, we flip the problem:

> For each element `arr[i]`, find how many subarrays it is the **minimum in**, then add its total contribution.

### Contribution Formula

```
contribution = arr[i] * left[i] * right[i]
```

Where:
- `left[i]`: Number of elements to the **left (including i)** where `arr[i]` is the minimum.
- `right[i]`: Number of elements to the **right (including i)** where `arr[i]` is the minimum.

---

## 🔄 Monotonic Stack Approach

We use a **monotonic increasing stack** to efficiently calculate:

- `left[i]`: Number of contiguous elements to the **left** (including itself) **greater than or equal to `arr[i]`**.
- `right[i]`: Number of contiguous elements to the **right** (including itself) **strictly greater than `arr[i]`**.

---

## 💻 C++ Code

```cpp
class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        stack<pair<int, int>> st;
        vector<int> l(n), r(n);

        // Calculate left
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (!st.empty() && st.top().first >= arr[i]) {
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i], cnt});
            l[i] = cnt;
        }

        // Clear stack
        while (!st.empty()) st.pop();

        // Calculate right
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;
            while (!st.empty() && st.top().first > arr[i]) {
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i], cnt});
            r[i] = cnt;
        }

        // Final sum
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i] * l[i] * r[i];
        }
        return sum;
    }
};
```

---

## 🧠 Dry Run Example

```cpp
arr = [3, 1, 2, 4]
```

Frequencies:
- `3` appears as min in 1 subarray → contributes `3 * 1 * 1 = 3`
- `1` is min in 6 subarrays → contributes `1 * 2 * 3 = 6`
- `2` is min in 2 subarrays → contributes `2 * 1 * 2 = 4`
- `4` is min in 1 subarray → contributes `4 * 1 * 1 = 4`

**Total = 3 + 6 + 4 + 4 = 17**

---

## ⏱ Time & Space Complexity

**Time Complexity: O(n)**  
- Each element is pushed and popped **at most once** from the stack.
- Left and right passes = O(n)

**Space Complexity: O(n)**  
- For `left[]`, `right[]`, and stack

---

## ✅ Final Output

```cpp
Input:  [3, 1, 2, 4]
Output: 17
```

---

## 🧵 Conclusion

This problem is a perfect example of using the **contribution technique**:

> Instead of generating all subarrays, calculate how much each element contributes to the answer.

Whenever you see:
- "Sum over all subarrays of X"
Try to flip the logic:
- "How many subarrays does element X affect?"

This trick also applies to:
- Maximum in subarrays
- Product of subarray GCDs
- Histogram problems

---
