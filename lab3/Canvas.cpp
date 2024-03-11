#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height)
{
    this->height = height;
    this->width = width;
    this->a = new char* [height];
    for (int i = 0; i < height; ++i)
    {
        this->a[i] = new char[width];
        for (int j = 0; j < width; ++j)
        {
            this->a[i][j] = ' ';
        }
    }
}

Canvas::~Canvas()
{
    for (int i = 0; i < this->height; ++i)
    {
        delete[] this->a[i];
    }
    delete[] this->a;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {

            int dx = i - x;
            int dy = j - y;
            double distance = sqrt(dx * dx + dy * dy);

            if (abs(distance - ray) < 0.5)
            {
                this->a[i][j] = ch;
            }
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {

            int dx = i - x;
            int dy = j - y;
            double distance = sqrt(dx * dx + dy * dy);

            if (distance <= ray)
            {
                this->a[i][j] = ch;
            }
        }
    }
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top; i <= bottom; i++)
        if (i >= 0 && i < this->height)
        {
            if (left >= 0 && left < this->width)
                this->a[i][left] = ch;
            if (right >= 0 && right < this->width)
                this->a[i][right] = ch;
        }
    for (int j = left; j <= right; j++)
        if (j >= 0 && j < this->width)
        {
            if (top >= 0 && top < this->height)
                this->a[top][j] = ch;
            if (bottom >= 0 && bottom < this->height)
                this->a[bottom][j] = ch;
        }
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = top + 1; i < bottom; i++)
        for (int j = left + 1; j < right; j++)
            if (i >= 0 && i < this->height && j >= 0 && j < this->width)
                this->a[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < this->width && y >= 0 && y < this->height)
        this->a[y][x] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {

    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        this->a[y1][x1] = ch;
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
            printf("%c ", a[i][j]);
        printf("\n");
    }
}
void Canvas::Clear()
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            this->a[i][j] = ' ';
}
