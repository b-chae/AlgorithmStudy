#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int> > stack;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    long long ans = 0;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (stack.empty())
        {
            stack.push_back(make_pair(x, 0));
        }
        else if (stack.back().first > x)
        {
            stack.push_back(make_pair(x, 0));
        }
        else
        {
            while(!stack.empty() && stack.back().first <= x){
                pair<int, int> d = stack.back();
                ans += d.second;
                stack.pop_back();
                if(!stack.empty()){
                    stack.back().second += d.second + 1;
                }
            }
            stack.push_back(make_pair(x, 0));
        }
    }

    while(!stack.empty()){
        pair<int, int> d = stack.back();
        ans += d.second;
        stack.pop_back();
        if(!stack.empty()){
            stack.back().second += d.second + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
