#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;

    vector<int> arr(n);
    vector<int> p(n + 1, 0);  

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        p[i + 1] = p[i] + arr[i];  
    }

    while (~scanf("%d%d", &a, &b)) {
        int sum = p[b + 1] - p[a];
        printf("%d\n", sum);
    }

    return 0;
}