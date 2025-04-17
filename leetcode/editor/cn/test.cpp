#include <vector>
#include <queue>
#include "iostream"
using namespace std;
int main(){
    // lambda 函数用于定义比较规则，按照 pair 的第一个值降序排列
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    };

    // 创建降序的小根堆，并传入比较函数
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

    // 向小根堆中插入元素
    minHeap.push({3, 10});
    minHeap.push({1, 20});
    minHeap.push({2, 15});

    // 输出小根堆的顶部元素
    cout << "Top element of descending min heap: {" << minHeap.top().first << ", " << minHeap.top().second << "}\n";

    return 0;
}
