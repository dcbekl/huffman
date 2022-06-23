#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "huf.h"
#include "read.h"
#include "write.h"
#include "tools.h"
#include <iomanip>

using namespace std;

//压缩文件
void YS(){

    system("cls");

    string path;    //"../flowers.txt";

    cout << "请输入要压缩的文件路径：\n>> ";
    
    cin >> path;

    //判读文件是否成功打开
    if(!TongJi(path, PL)){

        cout << "文件打开失败！请检查文件路径是否正确...";

        return;
    }    

    Clear(HT, HTnum);
    Clear(HC, HCnum);

    CreateHuff(HT, PL);

    HuffCoding(HT, HC, PL[SIZE]); //构建哈夫曼编码

    double sum = 0.0;
    int k = 0;

    string inpath = FILEPATH + ".txt";
    writeYS(inpath, HT, HC, PL[SIZE]);

    cout << "文件压缩成功！" << endl;
}

//打印哈夫曼树中各结点之间的关系
void printTree()
{

    //控制台输出
    int m = PL[SIZE] * 2 - 1;
	printf("哈夫曼树为:>\n");
	printf("下标   权值     父结点   左孩子   右孩子\n");
    for (int i = 1; i <= m; i++)
	{
		printf("%-4d   %-6.7lf   %-6d   %-6d   %-6d    %c", i, HT[i].weight, HT[i].parent, HT[i].lc, HT[i].rc, HT[i].data);
        if(HT[i].data != '\n')
            cout << endl;
	}
	printf("\n");

    //写入文件
    ofstream of;
    string treePath = FILEPATH + ".tree";
    
    of.open(treePath, ios::out);

    if(!of.is_open()){
        cout << "文件输出失败！" << endl;
        return;
    }

    for (int i = 1; i <= m; i++)
	{
        of << setiosflags(ios::left);   //左对齐

        of << setw(4) << i << setw(14) <<  setprecision(7) << HT[i].weight << setw(6) << HT[i].parent << setw(6) << HT[i].lc
        << setw(6) << HT[i].rc << setw(6) << HT[i].data << endl;

	}

    of.close();
}

//打印哈夫曼表
void printTable(){

    //控制台输出
    int k = 0;
    for (int i = 1; i <= PL[SIZE]; i++) //打印哈夫曼编码
	{
		printf("数据%c的编码为:%s\n", HT[i].data, HC[i]);
        k++;
	}

    //写入文件
    ofstream of;
    string treePath = FILEPATH + ".table";
    
    of.open(treePath, ios::out);

    if(!of.is_open()){
        cout << "文件输出失败！" << endl;
        return;
    }

    k = 0;
   for (int i = 1; i <= PL[SIZE]; i++) //打印哈夫曼编码
	{
		of << "数据" << HT[i].data << "的编码为:" << HC[i] << endl;
        k++;
	}

    of.close();

    // for(int i = 1; i < HCnum; i++){

    //     cout << strlen(HC[i]) << endl;
    // }
}

//计算带权路径
void printWPL(){

    double WPL = 0.0;
    for(int i = 1; i <= PL[SIZE]; i++){

        WPL += HT[i].weight * HT[i].depth;
    }
    cout << "带权路径和：" << WPL << endl;
}

//解压缩
void JYS(){

    system("cls");

    string path;   

    cout << "请输入要解压缩的文件路径：\n>> ";
    
    cin >> path;

    ifstream inf;
    inf.open(path, ios::out);

    if(!inf.is_open()){

        cout << "文件解压缩失败！请检查文件路径是否正确...";

        return;
    } 

    string outpath = getFilePath(path) + "2" + ".txt";

    ofstream of;
    of.open(outpath, ios::out);

    clearQueue(queue);  //清空队列
    char buf;
    int sum = 0, ss = 0;

    buf = inf.get();ss++;

    //正式读取文件
    while(!inf.eof()){

        if(int(buf) >= -128 && int(buf) <= 127){
            
            sum ++;

            buf = (buf+256) % 256;

            E_In(queue, buf);

            while(queue->size > 20){

                buf = getC(queue);

                sum--;

                of << buf;
            }

        }else{  //中文，直接写入

            of << buf;
        }

        buf = inf.get();ss++;
    }

    // while(sum > 0){
    while(queue->size > 0){

        buf = getC(queue);

        sum--;

        of << buf;
    }

    // cout << "共读入：" << ss << endl;

    of.close();
    inf.close();
}

//退出系统
void Exit(){

    Clear(HT, HTnum);
    Clear(HC, HCnum);
    cout << "成功退出系统！" << endl;
    system("pause");
    exit(0);
}

#endif
// chcp 60051改变cmd解码的方式