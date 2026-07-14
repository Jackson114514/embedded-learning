#pragma once
#include<iostream>
#include<vector>
using namespace std;
class mySort {
public:
	void printArr(vector<int>& vec);
public:
	//√∞≈›≈≈–Ú
	void BubbleSort(vector<int>& vec);
	//—°‘Ò≈≈–Ú
	void SeleteSort(vector<int>& vec);
	//≤Â»Î≈≈–Ú
	void InsertSort(vector<int>& vec);
	//œ£∂˚≈≈–Ú(Àı–°‘ˆ¡ø≈≈–Ú£©
	void ShellSort(vector<int>& vec);
	void ShellInsert(vector<int>& vec, int start, int gap);
	//º∆ ˝≈≈–Ú
	void CountSort(vector<int>& vec);
};