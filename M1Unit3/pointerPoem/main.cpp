#include <iostream>
#include <string>
using namespace std;

int main() {
                //POINTER TERMINOLOGY
        //use * to declare a pointer variable
        //also use * as the dereference operator
        //use & as the 'address of operator
        //use -> as the arrow operator - means points to used in obj
//-------------------------------------------------------------------------------
        string phrase1 = "I woz here.\n";
        string phrase2 = "Here I Woz.\n";
        string phrase3 = "Woz I here?.\n";
        string phrase4 = "Yes I woz!\n";
//-------------------------------------------------------------------------------
        cout<<phrase1 + phrase2 + phrase3 + phrase3 + phrase4 << endl;
        cout<<&phrase1<<endl;  //address of phrase1 VARIABLE
//-------------------------------------------------------------------------------
        string *p1;   //declarative operator
        string *p2;   //declarative operator
        string *p3;   //declarative operator

        p1 = &phrase1;//make point to phrase1
        p2 = &phrase2;//make point to phrase2
        p3 = &phrase3;//make point to phrase3

        string  *p4 = &phrase4;//declare and seat at the same time
//-------------------------------------------------------------------------------
        cout<<p1<<endl; //value of p1
        cout<<*p1<<endl; //deref p1
        cout<<*p1 + *p2 + *p3 + *p4 << endl; //deref entire poem
        cout<<&p1<<endl; //address of pointer variable
        p1 = p4; //re-assigning p1 to the value of p4
        cout<<*p1 + *p2 + *p3 + *p4 << endl; //deref entire poem
//-------------------------------------------------------------------------------
        //string  x = p1 + p2; //cant add mem address's
        string y = *p1 + *p2; //concat 1st and 2nd lines of poem
        cout << y << endl;
//-------------------------------------------------------------------------------
        int *pNless; //declared point to int called pNless
        pNless = new int; //allocate mem on heap. points to a dynamic var(aka nameless)
        *pNless = 42;//assign an int to nameless mem location
        cout << *pNless << endl;
//      int *pN2 = new int(7); //nameless on one line


    return 0;
}
