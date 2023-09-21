#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    MyString str1(50, "Hello, ");
    MyString str2(50, "World!");
    str1.print();
    str2.print();
    cout << endl << str1.mystrstr("Hell") << endl;
    str1.mystrcat(str2);
    str1.print();
    cout << endl << str1.mystrlen() << endl;
    str1.mydelchr('!');
    str1.print();
    cout << endl << str1.mystrlen() << endl;
    str1.mydelchr('l');
    str1.print();
    cout << endl << str1.mystrlen() << endl;
    cout << endl << str1.mystrcmp(str2) << endl;
    str1[0] = 'b';
    str1.print();
    cout << "\n\n\n";
    char c = 'j';
    MyString a(str1);
    MyString b(a.mystrlen() + 2);
    for (int i = 1; i < a.mystrlen() + 1; i++)
    {
        b[i] = str1[i - 1];
    }
    b[0] = c;
    b[a.mystrlen() + 1] = '\0';
    b.print();
    MyString m = str1 + b;
    m.print();
    cout << "\n\n\n";
    MyString str4(70, "Gnome");
    ++str4;
    str4.print();
    str4++;
    str4.print();
    MyString str5(move(str4));
    cout << "\n\n\n";
    str5.print();
    cout << endl;
    str4.print();
}