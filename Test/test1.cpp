// 分离路径的核心路径
#include <iostream>
using namespace std;

void print(int *p, int n);
int main (){

    int *p = (int*) malloc (sizeof (int) * 5);

    for(int i = 0; i < 5; i++){

        p[i] = 2 * i + 1;
    }

    print(p, 5);

    int *q;
    for(int i =0; i < 5; i++){
        q = p;

        p++;

        delete q;    
    }

    print(p, 5);

    return 0;
}

void print(int *p, int n){

    for(int i = 0; i < n; i++){

        cout << p[i] << " ";
    }
    cout << endl;
}