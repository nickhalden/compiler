
#include "Node.h"
#include <iostream>
#include<vector>
using namespace std;

template<class T>
Node<T>::Node()
{
}


//  This constructor is just to set next pointer of a node and the data contained.
template<class T>
Node<T>::Node(const T& item,Node<T>* ptrnext)
{
    this->data = item;
    this->next = ptrnext;
}

template<class T>
Node<T>*Node<T>::NextNode()
{
    return this->next;
}

//  This methods inserts a node just after the node that the method belongs to 
//  TO-DO: Consider a better implementation
template<class T>
void Node<T>::InsertAfter(Node<T> *p)
{
    // not to lose the rest of the list, we ought to link the rest of the
    // list to the Node<T>* p first
    p->next = this->next;

    // now we should link the previous Node to Node<T> *p , i.e the Node that we are 
    //inserting after,
    this->next = p;
}

template<class T>
Node<T> * GetNode(const T& item, Node<T>* nextptr = NULL)
{
    Node<T>* newnode; // Local ptr for new node
    newnode = new Node<T>(item,nextptr);
    if ( newnode == NULL)
    {
        cerr << "Memory allocation failed." << endl;
        exit(1);
    }
    return newnode;
}

