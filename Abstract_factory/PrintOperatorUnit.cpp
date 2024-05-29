#include "PrintOperatorUnit.h"

PrintOperatorUnit::PrintOperatorUnit(const std::string& text) : m_text(text) { }

void PrintOperatorUnit::add(const std::shared_ptr<Unit>& /* unit */, Flags /* flags */) { }

std::string PrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}
