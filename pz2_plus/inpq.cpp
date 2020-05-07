#include "prototypes.h"
#include <stdio.h>

void INPQPush(inpqueue *&Q, int elem)
{
   if (INPQEmptiness(Q))
   {
      Q = new inpqueue();
      Q->beg = new inpqlist(elem);
      Q->end = Q->beg;
   }
   else
   {
      inpqlist *CURR = Q->beg;
      if (elem >= CURR->elem)
      {
         while (CURR->next && elem >= CURR->next->elem)
            CURR = CURR->next;
         if (CURR->next)
         {
            inpqlist *LINK = CURR->next;
            CURR->next = new inpqlist(elem, LINK);
         }
         else
         {
            CURR->next = new inpqlist(elem);
            Q->end = CURR;
         }
      }
      else
      {
         CURR = Q->beg;
         Q->beg = new inpqlist(elem, CURR);
      }
      
   }
}

int INPQPop(inpqueue *&Q)
{
   int elem = Q->beg->elem;
   inpqlist *q = Q->beg;
   Q->beg = Q->beg->next;
   delete q;
   q = NULL;
   if (!Q->beg)
   {
      delete Q;
      Q = NULL;
   }
   return(elem);
}

void INPQPrint(inpqueue *const Q)
{
      printf_s("Содержимое очереди: ");
      const inpqlist *p = Q->beg;
      do
      {
         printf_s("%d ", p->elem);
         p = p->next;
      } while (p);
   printf_s("\n");
}
