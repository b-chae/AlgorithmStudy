#include <cmath>
using namespace std;

int gcd(int a, int b){
    if(a < b) swap(a, b);
    
    while(b!=0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

long long solution(int w, int h) {
    long long answer = 1;
    
    answer = (long long)w*h - (w+h-gcd(w,h));
    
    return answer;
}
