#include "iostream"
#include "jb_bool.hpp"

static int isNeg(const char *str)
{
    int nb = 1;

    if (!str) {
        return 0;
    }

    for (size_t i = 0; str[i] && !charIsNum(str[i]); i++) {
        if (str[i] == '-')
            nb *= -1;
    }
    return nb;
}

static size_t getStartIndexAfterSign(const char *str)
{
    size_t i = 0;

    if (!str) {
        return 0;
    }

    for (; str[i] && !charIsNum(str[i]); i++);
    return i;
}

extern int getNumber(const char *str)
{
    size_t idx = getStartIndexAfterSign(str);
    int neg = isNeg(str);
    int nb = 0;

    if (!str) {
        std::cerr << "str is NULL" << "\n";
        return 0;
    }
    for (size_t i = idx; str[i]; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }

    return nb * neg;
}
