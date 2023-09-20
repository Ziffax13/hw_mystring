#include "MyString.h"
#include <iostream>

using namespace std;

int MyString::count = 0;

MyString::MyString()
{
    str = new char[80];
    count++;
}

MyString::MyString(int s)
{
    str = new char[s];
    count++;
}

MyString::MyString(const char s)
{
    str = new char[2];
    str[0] = s;
    str[1] = '\0';
    count++;
}

MyString::MyString(int x, const char* s)
{
    str = new char[x];
    strcpy_s(str, x, s);
    count++;
}

MyString::MyString(MyString& s)
{
    this->mystrcpy(s);
    count++;
}

MyString::~MyString()
{
    delete[] str;
    count--;
}

void MyString::print()
{
    cout << str;
}

void MyString::input()
{
    cin >> str;
}

void MyString::mystrcpy(MyString& s)
{
    delete[] str;
    str = new char[s.mystrlen() + 1];
    for (int i = 0; i < s.mystrlen() + 1; i++)
    {
        str[i] = s.str[i];
    }
}

bool MyString::mystrstr(const char* st)
{
    if (strlen(st) > this->mystrlen())
    {
        return false;
    }
    bool res  = true;
    for (int i = 0; i < this->mystrlen() - strlen(st); i+= strlen(st))
    {
        for (int j = i; j < strlen(st); j++)
        {
            if (str[j] == st[j])
            {
                res = true;
                continue;
            }
            res = false;
            break;
        }
    }
    return res;
}

int MyString::mystrlen()
{
    int len = 0;
    while (str[len]!= '\0')
    {
        len++;
    }
    return len;
}

void MyString::mystrcat(MyString& b)
{
    MyString a(*this);
    delete[] str;
    str = new char[b.mystrlen() + a.mystrlen() + 1];
    for (int i = 0; i < b.mystrlen() + a.mystrlen() + 1; i++)
    {
        str[i] = (i < a.mystrlen()) ? a.str[i] : b.str[i-a.mystrlen()];
    }
}

void MyString::mydelchr(char c)
{
    for (int i = 0; i < this->mystrlen(); i++)
    {
        if (str[i] == c)
        {
            for (int j = i; j < this->mystrlen(); j++)
            {
                str[j] = str[j+1];
                i--;
            }
        }
    }
}

int MyString::mystrcmp(MyString& b)
{
    return (this->mystrlen() == b.mystrlen()) ? 0 : (this->mystrlen() < b.mystrlen()) ? -1 : 1;
}

char& MyString::operator[](const unsigned int x)
{
    return str[x];
}

void MyString::operator()()
{
    input();
}

MyString& MyString::operator=(MyString& s)
{
    delete[] str;
    str = new char[s.mystrlen() + 1];
    for (int i = 0; i < s.mystrlen() + 1; i++)
    {
        str[i] = s.str[i];
    }
    return *this;
}

MyString operator+(char c, MyString a)
{
    MyString b(a.mystrlen() + 2);
    for (int i = 1; i < a.mystrlen() + 1; i++)
    {
        b[i] = a[i - 1];
    }
    b[0] = c;
    b[a.mystrlen() + 1] = '\0';
    return b;
}


//MyString operator+(MyString a, char c)
//{
//}
//
//
//MyString operator+(MyString a, int x)
//{
//    MyString b(a.mystrlen() + x + 1);
//    for (int i = a.mystrlen(); i < b.mystrlen() + x + 1; i++)
//    {
//        b[i] = '0';
//    }
//    b[b.mystrlen() + x + 1] = '\0';
//    return b;
//}
//
//MyString operator+(int x, MyString a)
//{
//    MyString b = a + x;
//    return b;
//}
//
//MyString& operator++(MyString a)
//{
//    MyString b(a.mystrlen() + 1);
//    for (int i = 1; i < a.mystrlen() + 1; i++)
//    {
//        b[i] = a[i - 1];
//    }
//    b[0] = '0';
//    b[b.mystrlen()] = '\n';
//    return b;
//}
