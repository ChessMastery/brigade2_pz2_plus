#ifndef PROTOTYPES_H // ������������ ����
#define PROTOTYPES_H // ��������� ��������� ������� � ���������
#include <stdlib.h>
struct slist // ����
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

struct qlist // �������
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

struct inpqlist // ������� � ����������� ���������
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

struct outpqlist // ������� � ����������� ����������
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

struct dlist // ���
{
   char elem;
   dlist *prev, *next;
   dlist(int _elem = 0, dlist *_prev = NULL, dlist *_next = NULL) : elem(_elem), prev(_prev), next(_next) {};
};

struct deque
{
   dlist *beg, *end;
   deque() : beg(NULL), end(NULL) {};
};

inline bool DEmptiness(deque *Q)
{
   return Q == NULL;
}

void DBPush(deque *&Q, int elem);

void DEPush(deque *&Q, int elem);

int DBPop(deque *&Q);

int DEPop(deque *&Q);

void DPrint(deque *const Q);

// ��������� �������

int QCPop(queue *&Q);

#endif
