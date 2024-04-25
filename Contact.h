#ifndef NAGYHAZI_2_CONTACT_H
#define NAGYHAZI_2_CONTACT_H

#include "string.h"
#include "PhoneNumber.h"
#include "Name.h"

class Contact {
    Name name;
    String address;
    PhoneNumber number, workNumber;
public:
    Contact(String name, PhoneNumber phoneNumber);
    Contact(String name, PhoneNumber phoneNumber, String nickname, String address, PhoneNumber work);

    Name getName() const { return name; }
    String getAddress() const { return address; }
    PhoneNumber getNumber() const { return number; };
    PhoneNumber getWorkNumber() const { return workNumber; }
};

#endif //NAGYHAZI_2_CONTACT_H
