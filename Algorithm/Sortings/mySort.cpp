#include"mySort.h"
#include<algorithm>
void mySort::printArr(vector<int>& vec) {
	for (auto& i : vec) cout << i << " ";
}
void mySort::BubbleSort(vector<int>& vec)
{
	for (int j = vec.size() - 1; j >= 1; j--) {
		bool flag = true;//优化
		for (int i = 0; i < j; i++) {
			if (vec[i] > vec[i + 1]) {
				swap(vec[i], vec[i + 1]);
				flag = false;
			}
		}
		if (flag) break;
	}

}
void mySort::SeleteSort(vector<int>& vec){
	//时间复杂度（平均）：O(n2)
	//空间复杂度：O（1）；
	//稳定性：不稳定；
	for (int i = 0; i < vec.size(); i++) {
		int minindex = i;
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[j] < vec[minindex]) {
				minindex = j;
			}
		}
		swap(vec[i], vec[minindex]);
	}
}
void mySort::InsertSort(vector<int>& vec) {
	//时间复杂度：O(n^2)
	//空间复杂度：O(1)
	//稳定性：稳定
	for (int j = 1; j <= vec.size() - 1; j++) {
		//构造无序区
		for (int i = 0; i < j; i++) {
			//构造有序区
			if (vec[j] < vec[i]) {
				int tmp = vec[j];
				for (int k = j - 1; k >= i; k--) {
					vec[k + 1] = vec[k];
				}
				vec[i] = tmp;
				break;
			}
		}
	}
}
void mySort::ShellInsert(vector<int>& vec, int start, int gap) {
	for (int j = start+gap; j <= vec.size() - 1; j+=gap) {
		//构造无序区
		for (int i =start; i < j; i+=gap) {
			//构造有序区
			if (vec[j] < vec[i]) {
				int tmp = vec[j];
				for (int k = j - gap; k >= i; k-=gap) {
					vec[k + gap] = vec[k];
				}
				vec[i] = tmp;
				break;
			}
		}
	}
}

	void mySort::ShellSort(vector<int>& vec) {
		for (int gap = vec.size() / 2; gap >= 1; gap /= 2) {
			for (int i = 0; i < gap; i++) {
				ShellInsert(vec, i, gap);
			}
		}
	}
	void mySort::CountSort(vector<int>& vec) {
		//先找最大值
		int maxx = *max_element(vec.begin(), vec.end());
//根据最大值开辟计数数组
		int* countArr = new int[maxx + 1]();//加（）全部初始化为0
		//将源数据放入新数组中并计数
		for (int i = 0; i < vec.size(); i++) {
			countArr[vec[i]]++;//统计vec[i]中出现的次数
		}
		vec.clear();
		//按照下标依次取出计数数组的下标
		for (int i = 0; i <=maxx; i++) {
			while (countArr[i]) {
				vec.push_back(i);
				countArr[i]--;
			}
		}
		delete[]countArr;//new对应delete，new[]对应delete[]
	}
