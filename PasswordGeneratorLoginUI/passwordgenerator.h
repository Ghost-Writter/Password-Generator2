#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#define MIN_LENGTH_PASSWORD 6

#define MIN_HSYMBOL 128         //Первый заглавный символ
#define MAX_HSYMBOL 159         //Последний заглавный символ
#define MIN_NSYMBOL 48          //Первый символ-число
#define MAX_NSYMBOL 57          //Последний символ-число
#define MIN_LSYMBOL_LEFT 160    //Первый строчной символ
#define MAX_LSYMBOL_LEFT 175    //Последний строчной символ
#define MIN_LSYMBOL_RIGHT 224   //Первый строчной символ
#define MAX_LSYMBOL_RIGHT 239   //Последний строчной символ

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

class PasswordGenerator
{
public:

    PasswordGenerator(
            std::string inputLogin,
            int inputLoginLength,
            int inputPasswordLength)

        : m_login(inputLogin),
          m_password(""),
          m_loginLength(inputLoginLength),
          m_passwordLength(inputPasswordLength >= MIN_LENGTH_PASSWORD ? inputPasswordLength : MIN_LENGTH_PASSWORD)
    {}

    std::string getLogin() const;
    std::string getPassword() const;
    int getLoginLength() const;
    int getPasswordLength() const;

    std::string generatePassword();

private:

    const std::string m_login;          //входной логин
    std::string m_password;             //сгенерированный пароль
    int m_loginLength;                  //длина логина
    int m_passwordLength;               //длина пароля

    std::string createPassword(const int &inputLoginLength, const int &inputPasswordLength);
    int getRandInt(const int &inputIntervalMin, const int &inputIntervalMax);

};

#endif // PASSWORDGENERATOR_H
