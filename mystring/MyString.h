#pragma once
class MyString
{
    char* str;
public:
    static int count;

    MyString();
    MyString(int);
    MyString(int, const char*);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();

    void print();
    void input();
    void mystrcpy(MyString&);
    bool mystrstr(const char*);
    int mystrlen()const;
    void mystrcat(MyString&);
    void mydelchr(char);
    int mystrcmp(MyString&);

    char& operator[](int x);
    void operator()();
    MyString& operator=(const MyString&);
};

MyString operator+(MyString& a, MyString& b);
MyString operator+(char c, const MyString& a);
MyString operator+(MyString, char);
MyString operator+(MyString, int);
MyString operator+(int, MyString);
MyString& operator++(MyString&);
MyString& operator++(MyString&, int);