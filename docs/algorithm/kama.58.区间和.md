# Kama 58 区间和

## ✅ 解法总结

- 构建前缀和数组 prefixSum，预处理数组，使得任意区间和查询可在 O(1) 时间内完成

## 💡 关键思路

- 区间和重复查询场景，用前缀和优化效率

- 前缀和定义：prefixSum[i] = nums[0] + nums[1] + ... + nums[i - 1]

- 这样，查询区间 [l, r] 之和为：prefixSum[r + 1] - prefixSum[l]

- 一次预处理，多次查询时非常高效

## 💥 我踩的坑

## 🔍 最终代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;

    vector<int> nums(n);
    vector<int> prefixSum(n + 1, 0); // prefixSum[0] = 0

    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    while (~scanf("%d%d", &a, &b)) {
        int sum = prefixSum[b + 1] - prefixSum[a];
        printf("%d\n", sum);
    }

    return 0;
}
```
