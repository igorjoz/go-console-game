#include "Helper.h"


int Helper::convertDigitsArrayIntoNumber(char digits[], int length) {
    int number = 0;

    for (int i = 0; i < length; i++)
    {
        int digit = digits[i] - '0';

        number = number * 10 + digit;
    }

    return number;
}