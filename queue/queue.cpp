#include<iostream>
using namespace std;

struct Queue
{
  int num;
  Queue *next;
};

void PrintQueue(Queue *head)
{
  while( head != NULL)
    {
      cout << head->num;
      head = head->next;
      if (head != NULL)
	{
	  cout << "->";
	}
    }
  cout << endl;
}

int Peek(Queue *head)
{
  if (head == NULL) return 0;
  return head->num;
}

Queue *Enqueue(Queue *head, int num)
{
  Queue *temp = new Queue;
  temp->num = num;
  if (head == NULL)
    {
      head = temp;
      return head;
    }
  Queue *q = head;
  while ( q->next != NULL)
    {
      q = q->next;
    }
  q->next = temp;
  //head = temp;
  return head;
}

Queue *Dequeue(Queue* head)
{
  if (head == NULL) return NULL;
  return head->next;
}

int main(void)
{
  Queue *test = NULL;
  test = Enqueue(test, 25);
  test = Enqueue(test, 35);
  test = Enqueue(test, 45);
  PrintQueue(test);
  cout << Peek(test) << endl;
  test = Dequeue(test);
  PrintQueue(test);
  return 0;
}
  
      


