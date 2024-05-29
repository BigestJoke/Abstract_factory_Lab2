#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include "Unit.h"
#include <string>

class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit(const string& text);
    void add(const shared_ptr<Unit>& /* unit */, Flags /* flags */) override;
    string compile(unsigned int level = 0) const override;
private:
    string m_text;
};

#endif // PRINTOPERATORUNIT_H
