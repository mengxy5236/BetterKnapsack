#include <iostream>
#include <vector>
#include <algorithm>
#include "greedy.h"

using namespace std;

int main() {
    // 示例数据（P0X）
    int capacity = 0;
    vector<int> weights ;
    vector<int> profits ;
	int n = 0;// 每组对象的数量

	cout << "输入背包的容量与每组对象的数量(用空格分隔)：" << endl;
    cin >> capacity >> n;

    if (capacity < 0 || n <= 0) {
        cerr << "输入的容量或对象数量不合法。" << endl;
        return 1;
    }

	cout << "输入每个对象的权重（用空格分隔）：" << endl;
	for (int i = 0; i < n; ++i) {
		int weight;
		cin >> weight;
		weights.push_back(weight);
	}
	cout << "输入每个对象的利润（用空格分隔）：" << endl;
	for (int i = 0; i < n; ++i) {
		int profit;
		cin >> profit;
		profits.push_back(profit);
	}

    pair<int, vector<int>> result = knapsackGreedy(capacity, weights, profits);
    int value = result.first;
    vector<int> selection = result.second;

    cout << "总价值: " << value << endl;
    cout << "权重的最优选择: ";
    for (int sel : selection) {
        cout << sel << " ";
    }
    cout << endl;

    return 0;
}
