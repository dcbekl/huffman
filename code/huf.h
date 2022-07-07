#ifndef __huf_H__
#define __huf_H__
#include <iostream>
#define SIZE 128
#define QUEUEMAXLEN 100
using namespace std;

typedef struct HTNode
{
    char data;  //数据
    int weight; //权值
    int parent; //父节点
    int lc, rc; //左右子节点
    int depth;
}node, *HuffmanTree;

typedef char **HuffmanCode; //字符指针数组中存储的元素类型

typedef struct QueueNode
{
    char data[QUEUEMAXLEN];

    int front = 0;
    int rear = 0;

    int size = 0;
}seqQueue;

int SUM = 0;
int YSUM = 0;
seqQueue *queue = new seqQueue;
//入队
void enQuene(seqQueue *queue, char x){

    if(queue->front == (queue->rear+1) % QUEUEMAXLEN )
        return;

    queue->rear = (queue->rear + 1) % QUEUEMAXLEN;

    queue->data[queue->rear] = x;

    queue->size++;
}

//出队
char outQuene(seqQueue *queue){

    if(queue->front == queue->rear)
        return '0'; 

    queue->front = (queue->front + 1) % QUEUEMAXLEN;

    queue->size--;

    return queue->data[queue->front];
}

//清空队列
void clearQueue(seqQueue *queue){

    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

int PL[SIZE+2] = {0};      //权重， 最后两位分别代表权重非零的个数，和PL总和
HuffmanTree HT;
HuffmanCode HC;
int HTnum = 0;     
int HCnum = 0;
string FILENAME;
string FILEPATH;


void Menu(){

    system("cls");
    cout << "**************哈夫曼压缩与解压缩系统****************" << endl;
    cout << "1.压缩文件" << endl;
    cout << "2.打印哈夫曼树" << endl;
    cout << "3.打印哈夫曼表" << endl;
    cout << "4.计算带权路径长度WPL" << endl;
    cout << "5.计算文本的压缩比" << endl;
    cout << "6.解压缩文件" << endl;
    cout << "7.退出系统" << endl;
    cout << ">> ";
}

#endif
