#include <iostream>
#include "Linked_list.h"

using  namespace std;

int main() {
    cout << "Hello, World!\n";

    Linked_list ob;
    Node *head = ob.insert(nullptr,10,0);
    head = ob.insert(head,25,1);
    head = ob.insert(head,68,2);
    ob.show(head);
    head = ob.remove(head,2);
    ob.show(head);
    head = ob.remove(head,2);
    head = ob.insert(head,69,2);
    head = ob.insert(head,657,3);
    ob.show(head);
    Node *node = ob.find(head,25);
    node->setData(30);
    cout<<node->getData()<<endl;
    ob.show(head);
    return 0;
}