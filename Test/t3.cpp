//测试分离文件路径

#include <iostream>
using namespace std;
string getFileName(string path);

//获取路径
string getFilePath(string path){

    int rear = 0;
    for(int i = path.size()-1; i >= 0; i--){

        if(path[i] == '.'){
            rear = i-1;
            break;
        }
    }

    int u = rear + 1;
    char ch[u]; 

    for(int i = 0; i < u; i++){

        ch[i] = path[i];
    }

    ch[u] = '\0';

    string fn = ch;

    return fn;
}

int main(){

    string inPath;
    string fileName;

    cout << "请输入文件路径：" << endl;

    cin >> inPath;

    fileName = getFilePath(inPath);

    cout << fileName << endl;

    return 0;
}

string getFileName(string path){

    int font = 0, rear = 0;
    for(int i = path.size()-1; i >= 0; i--){

        if(path[i] == '.'){
            rear = i-1;
        }

        if(path[i] == '\\' || path[i] == '/'){
            font = i+1;
            break;
        }
    }

    int u = rear - font + 1;
    char ch[u+1]; 

    for(int i = 0; i < u; i++){

        ch[i] = path[font++];
    }

    string fn = ch;

    return fn;
}
