#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
   Node<T>* n;
   int pos;
};

template<typename T>
List<T> list()
{
   List<T> lst;
   lst.n=NULL;
   lst.pos=0;
   return lst;
}

template<typename T>
T* listAdd(List<T>& lst,T e)
{
   Node<T>* x = add<T>(lst.n, e);
   return &(x->info);
}

template<typename T>
T* listAddFirst(List<T>& lst,T e)
{
   Node<T>* x = addFirst<T>(lst.n, e);
   return &(x->info);
}

template<typename T,typename K>
T listRemove(List<T>& lst,K k,int cmpTK(T,K))
{
   return remove<T>(lst.n, k, cmpTK);
}

template<typename T>
T listRemoveFirst(List<T>& lst)
{
   return removeFirst<T>(lst.n);
}

template<typename T,typename K>
T* listFind(List<T> lst,K k,int cmpTK(T,K))
{
   Node<T>* x = find<T,K>(lst.n, k, cmpTK);
   return &(x->info);
}

template<typename T>
bool listIsEmpty(List<T> lst)
{
   return isEmpty<T>(lst.n);
}

template<typename T>
int listSize(List<T> lst)
{
   int x=0;
   if(lst.n != NULL)
   {
      while(lst.n != NULL)
      {
         x++;
         lst.n = lst.n->sig;
      }
   }
   return x;
}

template<typename T>
void listFree(List<T>& lst)
{
   lst.n = NULL;
   lst.pos = 0;
}

template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
   Node<T>* x = orderedInsert<T>(lst.n, t, cmpTT);
   return &(x->info);
}

template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
   sort<T>(lst.n, cmpTT);
}

template<typename T>
void listReset(List<T>& lst)
{
   lst.pos = 0;
}

template<typename T>
bool listHasNext(List<T> lst)
{
   return lst.pos < (listSize<T>(lst));
}

template<typename T>
T* listNext(List<T>& lst)
{
   Node<T>* q = lst.n;

   int i=0;
   while(i<lst.pos)
   {
      q = q->sig;
      i++;
   }
   lst.pos++;

   return &(q->info);
}

#endif
