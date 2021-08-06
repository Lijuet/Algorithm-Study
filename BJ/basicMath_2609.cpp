#include <bits/stdc++.h>
using namespace std;
int A, B;

int GCD(int x, int y){
    if(y == 0) return x;
    return GCD(y, x % y);
}

int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    scanf("%d %d", &A, &B);

    int gcd = GCD(A, B);
    printf("%d\n%d", gcd, A * B / gcd);

    return 0;
}