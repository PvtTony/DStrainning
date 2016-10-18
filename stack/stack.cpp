#include<iostream>
using namespace std;

struct Stack
{
  int num;
  Stack *next;
};

//Stack *CreateStack();
void PrintStack(Stack *head);
Stack *Push(Stack *head, int num);
Stack* Pop(Stack *head);
int Top(Stack *head);

/*Stack *CreateStack()
{
  Stack *temp = new Stack;
  Pop(temp);
  return temp;
  }*/

void PrintStack(Stack *head)
{  
  while (head != NULL)
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

Stack *Push(Stack *head, int num)
{
  Stack *temp = new Stack;
  temp->num = num;
  if (head == NULL)
    {
      return temp;
    }
  else
    {
      temp->next = head;
    }
  return temp;
}

Stack *Pop(Stack *head)
{
  if (head == NULL) return head;
  return head->next;
}

int Top(Stack *head)
{
  if(head) return head->num;
  else return 0;
}

int main(void)
{
  Stack *test = NULL;
  PrintStack(test);
  test = Push(test, 25);
  //PrintStack(test);
  cout << Top(test) << endl;
  test = Push(test, 35);
  //PrintStack(test);
  cout << Top(test) << endl;
  test = Pop(test);
  PrintStack(test);
  return 0;
}
