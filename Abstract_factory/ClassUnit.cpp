#include "ClassUnit.h"

const vector<string> ClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };

ClassUnit::ClassUnit(const string& name) : m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void ClassUnit::add(const shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;

    if (flags < ACCESS_MODIFIERS.size())
    {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

string ClassUnit::compile(unsigned int level) const
{
    string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
        {
            continue;
        }
        result += ACCESS_MODIFIERS[i] + ":\n";
        for (const auto& f : m_fields[i])
        {
            result += f->compile(level + 1);
        }
        result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}

//----------------------------------------------------------------------------------
const vector<string> CppUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };

CppUnit::CppUnit(const string& name) :ClassUnit(name), m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void CppUnit::add(const shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;

    if (flags < ACCESS_MODIFIERS.size())
    {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

string CppUnit::compile(unsigned int level) const
{
    string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
        {
            continue;
        }
        result += ACCESS_MODIFIERS[i] + ":\n";
        for (const auto& f : m_fields[i])
        {
            result += f->compile(level + 1);
        }
        result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}

//----------------------------------------------------------------------------------
const vector<string> CSUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };

CSUnit::CSUnit(const string& name) :ClassUnit(name), m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void CSUnit::add(const shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;

    if (flags < ACCESS_MODIFIERS.size())
    {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

string CSUnit::compile(unsigned int level) const
{
    string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
        {
            continue;
        }
        result += ACCESS_MODIFIERS[i] + ":\n";
        for (const auto& f : m_fields[i])
        {
            result += f->compile(level + 1);
        }
        result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}

//------------------------------------------------------------------------------------
const vector<string> JavaUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };

JavaUnit::JavaUnit(const string& name) :ClassUnit(name), m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void JavaUnit::add(const shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;

    if (flags < ACCESS_MODIFIERS.size())
    {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

string JavaUnit::compile(unsigned int level) const
{
    string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
        {
            continue;
        }
        result += ACCESS_MODIFIERS[i] + ":\n";
        for (const auto& f : m_fields[i])
        {
            result += f->compile(level + 1);
        }
        result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}
