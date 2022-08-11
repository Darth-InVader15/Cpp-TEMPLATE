#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

    struct Node
    {
        int data;
        Node* next;
    };


    int main()
    {
        Node* head = new Node();
        Node* temp = head;

        int val, n;
        cout<<"Enter No of elements"<<"\n";
        cin>>n;
       
        while(n--)
        {
            cout<<"Enter Value for Linked List"<<"\n";
            cin>>val;
            Node*A = new  Node();
            A ->data = val;
            temp ->next = A;
            temp = A;

        }

        temp = head->next;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;

        }


       

        return 0;

    }
