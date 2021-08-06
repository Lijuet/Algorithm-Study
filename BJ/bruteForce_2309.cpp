#include <bits/stdc++.h>
using namespace std;
int main(){
    int dwarfHeights[9], sum = 0, totalHeight = 0, i, j;

    for(int i = 0; i < 9; i++) {
        scanf("%d", dwarfHeights + i);
        totalHeight += dwarfHeights[i];
    }

    sort(dwarfHeights, dwarfHeights + 9);

    for(i = 8; i > 0; i--){
        for(j = i - 1; j >= 0; j--){
            sum = totalHeight - (dwarfHeights[i] + dwarfHeights[j]);
            if(sum == 100) break;
        }
        if(sum == 100) break;
    }

    for(int k = 0; k < 9; k++){
        if((k == i) || (k == j)) continue;
        printf("%d\n", dwarfHeights[k]);
    }

    return 0;
}