#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "prototypes.h"

int MStack() // ���� ��� �����
{
   enum SComands { CMD_SPUSH = 1, CMD_SPRINT, CMD_SPOP, CMD_SCLEAR, CMD_SBACK };

   int n = 0, exitFlag = 0, m = 0;
   stack *st = NULL;
   setlocale(LC_CTYPE, "Russian");
   do
   {
      printf_s("<1> - ��������� ������� � ����\n");
      printf_s("<2> - ����������� ���������� �����\n");
      printf_s("<3> - ������� ������� �� �����\n");
      printf_s("<4> - �������� ������\n");
      printf_s("<5> - ��������� � ����������� ����\n");
      int repeatFlag = 0;
      do {
         printf_s("������� ����� ������� (�� 1 �� 5): ");
         if (!scanf_s("%d", &n))
         {
            printf_s("������ �����\n");
            _getch();
            return 1;
         }
         switch (n)
         {
         case CMD_SPUSH: printf_s("������� �����: ");
            if (!scanf_s("%d", &m))
            {
               printf_s("������ �����\n");
               _getch();
               return 1;
            }
            SPush(st, m);
            break;
         case CMD_SPRINT: if (SEmptiness(st))
            printf_s("���� ����\n");
                        else
            SPrint(st);
            break;
         case CMD_SPOP: SPop(st, m) ?
            printf_s("���� ����\n") :
            printf_s("�� ����� �������� �������: %d\n", m);
            break;
         case CMD_SCLEAR: delete st;
            st = NULL;
            break;
         case CMD_SBACK: delete st;
            st = NULL;
            exitFlag = 1;
            break;
         default: printf_s("������: �������� ����� �������\n");
            repeatFlag = 1;
         }
      } while (!repeatFlag && !exitFlag);
   } while (!exitFlag);
   return 0;
}

int MQueue()  // ���� ��� �������
{

   enum Comands { CMD_QPUSH = 1, CMD_QPRINT, CMD_QPOP, CMD_QCLEAR, CMD_QBACK };

   int n = 0, exitFlag = 0, m = 0;
   queue *Q = NULL;
   setlocale(LC_CTYPE, "Russian");
   do
   {
      printf_s("<1> - ��������� ������� � �������\n");
      printf_s("<2> - ����������� ���������� �������\n");
      printf_s("<3> - ������� ������� �� �������\n");
      printf_s("<4> - �������� ������\n");
      printf_s("<5> - ��������� � ����������� ����\n");
      int repeatFlag = 0;
      do {
         printf_s("������� ����� ������� (�� 1 �� 5): ");
         if (!scanf_s("%d", &n))
         {
            printf_s("������ �����\n");
            _getch();
            return 1;
         }
         switch (n)
         {
         case CMD_QPUSH: printf_s("������� �����: ");
            if (!scanf_s("%d", &m))
            {
               printf_s("������ �����\n");
               _getch();
               return 1;
            }
            QPush(Q, m);
            break;
         case CMD_QPRINT: if (QEmptiness(Q))
            printf_s("������� �����\n");
                        else
            QPrint(Q);
            break;
         case CMD_QPOP: QEmptiness(Q) ?
            printf_s("������� �����\n") :
            printf_s("�� ������� �������� �������: %d\n", QPop(Q));
            break;
         case CMD_QCLEAR: delete Q;
            Q = NULL;
            break;
         case CMD_QBACK: delete Q;
            Q = NULL;
            exitFlag = 1;
            break;
         default: printf_s("������: �������� ����� �������\n");
            repeatFlag = 1;
         }
      } while (!repeatFlag && !exitFlag);
   } while (!exitFlag);
   return 0;
}

int MInPriorityQueue() // ���� ��� ������� � ����������� ���������
{
   enum Comands { CMD_INPQPUSH = 1, CMD_INPQPRINT, CMD_INPQPOP, CMD_INPQCLEAR, CMD_INPQBACK };

   int n = 0, exitFlag = 0, m = 0;
   inpqueue *Q = NULL;
   setlocale(LC_CTYPE, "Russian");
   do
   {
      printf_s("<1> - ��������� ������� � �������\n");
      printf_s("<2> - ����������� ���������� �������\n");
      printf_s("<3> - ������� ������� �� �������\n");
      printf_s("<4> - �������� ������\n");
      printf_s("<5> - ��������� � ����������� ����\n");
      int repeatFlag = 0;
      do {
         printf_s("������� ����� ������� (�� 1 �� 5): ");
         if (!scanf_s("%d", &n))
         {
            printf_s("������ �����\n");
            _getch();
            return 1;
         }
         switch (n)
         {
         case CMD_INPQPUSH: printf_s("������� �����: ");
            if (!scanf_s("%d", &m))
            {
               printf_s("������ �����\n");
               _getch();
               return 1;
            }
            INPQPush(Q, m);
            break;
         case CMD_INPQPRINT: if (INPQEmptiness(Q))
            printf_s("������� �����\n");
                        else
            INPQPrint(Q);
            break;
         case CMD_INPQPOP: INPQEmptiness(Q) ?
            printf_s("������� �����\n") :
            printf_s("�� ������� �������� �������: %d\n", INPQPop(Q));
            break;
         case CMD_INPQCLEAR: delete Q;
            Q = NULL;
            break;
         case CMD_INPQBACK: delete Q;
            Q = NULL;
            exitFlag = 1;
            break;
         default: printf_s("������: �������� ����� �������\n");
            repeatFlag = 1;
         }
      } while (!repeatFlag && !exitFlag);
   } while (!exitFlag);
   return 0;
}

int MOutPriorityQueue() // ���� ��� ������� � ����������� ����������
{
   enum Comands { CMD_OUTPQPUSH = 1, CMD_OUTPQPRINT, CMD_OUTPQPOP, CMD_OUTPQCLEAR, CMD_OUTPQBACK };

   int n = 0, exitFlag = 0, m = 0;
   outpqueue *Q = NULL;
   setlocale(LC_CTYPE, "Russian");
   do
   {
      printf_s("<1> - ��������� ������� � �������\n");
      printf_s("<2> - ����������� ���������� �������\n");
      printf_s("<3> - ������� ������� �� �������\n");
      printf_s("<4> - �������� ������\n");
      printf_s("<5> - ��������� � ����������� ����\n");
      int repeatFlag = 0;
      do {
         printf_s("������� ����� ������� (�� 1 �� 5): ");
         if (!scanf_s("%d", &n))
         {
            printf_s("������ �����\n");
            _getch();
            return 1;
         }
         switch (n)
         {
         case CMD_OUTPQPUSH: printf_s("������� �����: ");
            if (!scanf_s("%d", &m))
            {
               printf_s("������ �����\n");
               _getch();
               return 1;
            }
            OUTPQPush(Q, m);
            break;
         case CMD_OUTPQPRINT: if (OUTPQEmptiness(Q))
            printf_s("������� �����\n");
                        else
            OUTPQPrint(Q);
            break;
         case CMD_OUTPQPOP: OUTPQEmptiness(Q) ?
            printf_s("������� �����\n") :
            printf_s("�� ������� �������� �������: %d\n", OUTPQPop(Q));
            break;
         case CMD_OUTPQCLEAR: delete Q;
            Q = NULL;
            break;
         case CMD_OUTPQBACK: delete Q;
            Q = NULL;
            exitFlag = 1;
            break;
         default: printf_s("������: �������� ����� �������\n");
            repeatFlag = 1;
         }
      } while (!repeatFlag && !exitFlag);
   } while (!exitFlag);
   return 0;
}

int MDeque()  // ���� ��� ����
{

   enum Comands { CMD_QEPUSH = 1, CMD_QBPUSH, CMD_QPRINT, CMD_QBPOP, CMD_QEPOP, CMD_QCLEAR, CMD_QBACK };

   int n = 0, exitFlag = 0, m = 0;
   deque *Q = NULL;
   setlocale(LC_CTYPE, "Russian");
   do
   {
      printf_s("<1> - ��������� ������� � ����� ����\n");
      printf_s("<2> - ��������� ������� � ������ ����\n");
      printf_s("<3> - ����������� ���������� ����\n");
      printf_s("<4> - ������� ������� �� ������ ����\n");
      printf_s("<5> - ������� ������� �� ����� ����\n");
      printf_s("<6> - �������� ������\n");
      printf_s("<7> - ��������� � ����������� ����\n");
      int repeatFlag = 0;
      do {
         printf_s("������� ����� ������� (�� 1 �� 7): ");
         if (!scanf_s("%d", &n))
         {
            printf_s("������ �����\n");
            _getch();
            return 1;
         }
         switch (n)
         {
         case CMD_QEPUSH: printf_s("������� �����: ");
            if (!scanf_s("%d", &m))
            {
               printf_s("������ �����\n");
               _getch();
               return 1;
            }
            DEPush(Q, m);
            break;
         case CMD_QBPUSH: printf_s("������� �����: ");
            if (!scanf_s("%d", &m))
            {
               printf_s("������ �����\n");
               _getch();
               return 1;
            }
            DBPush(Q, m);
            break;
         case CMD_QPRINT: if (DEmptiness(Q))
            printf_s("��� ����\n");
                        else
            DPrint(Q);
            break;
         case  CMD_QBPOP: DEmptiness(Q) ?
            printf_s("��� ����\n") :
            printf_s("�� ���� �������� �������: %d\n", DBPop(Q));
            break;
         case  CMD_QEPOP: DEmptiness(Q) ?
            printf_s("��� ����\n") :
            printf_s("�� ���� �������� �������: %d\n", DEPop(Q));
            break;
         case CMD_QCLEAR: delete Q;
            Q = NULL;
            break;
         case CMD_QBACK: delete Q;
            Q = NULL;
            exitFlag = 1;
            break;
         default: printf_s("������: �������� ����� �������\n");
            repeatFlag = 1;
         }
      } while (!repeatFlag && !exitFlag);
   } while (!exitFlag);
   return 0;
}

int MCQueue()  // ���� ��� ��������� �������
{

   enum Comands { CMD_QPUSH = 1, CMD_QPRINT, CMD_QPOP, CMD_QCLEAR, CMD_QBACK };

   int n = 0, exitFlag = 0, m = 0;
   queue *Q = NULL;
   setlocale(LC_CTYPE, "Russian");
   do
   {
      printf_s("<1> - ��������� ������� � �������\n");
      printf_s("<2> - ����������� ���������� �������\n");
      printf_s("<3> - ������� ������� �� �������\n");
      printf_s("<4> - �������� ������\n");
      printf_s("<5> - ��������� � ����������� ����\n");
      int repeatFlag = 0;
      do {
         printf_s("������� ����� ������� (�� 1 �� 5): ");
         if (!scanf_s("%d", &n))
         {
            printf_s("������ �����\n");
            _getch();
            return 1;
         }
         switch (n)
         {
         case CMD_QPUSH: printf_s("������� �����: ");
            if (!scanf_s("%d", &m))
            {
               printf_s("������ �����\n");
               _getch();
               return 1;
            }
            QPush(Q, m);
            break;
         case CMD_QPRINT: if (QEmptiness(Q))
            printf_s("������� �����\n");
                        else
            QPrint(Q);
            break;
         case CMD_QPOP: QEmptiness(Q) ?
            printf_s("������� �����\n") :
            printf_s("�� ������� �������� �������: %d\n", QCPop(Q));
            break;
         case CMD_QCLEAR: delete Q;
            Q = NULL;
            break;
         case CMD_QBACK: delete Q;
            Q = NULL;
            exitFlag = 1;
            break;
         default: printf_s("������: �������� ����� �������\n");
            repeatFlag = 1;
         }
      } while (!repeatFlag && !exitFlag);
   } while (!exitFlag);
   return 0;
}

int main() // ������� ����
{
   enum Comands { CMD_STACK = 1, CMD_QUEUE, CMD_INPRIORITYQUEUE, CMD_OUTPRIORITYQUEUE, CMD_DEQUE, CMD_CQUEUE, CMD_EXIT };

   int n = 0, exitFlag = 0, m = 0;
   setlocale(LC_CTYPE, "Russian");
   do
   {
      printf_s("�������� ��������� ������:\n");
      printf_s("<1> - ����\n");
      printf_s("<2> - �������\n");
      printf_s("<3> - ������� � ����������� ���������\n");
      printf_s("<4> - ������� � ����������� ����������\n");
      printf_s("<5> - ���\n");
      printf_s("<6> - ��������� �������\n");
      printf_s("<7> - �����\n");
      int repeatFlag = 0;
      do {
         printf_s("������� ����� ������� (�� 1 �� 7): ");
         if (!scanf_s("%d", &n))
         {
            printf_s("������ �����");
            _getch();
            return 1;
         }
         switch (n)
         {
         case CMD_STACK: if (MStack()) return 1;
            repeatFlag = 1;
            break;
         case CMD_QUEUE: if (MQueue()) return 1;
            repeatFlag = 1;
            break;
         case CMD_INPRIORITYQUEUE: if (MInPriorityQueue()) return 1;
            repeatFlag = 1;
            break;
         case CMD_OUTPRIORITYQUEUE: if (MOutPriorityQueue()) return 1;
            repeatFlag = 1;
            break;
         case CMD_DEQUE: if (MDeque()) return 1;
            repeatFlag = 1;
            break;
         case CMD_CQUEUE: if (MCQueue()) return 1;
            repeatFlag = 1;
            break;
         case CMD_EXIT: exitFlag = 1;
            break;
         default: printf_s("������: �������� ����� �������\n");
            repeatFlag = 1;
         }
      } while (!repeatFlag && !exitFlag);
   } while (!exitFlag);

   return 0;
}
