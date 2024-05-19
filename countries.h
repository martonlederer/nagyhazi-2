//
// Created by Marton Lederer on 19/05/2024.
//

#ifndef NAGYHAZI_2_COUNTRIES_H
#define NAGYHAZI_2_COUNTRIES_H

#include "String.h"

struct Country {
    const char* dialCode;
    const char* name;
};

struct CountryStat {
    const char* name;
    size_t count;
};

extern Country countries[];

#endif //NAGYHAZI_2_COUNTRIES_H
