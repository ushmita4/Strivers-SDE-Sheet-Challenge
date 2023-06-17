/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)

{

    

    Node*n= new Node();

    n->next= head;

 
    Node* p1= n;

    Node* p2= n;


    for(int i=1; i<=K; i++){

      p1= p1->next;

    }

     

    while(p1->next!=NULL){

        p1= p1->next;

        p2= p2->next;

 

    }

   

    p2->next= p2->next->next;

    return n->next;

}
