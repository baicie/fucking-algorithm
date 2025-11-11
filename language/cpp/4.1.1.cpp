#include <iostream>
using namespace std;

class Demo
{
public:
    Demo(int a)
    {
        this->a = a;
    }
    Demo &operator=(Demo &d)
    {
        this->a = d.a;
        return *this;
    }
    int a;
}