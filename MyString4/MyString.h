#pragma once
#include <iostream>
#include <initializer_list>
using namespace std;

class MyString {
private:
    char* str;
    int length;
    static int objectCount;

public:
    MyString();
    MyString(int size);
    MyString(const char* initStr);
    MyString(const MyString& obj);
    MyString(MyString&& obj) noexcept;
    MyString(initializer_list<char> initList);
    ~MyString();

    void Input();
    void Output() const;

    void MyStrcpy(const MyString& obj);
    bool MyStrStr(const char* substr) const;
    int MyChr(char c) const;
    int MyStrLen() const;
    void MyStrCat(const MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(const MyString& b) const;

    MyString& operator=(const MyString& obj);
    MyString& operator=(MyString&& obj) noexcept;
    MyString operator+(const MyString& b) const;
    char& operator[](int index);
    MyString& operator++();
    MyString operator++(int);
    void operator()();
    MyString operator+(char c) const;

    static int getObjectCount();

    const char* getStr() const;
    int getLength() const;
    void setStr(const char* newStr);
    void setLength(int newLength);

    friend ostream& operator<<(ostream& out, const MyString& obj);
    friend istream& operator>>(istream& in, MyString& obj);
};
