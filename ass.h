#ifndef ASS_H
#define ASS_H

#include "Node.h"


template <typename T>
class Ass
    {
        Node<T>* top;
        Node<T>* ass;
        int tam;

    public:

        Ass();
        void push(const T& dato);
        bool isempty()const;
        T topete() const;
        T asses() const;
        void pop();
        int getsize()const;
        ~Ass();

    };

#include "ass.hpp"
#endif
