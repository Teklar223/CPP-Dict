

namespace mydict
{
    class dictionary
    {
        public:
            dictionary();
            dictionary(const dictionary & other);
            dictionary(dictionary && other);

            ~dictionary();

    };
}