#include<iostream>

using namespace std;
class A{
    protected:
        int data;

    public:
        A(){
            data  = 0;
            cout << "A Default Ctor" << '\n';
        }
        A(int a){
            data=a;
            cout<<"A Parameterised ctor"<<endl;
        }
        ~A(){
            cout<<"A dtor"<<endl;
            //cout << data << '\n';
            //delete &data;
        }
        virtual void foo(string ss){
            cout<<"Hello "<<ss<<" I'm Mr.A\n.Nice to meet you.\n";
        }

        friend void getData(A &ob);

};

class B: public A{
    public:
        B(){
            cout << "B Default Ctor" << '\n';
        }
        void foo(string ss){
            cout<<"Hello "<<ss<<" I'm Mr.B, elder son of Mr.A\n.Nice to meet you.\n";
            data ++;
        }
        ~B(){
            cout<< "B detor"<<endl;
        }

};

class C:public A{

public:
    C(){
        cout << "C Default Ctor" << '\n';
    }
    void foo(string ss){
        cout<<"Hello "<<ss<<" I'm Mr.C, younger son of Mr.A\n.Nice to meet you.\n";
        data ++;
    }

    ~C(){
        cout<<"C detor"<<endl;
    }
};

void getData(A &ob){
        cout<< ob.data<<endl;
}
int main(int argc, char const *argv[]) {
    A *a, *d;//These are the pointers to the object not instanaces, hence no initialisations
    B b;//This is the object of B which inherits A, hence teo
    C c;
    a = &b;
    d = &c;

    a->foo("Sonu");
    d->foo("Sappy");
    c.foo("7:Hermit");
    getData(b);
    getData(c);
    return 0;
}
/*Output:-

A Default Ctor
B Default Ctor
A Default Ctor
C Default Ctor
Hello Sonu I'm Mr.B, elder son of Mr.A
.Nice to meet you.
Hello Sappy I'm Mr.C, younger son of Mr.A
.Nice to meet you.
Hello 7:Hermit I'm Mr.C, younger son of Mr.A
.Nice to meet you.
1------------------------------------------------->> This the count of B object modifying the data or in other words calling the foo()
2------------------------------------------------->>This is the count of C object modifying the data or in other words calling the foo()
C detor-------------|=>first C dies then B coz C is declared and Initiated at last
A dtor
B detor--------------|=>then B dies coz declared and Initiated first;
A dtor
*/
