
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template<typename K,typename T>
struct Map
{
   Array<K> key;
   Array<T> value;
   int i;
};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.key = array<K>();
   m.value = array<V>();
   m.i = 0;
   return m;
}

template<typename K,typename V>
V* mapGet(Map<K,V> m,K k)
{
   V* v = NULL;
   for(int i=0;i<arraySize(m.key);i++)
   {
      if(m.key.arr[i] == k)
      {
         v = arrayGet(m.value, i);
      }
   }

   return v;
}

template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
   V* x = mapGet(m, k);
   if(x == NULL)
   {
      arrayAdd(m.key, k);
      arrayAdd(m.value, v);
      return m.value.arr + m.value.len-1;
   }
   else
   {
      *x = v;
      return x;
   }
   return NULL;
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{

   V* v = mapGet<K,V>(m,k);
   if(v != NULL)
   {
      return true;
   }
   else
   {
      return false;
   }
   return true;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{
   V* x = mapGet<K,V>(m,k);
   V v = *x;
   for(int i=0; i<m.value.len; i++)
   {
      if(v == m.value.arr[i])
      {
         arrayRemove<K>(m.key, i);
         arrayRemove<V>(m.value, i);
      }
   }
   return v;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
   arrayRemoveAll<V>(m.value);
   arrayRemoveAll<K>(m.key);
}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{
   return m.key.len;
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{
   return m.value.len > m.i;
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{
   K k = m.key.arr[m.i];
   m.i++;
   return k;
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
   V* v = m.value.arr + m.i;
   m.i++;
   return v;
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{
   m.i = 0;
}

template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
   arraySort<K>(m.key, cmpKK);
}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{
   arraySort<V>(m.value, cmpVV);
}

#endif
