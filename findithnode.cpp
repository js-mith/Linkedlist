#include <iostream>
using namespace std;
#include "node.cpp"


void printIthNode(node *head, int i)
{
    int count = 0;
    node *current = head;
    while (current != NULL && count != i) {
      current = current->next;
      count++;
    }
    if(count == i && current != NULL){
      cout << current->data;
    }
   
}

node* takeinput()
{
	int data;
	cin >> data;
	node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		node *newNode = new node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		node *head = takeinput();
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}