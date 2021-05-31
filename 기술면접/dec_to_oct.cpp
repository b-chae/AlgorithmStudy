/* 10진수를 8진수로 변환 */

void dec_to_oct(int n){
    if(n<8){
        cout << n;
        return;
    }

    dec_to_oct(n/8);
    cout << n % 8;
}