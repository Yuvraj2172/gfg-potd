//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    Node* mergeResult(Node* node1, Node* node2)
{
    if(node1==NULL){
         Node * curr= node2;
    Node * prev =NULL;
    Node * net = NULL;
    while(curr!=NULL){
        net = curr->next;
        curr->next = prev;
        prev=curr;
        curr=net;
        
    }
    node2=prev;
    
    return node2;
    }
    else if(node2==NULL){
         Node * curr= node1;
    Node * prev =NULL;
    Node * net = NULL;
    while(curr!=NULL){
        net = curr->next;
        curr->next = prev;
        prev=curr;
        curr=net;
        
    }
    node1=prev;
    
    return node1;
    }
    Node* temp1 = node1;
    Node* temp2 = node2;
    

    if (temp1->data > temp2->data) {
        Node* a = temp2->next;
        temp2->next = node1;
        node1 = temp2;
        node2 = a;
    }

    temp1 = node1;
    temp2 = node2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp2->data >= temp1->data) {
            while (temp1->next != NULL && temp1->next->data <= temp2->data) {
                temp1 = temp1->next;
            }

            Node* a = temp1->next;
            Node* b = temp2->next;
            temp1->next = temp2;
            temp2->next = a;
            temp2 = b;
        }
    }
    
    Node * curr= node1;
    Node * prev =NULL;
    Node * net = NULL;
    while(curr!=NULL){
        net = curr->next;
        curr->next = prev;
        prev=curr;
        curr=net;
        
    }
    node1=prev;

    return node1;
}    
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends