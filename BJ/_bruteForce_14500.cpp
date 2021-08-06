#include <bits/stdc++.h>
using namespace std;

int map[500][500];
int N, M;

int main(){
    scanf("%d %d", &N, &M);
    
    //get map input

    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++)
            scanf("%d", &map[r][c]);

    
    return 0;
}