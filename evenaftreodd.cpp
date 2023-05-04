#include <iostream>
using namespace std;
#include "node.cpp"

node *evenAfterOdd(node *head)
{
	//write your code here
	node *current = head;
	node *oddH= NULL;
	node *oddT = NULL;
    node *evenH = NULL;
    node *evenT = NULL;

	if(current == NULL){
		return NULL;
	}
       

    while (current != NULL) 
	{
      if (current -> data % 2 == 0) {
        if (evenH == NULL) {
          evenH = evenT = current;
        } else {
          evenT ->next = current;
          evenT = current;
        }
      } 
	  
	  else
	   {
        if (oddH == NULL) {
          oddH = oddT = current;
        } else {
          oddT -> next = current;
          oddT = current;
        }
      }
      current = current->next;
	}

        if (evenH == NULL) {
          oddT->next = NULL;
          return oddH;
        }
		 else if (oddH ==NULL) 
		 {
          evenT->next = NULL;
          return evenH;
        } else {
          
          evenT->next = NULL;
          oddT->next = evenH;

          return oddH;
        }
}


node *takeinput_better()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }

        cin >> data;
    }

    return head;
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";

        head = head->next;
    }
    cout << endl;
}
int main()
{
    node *head = takeinput_better();

    print(head);

    cout << " =======  evenAfterodd ====== " << endl;
    head = evenAfterOdd(head);
		print(head);

    return 0;
}