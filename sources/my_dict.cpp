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
        printf("Copy Constructor\n");
    }

    Dictionary::Dictionary(Dictionary&& other)
    {
        printf("Move Constructor\n");
    }

    Dictionary &Dictionary::operator=(const Dictionary &other)
    {
        printf("Copy Assignment\n");
    }

    Dictionary &Dictionary::operator=(Dictionary &&other)
    {
        printf("Move Assignment\n");
    }

    Dictionary::~Dictionary()
    {
        printf("Destructor\n");
    }

    /* Contains method */

    bool Dictionary::contains_key(const string key)
    {
        printf("contains_key call\n");
    }

    bool Dictionary::contains_value(const any vaL)
    {
        printf("contains_value call\n");
    }

    /* Operators */

    ostream &operator<<(ostream& out, Dictionary& dict)
    {
        out << "Cout not implemented" << std::endl;
    }

    any& Dictionary::operator[](const string key)
    {
        return dict.at(key);
    }

    /* Iterator idioms */

    Dictionary::Iterator Dictionary::begin()
    {
        printf("iterator begin call");
    }

    Dictionary::Iterator Dictionary::end()
    {
        printf("iterator end call");
    }

    Dictionary::Iterator Dictionary::begin_keys()
    {
        printf("iterator begin_keys call");
    }

    Dictionary::Iterator Dictionary::end_keys()
    {
        printf("iterator end_keys call");
    }

    Dictionary::Iterator Dictionary::begin_values()
    {
        printf("iterator begin_values call");
    }

    Dictionary::Iterator Dictionary::end_values()
    {
        printf("iterator end_values call");
    }


    /* Iterator impl*/
    Dictionary::Iterator::Iterator(const Dictionary& dict)
    {
        printf("iterator constructor call");
    }

    Dictionary::Iterator &Dictionary::Iterator::operator++() // ++obj 
    {
        printf("iterator ++() call");
    }

    Dictionary::Iterator Dictionary::Iterator::operator++(int) // obj++
    {
        printf("iterator ++(int) call");
    }

    any* Dictionary::Iterator::operator->()
    {
        printf("iterator -> call");
    }

    any Dictionary::Iterator::operator*()
    {
        printf("iterator * call");
    }

    bool Dictionary::Iterator::operator==(const Iterator &other) const
    {
        printf("iterator == call");
    }

    bool Dictionary::Iterator::operator!=(const Iterator &other) const
    {
        printf("iterator != call");
    }
}