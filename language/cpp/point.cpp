#include <iostream>

using namespace std;

int main()
{
    int num = 10;
    int *p = &num;
    int num2 = *p;
    cout << "num: " << num << endl;
    cout << "p: " << p << endl;
    cout << "p*: " << *p << endl;
    cout << "num2" << num2 << endl;
    return 0;
}