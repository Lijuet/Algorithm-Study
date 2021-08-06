#include <bits/stdc++.h>
using namespace std;
int N;
long long result = 0;
int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++) result += i * (N / i);

    printf("%lld", result);
    return 0;
}
