#include <bits/stdc++.h>
#define MAX 100
#define NIL -1
using namespace std;


class Fibo{
    int lookup[MAX];
public:
    Fibo() {
        for(int i = 0; i < MAX; i++) lookup[i] = NIL;
    }

    int cal_TopDown(int n){
        if(lookup[n] = NIL){
            if(n <= 1) lookup[n] = n;
            else lookup[n] = cal_TopDown(n - 1) + cal_TopDown(n - 2);
        }
        return lookup[n];
    }

    int cal_BottomUp(int n){
        int memo[2] = {0, 1};

        for(int i = 2; i <= n; i++)
            memo[i % 2] = memo[(i - 1) % 2] + memo[(i - 2) % 2];
        
        return memo[n % 2];
    }
};

int main(int argc, char** argv){
    Fibo fibo;
    cout << fibo.cal_TopDown(atoi(argv[1])) << endl;
    cout << fibo.cal_BottomUp(atoi(argv[1])) << endl;
}