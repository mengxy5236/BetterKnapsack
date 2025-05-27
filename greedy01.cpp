#include <iostream>
#include <vector>
#include <algorithm>
#include "greedy.h"

using namespace std;

//===============================================================

/*
    greedy.h��greedy01.cpp��01���������̰���㷨��֤;
	greedy.h������̰��ѡ����knapsackGreedy��
    ���뱳����������Ʒ�����������������ܼ�ֵ����Ʒѡ�������

*/

//===============================================================

struct Item {
    int index;
    int weight;
    int profit;
    double ratio; // profit / weight
};

// ̰��ѡ����
pair<int, vector<int>> knapsackGreedy(int capacity, const vector<int>& weights, const vector<int>& profits) {
    int n = weights.size();
    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        items[i] = { i, weights[i], profits[i], (double)profits[i] / weights[i] };
    }

    // ����λ��ֵ�Ӵ�С����
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
        });

    int totalValue = 0;
    vector<int> selected(n, 0);
    int remainingCapacity = capacity;

    for (int i = 0; i < n && remainingCapacity > 0; ++i) {
        if (items[i].weight <= remainingCapacity) {
            selected[items[i].index] = 1;
            totalValue += items[i].profit;
            remainingCapacity -= items[i].weight;
        }
    }

    return { totalValue, selected };
}
