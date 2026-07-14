#include<iostream>
#include"mySort.h"
using namespace std;
int main() {
	vector<int>vec{ 20,40,30,10,60,50 };
	mySort ms;
	ms.CountSort(vec);
	ms.printArr(vec);
	return 0;
}