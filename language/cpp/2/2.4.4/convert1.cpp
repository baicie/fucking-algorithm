#include <iostream>

int stonetolb(int);
int main()
{
    using namespace std;
    int stone;
    int aunt = stonetolb(20);
    int aunts = aunt + stonetolb(10);
    cout << "Aunt weight: " << stonetolb(16) << " pounds." << endl;
    cout << "Enter the weight in stone: ";
    cin >> stone;
    int pounds = stonetolb(stone);
    cout << stone << " stone = ";
    cout << pounds << " pounds." << endl;
    return 0;
}

int stonetolb(int sts)
{
    return 14 * sts;
}