/****************************************************************

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

*****************************************************************/

#include<bits/stdc++.h>

Node * findIntersection(Node *firstHead, Node *secondHead)

{
 Node *f=firstHead;
 Node *s=secondHead;
 unordered_set<Node *>st;
while(f)
{

         st.insert(f);

         f=f->next;

 

     }

     while(s)

     {

         if(st.find(s)!=st.end())

         {

             return s;

         }

         s=s->next;

     }

    

    return NULL;

}
