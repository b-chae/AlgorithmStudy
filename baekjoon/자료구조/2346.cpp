#include <iostream>

using namespace std;

int N;

struct node{
    int n;
    int t;
    struct node* previous;
    struct node* next;
};

struct node list[1000];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        list[i].n = i+1;
    }
    for(int i=1; i<N; i++) list[i].previous = &list[i-1];
    for(int i=0; i<N-1; i++) list[i].next = &list[i+1];
    list[N-1].next = &list[0];
    list[0].previous = &list[N-1];

    int x;
    for(int i=0; i<N; i++){
        cin >> x;
        list[i].t = x;
    }

    struct node* now = &list[0];
    for(int i=0; i<N; i++){
        cout << now->n << " ";
        now->previous->next = now->next;
        now->next->previous = now->previous;
        int k = now->t;
        if(k>0){
            for(int j=0; j<k; j++){
                now = now->next;
            }
        }
        else{
            for(int j=0; j>k; j--){
                now = now->previous;
            }
        }
    }

    return 0;
}