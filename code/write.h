#ifndef __WRITE_H__
#define __WRITE_H__

#include <iostream>
#include <string>
#include <fstream>
#include "huf.h"
#include <string>
using namespace std;

int isExist(HuffmanTree HT, char buf, int n);
char E_Out(seqQueue *queue);

//输出压缩文件
void writeYS(string inputPath, HuffmanTree HT, HuffmanCode HC, int n){

    cout << inputPath << endl;
    ifstream rf;
    rf.open(inputPath, ios::in);

    //文件打开失败
    if(!rf.is_open()){    

        cout << "Error! File open failed" << endl;
    }

    string path = FILEPATH + ".huf";
    
    ofstream of(path, ios::out | ios::binary);;

    if(!of.is_open()){ //

        cout << "文件压缩失败！" << endl;
        return;
    }

    SUM = 0;
    YSUM = 0;
    char buf;
    string line;
    int m;

    clearQueue(queue);
    buf = rf.get();
    while(!rf.eof()){

        m = isExist(HT, buf, n);

        //如果是中文
        if(!m){

            SUM++;
            of.write((char *)&buf, sizeof(char));
            buf = rf.get();
            continue;
        }
        
        //如果不是中文
        if(m){   

            SUM ++;
            for(int i = 0; i < strlen(HC[m]); i++){

                enQuene(queue, HC[m][i]);
            }

            //队列中数据量不足，可能出现读不出8位
            if(queue->size < 10){ 
                
                buf = rf.get();
                continue;
            }

            buf = E_Out(queue);
        }

        of.write((char *)&buf, sizeof(char));

        buf = rf.get();
    }

    //最后不够八位，后位补零
    while(queue->size > 0){

        buf = E_Out(queue);
        of.write((char *)&buf, sizeof(char));
    }

    rf.close();
    of.close();
}

//弹出八个
char E_Out(seqQueue *queue){

    int sum = 0;
    char ch;

    for(int i = 0; i < 8; i++){

        ch = outQuene(queue);

        cout << ch;

        sum *= 2;
        sum += ch - '0';
    }

    ch = char(sum);

    YSUM ++;

    return char(sum);
}

int isExist(HuffmanTree HT, char buf, int n){

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(buf == HT[i].data){

            res = i;
            break;
        }
    }

    return res;
}

#endif