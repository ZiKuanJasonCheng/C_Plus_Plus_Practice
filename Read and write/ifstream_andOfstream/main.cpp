//
//  main.cpp
//  ifstream_and_ofstream
//
//
// http://math.hws.edu/eck/cs225/s03/files_and_strings.html

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    // string
    cout << "Enter a sentence:\n";
    string str;
    cin >> str;  // str will skip leading spaces and only store the first word ending with a last character before a space
    cout << "str=" << str << endl;
    // To read the whole sentence, use getline(cin, str). This will read everything from cin up to and including the next end-of-line character and store the result (without the end-of-line) in str.
    getline(cin, str);  // To absorb the previous \n character
    cout << "(absorb the previous \\n character) str=" << str << endl;
    cout << "Next input:" << endl;
    getline(cin, str);
    cout << "str=" << str << endl;
    
    // ifstream and ofstream
    int x;
    ifstream in;    // Create an input file stream.
    string filename="input.txt";
    in.open(filename);  // Use it to read from a file named data.txt.
    if (!in) {
        cout << "Error: Can't open the file named " << filename << endl;
        exit(1);
    }
    in >> x;    // Read the first item from the file into an integer variable x.
    in >> str;  // Read the next item from the file into a string variable str.
    cout << "x=" << x << endl;
    cout << "str=" << str << endl;
    ifstream in2;
    // Read the entire line until the end of file
    filename="input2.txt";
    
    in2.open(filename);  // Use it to read from a file named data.txt.
    if (!in2) {
        cout << "Error: Can't open the file named " << filename << endl;
        exit(1);
    }
    //getline(in,str);  // Get the first line from the file, if any.
    getline(in2,str);  // Get the first line from the file, if any.
    while (in2) {  // Continue if the line was sucessfully read.
        cout << "str=" << str << endl;
        getline(in2,str);   // Try to get another line.
    }
    cout << "str=" << str << endl; // This will print the last line repeatedly
    
    // Write something to a file
    ofstream out;
    filename="output.txt";
    out.open(filename);
    //out.open(filename,ios::noreplace);  // If the file exists, the program will fail. ios::noreplace is part of a MS run-time library. https://stackoverflow.com/questions/44999606/what-is-the-difference-between-iosapp-and-iosnoreplace-modes-in-file-handlin
    out << "Write something about it." << endl;
    out << "Go through the next line." << endl;
    
    // Append the file
    ofstream out2;
    filename="output.txt";
    out2.open(filename, ios::app);
    out2 << "You can append contents to the bottom of the file." << endl;
    out2 << "That's it." << endl;
    
    // Enter a output file name to write something to the file
    ofstream out3;
    cout << "Please enter the output file name, including extension (.txt):";
    cin >> filename;
    out3.open( filename.c_str() );
    out3 << "Add new contents" << endl;
    out3 << "blablabla" << endl;

    return 0;
}
