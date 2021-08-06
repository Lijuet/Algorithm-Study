#include <bits/stdc++.h>
using namespace std;
int test, N;
long long sumFactors[1000001] = { 0 };
long long result;

int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    scanf("%d", &test);

    for(int i = 1; i <= 1000000; i++){
        for(int j = 1; i * j <= 1000000; j++)
            sumFactors[i * j] += j;
    }
    for(int i = 1; i <= 1000000; i++) sumFactors[i] += sumFactors[i - 1];
    //Reduce the part repeated by extracting
    
    while(test--){
        scanf("%d", &N);
        printf("%lld\n", sumFactors[N]);
    }
    return 0;
}