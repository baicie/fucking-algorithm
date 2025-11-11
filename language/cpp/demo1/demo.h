#include <string>
using namespace std;

#define MAX 1000

struct Person
{
    string m_Name;
    int m_Sex;      // 性别：1男 2女
    int m_Age;      // 年龄
    string m_Phone; // 电话
    string m_Addr;  // 住址
};

struct AddressBooks
{
    struct Person personArray[MAX]; // 通讯录中保存的联系人数组
    int m_Size;                     // 通讯录中人员个数
};

void addPerson(AddressBooks *abs);
void showPerson(AddressBooks *abs);