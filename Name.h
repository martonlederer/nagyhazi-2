#ifndef NAGYHAZI_2_NAME_H
#define NAGYHAZI_2_NAME_H

#include "string.h"

class Name {
public:
    String first, last, nickname;

    Name(String first, String last);
    Name(String first, String last, String nickname);
    String getFullName() const;
};

#endif //NAGYHAZI_2_NAME_H
