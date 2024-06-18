#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "Unit.h"
#include <vector>
#include <string>

class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED,
        FILE
    };
    static const vector<string> ACCESS_MODIFIERS;
public:
    explicit ClassUnit(const string& name);
    void add(const shared_ptr<Unit>& unit, Flags flags) override;
    string compile(unsigned int level = 0) const override;
private:
    string m_name;
    using Fields = vector<shared_ptr<Unit>>;
    vector<Fields> m_fields;
};

class CppUnit : public ClassUnit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const vector<string> ACCESS_MODIFIERS;
public:
    explicit CppUnit(const string& name);
    void add(const shared_ptr<Unit>& unit, Flags flags) override;
    string compile(unsigned int level = 0) const override;
private:
    string m_name;
    using Fields = vector<shared_ptr<Unit>>;
    vector<Fields> m_fields;
};

class CSUnit : public ClassUnit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVAT_PROTECTED
    };
    static const vector<string> ACCESS_MODIFIERS;
public:
    explicit CSUnit(const string& name);
    void add(const shared_ptr<Unit>& unit, Flags flags) override;
    string compile(unsigned int level = 0) const override;
private:
    string m_name;
    using Fields = vector<shared_ptr<Unit>>;
    vector<Fields> m_fields;
};

class JavaUnit : public ClassUnit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT
    };
    static const vector<string> ACCESS_MODIFIERS;
public:
    explicit JavaUnit(const string& name);
    void add(const shared_ptr<Unit>& unit, Flags flags) override;
    string compile(unsigned int level = 0) const override;
private:
    string m_name;
    using Fields = vector<shared_ptr<Unit>>;
    vector<Fields> m_fields;
};

#endif // CLASSUNIT_H
