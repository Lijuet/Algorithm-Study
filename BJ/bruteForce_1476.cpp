#include <bits/stdc++.h>
using namespace std;

int E, S, M, i;

int main(){
    scanf("%d %d %d", &E, &S, &M);
    i = E;

    while(true){
        if(i % 28 == S % 28 && i % 19 == M % 19) break;
        i += 15;
    }

    printf("%d\n", i);

    return 0;
}