#include <iostream>
unsigned int faStr1(const char* str)
{
    unsigned int result = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        bool noDigit = true;
        while ((str[i] != ' ') && (str[i] != '\0'))
        {
            if ((str[i] >= '0') && (str[i] <= '9'))
            {
                noDigit = false;
            }
            ++i;
        }
        if (noDigit)
        {
            ++result;
        }
    }
    return result;
}
unsigned int faStr2(const char* str)
{
    unsigned int result = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        bool flag = false;
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            flag = true;
            ++i;
            while ((str[i] != ' ') && (str[i] != '\0'))
            {
                if ((str[i] < 'a') || (str[i] > 'z'))
                {
                    flag = false;
                }
                ++i;
            }
        }
        if (flag)
        {
            ++result;
        }
    }
    return result;
}
unsigned int faStr3(const char* str)
{
    unsigned int result = 0;
    double sum = 0;
    double word = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        ++word;
        int count = 0;
        while ((str[i] != ' ') && (str[i] != '\0'))
        {
            ++count;
            ++i;
        }
        sum += count;
    }
    double r = sum / word;
    return std::round(r);
}
