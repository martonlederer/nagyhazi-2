//
// Created by Marton Lederer on 06/05/2024.
//
#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(const String& raw) {
    for (size_t i = 0; i < 46; i++) {
        size_t dialCodeLen = strlen(countries[i].dialCode);
        for (size_t j = 0; j < dialCodeLen; j++) {
            if (raw[j + 1] != countries[i].dialCode[j]) break;
            if (j == dialCodeLen - 1) {
                country = countries[i].dialCode;
                num = String(raw.c_str() + 1 + strlen(countries[i].dialCode));
                break;
            }
        }
    }

    if (country.len() == 0) num = raw;
}

String PhoneNumber::toString() const {
    String full = '+';
    full = full + country + " " + num;
    return full;
}

String PhoneNumber::getCountry() const {
    for (size_t i = 0; i < 46; i++) {
        Country c = countries[i];

        if (strcmp(c.dialCode, country.c_str()) == 0)
            return {c.name};
    }

    return { "" };
}
