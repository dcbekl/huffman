#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;

//获取最小的两位
void getTwoMin(HuffmanTree& HT, int n, int& s1, int& s2){ //拿到权值最小的两个值，其中s1<s2
	int min;

	//找第一个最小值
	for (int i = 1; i <= n; i++){
		if (HT[i].parent == 0)
		{
			min = i;
			break;
		}
	}

	for (int i = min + 1; i <= n; i++){
		if (HT[i].parent == 0 && HT[i].weight < HT[min].weight)
			min = i;
	}
	
	s1 = min; //第一个最小值给s1

	//找第二个最小值
	for (int i = 1; i <= n; i++){
		if (HT[i].parent == 0 && i != s1)
		{
			min = i;
			break;
		}
	}
	for (int i = min + 1; i <= n; i++){
		if (HT[i].parent == 0 && HT[i].weight < HT[min].weight && i != s1)
			min = i;
	}
	s2 = min; //第二个最小值给s2
}

//构建哈夫曼树
template <size_t size>
void CreateHuff(HuffmanTree& HT, int (&arr)[size]){

	int n = arr[size-2];
    int m = 2 * n - 1;  //哈夫曼树的总结点数
    HT = (HuffmanTree)calloc(m+1, sizeof(HTNode));  //下标为零的位置不存放数据
	HTnum = m + 1;

	int t = 1, sum = 0;

	//结点，添加权值
    for (int i = 0; i < size-2; i++){

		if(arr[i] != 0){
			// HT[t].weight = 1.0 * arr[i] / arr[size - 1];
			HT[t].weight = arr[i];
			HT[t].data = char(i);
			t++;
		}    	
    }

	for (int i = n + 1; i <= m; i++) //构建哈夫曼树
	{
		//选择权值最小的s1和s2，生成它们的父结点
		int s1, s2;
		getTwoMin(HT, i - 1, s1, s2); //在下标为1到i-1的范围找到权值最小的两个值的下标，其中s1的权值小于s2的权值
		HT[i].weight = HT[s1].weight + HT[s2].weight; //i的权重是s1和s2的权重之和
		HT[s1].parent = i; //s1的父亲是i
		HT[s2].parent = i; //s2的父亲是i
		HT[i].lc = s1; //左孩子是s1
		HT[i].rc = s2; //右孩子是s2
		HT[i].data = '@' ;
		HT[i].parent = 0;
	}
}

//生成哈夫曼编码
void HuffCoding(HuffmanTree& HT, HuffmanCode& HC, int n)
{
	HC = (HuffmanCode)malloc(sizeof(char*)*(n + 1)); //开n+1个空间，因为下标为0的空间不用
	HCnum = n + 1;
	char* code = (char*)malloc(sizeof(char)*n); //辅助空间，编码最长为n(最长时，前n-1个用于存储数据，最后1个用于存放'\0')
	code[n - 1] = '\0'; //辅助空间最后一个位置为'\0'

	for (int i = 1; i <= n; i++)
	{
		int start = n - 1; //每次生成数据的哈夫曼编码之前，先将start指针指向'\0'
		int c = i; //正在进行的第i个数据的编码
		int p = HT[c].parent; //找到该数据的父结点
		while (p) //直到父结点为0，即父结点为根结点时，停止
		{
			if (HT[p].lc == c) //如果该结点是其父结点的左孩子，则编码为0，否则为1
				code[--start] = '0';
			else
				code[--start] = '1';
			c = p; //继续往上进行编码
			p = HT[c].parent; //c的父结点
		}
		HC[i] = (char*)malloc(sizeof(char)*(n - start)); //开辟用于存储编码的内存空间
		HT[i].depth = n - start - 1;
		strcpy(HC[i], &code[start]); //将编码拷贝到字符指针数组中的相应位置
	}

	delete[] code; //释放辅助空间
}

void clearHT(HuffmanTree HT){

	free(HT);
}

void clearHC(HuffmanCode HC){

	for(int i = 1; i < HCnum; i++){

		free(HC[i]);
	}
}
#endif