#include "MethodUnit.h"

MethodUnit::MethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
    m_name(name), m_returnType(returnType), m_flags(flags) { }


void MethodUnit::add(const std::shared_ptr<Unit>& unit, Flags /* flags */)
{
    m_body.push_back(unit); // Добавляет единицу (unit) в тело метода.
}

string MethodUnit::compile(unsigned int level) const
{
    string result = generateShift(level);
    if (m_flags & STATIC)
    {
        result += "static ";
    }
    else if (m_flags & VIRTUAL)
    {
        result += "virtual ";
    }
    result += m_returnType + " "; // Добавляет возвращаемый тип метода.
    result += m_name + "()";
    if (m_flags & CONST)
    {
        result += " const";
    }
    result += " {\n";
    for (const auto& b : m_body) // Проходит по всем элементам тела метода.
    {
        result += b->compile(level + 1); // Компилирует каждый элемент и добавляет его в результирующую строку.
    }
    result += generateShift(level) + "}\n";
    return result;
}
//---------------------------------------------------------------------------
CppMethodUnit::CppMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :MethodUnit(name,returnType,flags),
    m_name(name), m_returnType(returnType), m_flags(flags) { }

void CppMethodUnit::add(const std::shared_ptr<Unit>& unit, Flags /* flags */)
{
    m_body.push_back(unit);
}

string CppMethodUnit::compile(unsigned int level) const
{
    string result = generateShift( level );
    if( m_flags & STATIC )
    {
        result += "static ";
    }
    else if( m_flags & VIRTUAL )
    {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & CONST )
    {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

//---------------------------------------------------------------------------
CSMethodUnit::CSMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :MethodUnit(name,returnType,flags),
    m_name(name), m_returnType(returnType), m_flags(flags) { }

void CSMethodUnit::add(const std::shared_ptr<Unit>& unit, Flags /* flags */)
{
    m_body.push_back(unit);
}

string CSMethodUnit::compile(unsigned int level) const
{
    string result = generateShift( level );

    if( m_flags & STATIC )
    {
        result += "static ";
    }
    else if( m_flags & VIRTUAL )
    {
        result += "virtual ";
    }
    else if( m_flags & OVERRIDE)
    {
        result += "override ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

//---------------------------------------------------------------------------
JavaMethodUnit::JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :MethodUnit(name,returnType,flags),
    m_name(name), m_returnType(returnType), m_flags(flags) { }

void JavaMethodUnit::add(const std::shared_ptr<Unit>& unit, Flags /* flags */)
{
    m_body.push_back(unit);
}

string JavaMethodUnit::compile(unsigned int level) const
{
    string result = generateShift( level );
    if( m_flags & STATIC )
    {
        result += "static ";
    }
    if( m_flags & FINAL )
    {
        result += "final ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

//---------------------------------------------------------------------------
