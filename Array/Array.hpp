#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array
{
   T* arr; 
   int len; 
   int cap; 
};

template<typename T>
void _redim(Array<T>& a, int len, int newCap)
{
   T* n = new T[newCap];
   for(int i=0; i<len; i++)
   {
      n[i] = a.arr[i];
   }
   delete(a.arr);
   a.arr = n;
}

template<typename T>
Array<T> array(int cap)
{
   Array<T> a;
   a.arr = new T[cap];
   a.len = 0;
   a.cap = cap;
   return a;
}

template<typename T>
Array<T> array()
{
   return array<T>(50);
}

template<typename T>
int arrayAdd(Array<T>& a,T t)
{
   if(a.len == a.cap)
   {
      _redim(a, a.len, a.cap+1);
   }
   //
   if(a.len < 0)
   {
      a.len += abs(a.len) ;
   }
   //
   a.arr[a.len] = t;
   a.len++;
   return a.len;
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   return &(a.arr[p]);
}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   a.arr[p] = t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   Array<T> n = array<T>();

   for(int i=0; i<(a.len+1); i++)
   {
      if(i!=p&&i<p)
      {
         arrayAdd(n, a.arr[i]);
      }
      else if(i>p)
      {
         arrayAdd(n, a.arr[i-1]);
      }
      else
      {
         arrayAdd(n, t);
      }
   }

   delete(a.arr);
   a = n;
}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   T x = a.arr[p];
   Array<T> n = array<T>();

   for(int i=0; i<a.len; i++)
   {
      if(i != p)
      {
         arrayAdd<T>(n, a.arr[i]);
      }
   }
   delete(a.arr);
   a.arr = n.arr;
   a.len--;
   return x;
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   a = array<T>();
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   int j=-1;
   for(int i=0; (i<a.len); i++)
   {
      if(cmpTK(a.arr[i],k)==0)
      {
         j=i;
         break;
      }
   }
   return j;
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   return orderedInsert<T>(a.arr, a.len, t, cmpTT);
}

template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort<T>(a.arr, a.len, cmpTT);
}


#endif
