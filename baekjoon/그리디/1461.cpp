#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> positive;
vector<int> negative;
int answer = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int x;
    for(int i=0; i<N; i++){
        cin >> x;
        if(x<0) negative.push_back(x);
        else positive.push_back(x);
    }

    sort(negative.begin(), negative.end());
    sort(positive.begin(), positive.end());

    int ps = 0, ns = 0;
    int pn = positive.size()-1;
    int nn = negative.size()-1;

    // ns nn ps pn
    if(negative.empty() || (!positive.empty() && positive[pn] > -negative[0])){
        answer += positive[pn];
        pn -= M;
    }
    else{
        answer -= negative[ns];
        ns += M;
    }

    while(ns <= nn){
        answer -= negative[ns]*2;
        ns += M;
    }

    while(ps <= pn){
        answer += positive[pn]*2;
        pn -= M;
    }

    cout << answer << "\n";

    return 0;
}