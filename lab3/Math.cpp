#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <cstdarg>
#include <cstdlib>
#include <cstdio>

int Math::Add(int a, int b) {
    return a + b;

}
int Math::Add(int a, int b, int c)
{
    return a + b + c;
}
int Math::Add(double a, double b)
{
    return a + b;
}
int Math::Add(double a, double b, double c)
{
    return a + b + c;
}
int Math::Mul(int a, int b)
{
    return a * b;
}
int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}
int Math::Mul(double a, double b)
{
    return a * b;
}
int Math::Mul(double a, double b, double c)
{
    return a * b * c;
}
int Math::Add(int count, ...) {
    int sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}
char* Math::Add(const char* str1, const char* str2) {
    char* resultString = new char[20];
    if (str1 == nullptr || str2 == nullptr)
        return nullptr;

    int num1 = std::atoi(str1);
    int num2 = std::atoi(str2);
    int result = num1 + num2;

    std::sprintf(resultString, "%d", result);

    return resultString;
}
