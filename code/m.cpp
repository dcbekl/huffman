#include "menu.h"

int main(){

    char n;
    while(true){

        Menu();
        cin >> n;
        switch(n){
            case '1': YS(); break;   //1.压缩文件
            case '2': printTree(); break;   //2.打印哈夫曼树
            case '3': printTable();break;   //3.打印哈夫曼表
            case '4': printWPL();break;   //4.计算带权路径长度WPL
            case '5': JYS(); break;  //5.解压缩文件
            case '6': Exit(); break;   //6.退出系统
            default: break;
        }

        cout << endl;
        system("pause");       
    }

}