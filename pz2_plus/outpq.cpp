#include "prototypes.h"
#include <stdio.h>

void OUTPQPush(outpqueue *&Q, int elem)
{
   if (OUTPQEmptiness(Q))
   {
      Q = new outpqueue();
      Q->beg = new outpqlist(elem);
      Q->end = Q->beg;
   }
   else
   {
      Q->end->next = new outpqlist(elem);
      Q->end = Q->end->next;
   }
}

int OUTPQPop(outpqueue *&Q)
{
   outpqlist *CURR = Q->beg;
   int elem = Q->beg->elem;
   if (CURR->next)
   {
      bool first = true;
      outpqlist *MAX = CURR;
      while (CURR->next)
      {
         if (CURR->next->elem < elem)
         {
            elem = CURR->next->elem;
            MAX = CURR;
            first = false;
         }
         CURR = CURR->next;
      }
      if (!first)
      {
         if (MAX->next->next)
         {
            elem = MAX->next->elem;
            CURR = MAX->next->next;
            delete MAX->next;
            MAX->next = CURR;
         }
         else
         {
            elem = CURR->elem;
            delete MAX->next;
            MAX->next = NULL;
            Q->end = MAX;
         }
      }
      else
      {
         CURR = Q->beg->next;
         delete Q->beg;
         Q->beg = CURR;
      }
   }
   else
   {
      delete Q;
      Q = NULL;
   }
   return(elem);
}

void OUTPQPrint(outpqueue *const Q)
{
      printf_s("Содержимое очереди: ");
      const outpqlist *p = Q->beg;
      do
      {
         printf_s("%d ", p->elem);
         p = p->next;
      } while (p);
   printf_s("\n");
}
