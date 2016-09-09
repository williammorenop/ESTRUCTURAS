
#include <iostream>

using namespace std;


template <typename T>
class List
    {
        Node<T>* top;
        Node<T>* ass;
        int tam;

    public:

        List();
        void pushf(const T& dato);
        void push(const T& dato,int i);
        void pushlast(const T& dato);
        bool isempty()const;
    T top() const;
        T dat(int i) const;
        T ass() const;
    void popf();
        void pop(int i);
        void popl();
        int getsize()const;
        ~List();

    };
