#pragma once
class MyString
{
    char* str;
public:
    static int count;
    MyString();
    MyString(int);
    MyString(int, const char*);
    MyString(MyString&);
    MyString(const char s);
    ~MyString();

    void print();
    void input();
    void mystrcpy(MyString&);
    bool mystrstr(const char*);
    int mystrlen();
    void mystrcat(MyString&);
    void mydelchr(char);
    int mystrcmp(MyString&);

    char& operator[](const unsigned int x);
    void operator()();
    MyString& operator=(MyString&);
};

MyString operator+(MyString, char);
MyString operator+(char, MyString);
MyString operator+(MyString, int);
MyString operator+(int, MyString);
MyString& operator++(MyString);
MyString& operator--(MyString);