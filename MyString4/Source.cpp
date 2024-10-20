#include "MyString.h"
#include <iostream>
using namespace std;

int main() {
    MyString str1("Привет");
    MyString str2("Мир");
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;

    MyString str3;
    str3 = str1;
    cout << "str3 после присваивания str1: " << str3 << endl;

    cout << "Введите новую строку для str3: ";
    cin >> str3;
    cout << "str3 после ввода: " << str3 << endl;

    MyString str4 = str1 + str2;
    cout << "str1 + str2 = " << str4 << endl;

    MyString str5 = str4 + '!';
    cout << "str4 + '!' = " << str5 << endl;

    cout << "str5[0]: " << str5[0] << endl;

    ++str1;
    cout << "str1 после префиксного ++: " << str1 << endl;

    str2++;
    cout << "str2 после постфиксного ++: " << str2 << endl;

    MyString str6{ 'H', 'e', 'l', 'l', 'o' };
    cout << "str6: " << str6 << endl;

    MyString str7 = move(str1);
    cout << "str7 после переноса str1: " << str7 << endl;
    cout << "str1 после переноса: " << str1 << endl;

    str7 = move(str2);
    cout << "str7 после переноса str2: " << str7 << endl;
    cout << "str2 после переноса: " << str2 << endl;

    cout << "Общее количество объектов MyString: " << MyString::getObjectCount() << endl;

    return 0;
}
