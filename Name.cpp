//
// Created by Marton Lederer on 06/05/2024.
//

#include "Name.h"
#include <cstring>

Name::Name(const String& full) {
    char* tempFull = new char[full.len() + 1];
    strcpy(tempFull, full.c_str());
    strtok(tempFull, " ");
    last = String(tempFull);
    first = String(full.c_str() + strlen(tempFull) + 1);
}

String Name::getFullName() const {
    String temp = last;
    temp = temp + " " + first;

    if (nickname != "") {
        temp = temp + " (" + nickname + ")";
    }

    return temp;
}
