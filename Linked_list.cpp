//
// Created by uzumaki on 12/03/18.
//
#include <iostream>
#include "Linked_list.h"

using namespace std;
//Node operation class
Node::Node(int data, Node *node) {
    __data = data;
    next = node;
}

void Node::setData(int data) {
    __data = data;
}

void Node::setNext(Node *node) {
    next = node;
}

int Node::getData() {
    return __data;
}

Node *Node::getNext() {
    return next;
}
//Linked_list operattion class
Linked_list::Linked_list() {
    __lenght = 0;


}

Node* Linked_list::insert(Node *node, int data, int pos) {
    Node *t = new Node(data, nullptr);
    if(node == nullptr) {
        node = t;
    }else{
        Node *temp = node;
        while(--pos != 0){
            temp = temp->getNext();
        }
        t->setNext(temp->getNext());
        temp->setNext(t);
    }
    __lenght ++;
    return node;
}

Node* Linked_list::remove(Node *node, int pos) {
    if(node!= nullptr && pos<__lenght){
        if(pos==0){
            node = node->getNext();
        } else{
            Node *temp = node;
            while(--pos != 0){
                temp = temp->getNext();
            }
            temp->setNext(temp->getNext()->getNext());
        }
        __lenght--;
    } else{
        cout<<"Not possible to delete!!"<<endl;
    }
    return  node;
}

Node *Linked_list::find(Node *node, int data) {
    return node->getData() == data ? node : find(node->getNext(), data);
}

void Linked_list::show(Node *node) {
    Node *t = node;
    if(node!= nullptr) {
        while (t != nullptr) {
            cout<<"||" << t->getData() << "||->";
            t = t->getNext();
        }
        cout << "NULL\n";
    }else{
        cout<<"NO list to show\n";
    }

}

int Linked_list::getLenght() {
    return __lenght;
}
