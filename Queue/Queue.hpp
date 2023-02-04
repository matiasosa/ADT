#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
   Node<T>* p;
};

template<typename T>
Queue<T> queue()
{
   Queue<T> q;
   q.p = NULL;
   return q;
}

template<typename T>
T* queueEnqueue(Queue<T>& q,T e)
{
   Node<T>* x = enqueue<T>(q.p, e);
   return &(x->info);
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
   return dequeue(q.p);
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
   return isEmpty<T>(q.p);
}

template<typename T>
int queueSize(Queue<T> q)
{
   if(q.p == NULL)
   {
      return 0;
   }
   int i=1;
   Node<T>* d = q.p->sig;
   while(d != q.p)
   {
      i++;
      d = d->sig;
   }

   return i;
}

#endif
