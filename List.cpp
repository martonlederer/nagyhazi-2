//
// Created by Marton Lederer on 06/05/2024.
//

#include <stdexcept>
#include "List.hpp"

template<typename T>
void List<T>::push(T el) {
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

template<typename T>
T List<T>::remove(size_t idx) {
    if (idx >= count) {
        throw std::out_of_range ("Túl nagy index");
    }

    if (idx == 0) {
        ListItem* next = elements->next;
        T val = elements->value;

        delete elements;
        elements = next;

        return val;
    }

    size_t i = 0;
    ListItem* curr = elements->next;
    ListItem* prev = elements;

    while (curr != nullptr && i <= idx) {
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

    return val;
}

template<typename T>
T& List<T>::operator[](size_t idx) const {
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

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator++() {
    if (curr != nullptr)
        curr = curr->next;
    return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int) {
    List<T>::iterator it = *this;
    operator++();
    return it;
}

template<typename T>
T& List<T>::iterator::operator*() const {
    return curr->value;
}

template<typename T>
T* List<T>::iterator::operator->() const {
    return &(curr->value);
}

template<typename T>
bool List<T>::iterator::operator==(List<T>::iterator it) const {
    return curr == it.curr;
}

template<typename T>
bool List<T>::iterator::operator!=(List<T>::iterator it) const {
    return !operator==(it);
}

template<typename T>
typename List<T>::iterator List<T>::begin() {
    return List<T>::iterator(elements);
}

template<typename T>
typename List<T>::iterator List<T>::end() {
    return List<T>::iterator(nullptr);
}
