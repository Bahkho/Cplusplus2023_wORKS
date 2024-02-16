// Demo - Input Output

//#include <iostream>
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
//Demo of IO/Random/loop
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
//#include <conio.h>
using namespace std;
int main()
{
 string name;
 cout << "Please enter you full name: ";
 getline(cin, name);
 cout << "Hello " << name << ".\n";
// _getch();
 return 0;
}//end main

//int main()
//{
// string mystr;
// float price = 0;
// int quantity = 0;
//
// cout << "Enter price: ";
// getline(cin, mystr);
// //price = mystr; //conversion error str to float
// stringstream(mystr) >> price;
// cout << "Enter quantity: ";
// getline(cin, mystr);
// stringstream(mystr) >> quantity;
// cout << "Total cost: " << price * quantity <<endl;
// _getch();
// return 0;
//}//end main
//int main()
//{
//    srand(time(0));//send srand the time as a seed value
//    for (int i = 0; i < 100; i++)
//    {
////cout << i + 1 << " " << rand() << endl;//not scaled
//        cout << i + 1 << " " << 1 + rand() % 10 << endl;
//    }
//    _getch();
//    return 0;
//}