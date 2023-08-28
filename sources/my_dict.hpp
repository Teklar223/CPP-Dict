#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <stdexcept>
#include <ostream>
#include <fstream>

using std::iterator;
using std::vector;
using std::string;
using std::map;
using std::ostream;
using std::fstream;

namespace mydict
{
    /**
     * @brief A small dictionary implementation. *
     * sources:
     * 1. https://stackoverflow.com/questions/327311/how-are-pythons-built-in-dictionaries-implemented
     */

    class Entry { };

    
    class DictEntry : Entry{
        /**
         * @brief Helper class to manage Dictionary Entries and their assignments, etc..
         * 
         */
        public:
            DictEntry& operator=(string a)
            {
                printf("DictEnt assign value %p\n",&a);
                return *this;
            }

            DictEntry& operator=(const DictEntry& a)
            {
                printf("DictEnt assign DictEnt %p\n",&a);
                return *this;
            }

        private:
            string hash;
            //some way to store the type (maybe any???)
            string value;
    };

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

            Dictionary& operator=(string);
            DictEntry& operator[](const string key) const;
            bool contains_key(const string key);
            bool contains_value(const string val);

            friend ostream &operator<<(ostream &out, Dictionary &dict);
            friend fstream &operator<<(fstream &out, Dictionary &dict);
            friend string &operator<<(string &out, Dictionary &dict);

        private:
            map<string, string> dict; // stage 2: implement this part myself (trie sounds good)

        public:
            class Iterator
            {
                public:
                    Iterator();

                    Iterator &operator++();

                    Iterator operator++(int);

                    string *operator->();

                    string operator*();

                    bool operator==(const Iterator &other) const;

                    bool operator!=(const Iterator &other) const;
            };

    };
}