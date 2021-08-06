#include <bits/stdc++.h>
using namespace std;

int channel, numBroken, numDigit;
int original[6], smaller[6], bigger[6];
bool isBrokenNumber[10];

int main(){
    scanf("%d %d", &channel, &numBroken);
    
    while(numBroken--){
        int idx;
        scanf("%d", &idx);
        isBrokenNumber[idx] = true;
    }

    // Find the most similar number
    int temp = channel;
    for(int i = 0; i < 6; i++, temp /= 10){
        if(temp == 0) {
            numDigit = i;
            break;
        }
        original[i] = temp % 10;
    }

    for(int i = numDigit - 1; i >= 0; i--){
        
    }

    // Extract one

    // The most similar number's digit + difference


    return 0;
}