#include<iostream>
using namespace std;

struct List
{
	int num;
	List *next;
};

List *CreateList(int size);
void DisplayList(List *head);
List *InsertItem(List *head, int val, int pos);
List *RemoveItem(List *head, int pos);

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

List *InsertItem(List *head, int val, int pos)
{
	List *item = new List;
	item->num = val;
	if (pos == 0)
	{
		//List *temp = head;
		item->next = head;
		head = item;
//		head = temp;
		return head;
	}
	List *temp_b4 = head;
	while (--pos != 0)
	{
		temp_b4 = temp_b4->next;
	}
	List *temp_after = temp_b4->next;
	item->next = temp_after;
	temp_b4->next = item;
	return head;

}

List *RemoveItem(List *head, int pos)
{
	if (head == NULL) return head;
	if (pos == 0)
	{
		return head->next;
	}
	List *prev = head;
	while (--pos != 0)
	{
		prev = prev->next;
	}
	List *del = prev->next, *after = del->next;
	prev->next = after;
	delete del;
	return head;
}

int main(void)
{
	//List *CreateList(int size);
	//void DisplayList(List *head);
	List *testlist = new List;
	int size;
	cout << "Size of the linkedlist" << endl;
	cin >> size;
	testlist = CreateList(size);
	DisplayList(testlist);
	cout << "Insert an element" << endl;
	int insert_num, insert_pos;
	cout << "pos: ";
	cin >> insert_pos;
	cout << "num: ";
	cin >> insert_num;
	cout << endl;
	testlist = InsertItem(testlist, insert_num, insert_pos);
	DisplayList(testlist);
	cout << "Remove an item" << endl;
	int remove_item;
	cout << "pos: ";
	cin >> remove_item;
	cout << endl;
	testlist = RemoveItem(testlist, remove_item);
	DisplayList(testlist);
	delete testlist;
	return 0;
}
