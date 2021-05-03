#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Delivery {
public:
    int from;
    int to;
    int cnt;
    Delivery(int from, int to, int cnt) {
        this->from = from;
        this->to = to;
        this->cnt = cnt;
    }
};
 
bool cmp(Delivery a, Delivery b) {
    if (a.to < b.to) return true;
    else return false;
}
 
int main(void) {
    int n, c, m;
    cin >> n >> c >> m;
    vector<Delivery> list;
    vector<int> left(n + 1, c);
    int box_cnt = 0;
    for (int i = 0; i < m; i++) {
        int from, to, cnt;
        cin >> from >> to >> cnt;
        list.push_back(Delivery(from, to, cnt));
    }
    sort(list.begin(), list.end(), cmp);
    
    for (auto d : list) {

        int min = left[d.from];
        for (int i = d.from + 1; i < d.to; i++) {
            if (min > left[i]) min = left[i];
        }

        int cnt = d.cnt;
        if (min < cnt) cnt = min;
 
        box_cnt += cnt;
 
        for (int i = d.from; i < d.to; i++) {
            left[i] -= cnt;
        }
    }
    cout << box_cnt;
    return 0;
}
