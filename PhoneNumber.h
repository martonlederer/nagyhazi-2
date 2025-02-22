#ifndef NAGYHAZI_2_PHONENUMBER_H
#define NAGYHAZI_2_PHONENUMBER_H

#include "String.h"
#include <cstring>
#include "countries.h"

class PhoneNumber {
    // telefonszám és országkód külön
    String country, num;
public:
    // telefonszám feldolgozása string-ből
    explicit PhoneNumber(const String& raw);

    /**
     * Nem formázott szám
     */
    String raw() const { return String("+") + country + num; }

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
