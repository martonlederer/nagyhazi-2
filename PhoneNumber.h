#ifndef NAGYHAZI_2_PHONENUMBER_H
#define NAGYHAZI_2_PHONENUMBER_H

#include "string.h"

class PhoneNumber {
    int country, num;
public:
    PhoneNumber(String raw);
    String c_str() const;
};

#endif //NAGYHAZI_2_PHONENUMBER_H
