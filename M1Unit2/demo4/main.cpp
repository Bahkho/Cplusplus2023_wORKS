//Using Library Functions for String Validation in C++
//C++ provides functions we can use to determine whether specific characters are numbers or letters. The following functions are
//located in the cctype header:
//isalnum(int) Returns non-zero if the parameter is a letter or a digit
//isalpha(int) Returns non-zero if the parameter is a letter
//iscntrl(int) Returns non-zero if the parameter is a control character
//isdigit(int) Returns non-zero if the parameter is a digit
//isgraph(int) Returns non-zero if the parameter is printable character that is not whitespace
//isprint(int) Returns non-zero if the parameter is printable character (including whitespace)
//ispunct(int) Returns non-zero if the parameter is neither alphanumeric nor whitespace
//isspace(int) Returns non-zero if the parameter is whitespace
//isxdigit(int) Returns non-zero if the parameter is a hexadecimal digit (0-9, a-f, A-F)
//Note: When validating variable length inputs, the best way to validate strings (besides using a regular expression library) is to step
//through each character of the string (examples below)


// Character Validation as a String Example
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    bool rejected = false;
    string name;
    while(true)
    {
        cout << "Enter your name:";
        getline(cin,name);
        for(int i=0;i<name.length()&&!rejected;i++)
        {
            if(isalpha(name[i]))
                continue;
            if(name[i]==' ')
                continue;
            rejected = true; //otherwise reject
        }//end for
        if(!rejected)//input valid
        {
            cout << "Input is valid";
            break;
        }else{
            cout << "Input is NOT valid"<<endl;
            rejected = false;//reset
        }
    }//end while
    return 0;
}
//Numeric Validation as a String Example
//#include <iostream>
//#include <string>
//#include <cctype>
//#include <sstream>
//using namespace std;
//int main() {
//    string strAge;
//    int age;
//    stringstream ss;
//    bool valid = true;
//    while (1) {
//        cout << "Enter your age:";
//        cin >> strAge;
//        for (int i = 0; i < strAge.length(); i++) {
//            if (!isdigit(strAge[i])) {
//                valid = false;
//                cout << "Input is NOT valid" << endl;
//                break;//out of for loop
//            }
//            ss << strAge;//convert str to int
//            ss >> age;
//        }//end for
//        if (valid) {
//            cout << "Age is valid: " << age << endl;
//            break;//out of while loop
//        } else {
//            valid = true;
//        }
//    }//end while
//    return 0;
//}