### 🔸 Problem: Coin Piles ([GFG Link](https://www.geeksforgeeks.org/problems/coin-piles5152/1))

You are given an array `arr[]` of integers where each element represents the number of coins in a pile. You are also given an integer `k`.  
Your task is to remove the **minimum number of coins** such that the **absolute difference** between the number of coins in any two remaining piles is at most `k`.

👉 You can also remove entire piles by removing all their coins.

### 🧪 Examples

#### Example 1:
**Input**:  
`arr = [2, 2, 2, 2], k = 0`  
**Output**:  
`0`  
**Explanation**: All piles are already equal. No coins need to be removed.

#### Example 2:
**Input**:  
`arr = [1, 5, 1, 2, 5, 1], k = 3`  
**Output**:  
`2`  
**Explanation**: Reduce the two `5`s to `4`, removing 1 coin from each. All differences ≤ 3.

---

## 💡 Approach

1. **Sort** the array to make processing easier.
2. For each pile `arr[i]`, consider it as the **target** minimum pile.
3. Use **binary search** to find the first pile where `arr[j] > arr[i] + k`.
4. Use **prefix sums** to:
   - Remove all coins from piles `< target`.
   - Reduce piles `> target + k` to `target + k`.
5. Keep track of the **minimum number of coins removed**.

### ⏱️ Time Complexity

- Sorting: `O(n log n)`
- Prefix sum: `O(n)`
- Main loop with binary search: `O(n log n)`

**Total**: `O(n log n)`

---

## 🧾 C++ Code

```cpp
int minimumCoins(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];

    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        int target = arr[i];
        int l = i, r = n - 1, j = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] > target + k) {
                j = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int cnt = pre[i];
        if (j < n)
            cnt += pre[n] - pre[j] - (n - j) * (target + k);
        mini = min(mini, cnt);
    }
    return mini;
}
