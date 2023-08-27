#include "my_dict.hpp"

namespace mydict
{
    /* Constructors + Destructor */

    Dictionary::Dictionary()
    {
        printf("Regular Constructor\n");
    }

    Dictionary::Dictionary(const Dictionary& other)
    {
        printf("Copy Constructor %p\n",&other);
    }

    Dictionary::Dictionary(Dictionary&& other)
    {
        printf("Move Constructor %p\n",&other);
    }

    Dictionary &Dictionary::operator=(const Dictionary &other)
    {
        printf("Copy Assignment %p\n",&other);
        return *this;
    }

    Dictionary &Dictionary::operator=(Dictionary &&other)
    {
        printf("Move Assignment call %p\n",&other);
        return *this;
    }

    Dictionary::~Dictionary()
    {
        printf("Destructor\n");
    }

    /* Contains method */

    bool Dictionary::contains_key(const string key)
    {
        printf("contains_key call %s\n",key.c_str());
        return true;
    }

    bool Dictionary::contains_value(const any value)
    {
        printf("contains_value call %p\n", &value);
        return true;
    }

    /* Operators */

    ostream &operator<<(ostream& out, Dictionary& dict)
    {
        out << "Cout not implemented " << &dict << std::endl;
        return out;
    }

    any& Dictionary::operator[](const string key)
    {
        return dict.at(key);
    }

    /* Iterator idioms */

    Dictionary::Iterator Dictionary::begin()
    {
        printf("iterator begin call");
        return Iterator();
    }

    Dictionary::Iterator Dictionary::end()
    {
        printf("iterator end call");
        return Iterator();
    }

    Dictionary::Iterator Dictionary::begin_keys()
    {
        printf("iterator begin_keys call");
        return Iterator();
    }

    Dictionary::Iterator Dictionary::end_keys()
    {
        printf("iterator end_keys call");
        return Iterator();
    }

    Dictionary::Iterator Dictionary::begin_values()
    {
        printf("iterator begin_values call");
        return Iterator();
    }

    Dictionary::Iterator Dictionary::end_values()
    {
        printf("iterator end_values call");
        return Iterator();
    }


    /* Iterator impl*/
    Dictionary::Iterator::Iterator()
    {
        printf("iterator constructor call");
    }

    Dictionary::Iterator &Dictionary::Iterator::operator++() // ++obj 
    {
        printf("iterator ++() call");
        return *this;
    }

    Dictionary::Iterator Dictionary::Iterator::operator++(int) // obj++
    {
        printf("iterator ++(int) call");
        return *this;
    }

    any* Dictionary::Iterator::operator->()
    {
        printf("iterator -> call");
        return nullptr;
    }

    any Dictionary::Iterator::operator*()
    {
        printf("iterator * call");
        return 1;
    }

    bool Dictionary::Iterator::operator==(const Iterator &other) const
    {
        printf("iterator == call %p\n",&other);
        return true;
    }

    bool Dictionary::Iterator::operator!=(const Iterator &other) const
    {
        printf("iterator != call %p\n",&other);
        return true;
    }
}