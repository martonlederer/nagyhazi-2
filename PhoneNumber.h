#ifndef NAGYHAZI_2_PHONENUMBER_H
#define NAGYHAZI_2_PHONENUMBER_H

#include "String.h"

class PhoneNumber {
    // telefonszám és országkód külön
    int country, num;
public:
    // telefonszám feldolgozása string-ből
    PhoneNumber(String raw);

    /**
     * Telefonszám összeillesztése string-be
     */
    String c_str() const;

    /**
     * Ország nevének visszaadása
     */
    String getCountry() const;

    /**
     * Országkód visszaadása
     */
    int getCountryCode() const;
};

#endif //NAGYHAZI_2_PHONENUMBER_H
