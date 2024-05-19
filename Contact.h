//
// Created by Marton Lederer on 18/05/2024.
//

#ifndef NAGYHAZI_2_CONTACT_H
#define NAGYHAZI_2_CONTACT_H

#include "String.h"
#include "PhoneNumber.h"
#include "Name.h"
#include <iostream>

class Contact {
    // név, cím, telefonszámok
    Name name;
    String address;
    PhoneNumber number, workNumber;
public:
    // konstruktorok
    Contact(
            String& name,
            String& phoneNumber,
            String& nickname,
            String& address,
            String& work
    ) : name(name, nickname), address(address), number(phoneNumber), workNumber(work) {}

    /**
     * Név visszaadása
     */
    Name getName() const { return name; }

    /**
     * Cím visszaadása
     */
    String getAddress() const { return address; }

    /**
     * Mobilszám visszaadása
     */
    PhoneNumber getNumber() const { return number; }

    /**
     * Munkahelyi szám visszaadása
     */
    PhoneNumber getWorkNumber() const { return workNumber; }

    ~Contact() {}
};

inline std::ostream& operator<<(std::ostream& os, const Contact& c) {
    return os << c.getName().getFullName() << '\n'
              << " - Privat: " << c.getNumber().toString() << '\n'
              << " - Munkahelyi: " << c.getWorkNumber().toString() << '\n'
              << " - Cim: " << c.getAddress() << std::endl;
}

#endif //NAGYHAZI_2_CONTACT_H
