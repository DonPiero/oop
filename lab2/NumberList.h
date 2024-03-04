#ifndef UNTITLED_NUMBERLIST_H
#define UNTITLED_NUMBERLIST_H

class NumberList
{
    int numbers[10];
    int count;
public:
    void Init();
    bool Add(int x);
    void Sort();
    void Print();
};

#endif //UNTITLED_NUMBERLIST_H
