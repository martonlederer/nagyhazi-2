//
// Created by Marton Lederer on 03/05/2024.
//

#ifndef NAGYHAZI_2_LOADER_H
#define NAGYHAZI_2_LOADER_H

#include "List.hpp"
#include "String.h"
#include "Contact.h"

class Loader {
    List<Contact*> contacts;
public:
    void addContact(Contact c);
    void removeContact(size_t idx);
    void list();
    void countryStats();
    void search(String q);
    void load();
    void save();
};

#endif //NAGYHAZI_2_LOADER_H
