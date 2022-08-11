#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

    struct Node
    {   
        int data;
        Node* next; 
    };
    int32_t main()
    {
        Node* head = new Node();
        Node* temp =  head;
        cout<<"Enter no of elements\n";
        int n;
        cin>>n;
        int i = n;
        while(i--)
        {
            int temp;
            cin>>temp;
            Node* temp1 = new Node();
            temp1->data = temp;
            temp->next = temp1;
            temp = temp1;
        }
        temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
        temp = head;
        Node* temp2 = new Node();
        while(temp)
        {
            temp2->data = temp->data;
            temp2 = temp2->next;
            temp = temp->next;
        }
        Node*head2 = temp2;
        temp2 = head2;
        while(temp2)
        {
            cout<<
        }
    }