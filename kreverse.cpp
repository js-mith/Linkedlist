#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node *kReverse(Node *head, int k)
{
	//Write your code here
	if(head == NULL || k ==0){
		return head;
	}
	Node *prev = NULL;
	Node *curr = head;
	Node *forward = NULL;
	
	while(curr != NULL){
	          for (int i = 1; i <= k && curr != NULL; i++) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
			
          }
          if (forward != NULL)
            head->next = kReverse(forward, k);
          return prev;
          
        }
     
}

int main() {
     	Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
     return 0;
}