#ifndef NAGYHAZI_2_LIST_H
#define NAGYHAZI_2_LIST_H

#include <cstddef>

template<typename T>
class List {
    struct ListItem {
        ListItem* next;
        T value;
    };

    ListItem* elements;
    size_t count;
public:
    List();
    List(T array[], size_t len);
    size_t size() const;
    void push(T el);
    T remove(size_t idx);

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

    iterator begin();
    iterator end();
};

#endif
