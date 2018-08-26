//
// Created by uzumaki on 12/03/18.
//

#include "Circular_array.h"

void Circular_array::insertFront(int x) {

    if(this->lenght == this->array_lenght){
        cout<<this->lenght<<" "<<this->array_lenght<<endl;
        int *newaArray = new int[2*this->array_lenght];

        for (int i = 0; i <this->array_lenght ; ++i) {
            newaArray[i] = this->ar[(head+i)%this->array_lenght];
        }

        this->ar = newaArray;
        this->head = 0;
        this->tail = this->lenght - 1;

    }
    this->head -=1;
    if(this->head<0)
        this->head = this->array_lenght-1;
    this->ar[this->head] = x;
    this->lenght +=1;

}

void Circular_array::insertBack(int x) {
    if(this->lenght == this->array_lenght){
        int *newaArray = new int[2*this->array_lenght];

        for (int i = 0; i <this->array_lenght ; ++i) {
            newaArray[i] = this->ar[(head+i)%this->array_lenght];
        }

        this->ar = newaArray;

        this->head = 0;
        this->tail = this->lenght-1;
    }
    this->tail +=1;
    if(this->tail==this->array_lenght)
        this->tail = 0;
    this->ar[this->tail] = x;
    this->lenght+=1;

}

Circular_array::Circular_array(int lenght) {

    this->array_lenght = lenght;
    this->lenght = 0;
    this->ar = new int[lenght];
    this->head = 0;
    this->tail = 0;

}

void Circular_array::setLenght(int lenght) {
    this->array_lenght = lenght;
}

int Circular_array::getLenght() {

    return  this->array_lenght;
}

void Circular_array::removeBack() {
    this->ar[this->tail] = NULL;
    this->tail-=1;

    if(this->tail==-1)
        this->tail = this->array_lenght-1;

    this->lenght -=1;
}


void Circular_array::removeFront() {
    this->ar[this->head] = NULL;
    this->head +=1;

    if(this->head==this->array_lenght)
        this->head = 0;

    this->lenght-=1;
}

void Circular_array::show() {
    cout<<"\r\n";
    for (int i = 0; i < this->array_lenght; ++i) {
        if(this->head == this->tail && this->head == i)
            cout<<"HEAD :: TAIL :";

        else if(i==this->head)
            cout<<"HEAD: ";
        else if(i == this->tail)
            cout<<"TAIL: ";
        else
            cout<<"      ";
        cout<<this->ar[i]<<endl;

    }
}
