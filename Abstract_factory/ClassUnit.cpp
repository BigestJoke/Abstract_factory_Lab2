#include "ClassUnit.h" // Включает определение класса ClassUnit и его производных.

const vector<string> ClassUnit::ACCESS_MODIFIERS = { "public","protected","private","default","internal","protected_internal", "private_protected","file" };

ClassUnit::ClassUnit(const string& name) : m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size()); // Изменяет размер m_fields, чтобы он соответствовал количеству модификаторов доступа.
}

void ClassUnit::add(const shared_ptr<Unit>& unit, Flags flags) // Переопределение функции add для добавления объектов с флагами.
{
    int accessModifier = PRIVATE;

    if (flags < ACCESS_MODIFIERS.size()) // Проверка, что флаг находится в пределах доступных модификаторов.
    {
        accessModifier = flags; // Устанавливает модификатор доступа в соответствии с флагом.
    }
    m_fields[accessModifier].push_back(unit); // Добавляет объект unit в соответствующий вектор m_fields.
}

string ClassUnit::compile(unsigned int level) const
{
    string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) // Проходит по всем модификаторам доступа.
    {
        if (m_fields[i].empty())
        {
            continue;
        }
        result += ACCESS_MODIFIERS[i] + ":\n";
        for (const auto& f : m_fields[i]) // Проходит по всем полям текущего модификатора доступа.
        {
            result += f->compile(level + 1); // Компилирует каждое поле и добавляет его в результирующую строку.
        }
        result += "\n"; // Добавляет новую строку в результирующую строку.
    }
    result += generateShift(level) + "};\n";
    return result;
}

//----------------------------------------------------------------------------------
const vector<string> CppUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };


CppUnit::CppUnit(const string& name) : ClassUnit(name), m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void CppUnit::add(const shared_ptr<Unit>& unit, Flags flags)
{
    int accessModifier = PRIVATE;

    if (flags < ACCESS_MODIFIERS.size())
    {
        accessModifier = flags; // Устанавливает модификатор доступа в соответствии с флагом.
    }
    m_fields[accessModifier].push_back(unit); // Добавляет объект unit в соответствующий вектор m_fields.
}

string CppUnit::compile(unsigned int level) const
{
    string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) // Проходит по всем модификаторам доступа.
    {
        if (m_fields[i].empty())
        {
            continue;
        }
        result += ACCESS_MODIFIERS[i] + ":\n"; // Добавляет модификатор доступа в результирующую строку.
        for (const auto& f : m_fields[i]) // Проходит по всем полям текущего модификатора доступа.
        {
            result += f->compile(level + 1); // Компилирует каждое поле и добавляет его в результирующую строку.
        }
        result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}

//----------------------------------------------------------------------------------
const vector<string> CSUnit::ACCESS_MODIFIERS = { "public", "protected" , "private" ,"internal","protected_internal","privat_protected" };


CSUnit::CSUnit(const string& name) : ClassUnit(name), m_name(name)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void CSUnit::add(const shared_ptr<Unit>& unit, Flags flags) // Переопределение функции add для добавления объектов с флагами.
{
    int accessModifier = PRIVATE; // По умолчанию модификатор доступа PRIVATE.

    if (flags < ACCESS_MODIFIERS.size()) // Проверка, что флаг находится в пределах доступных модификаторов.
    {
        accessModifier = flags; // Устанавливает модификатор доступа в соответствии с флагом.
    }
    m_fields[accessModifier].push_back(unit); // Добавляет объект unit в соответствующий вектор m_fields.
}

string CSUnit::compile(unsigned int level) const // Переопределение функции compile для компиляции объекта с уровнем по умолчанию 0.
{
    string result = generateShift(level) + "public class " + m_name + " {\n"; // Создает строку с началом объявления класса и его имени.

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) // Проходит по всем модификаторам доступа.
    {
        if (m_fields[i].empty()) // Пропускает, если текущий вектор m_fields пуст.
        {
            continue;
        }
        for (const auto& f : m_fields[i]) // Проходит по всем полям текущего модификатора доступа.
        {
            result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level + 1); // Компилирует каждое поле и добавляет его в результирующую строку.
        }
        result += "\n"; // Добавляет новую строку в результирующую строку.
    }
    result += generateShift(level) + "}\n"; // Закрывает объявление класса.
    return result; // Возвращает результирующую строку.
}

//------------------------------------------------------------------------------------
const vector<string> JavaUnit::ACCESS_MODIFIERS = {"public","protected", "private","default" };
// Инициализация статического вектора строк для хранения модификаторов доступа для Java.

JavaUnit::JavaUnit(const string& name) : ClassUnit(name), m_name(name) // Конструктор класса JavaUnit, принимающий имя класса и вызывающий конструктор базового класса.
{
    m_fields.resize(ACCESS_MODIFIERS.size()); // Изменяет размер m_fields, чтобы он соответствовал количеству модификаторов доступа.
}

void JavaUnit::add(const shared_ptr<Unit>& unit, Flags flags) // Переопределение функции add для добавления объектов с флагами.
{
    int accessModifier = PRIVATE; // По умолчанию модификатор доступа PRIVATE.

    if (flags < ACCESS_MODIFIERS.size()) // Проверка, что флаг находится в пределах доступных модификаторов.
    {
        accessModifier = flags; // Устанавливает модификатор доступа в соответствии с флагом.
    }
    m_fields[accessModifier].push_back(unit); // Добавляет объект unit в соответствующий вектор m_fields.
}

string JavaUnit::compile(unsigned int level) const // Переопределение функции compile для компиляции объекта с уровнем по умолчанию 0.
{
    string result = generateShift(level) + "public class " + m_name + " {\n"; // Создает строку с началом объявления класса и его имени.

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) // Проходит по всем модификаторам доступа.
    {
        if (m_fields[i].empty()) // Пропускает, если текущий вектор m_fields пуст.
        {
            continue;
        }
        for (const auto& f : m_fields[i]) // Проходит по всем полям текущего модификатора доступа.
        {
            result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level + 1); // Компилирует каждое поле и добавляет его в результирующую строку.
        }
        result += "\n"; // Добавляет новую строку в результирующую строку.
    }
    result += generateShift(level) + "}\n"; // Закрывает объявление класса.
    return result; // Возвращает результирующую строку.
}
