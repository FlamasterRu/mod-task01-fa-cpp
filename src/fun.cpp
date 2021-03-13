unsigned int round(double n)
{
    double b = n * 10;
    int a = b;
    a %= 10;
    if (a < 5)
    {
        return static_cast<unsigned int>(n);
    }
    else
    {
        return static_cast<unsigned int>(n) + 1;
    }
}

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
    int i = 0, count = 0;
    double word = 0, sum = 0;
    char state = 'a';
    while (str[i] != '\0')
    {
        if ((state == 'a') && (str[i] != ' '))
        {
            count = 1;
            state = 'b';
            ++word;
        }
        else if ((state == 'b') && (str[i] != ' '))
        {
            ++count;
        }
        else if ((state == 'b') && (str[i] == ' '))
        {
            sum += count;
            state = 'a';
            count = -1;
        }
        ++i;
    }
    if (count != -1)
    {
        sum += count;
    }
    return round(sum/word);
}
