#include<iostream>
using namespace std;

struct DoubleLL
{
	int num;
	DoubleLL *prev;
	DoubleLL *next;
};

DoubleLL *Insert(DoubleLL *head, int num, int pos);
void PrintList(DoubleLL *head);
DoubleLL *Remove(DoubleLL *head, int pos);
void DeleteDoubleLL(DoubleLL *head);

void PrintList(DoubleLL *head)
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

DoubleLL *Insert(DoubleLL *head, int num, int pos)
{
	DoubleLL *newTemp = new DoubleLL;
	newTemp->num = num;
	if (head == NULL && pos == 0)
	{
		newTemp->next = NULL;
		newTemp->prev = NULL;
		return newTemp;
	}
	if (pos == 0)
	{
		newTemp->next = head;
		head->prev = newTemp;
		return newTemp;
	}
	if (head->next == NULL)
	{
		if (pos > 1)
		{
			return head;
		}
		head->next = newTemp;
		newTemp->prev = head;
		newTemp->next = NULL;
		return head;

	}
	DoubleLL *temp_b4 = head;
	while (--pos != 0)
	{
		temp_b4 = temp_b4->next;
	}
	if (temp_b4->next == NULL)
	{
		newTemp->next = NULL;
		temp_b4->next = newTemp;
		newTemp->prev = temp_b4;
		return head;
	}
	DoubleLL *temp_after = temp_b4->next;
	newTemp->next = temp_after;
	temp_after->prev = newTemp;
	temp_b4->next = newTemp;
	newTemp->prev = temp_b4;
	return head;
}

DoubleLL *Remove(DoubleLL *head, int pos)
{
	if (head == NULL) return 0;
	if (pos == 0)
	{
		if (head->next != NULL)
		{
			head->next->prev = NULL;
			return head->next;
		}
		return NULL;
	}
	DoubleLL *prev = head;
	while (--pos != 0)
	{
		prev = prev->next;
	}
	if (prev->next->next == NULL)
	{
		DoubleLL *del = prev->next;
		prev->next = NULL;
		delete del;
		return head;
	}
	DoubleLL *del = prev->next, *after = del->next;
	prev->next = after;
	after->prev = prev;
	delete del;
	return head;
}

void DeleteDoubleLL(DoubleLL *head)
{
	if (head != NULL)
	{
		DeleteDoubleLL(head->next);
		delete(head);
		return ;
	}
	else
	{
		return ;
	}
}

int main(void)
{
	DoubleLL *temp = NULL;
	temp = Insert(temp, 1, 0);
	temp = Insert(temp, 2, 1);
	temp = Insert(temp, 3, 2);
	temp = Insert(temp, 4, 3);
	temp = Insert(temp, 5, 4);
	PrintList(temp);
	temp = Remove(temp, 4);
	PrintList(temp);
	DeleteDoubleLL(temp);
}