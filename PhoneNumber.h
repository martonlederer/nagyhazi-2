#ifndef NAGYHAZI_2_PHONENUMBER_H
#define NAGYHAZI_2_PHONENUMBER_H

#include "String.h"

class PhoneNumber {
    int country, num;
public:
    PhoneNumber(String raw);
    String c_str() const;
    int getCountry() const;
    int getCountryCode() const;
};

#endif //NAGYHAZI_2_PHONENUMBER_H
