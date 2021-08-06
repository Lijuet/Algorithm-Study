//https://www.acmicpc.net/problem/6588
#include <bits/stdc++.h>
using namespace std;

char isPrime[1000001];

void Eratos(){
    for(int x = 2; x <= 1000; x++)
        for(int i = 2 * x; i <= 1000000; i += x)
            isPrime[i] = 0;
}


int main(){
    int N, isGC;
    memset(isPrime, 1, 1000001);
    isPrime[0] = isPrime[1] = 0;

    Eratos();

    while(1){
        isGC = 0;
        scanf("%d", &N);
        if(N == 0) break;
        for(int i = 3; i <= N / 2; i+=2)
            if(isPrime[i] && isPrime[N - i]) {
                printf("%d = %d + %d\n", N, i, N - i);
                isGC = 1;
                break;
            } 

        if(!isGC) printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}