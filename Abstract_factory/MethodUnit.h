#ifndef METHODUNIT_H
#define METHODUNIT_H

#include "Unit.h"
#include <vector>
#include <string>

class MethodUnit : public Unit
{
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit(const string& name, const string& returnType, Flags flags);
    void add(const shared_ptr<Unit>& unit, Flags = 0) override;
    string compile(unsigned int level = 0) const override;
private:
    string m_name;
    string m_returnType;
    Flags m_flags;
    vector<shared_ptr<Unit>> m_body;
};


class CppMethodUnit : public MethodUnit
{
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    CppMethodUnit(const string& name, const string& returnType, Flags flags);
    void add(const shared_ptr<Unit>& unit, Flags /* flags */ = 0) override;
    string compile(unsigned int level = 0) const override;
private:
    string m_name;
    string m_returnType;
    Flags m_flags;
    vector<shared_ptr<Unit>> m_body;
};

class CSMethodUnit : public MethodUnit
{
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    CSMethodUnit(const string& name, const string& returnType, Flags flags);
    void add(const shared_ptr<Unit>& unit, Flags /* flags */ = 0) override;
    string compile(unsigned int level = 0) const override;
private:
    string m_name;
    string m_returnType;
    Flags m_flags;
    vector<shared_ptr<Unit>> m_body;
};

class JavaMethodUnit : public MethodUnit
{
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    JavaMethodUnit(const string& name, const string& returnType, Flags flags);
    void add(const shared_ptr<Unit>& unit, Flags /* flags */ = 0) override;
    string compile(unsigned int level = 0) const override;
private:
    string m_name;
    string m_returnType;
    Flags m_flags;
    vector<shared_ptr<Unit>> m_body;
};
#endif // METHODUNIT_H
