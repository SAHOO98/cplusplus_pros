//
// Created by uzumaki on 12/03/18.
//

#ifndef CPLUSPLUS_PROS_LINKED_LIST_H
#define CPLUSPLUS_PROS_LINKED_LIST_H


class Node {
private:
    int __data;
    Node *next;
public:
    Node(int data,Node *node);
    void setData(int data);
    void setNext(Node *node);
    int getData();
    Node* getNext();
};

class Linked_list{
private:
    int __lenght;

public:
    Linked_list();
    Node* insert(Node *node,int data, int pos);
    Node* remove(Node *node,int pos);
    Node* find(Node *node,int data);
    void show(Node *node);
    int getLenght();

};
#endif //CPLUSPLUS_PROS_LINKED_LIST_H
