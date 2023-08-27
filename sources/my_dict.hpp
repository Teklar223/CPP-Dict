#include <vector>
#include <string>
#include <map>
#include <any>
#include <iterator>
#include <stdexcept>
#include <ostream>

using std::iterator;
using std::vector;
using std::string;
using std::map;
using std::any;
using std::ostream;

namespace mydict
{
    /**
     * @brief A small dictionary implementation. *
     * sources:
     * 1. https://stackoverflow.com/questions/327311/how-are-pythons-built-in-dictionaries-implemented
     */
    class Dictionary
    {
        public:
            class Iterator;
        public:
            Dictionary();
            Dictionary(const Dictionary& other);
            Dictionary(Dictionary&& other);
            Dictionary& operator=(const Dictionary& other);
            Dictionary& operator=(Dictionary&& other);
            ~Dictionary();

            Iterator begin();
            Iterator end();
            Iterator begin_keys();
            Iterator end_keys();
            Iterator begin_values();
            Iterator end_values();

            any& operator[](const string key);
            bool contains_key(const string key);
            bool contains_value(const any val);

            friend ostream &operator<<(ostream &out, Dictionary &dict);

        private:
            map<string, any> dict; // stage 2: implement this part myself

        public:
            class Iterator
            {
                Iterator(const Dictionary& dict);

                Iterator &operator++();

                Iterator operator++(int);

                any *operator->();

                any operator*();

                bool operator==(const Iterator &other) const;

                bool operator!=(const Iterator &other) const;
            };

    };
}