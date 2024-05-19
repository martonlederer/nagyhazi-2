#ifndef NAGYHAZI_2_LIST_H
#define NAGYHAZI_2_LIST_H

#include <cstddef>
#include <stdexcept>
#include "memtrace.h"

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
    List(T array[], size_t len) : count(0) {
        for (size_t i = 0; i < len; i++)
            push(array[i]);
    }

    ~List() {
        ListItem* list = elements;
        ListItem* curr = nullptr;

        while (list != nullptr) {
            curr = list;
            list = list->next;

            delete curr;
        }
    }

    /**
     * Méret visszaadása
     */
    size_t size() const { return count; }

    /**
     * Új elem hozzáadása a listához
     */
    void push(T el) {
        ListItem* newItem = new ListItem{
            nullptr,
            el
        };
        count++;

        if (elements == nullptr) {
            elements = newItem;
            return;
        }
        ListItem* curr = elements;

        while (curr->next != nullptr)
            curr = curr->next;
        curr->next = newItem;
    }

    /**
     * Elem levétele a listáról index szerint
     */
    T remove(size_t idx) {
        if (idx >= count) {
            throw std::out_of_range ("Túl nagy index");
        }

        if (idx == 0) {
            ListItem* next = elements->next;
            T val = elements->value;

            delete elements;
            elements = next;
            count--;

            return val;
        }

        size_t i = 1;
        ListItem* curr = elements->next;
        ListItem* prev = elements;

        while (curr != nullptr && i < idx) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        if (curr == nullptr) {
            throw std::out_of_range ("Túl nagy index");
        }

        T val = curr->value;
        prev->next = curr->next;
        delete curr;
        count--;

        return val;
    }

    /**
     * Elem hozzáférése index szerint
     */
    T& operator[](size_t idx) const {
        if (idx >= count) {
            throw std::out_of_range ("Túl nagy index");
        }

        size_t i = 0;
        ListItem* curr = elements;

        while (curr != nullptr) {
            if (i == idx) break;
            curr = curr->next;
            i++;
        }

        if (curr == nullptr) {
            throw std::out_of_range ("Túl nagy index");
        }

        return curr->value;
    }

    // lista iterátor
    class iterator {
        ListItem* curr;
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::forward_iterator_tag;

        // Implement the rest of the iterator methods
        explicit iterator(ListItem* e = nullptr) : curr(e) {}

        iterator& operator++() {
            if (curr != nullptr)
                curr = curr->next;
            return *this;
        }

        iterator operator++(int) {
            List<T>::iterator it = *this;
            operator++();
            return it;
        }

        T& operator*() const { return curr->value; }
        T* operator->() const { return &(curr->value); }
        bool operator==(iterator it) const { return curr == it.curr; }
        bool operator!=(iterator it) const { return !operator==(it); }
    };

    // iterátor inicializáció funkciók
    iterator begin() { return List<T>::iterator(elements); }
    iterator end() { return List<T>::iterator(nullptr); }

    /**
     * Egy másik lista hozzáfűzése ehhez a listához
     */
    void concat(List<T>& list) {
        for (List<T>::iterator it = list.begin(); it != list.end(); ++it)
            push(*it);
    }

    template<typename P>
    void sort(P pred) {
        if (count <= 1) return;

        ListItem* sorted = nullptr;
        ListItem* curr = elements;

        while (curr != nullptr) {
            ListItem* prevNext = curr->next;
            ListItem* prev = nullptr;
            ListItem* next = sorted;

            while (next != nullptr && pred(next->value, curr->value)) {
                prev = next;
                next = next->next;
            }

            if (prev == nullptr) {
                curr->next = sorted;
                sorted = curr;
            } else {
                prev->next = curr;
                curr->next = next;
            }

            curr = prevNext;
        }
    }
};

#endif
