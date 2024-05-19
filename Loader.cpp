//
// Created by Marton Lederer on 12/05/2024.
//

#include "Loader.h"
#include <fstream>

void Loader::addContact(Contact *c) { contacts.push(c); }

void Loader::removeContact(size_t idx) {
    Contact* c = contacts.remove(idx);
    delete c;
}

void Loader::list() {
    unsigned int count = 1;

    for (List<Contact*>::iterator it = contacts.begin(); it != contacts.end(); ++it, ++count)
        std::cout << "[" << count << "] " << **it << std::endl;
}

void Loader::countryStats() {
    List<CountryStat*> stats;

    /*for (List<Contact*>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        auto existingCountry = std::find_if(stats.begin(), stats.end(), )
    }*/
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
    std::ifstream is;
    is.open("contacts.txt");

    if (!is) return;
    String param;
    char c;
    size_t fill_id = 0;
    String params[5];

    while (is.get(c) && !is.eof()) {
        switch (c) {
            case '\t':
                params[fill_id] = param;

                if (fill_id < 4) {
                    param = "";
                    fill_id++;
                }
                break;
            case '\n':
                params[fill_id] = param;
                if (fill_id > 3) {
                    Contact* contact = new Contact(
                            params[0],
                            params[1],
                            params[2],
                            params[3],
                            params[4]
                    );
                    addContact(contact);
                }
                param = "";
                fill_id = 0;
                break;
            default:
                String cc = String(c);
                param = param + cc;
        }
    }

    is.close();
}

void Loader::save() {
    std::ofstream os("contacts.txt");

    for (List<Contact*>::iterator it = contacts.begin(); it != contacts.end(); ++it) {
        Contact c = **it;

        os << c.getName().first << ' '
           << c.getName().last << '\t'
           << c.getNumber().toString() << '\t'
           << c.getName().nickname << '\t'
           << c.getAddress() << '\t'
           << c.getWorkNumber().toString() << std::endl;
    }

    os.close();
}
