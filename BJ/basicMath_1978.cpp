#include <bits/stdc++.h>
using namespace std;

int isPrime(int x){
    if(x == 1) return 0;
    for(int i = 2; i < x; i++)
        if(x % i == 0) return 0;
    return 1;
}

int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int test, N, result = 0;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &N);
        //if(isPrime(N)) result++;
        result += isPrime(N);
    }
    printf("%d", result);
    return 0;
}