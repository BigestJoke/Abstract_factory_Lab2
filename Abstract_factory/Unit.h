#ifndef UNIT_H
#define UNIT_H

#include <memory>
#include <string>
using namespace std;

class Unit
{
public:
    using Flags = unsigned int; // Определяет тип Flags как синоним для unsigned int.
public:
    virtual ~Unit() = default;
    virtual void add(const shared_ptr<Unit>&, Flags) = 0; // Чисто виртуальная функция для добавления объекта Unit с флагами.
    virtual string compile(unsigned int level = 0) const = 0; // Чисто виртуальная функция для компиляции объекта, с уровнем по умолчанию 0.
protected:
    virtual string generateShift(unsigned int level) const; // Виртуальная защищенная функция для генерации отступа на основе уровня.
};

#endif // UNIT_H
