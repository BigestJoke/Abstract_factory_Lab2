#include <iostream>
#include "Fabrics.h"

using namespace std;

string generateProgram(const AbstractFactory& factory)
{
    auto myClass = factory.createClassUnit("MyClass");
    myClass->add(factory.createMethodUnit("testFunc1", "void", 0), ClassUnit::PUBLIC);
    myClass->add(factory.createMethodUnit("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);
    myClass->add(factory.createMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);

    auto method = factory.createMethodUnit("testFunc4", "void", MethodUnit::STATIC);
    method->add(factory.createPrintOperatorUnit(R"(Hello, world!\n)"));
    myClass->add(method, ClassUnit::PROTECTED);

    return myClass->compile();
}
int main()
{
    AbstractFactory *fabric = new CppFactory;
    cout << "C++ Code:\n" << generateProgram(*fabric) << endl;

    fabric = new CsFactory;
    cout << "C# Code:\n" << generateProgram(*fabric) << endl;

    fabric = new JavaFactory;
    cout << "Java Code:\n" << generateProgram(*fabric) << endl;

    return 0;
}
