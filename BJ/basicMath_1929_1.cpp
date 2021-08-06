#include <bits/stdc++.h>
using namespace std;

int M, N;
char isNotPrime[1000001] = {1, 1};

void Eratos(){
    for(int x = 2; x <= sqrt(N); x++)
        for(int i = 2 * x; i <= N; i += x)
            isNotPrime[i] = 1;
}

int main(){
    scanf("%d %d", &M, &N);
    Eratos();
    for(int i = M; i <= N; i++) if(!isNotPrime[i]) printf("%d\n", i);
    return 0;
}