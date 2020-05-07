#ifndef PROTOTYPES_H // заголовочный файл
#define PROTOTYPES_H // объ€влены прототипы функций и структуры
#include <stdlib.h>
struct slist // стек
{
   slist *next;
   int elem;
   slist(slist *_next = NULL, int _elem = 0) : next(_next), elem(_elem) {};
};

typedef slist stack;

inline bool SEmptiness(const stack *p)
{
   return p == NULL;
}

void SPush(stack *&p, int num);

int SPop(stack *&p, int &num);

void SPrint(const stack *p);

struct qlist // очередь
{
   char elem;
   qlist *next;
   qlist(int _elem, qlist *_next = NULL) : elem(_elem), next(_next) {};
};

struct queue
{
   qlist *beg, *end;
   queue() : beg(NULL), end(NULL) {};
};

inline bool QEmptiness(queue *Q)
{
   return Q == NULL;
}

void QPush(queue *&Q, int elem);

int QPop(queue *&Q);

void QPrint(queue *const Q);

struct inpqlist // очередь с приоритетом включени€
{
   char elem;
   inpqlist *next;
   inpqlist(int _elem, inpqlist *_next = NULL) : elem(_elem), next(_next) {};
};

struct inpqueue
{
   inpqlist *beg, *end;
   inpqueue() : beg(NULL), end(NULL) {};
};

inline bool INPQEmptiness(inpqueue *Q)
{
   return Q == NULL;
}

void INPQPush(inpqueue *&Q, int elem);

int INPQPop(inpqueue *&Q);

void INPQPrint(inpqueue *const Q);

struct outpqlist // очередь с приоритетом исключени€
{
   char elem;
   outpqlist *next;
   outpqlist(int _elem, outpqlist *_next = NULL) : elem(_elem), next(_next) {};
};

struct outpqueue
{
   outpqlist *beg, *end;
   outpqueue() : beg(NULL), end(NULL) {};
};

inline bool OUTPQEmptiness(outpqueue *Q)
{
   return Q == NULL;
}

void OUTPQPush(outpqueue *&Q, int elem);

int OUTPQPop(outpqueue *&Q);

void OUTPQPrint(outpqueue *const Q);

#endif
