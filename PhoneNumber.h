#ifndef NAGYHAZI_2_PHONENUMBER_H
#define NAGYHAZI_2_PHONENUMBER_H

#include "String.h"
#include <cstring>

struct Country {
    const char* dialCode;
    const char* name;
};

class PhoneNumber {
    // telefonszám és országkód külön
    String country, num;
public:
    // telefonszám feldolgozása string-ből
    explicit PhoneNumber(const String& raw);

    /**
     * Telefonszám összeillesztése string-be
     */
    String toString() const;

    /**
     * Ország nevének visszaadása
     */
    String getCountry() const;

    /**
     * Országkód visszaadása
     */
    String getCountryCode() const { return country; }
};

#endif //NAGYHAZI_2_PHONENUMBER_H
