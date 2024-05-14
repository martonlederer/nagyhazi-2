//
// Created by Marton Lederer on 03/05/2024.
//

#ifndef NAGYHAZI_2_LOADER_H
#define NAGYHAZI_2_LOADER_H

#include "List.hpp"
#include "String.h"
#include "Contact.h"
#include <iostream>
#include <cstring>

class Loader {
    // névjegyek
    List<Contact*> contacts;
public:
    /**
     * Új névjegy felvétele
     */
    void addContact(Contact* c);
    /**
     * Névjegy eltávolítása
     */
    void removeContact(size_t idx);
    /**
     * Névjegyek listázása
     */
    void list();
    /*
     * Statisztika: melyik országhoz hány telefonszám tartozik
     */
    void countryStats();
    /**
     * Névjegy keresése szöveg alapján
     */
    void search(const String& q);
    /**
     * Névjegyek betöltése
     */
    void load();
    /**
     * Névjegyek mentése
     */
    void save();
    /**
     * Névjegyek visszaadása
     */
    List<Contact*> getContacts() const { return contacts; }
};

#endif //NAGYHAZI_2_LOADER_H
