#ifndef NUMBER_H
#define NUMBER_H

class Number {
private:
    char* value;
    int base;
    int digitCount;

public:
    Number(const char* value, int base);
    Number(const Number& obj);
    Number(const int value);
    Number(Number&& obj) noexcept;
    ~Number();

    Number& operator=(int nr);
    Number& operator=(Number&& obj) noexcept;
    Number& operator=(const char* sir);
    Number& operator+=(const Number& obj);
    Number& operator--(int value);
    Number& operator--();
    int operator[](int value);
    bool operator>(Number obj);
    bool operator<(Number obj);
    bool operator<=(Number obj);
    bool operator>=(Number obj);
    bool operator==(Number obj);
    bool operator!=(Number obj);

    friend Number operator+(Number n1, Number n2);
    friend Number operator-(Number n1, Number n2);

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount();
    int GetBase();
    char* GetNumber();
};

#endif // NUMBER_H
