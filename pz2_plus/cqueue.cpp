#include "prototypes.h"
#include <stdio.h>

int QCPop(queue *&Q)
{
   int elem = Q->beg->elem;
   qlist *q = Q->beg;
   Q->beg = Q->beg->next;
   delete q;
   q = NULL;
   Q->end->next = new qlist(elem);
   Q->end = Q->end->next;
   if (!Q->beg)
   {
      delete Q;
      Q = NULL;
   }
   return(elem);
}
