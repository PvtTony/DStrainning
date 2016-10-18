#include<iostream>
using namespace std;

struct List
{
  int num;
  List *next;
};

List *CreateList(int size);
void DisplayList(List *head);
void InsertItem(List *head, int val, int pos);


List *CreateList(int size)
{
  List *p = NULL;
  List *q = NULL;
  List *head = NULL;
  for (int i = 0; i < size; i++)
  {
    p = new List;
    cin >> p->num;
    if (head == NULL)
      {
	head = p;
      }
    else
      {
	q->next = p;
      }
    q = p;
  }
    if (head != NULL)
      {
	q->next = NULL;
      }

    return head;
}

void DisplayList(List *head)
{
  while(head != NULL)
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

void InsertItem(List *head, int val, int pos)
{
  List *item = new List;
  item->num = val;
  List *temp_b4 = head;
  while(--pos != 0)
    {
      temp_b4 = temp_b4->next;
    }
  List *temp_after = temp_b4->next;
  item->next = temp_after;
  temp_b4->next = item;
  
}

int main(void)
{
  //List *CreateList(int size);
  //void DisplayList(List *head);
  List *testlist = new List;
  int size;
  cin >> size;
  testlist = CreateList(size);
  DisplayList(testlist);
  cout << "Insert a element at pos 3" << endl;
  InsertItem(testlist, 30, 3);
  DisplayList(testlist);
  delete testlist;
  return 0;
}
