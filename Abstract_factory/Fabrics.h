#ifndef FABRICS_H
#define FABRICS_H

#include <memory>
#include <string>
#include "Unit.h"
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

class AbstractFactory
{
public:
    virtual ~AbstractFactory() = default;
    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) const = 0;
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const = 0;
};

class CppFactory : public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) const override
    {
        return std::make_shared<CppUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const override
    {
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override
    {
        return std::make_shared<CppPOU>(text);
    }
};

class CsFactory : public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) const override
    {
        return std::make_shared<CSUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const override
    {
        return std::make_shared<CSMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override
    {
        return std::make_shared<CSPOU>(text);
    }
};

class JavaFactory : public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) const override
    {
        return std::make_shared<JavaUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const override
    {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const override
    {
        return std::make_shared<JavaPOU>(text);
    }
};

#endif
