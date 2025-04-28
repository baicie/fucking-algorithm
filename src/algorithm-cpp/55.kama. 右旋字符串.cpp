#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    string s;
    cin >> num >> s;

    int len = s.size();
    num = num % len;

    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + num);
    reverse(s.begin() + num, s.end());

    cout << s << endl;
    return 0;
}