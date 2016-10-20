#include "passwordgenerator.h"

std::string PasswordGenerator::getLogin() const
{
    return this->m_login;
}

std::string PasswordGenerator::getPassword() const
{
    return this->m_password;
}

int PasswordGenerator::getLoginLength() const
{
    return this->m_loginLength;
}

int PasswordGenerator::getPasswordLength() const
{
    return this->m_passwordLength;
}

std::string PasswordGenerator::generatePassword()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    srand((time_t)ts.tv_nsec);

    int loginLength = getLoginLength();
    int passwordLength = getPasswordLength();

    std::string tempPassword = createPassword(loginLength, passwordLength);

    this->m_password = tempPassword;

    return tempPassword;
}

std::string PasswordGenerator::createPassword(const int &inputLoginLength, const int &inputPasswordLength)
{
    std::string tempPassword = "";

    int lowerCase = ((inputLoginLength * inputLoginLength * inputLoginLength) % 5) + 1;

    for(int i = 0; i < lowerCase; i++)
    {
        bool isRight = (rand() % 1 + 0) == 1 ? true : false;

        int characterValue;

        if(!isRight)
            characterValue = getRandInt(MIN_LSYMBOL_LEFT, MAX_LSYMBOL_LEFT);
        else
            characterValue = getRandInt(MIN_LSYMBOL_RIGHT, MAX_LSYMBOL_RIGHT);

        std::string characterBuffer(1, characterValue);
        tempPassword += characterBuffer;
    }

    int upperBound = (lowerCase + ((inputLoginLength * inputLoginLength) % 6)) + 1;

    if((lowerCase + 1) < inputPasswordLength)
    {
        for(int i = lowerCase; i < upperBound; i++)
        {
            int characterValue = getRandInt(MIN_HSYMBOL, MAX_HSYMBOL);

            std::string characterBuffer(1, characterValue);
            tempPassword += characterBuffer;
        }
    }

    if((upperBound + 1) < inputPasswordLength)
    {
        for(int i = upperBound; i < inputPasswordLength; i++)
        {
            int characterValue = getRandInt(MIN_NSYMBOL, MAX_NSYMBOL);

            std::string characterBuffer(1, characterValue);
            tempPassword += characterBuffer;
        }
    }

    return tempPassword;
}

int PasswordGenerator::getRandInt(const int &inputIntervalMin, const int &inputIntervalMax)
{
    int randValue = inputIntervalMin + rand() % (inputIntervalMax - inputIntervalMin);

    return randValue;
}
