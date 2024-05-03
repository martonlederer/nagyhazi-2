#ifndef NAGYHAZI_2_CONTACT_H
#define NAGYHAZI_2_CONTACT_H

#include "String.h"
#include "PhoneNumber.h"
#include "Name.h"

class Contact {
    // név, cím, telefonszámok
    Name name;
    String address;
    PhoneNumber number, workNumber;
public:
    // konstruktorok
    Contact(String name, PhoneNumber phoneNumber);
    Contact(String name, PhoneNumber phoneNumber, String nickname, String address, PhoneNumber work);

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
};

#endif //NAGYHAZI_2_CONTACT_H
