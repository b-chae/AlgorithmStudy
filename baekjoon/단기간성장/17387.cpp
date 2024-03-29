#include <iostream>

using namespace std;

int CCW(int x1, int y_1, int x2, int y2, int x3, int y3)
{
    long long area = (long long)x1 * y2 + (long long)x2 * y3 + (long long)x3 * y_1 - (long long)x1 * y3 - (long long)x3 * y2 - (long long)x2 * y_1;
    if (area < 0)
        return -1;
    if (area == 0)
        return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1, y_1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y_1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int res1 = CCW(x1, y_1, x2, y2, x3, y3);
    int res2 = CCW(x1, y_1, x2, y2, x4, y4);
    int res3 = CCW(x3, y3, x4, y4, x1, y_1);
    int res4 = CCW(x3, y3, x4, y4, x2, y2);

    if(res1==0 && res2==0 && res3==0 && res4==0){
        if(x1>x2){
            swap(x1, x2);
            swap(y_1, y2);
        }
        if(x3>x4){
            swap(x3, x4);
            swap(y3, y4);
        }
        if(x1>x3){
            swap(x1, x3); swap(y_1, y3); swap(x2, x4); swap(y2, y4);
        }

        if(x1==x2 && x2==x3 &&x3==x4){
            if(y_1>y2) swap(y_1, y2);
            if(y3>y4) swap(y3, y4);
            if(y_1>y3){
                swap(y_1, y3);
                swap(y2, y4);
            }
            if(y3>=y_1&&y3<=y2){
                cout << "1\n";
                return 0;
            }
            else{
                cout << "0\n";
                return 0;
            }
        }

        if(x3>=x1&&x3<=x2){
            cout << "1\n";
            return 0;
        }
    }
    else{
        if(res1*res2<=0 && res3*res4<=0){
            cout << "1\n";
            return 0;
        }
    }

    cout << "0\n";
    return 0;
}
