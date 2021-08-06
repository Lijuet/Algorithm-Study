#include <bits/stdc++.h>
using namespace std;

int N, maxCandy = 0;
char candyMap[50][50];

void countMaxCandy(){
    int cnt;

    for(int br = 0; br < N; br++){
        cnt = 1;
        for(int bc = 0, c = bc + 1; c < N; c++){
            if(candyMap[br][bc] == candyMap[br][c]){
                if(maxCandy < (++cnt)) maxCandy = cnt;
            }
            else{
                bc = c;
                cnt = 1;
            }
        }
    }

    for(int bc = 0; bc < N; bc++){
        cnt = 1;
        for(int br = 0, r = br + 1; r < N; r++){
            if(candyMap[br][bc] == candyMap[r][bc]){
                if(maxCandy < (++cnt)) maxCandy = cnt;
            } else{
                br = r;
                cnt = 1;
            }
        }
    }
}

void Bomboni(int r, int c, int _r, int _c){
    if((_r >= N) || (_c >= N)) return;

    
    swap(candyMap[r][c], candyMap[_r][_c]);
    countMaxCandy();
    swap(candyMap[r][c], candyMap[_r][_c]);
}
    
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        getchar();
        for(int j = 0; j < N; j++) scanf("%c", &candyMap[i][j]);
    }

    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            Bomboni(r, c, r + 1, c);
            Bomboni(r, c, r, c + 1);
        }
    }
    
    printf("%d\n", maxCandy);

    return 0;
}