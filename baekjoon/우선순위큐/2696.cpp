#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int T, N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int t=0;t<T;t++){
        cin >> N;
        priority_queue<int> maxHeap;
        priority_queue<int> minHeap;
        vector<int> ans;

        int x;

        for(int i=1;i<=N;i++){
            cin >> x;
            if(maxHeap.empty()){
                maxHeap.push(x);
            }
            else if(maxHeap.size()>minHeap.size()){
                int middle = maxHeap.top();
                if(x < middle){
                    maxHeap.pop();
                    maxHeap.push(x);
                    minHeap.push(-middle);
                }
                else{
                    minHeap.push(-x);
                }
            }
            else{
                int maxmiddle = maxHeap.top();
                int minmiddle = -minHeap.top();

                if(x < minmiddle){
                    maxHeap.push(x);
                }else{
                    minHeap.pop();
                    maxHeap.push(minmiddle);
                    minHeap.push(-x);
                }
            }
            if(i%2==1) ans.push_back(maxHeap.top());
        }
        cout << ans.size() << "\n";
        for(int a :ans){
            cout << a << " ";
        }
        cout << "\n";
    }

    return 0;
}
