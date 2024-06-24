#include "PrintOperatorUnit.h"

PrintOperatorUnit::PrintOperatorUnit(const std::string& text) : m_text(text) { }

void PrintOperatorUnit::add(const std::shared_ptr<Unit>& /* unit */, Flags /* flags */) { }

std::string PrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}

//------------------------------------------------------------------------------
CppPOU::CppPOU(const std::string& text) :PrintOperatorUnit(text), m_text(text) { }

void CppPOU::add(const std::shared_ptr<Unit>& /* unit */, Flags /* flags */) { }

std::string CppPOU::compile(unsigned int level) const
{
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}

//------------------------------------------------------------------------------
CSPOU::CSPOU(const std::string& text) :PrintOperatorUnit(text), m_text(text) { }

void CSPOU::add(const std::shared_ptr<Unit>& /* unit */, Flags /* flags */) { }

std::string CSPOU::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
}

//------------------------------------------------------------------------------
JavaPOU::JavaPOU(const std::string& text) :PrintOperatorUnit(text), m_text(text) { }

void JavaPOU::add(const std::shared_ptr<Unit>& /* unit */, Flags /* flags */) { }

std::string JavaPOU::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}

//------------------------------------------------------------------------------
