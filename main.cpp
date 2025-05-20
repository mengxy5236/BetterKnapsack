#include <iostream>
#include <vector>
#include <algorithm>
#include "greedy.h"

using namespace std;

int main() {
    // ʾ�����ݣ�P01��
    int capacity = 165;
    vector<int> weights = { 23, 31, 29, 44, 53, 38, 63, 85, 89, 82 };
    vector<int> profits = { 92, 57, 49, 68, 60, 43, 67, 84, 87, 72 };

    pair<int, vector<int>> result = knapsackGreedy(capacity, weights, profits);
    int value = result.first;
    vector<int> selection = result.second;

    cout << "�ܼ�ֵ: " << value << endl;
    cout << "ѡ������: ";
    for (int sel : selection) {
        cout << sel << " ";
    }
    cout << endl;

    return 0;
}
