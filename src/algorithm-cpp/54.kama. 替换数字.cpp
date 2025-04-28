#include <iostream>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int sOledIndex = s.size() - 1;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                count++;
            }
            /* code */
        }
        s.resize(s.size() + count * 5);
        int sNewIndx = s.size() - 1;
        while (sOledIndex >= 0)
        {
            if (isdigit(s[sOledIndex]))
            {
                s[sNewIndx--] = 'r';
                s[sNewIndx--] = 'e';
                s[sNewIndx--] = 'b';
                s[sNewIndx--] = 'm';
                s[sNewIndx--] = 'u';
                s[sNewIndx--] = 'n';
            }
            else
            {
                s[sNewIndx--] = s[sOledIndex];
            }
            sOledIndex--;
            /* code */
        }
        cout << s << endl;
        /* code */
    }
}