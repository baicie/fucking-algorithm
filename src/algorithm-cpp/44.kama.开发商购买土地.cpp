#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<int>> grid(row, vector<int>(col, 0));
    vector<int> rowSum(row, 0);
    vector<int> colSum(col, 0);
    int total = 0;

    // 输入 & 求总和、行列和
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
            rowSum[i] += grid[i][j];
            colSum[j] += grid[i][j]; // ✅ 修正为 colSum
            total += grid[i][j];
        }
    }

    // 前缀和
    vector<int> rowPrefix(row + 1, 0);
    for (int i = 0; i < row; i++) {
        rowPrefix[i + 1] = rowPrefix[i] + rowSum[i];
    }

    vector<int> colPrefix(col + 1, 0);
    for (int i = 0; i < col; i++) {
        colPrefix[i + 1] = colPrefix[i] + colSum[i];
    }

    int minDiff = INT_MAX;

    // 横向切割（从第1行~第n-1行切）
    for (int i = 1; i < row; i++) {
        int top = rowPrefix[i];
        int bottom = total - top;
        minDiff = min(minDiff, abs(top - bottom));
    }

    // 纵向切割（从第1列~第m-1列切）
    for (int i = 1; i < col; i++) {
        int left = colPrefix[i];
        int right = total - left;
        minDiff = min(minDiff, abs(left - right));
    }

    cout << minDiff << endl;
    return 0;
}
