#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	int m, n;
	int num;
	int cnt = 0;
	vector<int> v1, v2;
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		v1.push_back(num);
	}
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v2.push_back(num);
	}
 
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());
 
	if (v2[0] > v1[0]) {
		cout << -1 << "\n";
	}
	else {
		while (!v2.empty()) {
			int index = 0;
			for (int i = 0; i < v2.size(); i++) {
				if (index == v1.size()) {
					break;
				}
				if (v1[index] >= v2[i]) {
					index++;
					v2.erase(v2.begin() + i);
					i = i - 1;
				}
			}
			cnt++;
		}
		cout << cnt << "\n";
	}
}