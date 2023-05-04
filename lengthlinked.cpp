#include <iostream>
using namespace std;
#include "node.cpp"



int length(node *head)
{
		
    int count = 0;
    node* current = head; 
	    while (current != NULL) {
        count++;
        current = current->next;
    }
	cout <<endl;

    return count;

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
		cout << length(head) << endl;
	}
	return 0;
}