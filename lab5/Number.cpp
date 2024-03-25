#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>

int schimb(char* sir)
{
    int a = strlen(sir);
    int num = 0;
    for (int i = 0; i <a; i++)
        num = num*10 + (sir[i] - '0');
    return num;

}
Number::Number(const char* value, int base)
{
    if (base >= 2 && base <= 16)
    {
        this->base = base;
        this->digitCount = strlen(value);
        this->value = new char[this->digitCount + 1];
        strcpy(this->value, value);
        this->value[this->digitCount] = '\0';
    }
    else return;
}
Number::Number(const Number& obj)
{
    this->value = new char[obj.digitCount + 1];
    strcpy(this->value, obj.value);
    this->base = obj.base;
    this->digitCount = obj.digitCount;
    this->value[this->digitCount] = '\0';
}
Number::Number(const int value)
{
    this->base = 10;
    int num = value;
    int n = 0;
    int tmp = value;
    while (tmp)
    {
        n++;
        tmp /= 10;
    }
    this->digitCount = n;
    this->value = new char[n + 1];
    for (int i = n - 1; i >= 0; i--)
    {
        this->value[i] = num % 10 + '0';
        num /= 10;
    }
    this->value[n] = '\0';

}
Number::Number(Number&& obj) noexcept
{

    this->value = obj.value;
    this->digitCount = obj.digitCount;
    this->base = obj.base;

    obj.value = nullptr;
    obj.base = 0;
    obj.digitCount = 0;
}

Number::~Number()
{
    delete[] this->value;
}
Number& Number::operator= (int nr)
{
    int num = nr;
    int n = 0;
    while (num)
    {
        num /= this->base;
        n++;
    }
    char* aux = new char[n + 1];
    int i = n - 1;
    while (nr > 0)
    {
        int digit = nr % this->base;
        if (digit > 9 && digit < 16)
            aux[i--] = 'A' + digit - 10;
        else aux[i--] = digit + '0';
        nr /= this->base;
    }
    this->digitCount = n;
    delete[] this->value;
    this->value = aux;
    this->value[n] = '\0';
    return (*this);

}
Number& Number::operator =(Number&& obj) noexcept
{
    if (this != &obj) {

        delete[] this->value;

        this->value = obj.value;
        this->digitCount = obj.digitCount;
        this->base = obj.base;

        obj.value = nullptr;
        obj.base = 0;
        obj.digitCount = 0;
    }
    return (*this);

}
Number& Number::operator = (const char* sir)
{
    int i = 0, n = 0;
    while (sir[i])
    {
        n++;
        i++;
    }
    char* aux = new char[n + 1];
    strcpy(aux, sir);
    aux[n] = '\0';
    Number number(aux, 10);
    number.SwitchBase(this->base);
    delete[] this->value;
    this->value = new char[n + 1];
    this->digitCount = number.digitCount;
    strcpy(this->value, number.value);
    this->value[n] = '\0';
    return (*this);
}
Number& Number::operator += (const Number& obj)
{
    Number tmp1 = *this, tmp2 = obj;
    int b = 0;
    if (tmp1.base > tmp2.base) b = tmp1.base;
    else b = tmp2.base;
    if (tmp1.base != 10) tmp1.SwitchBase(10);
    if (tmp2.base != 10) tmp2.SwitchBase(10);
    int num1 = schimb(tmp1.value), num2 = schimb(tmp2.value);
    num1 = num1 + num2;
    Number number = num1;

    delete[] this->value;

    if (number.base != b) number.SwitchBase(b);
    this->value = new char[number.digitCount + 1];
    strcpy(this->value, number.value);
    this->value[number.digitCount] = '\0';
    this->digitCount = number.digitCount;
    this->base = number.base;

    return (*this);
}

Number& Number::operator --(int value)
{
    this->value[this->digitCount - 1] = '\0';
    this->digitCount--;
    return (*this);

}
Number& Number::operator -- ()
{
    do
    {
        for (int i = 0; i < this->digitCount; i++)
            this->value[i] = this->value[i + 1];
        this->digitCount--;
        this->value[this->digitCount] = '\0';
    } while (this->value[0] == '0');
    return (*this);
}
Number operator + (Number n1, Number n2)
{
    int b;
    if (n1.GetBase() > n2.GetBase())
        b = n1.GetBase();
    else b = n2.GetBase();
    if (n1.GetBase() != 10) n1.SwitchBase(10);
    if (n2.GetBase() != 10) n2.SwitchBase(10);
    int num1 = schimb(n1.GetNumber()), num2 = schimb(n2.GetNumber());
    num1 = num1 + num2;
    Number number = num1;
    if (number.GetBase() != b) number.SwitchBase(b);
    return number;
}
Number operator - (Number n1, Number n2)
{
    int b;
    if (n1.GetBase() > n2.GetBase())
        b = n1.GetBase();
    else b = n2.GetBase();
    if (n1.GetBase() != 10) n1.SwitchBase(10);
    if (n2.GetBase() != 10) n2.SwitchBase(10);
    int num1 = schimb(n1.GetNumber()), num2 = schimb(n2.GetNumber());
    num1 = num1 - num2;
    Number number = num1;
    if (number.GetBase() != b) number.SwitchBase(b);
    return number;
}
bool Number::operator <= (Number obj)
{
    Number tmp = *this;
    if (tmp.base != 10) tmp.SwitchBase(10);
    if (obj.base != 10) obj.SwitchBase(10);
    int num1 = schimb(tmp.value), num2 = schimb(obj.value);
    if (num1 <= num2) return true;
    return false;
}
bool Number::operator >= (Number obj)
{
    Number tmp = *this;
    if (tmp.base != 10) tmp.SwitchBase(10);
    if (obj.base != 10) obj.SwitchBase(10);
    int num1 = schimb(tmp.value), num2 = schimb(obj.value);
    if (num1 >= num2) return true;
    return false;
}
bool Number::operator == (Number obj)
{
    Number tmp = *this;
    if (tmp.base != 10) tmp.SwitchBase(10);
    if (obj.base != 10) obj.SwitchBase(10);
    int num1 = schimb(tmp.value), num2 = schimb(obj.value);
    if (num1 == num2) return true;
    return false;
}
bool Number::operator != (Number obj)
{
    Number tmp = *this;
    if (tmp.base != 10) tmp.SwitchBase(10);
    if (obj.base != 10) obj.SwitchBase(10);
    int num1 = schimb(tmp.value), num2 = schimb(obj.value);
    if (num1 != num2) return true;
    return false;
}
void Number::SwitchBase(int newBase)
{
    if (this->base == newBase) return;
    else
    {
        if (this->base != 10)
        {
            int num = 0, p = 1;
            for (int i = this->digitCount - 1; i >= 0; i--)
            {
                if (this->value[i] >= 'A' && this->value[i] <= 'F')
                    num = num + (this->value[i] - 'A' + 10) * p;
                else num = num + (this->value[i] - '0') * p;
                p *= this->base;
            }
            int tmp = num, len = 0;
            while (tmp)
            {
                len++;
                tmp /= 10;
            }
            this->digitCount = len;
            char* aux = new char[len + 1];
            for (int i = len - 1; i >= 0; i--)
            {
                aux[i] = num % 10 + '0';
                num /= 10;
            }
            delete[] this->value;
            this->value = aux;
            this->value[len] = '\0';
            this->base = 10;
        }
        if (newBase != 10)
        {
            int num = schimb(this->value);
            int tmp = num;
            int n = 0;
            while (tmp)
            {
                tmp /= newBase;
                n++;
            }
            char* aux = new char[n + 1];
            int i = n - 1;
            while (num > 0)
            {
                int digit = num % newBase;
                if (digit > 9 && digit < 16)
                    aux[i--] = 'A' + digit - 10;
                else aux[i--] = digit + '0';
                num /= newBase;
            }
            this->digitCount = n;
            delete[] this->value;
            this->value = aux;
            this->value[n] = '\0';
        }
    }
    this->base = newBase;
}
int Number::operator [](int value)
{
    return this->value[value];
}
bool Number::operator >(Number obj)
{
    Number tmp = *this;
    if (tmp.base != 10) tmp.SwitchBase(10);
    if (obj.base != 10) obj.SwitchBase(10);
    int num1 = schimb(tmp.value), num2 = schimb(obj.value);
    if (num1 > num2) return true;
    return false;

}
bool Number::operator< (Number obj)
{
    Number tmp = *this;
    if (tmp.base != 10) tmp.SwitchBase(10);
    if (obj.base != 10) obj.SwitchBase(10);
    int num1 = schimb(tmp.value), num2 = schimb(obj.value);
    if (num1 < num2) return true;
    return false;
}
void Number::Print()
{
    printf("Number: %s Base: %d Digits: %d\n", this->value, this->base, this->digitCount);
}
int Number::GetDigitsCount()
{
    return this->digitCount;
}
int Number::GetBase()
{
    return this->base;

}
char* Number::GetNumber()
{
    return this->value;
}
