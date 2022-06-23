# include<iostream>
using namespace std;

void E_In(char ch){

    int sum = int(ch);
    if(sum < 0)
        sum += 256;

    cout << "(" << sum << ")";
    int n, chu = 128;

    for(int i = 8; i > 0; i--){

        n = sum / chu;
        cout << char(n + '0');
        sum -= n*chu;
        chu /= 2;
    }
}

int main(){

    char buf ;

    while(buf != 'a'){

        cout << ">>>";
        cin >> buf;

        E_In(buf);
    }

}