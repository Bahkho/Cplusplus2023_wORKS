//--------------------Demo - Namespaces
//a namespace is a collection of class definitions and variable declarations
// (aka name definitions). The std namespace contains all the names
//defined in many standard C++ library files such as <iostream>. #include
//<iostream> places all the name definitions for names such as cin and cout into
//the std namespace. You must use the 'using namespace' directive to establish
// the link between your program and the definitions you have placed in it.
#include <iostream>
//#include <conio.h>
using namespace std;
namespace NS1{int square(int num);}
namespace NS2{int square(int num);}
int main()
{
    int answer = 0;
//example of single use of NS1::square()
    {
        using namespace NS1;
        answer = square(3);
        cout << "NS1 answer is: " << answer << endl;
    }
    {
        using namespace NS2;
        answer = square(3);
        cout << "NS2 answer is: " << answer << endl;
    }
//    _getch();
    return 0;
}//end main
namespace NS1
{
    int square(int num)
    {
        return num * num;
    }
}
namespace NS2
{
    int square(int num)
    {
        return num * num + 42;
    }
}