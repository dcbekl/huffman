//打印128-255号ascll码对应的值

#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;

int main(){

    ofstream fs;
    fs.open("tt.txt", ios::out);

    for(int i = 150; i < 170; i++)
        fs << char(i);

    fs << endl;

    fs.close();

    ifstream is;
    is.open("tt.txt", ios::in);

    while(is.good()){

        cout << int(is.get());
    }

    is.close();

    return 0;
}