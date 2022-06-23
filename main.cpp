#include "huf.h"
#include "read.h"
#include "tools.h"
#include "write.h"
#define SIZE 128
//chcp 65100; g++ main.cpp -o main.exe; ./main.exe  编译加运行
int main(){

    // while()
    string path = "../flowers.txt";
    int PL[SIZE+2] = {0};      //权重， 最后两位分别代表权重非零的个数，和PL总和

    if(TongJi(path, PL)){

        cout << "成功！\n";
    } 

    HuffmanTree HT;
    CreateHuff(HT, PL);
    //region
    // for(int i = 0; i < 128; i++){
    //     if(PL[i] > 0){
    //         cout << char(i) << "  " << 1.0 * PL[i] / PL[SIZE+1] << endl;
    //     }
    // }
    cout << "总项数： " << PL[SIZE] << endl;

    HuffmanCode HC;
    HuffCoding(HT, HC, PL[SIZE]); //构建哈夫曼编码

    double sum = 0.0;
    int k = 0;


    //region
	// for (int i = 1; i <= PL[SIZE]; i++) //打印哈夫曼编码
	// {
	// 	printf("数据%c的编码为:%s\n", HT[i].data, HC[i]);
    //     sum += HT[i].weight;
    //     cout << k + 1 << "&&" << sum << endl;
    //     k++;
	// }  
    // for(int i = 1; i <= 2 * PL[SIZE] - 1; i++){
    //     cout << HT[i].weight << "  ";
    // }

    writeYS("../flowers.txt", HT, HC, PL[SIZE]);
    cout << "发生什么事了！\n";
    // for(int i = 1; i <= PL[SIZE]; i++){

    //     cout << HT[i].data + "$$" ;
    //     printf("%s\n", HC[i]);
    // }

    Clear(HT);
    Clear(HC);
    system("pause");
    return 0;
}