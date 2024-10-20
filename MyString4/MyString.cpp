#include "MyString.h"
#include <cstring>
#include <iostream>
using namespace std;

int MyString::objectCount = 0;

MyString::MyString() {
    length = 80;
    str = new char[length + 1];
    str[0] = '\0';
    objectCount++;
}

MyString::MyString(int size) {
    length = size;
    str = new char[length + 1];
    str[0] = '\0';
    objectCount++;
}

MyString::MyString(const char* initStr) {
    length = strlen(initStr);
    str = new char[length + 1];
    strcpy(str, initStr);
    objectCount++;
}

MyString::MyString(const MyString& obj) {
    length = obj.length;
    str = new char[length + 1];
    strcpy(str, obj.str);
    objectCount++;
}

MyString::MyString(MyString&& obj) noexcept {
    str = obj.str;
    length = obj.length;
    obj.str = nullptr;
    obj.length = 0;
    objectCount++;
}

MyString::MyString(initializer_list<char> initList) {
    length = initList.size();
    str = new char[length + 1];
    int i = 0;
    for (char c : initList) {
        str[i++] = c;
    }
    str[length] = '\0';
    objectCount++;
}

MyString::~MyString() {
    delete[] str;
    objectCount--;
}

void MyString::Input() {
    char buffer[256];
    cin.getline(buffer, 256);
    setStr(buffer);
}

void MyString::Output() const {
    cout << str << endl;
}

void MyString::MyStrcpy(const MyString& obj) {
    setStr(obj.getStr());
}

bool MyString::MyStrStr(const char* substr) const {
    return strstr(str, substr) != nullptr;
}

int MyString::MyChr(char c) const {
    for (int i = 0; i < length; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen() const {
    return strlen(str);
}

void MyString::MyStrCat(const MyString& b) {
    char* temp = new char[length + b.length + 1];
    strcpy(temp, str);
    strcat(temp, b.str);
    delete[] str;
    str = temp;
    length += b.length;
}

void MyString::MyDelChr(char c) {
    int newLength = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != c) {
            str[newLength++] = str[i];
        }
    }
    str[newLength] = '\0';
    length = newLength;
}

int MyString::MyStrCmp(const MyString& b) const {
    return strcmp(str, b.str);
}

const char* MyString::getStr() const {
    return str;
}

int MyString::getLength() const {
    return length;
}

void MyString::setStr(const char* newStr) {
    delete[] str;
    length = strlen(newStr);
    str = new char[length + 1];
    strcpy(str, newStr);
}

void MyString::setLength(int newLength) {
    length = newLength;
}

ostream& operator<<(ostream& out, const MyString& obj) {
    out << obj.getStr();
    return out;
}

istream& operator>>(istream& in, MyString& obj) {
    char buffer[256];
    in.getline(buffer, 256);
    obj.setStr(buffer);
    return in;
}

MyString& MyString::operator=(const MyString& obj) {
    if (this != &obj) {
        setStr(obj.getStr());
        setLength(obj.getLength());
    }
    return *this;
}

MyString& MyString::operator=(MyString&& obj) noexcept {
    if (this != &obj) {
        delete[] str;
        str = obj.str;
        length = obj.length;
        obj.str = nullptr;
        obj.length = 0;
    }
    return *this;
}

MyString MyString::operator+(const MyString& b) const {
    MyString temp(length + b.length);
    strcpy(temp.str, str);
    strcat(temp.str, b.str);
    return temp;
}

char& MyString::operator[](int index) {
    if (index >= 0 && index < length) {
        return str[index];
    }
    throw out_of_range("Индекс за пределами строки");
}

MyString& MyString::operator++() {
    char* temp = new char[length + 2];
    strcpy(temp, str);
    strcat(temp, " ");
    delete[] str;
    str = temp;
    length++;
    return *this;
}

MyString MyString::operator++(int) {
    MyString temp(*this);
    ++(*this);
    return temp;
}

void MyString::operator()() {
    Input();
}

MyString MyString::operator+(char c) const {
    MyString temp(length + 1);
    strcpy(temp.str, str);
    temp.str[length] = c;
    temp.str[length + 1] = '\0';
    return temp;
}

int MyString::getObjectCount() {
    return objectCount;
}
