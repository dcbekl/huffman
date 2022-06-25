#ifndef __READ_H__
#define __READ_H__

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string getFileName(string path);
string getFilePath(string path);

template<size_t size>       
bool TongJi(string path, int (&arr)[size]){ //数组长度

    ifstream f;
    f.open(path, ios::in);

    if(!f.is_open()){

        cout << "File open failed!!!";
        f.close();
        return false;
    }

    //清除影响
    for(int i = 0; i < SIZE+2; i++)
        PL[i] = 0;

    FILENAME = getFileName(path);
    FILEPATH = getFilePath(path);

    char buf;
    int n;

    while(f.good()){

        buf = f.get();
        
        n = buf;
        if( n >= 0 && n < size-2){

            if(arr[n] == 0)
                arr[size-2] ++;    //数组的非零项加一
                
            arr[n]++;

            arr[size-1]++;      //求数组和++

        }
    }

    f.close();

    return true;
}

//获取文件名
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


//字符转成八位二进制,然后入队
void E_In(seqQueue *queue, char ch){

    int sum = int(ch);
    if(sum < 0)
        sum += 256;

    int n, chu = 128;

    for(int i = 8; i > 0; i--){

        n = sum / chu;
        enQuene(queue, char(n + '0'));
        sum -= n*chu;
        chu /= 2;
    }
}

//从队列中读出一个字符
char getC(seqQueue *queue){

    char ch[20];
    int i, j ,k;
    char res = 'a';

    for(i = 0; i < 20; i++){

        ch[i] = outQuene(queue);
        cout << ch[i];

        res = '\0';
        for(j = 1; j < HCnum; j++){     

            res = 'a';
            for(k = 0; k < strlen(HC[j]); k++){

                if(ch[k] != HC[j][k]){

                    res = '\0';
                    break;
                }
            }
            if(res != '\0'){

                res = HT[j].data;
                break;
            }
        }
        if(res != '\0')
            break;
    }

    ch[i+1] = '\0';

    return res;
}
#endif