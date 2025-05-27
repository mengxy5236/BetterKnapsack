#include <iostream>
#include <vector>
#include <algorithm>
#include "greedy.h"

using namespace std;

int main() {
    // ʾ�����ݣ�P0X��
    int capacity = 0;
    vector<int> weights ;
    vector<int> profits ;
	int n = 0;// ÿ����������

	cout << "���뱳����������ÿ����������(�ÿո�ָ�)��" << endl;
    cin >> capacity >> n;

    if (capacity < 0 || n <= 0) {
        cerr << "���������������������Ϸ���" << endl;
        return 1;
    }

	cout << "����ÿ�������Ȩ�أ��ÿո�ָ�����" << endl;
	for (int i = 0; i < n; ++i) {
		int weight;
		cin >> weight;
		weights.push_back(weight);
	}
	cout << "����ÿ������������ÿո�ָ�����" << endl;
	for (int i = 0; i < n; ++i) {
		int profit;
		cin >> profit;
		profits.push_back(profit);
	}

    pair<int, vector<int>> result = knapsackGreedy(capacity, weights, profits);
    int value = result.first;
    vector<int> selection = result.second;

    cout << "�ܼ�ֵ: " << value << endl;
    cout << "Ȩ�ص�����ѡ��: ";
    for (int sel : selection) {
        cout << sel << " ";
    }
    cout << endl;

    return 0;
}
