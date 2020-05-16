#include "prototypes.h"
#include <stdio.h>

void DEPush(deque *&Q, int elem)
{
   if (DEmptiness(Q))
   {
      Q = new deque();
      Q->beg = new dlist(elem);
      Q->end = Q->beg;
   }
   else
   {
      Q->end->next = new dlist(elem, Q->end);
      Q->end = Q->end->next;
   }
}

void DBPush(deque *&Q, int elem)
{
   if (DEmptiness(Q))
   {
      Q = new deque();
      Q->beg = new dlist(elem);
      Q->end = Q->beg;
   }
   else
   {
      Q->beg->prev = new dlist(elem, NULL, Q->beg);
      Q->beg = Q->beg->prev;
   }
}

int DBPop(deque *&Q)
{
   int elem = Q->beg->elem;
   Q->beg = Q->beg->next;
   if (Q->beg)
   {
      delete Q->beg->prev;
      Q->beg->prev = NULL;
   }
   else
   {
      delete Q;
      Q = NULL;
   }
   return(elem);
}

int DEPop(deque *&Q)
{
   int elem = Q->end->elem;
   Q->end = Q->end->prev;
   if (Q->end)
   {
      delete Q->end->next;
      Q->end->next = NULL;
   }
   else
   {
      delete Q;
      Q = NULL;
   }
   return(elem);
}

void DPrint(deque *const Q)
{
   printf_s("Содержимое очереди: ");
   const dlist *p = Q->beg;
   do
   {
      printf_s("%d ", p->elem);
      p = p->next;
   } while (p);
   printf_s("\n");
}