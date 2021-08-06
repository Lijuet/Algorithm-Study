#include <bits/stdc++.h>
using namespace std;

int isPrime(int x){
    if(x == 1) return 0;
    for(int i = 2; i <= sqrt(x); i++)
        if(x % i == 0) return 0;
    return 1;
}

int main(){
    int M, N;
    scanf("%d %d", &M, &N);

    for(int i = M; i <= N; i++) if(isPrime(i)) printf("%d\n", i);

    return 0;
}