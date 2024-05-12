//
// Created by Marton Lederer on 12/05/2024.
//

#include "Loader.h"

void Loader::addContact(Contact *c) {

}

void Loader::removeContact(size_t idx) {

}

void Loader::list() {
    for (List<Contact*>::iterator it = contacts.begin(); it != contacts.end(); ++it)
        std::cout << *it << std::endl;
}

void Loader::countryStats() {

}

void Loader::search(String q) {

}

void Loader::load() {

}

void Loader::save() {

}
