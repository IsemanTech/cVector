#ifndef CVECTOR_H
#define CVECTOR_H

class cVector
{
public:
    cVector();
    cVector(int);
    cVector(const cVector&); //copy constructor
    ~cVector();
    void push_back(int i);
    void pop_back();
    void erase(int i);
    //first element in vector
    void begin();
    int size();
    //overloading [] operator
    int operator[](int);
    //overload = operator
    cVector& operator=(const cVector& v);
    //overloading += operator
    //cVector& operator+=(int i);
    bool operator!=(const cVector& v);
    int at(int i);
    void clearAll();
private:
    int vSize;
    int maxSize;
    int* array;
    void alloc_new();
    int someInt;
};
#endif
