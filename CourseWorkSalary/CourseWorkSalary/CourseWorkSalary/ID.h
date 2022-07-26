#pragma once

/* Шаблон класса ID
*
* создан для того, чтобы была возможность создавать
* как чисто числовой идентификационный номер(для администраторов),
* так и буквенно-числовой (для сотрудников)
*/

template <typename T>
class ID
{
private:
    T id; //идентификационный номер
public:
    //конструктор по умолчанию
    ID() {}
    //конструктор с параметром
    ID(T id) : id(id) {}
    //конструктор копирования
    ID(const ID& I) : id(I.id) {}

    T getId() const
    {
        return id;
    }

    //перегрузка оператора присваивания
    ID& operator=(const ID& I)
    {
        if (this != &I) //проверка на самоприсваивание
        {
            id = I.id;
        }
        return *this;
    }
    //перегрузка оператора сравнения
    friend bool operator== (const ID& i1, const ID& i2)
    {
        return (i1.getId() == i2.getId());
    }
    //перегрузка оператора меньше
    bool operator< (const ID& I2)
    {
        return (getId() < I2.getId());
    }
    //перегрузка оператора вывода
    friend ostream& operator<< (ostream& os, const ID& I)
    {
        return os << I.getId();
    }
};