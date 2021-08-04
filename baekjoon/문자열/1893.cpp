#include <iostream>
#include <vector>
#include <map>

using namespace std;

int T;
string A, W, S;
int kmp[50000];
int ans[100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int t=0; t<T; t++){
        cin >> A >> W >> S;

        for(int i=0; i<A.length(); i++) ans[i] = 0;

        map<char, char> cmap;
        for(int i=0; i<A.length(); i++){
            cmap[A[i]] = A[(i+1)%A.length()];
        }

        for(int shift = 0; shift<A.length(); shift++){

            for(int i=0; i<W.length(); i++){
                kmp[i] = 0;
                if(shift != 0) W[i] = cmap[W[i]];
            }

            int j = 0;
            for(int i=1; i<W.length(); i++){
                while(j>0 && W[i] != W[j]){
                    j = kmp[j-1];
                }
                if(W[i] == W[j])
                    kmp[i] = ++j;
            }

            j=0;
            for(int i=0; i<S.length(); i++){
                while(j>0 && S[i] != W[j]){
                    j = kmp[j-1];
                }

                if(S[i] == W[j]){
                    if(j==W.length()-1){
                        ans[shift]++;
                        j = kmp[j];
                    }
                    else j++;
                }
            }
        }

        int count = 0;
        vector<int> ans_list;

        for(int i=0; i<A.length(); i++){
            if(ans[i]==1){
                count++;
                ans_list.push_back(i);
            }
            cout << ans[i] << " ";
        }

        if(count==0) cout << "no solution\n";
        else{
            if(count == 1) cout << "unique: " << ans_list[0] << "\n";
            else{
                cout << "ambiguous: ";
                for(int a:ans_list){
                    cout << a << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}