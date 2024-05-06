#ifndef NAGYHAZI_2_LIST_H
#define NAGYHAZI_2_LIST_H

#include <cstddef>

template<typename T>
class List {
    // belső struktúra láncolt lista elemhez
    struct ListItem {
        ListItem* next;
        T value;
    };

    // elemek és aktuális méret
    ListItem* elements;
    size_t count;
public:
    // konstruktorok
    List() : elements(nullptr), count(0) {}
    List(T array[], size_t len) : count(len) {
        for (size_t i = 0; i < len; i++)
            push(array[i]);
    }

    /**
     * Méret visszaadása
     */
    size_t size() const { return count; }

    /**
     * Új elem hozzáadása a listához
     */
    void push(T el);

    /**
     * Elem levétele a listáról index szerint
     */
    T remove(size_t idx);

    /**
     * Elem hozzáférése index szerint
     */
    T& operator[](size_t idx) const;

    // lista iterátor
    class iterator {
        ListItem* curr;
    public:
        iterator(ListItem* e);
        iterator& operator++();
        iterator operator++(int);
        T& operator*() const;
        T* operator->() const;
        bool operator==(iterator it) const;
        bool operator!=(iterator it) const;
    };

    // iterátor inicializáció funkciók
    iterator begin();
    iterator end();
};

#endif
