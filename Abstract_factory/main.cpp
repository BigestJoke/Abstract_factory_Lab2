#include <iostream>
#include "Fabrics.h"

using namespace std;

string generateProgram(const AbstractFactory& factory)
{
    auto myClass = factory.createClassUnit("MyClass");
    myClass->add(factory.createMethodUnit("testFunc1", "void", 0), ClassUnit::PUBLIC); // Добавление метода "testFunc1" с модификатором доступа PUBLIC.
    myClass->add(factory.createMethodUnit("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE); // Добавление статического метода "testFunc2" с модификатором доступа PRIVATE.
    myClass->add(factory.createMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC); // Добавление виртуального константного метода "testFunc3" с модификатором доступа PUBLIC.

    auto method = factory.createMethodUnit("testFunc4", "void", MethodUnit::STATIC); // Создание статического метода "testFunc4".
    method->add(factory.createPrintOperatorUnit(R"(Hello, world!\n)")); // Добавление оператора вывода "Hello, world!\n" в метод "testFunc4".
    myClass->add(method, ClassUnit::PROTECTED); // Добавление метода "testFunc4" с модификатором доступа PROTECTED в класс "MyClass".

    return myClass->compile();
}

int main()
{
    AbstractFactory *fabric = new CppFactory; // Создание фабрики для C++.
    cout << "C++ Code:\n" << generateProgram(*fabric) << endl; // Генерация и вывод программы на C++.

    fabric = new CsFactory; // Создание фабрики для C#.
    cout << "C# Code:\n" << generateProgram(*fabric) << endl; // Генерация и вывод программы на C#.

    fabric = new JavaFactory; // Создание фабрики для Java.
    cout << "Java Code:\n" << generateProgram(*fabric) << endl; // Генерация и вывод программы на Java.

    return 0; // Завершение программы.
}
