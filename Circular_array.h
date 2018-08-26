//
// Created by uzumaki on 12/03/18.
//

#ifndef CPLUSPLUS_PROS_CIRCULAR_ARRAY_H
#define CPLUSPLUS_PROS_CIRCULAR_ARRAY_H
#include <iostream>

using namespace std;

class Circular_array {
private:
    int head, tail, lenght, array_lenght;
    int *ar;

public:

    Circular_array(int);
    void setLenght(int);
    int getLenght();
    void insertFront(int);
    void insertBack(int);
    void removeFront();
    void removeBack();
    void show();


};


#endif //CPLUSPLUS_PROS_CIRCULAR_ARRAY_H
