#include "cVector.h"

cVector::cVector()
{
    maxSize = 20;
    array = new int[maxSize];
    vSize = 0;
}
cVector::cVector(int i)
{
    maxSize = i;
    array = new int[maxSize];
    vSize = 0;
}
cVector::cVector(const cVector& v)
{
    maxSize = v.maxSize;
    vSize = v.vSize;
    array = new int[maxSize];
    for (int i= 0; i < v.vSize; i++)
	    array[i] = v.array[i];	    
}
cVector::~cVector()
{
    delete[] array;
}
void cVector::push_back(int i)
{
    if (vSize + 1 > maxSize)
	alloc_new();
    array[vSize] = i;
    vSize++;
}
void cVector::pop_back()
{
    vSize--;    
}
void cVector::erase(int i)
{
    //erase element position
    for (int itr = 0; itr != vSize - 1; ++itr)
	{
	    if (itr == i)
		{
		    array[i] = 0;
		    break;
		}
	}
}	    
int cVector::operator[](int i)
{
    return array[i];
}
int cVector::at(int i)
{
    if (i < vSize)
	return array[i];
    //throw 10;
}
void cVector::alloc_new()
{
    //allocate twice as much memory
    maxSize = vSize * 2;
    int * tmp = new int[maxSize];
    for (int i = 0; i < vSize; i++)
	tmp[i] = array[i];
    delete[] array;
    array = tmp;
}
int cVector::size()
{
    return vSize;
}
/*
cVector& cVector::operator+=(int i)
{
    this->push_back(i);
    return *this;
    }*/
cVector& cVector::operator=(const cVector& v)
{
    if (this != &v) //vec = vec
	{
	    maxSize = v.maxSize;
	    vSize = v.vSize;
	    delete[] array; //delete array = delete v.array
	    array = new int[maxSize];
	    for (int i = 0; i < v.vSize; i++)
		array[i] = v.array[i];
	}
    return *this;

}
bool cVector::operator!=(const cVector& v)
{
    return (someInt != v.someInt);
}
    
void cVector::clearAll()
{
   vSize = 0;
}
