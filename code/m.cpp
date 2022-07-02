#include "menu.h"

int main(){

    char n;
    while(true){

        Menu();
        cin >> n;
        switch(n){
            case '1': YS(); break;          //1.压缩文件
            case '2': printTree(); break;   //2.打印哈夫曼树
            case '3': printTable();break;   //3.打印哈夫曼表
            case '4': printWPL();break;     //4.计算带权路径长度WPL
            case '5': compressRate(); break;//5.计算压缩比
            case '6': JYS(); break;         //6.解压缩文件
            case '7': Exit(); break;        //7.退出系统
            default: break;   
        }

        cout << endl;
        system("pause");       
    }

}