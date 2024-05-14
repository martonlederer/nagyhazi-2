//
// Created by Marton Lederer on 12/05/2024.
//

#include "Loader.h"

void Loader::addContact(Contact *c) { contacts.push(c); }

void Loader::removeContact(size_t idx) { contacts.remove(idx); }

void Loader::list() {
    for (List<Contact*>::iterator it = contacts.begin(); it != contacts.end(); ++it)
        std::cout << *it << std::endl;
}

void Loader::countryStats() {

}

void Loader::search(const String& q) {
    List<Contact*> firstNameRes;
    List<Contact*> lastNameRes;
    List<Contact*> nickNameRes;

    const char* query = q.c_str();

    for (List<Contact*>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        Contact* c = *it;

        if (strstr(c->getName().nickname.c_str(), query) != nullptr) nickNameRes.push(c);
        else if (strstr(c->getName().first.c_str(), query) != nullptr) firstNameRes.push(c);
        else if (strstr(c->getName().last.c_str(), query) != nullptr) lastNameRes.push(c);
    }

    firstNameRes.concat(lastNameRes);
    firstNameRes.concat(nickNameRes);

    std::cout << "Kereses eredmenye:" << std::endl;

    for (List<Contact*>::iterator it = firstNameRes.begin(); it != firstNameRes.end(); ++it)
        std::cout << *it << std::endl;
}

void Loader::load() {

}

void Loader::save() {

}
