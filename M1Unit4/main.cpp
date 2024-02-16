//-------------------Demo - File IO & Streams
//Notes:
//To read input from a file, your program
//must first connect the file to a stream object.
//A stream is an abstraction that represents a device on which input and
//output operations are performed. The term stream is an abstraction of a
//construct that allows you to send or receive an unknown number of bytes.
//The metaphor is a stream of water. You take the data as it comes, or send
//it as needed. (source: www.cplusplus.com)
// << this is the insertion operator
// >> this is the extraction operator
// If you create a text file in the same directory as the cpp
// or in CMakeFiles directory in CLion so that the
// the compiler can find it. If you put it in any other
// way you will need to set the properties of the file
// so that the compiler will be aware of it.
//You must explicitly close files because they will be
//left open if your program terminates abnormally.
//In addition, you should use exception handling
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//prototypes
void demoOpenCloseStreams();
void demoOpenPrint();
void demoOpenWrite();
int main() {
    cout << "Begin fileIO Demonstration"<<endl;
// cout << "Begin Open Close Streams Demo"<<endl;
// demoOpenCloseStreams();
// cout << "Begin Open Print Demo"<<endl;
// demoOpenPrint();
    cout << "Begin Open Write Demo"<<endl;
    demoOpenWrite();
    cout << "End fileIO Demonstration"<<endl;
return 0;
}//end main
void demoOpenCloseStreams(){
    cout << "Files Open" << endl;
//declare stream objects
    ifstream inStream;
    ofstream outStream;
//connect files to stream objects
    inStream.open("infile.txt");
    outStream.open("outfile.txt");
//a shorter version of above
    ifstream inStream2("infile.txt");
//close resources
    inStream.close();
    outStream.close();
    inStream2.close();
    cout<<"Files closed"<<endl;
}
void demoOpenPrint(){
    string line;
    ifstream myFileIn;
//you may use either .fail() or the .is_open() method
//of the file stream object
    myFileIn.open("myFileIn.txt");
    if(myFileIn.is_open())//or if(myFileIn.fail
    {
        cout << "File Open" << endl;
        while(!myFileIn.eof()){
            getline(myFileIn,line);
            cout << line<<endl;
        }
        myFileIn.close();
        cout<<"File closed"<<endl;
    }else{
        cout << "Input file failed to open"<< endl;
    }
}//end method
void demoOpenWrite(){
    ofstream myFileOut;
//to append to a file - use ios::app
    myFileOut.open("myFileOut.txt",ios::app);//open for append
    if(!myFileOut.fail())//true if it does not fail
    {
        myFileOut << "stuff" << " and more stuff" << endl;
        myFileOut.close();
        cout << "File Closed"<< endl;
    }else{
        cout << "Output File failed to open" << endl;
    }
}