#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
//     int num, factors[50];

//     scanf("%d", &num);

//     for(int i = 0; i < num; i++) scanf("%d", factors + i);
//     sort(factors, factors + num);

//     printf("%d\n", factors[0] * factors[num - 1]);

//     return 0;
// }

int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int num, answer;
    int* factors;

    scanf("%d", &num);
    factors = (int*)malloc(num * sizeof(int));
    /*
    엄청 큰 크기가 아닌 이상 그냥 static으로 할당하기
    */

    for(int i = 0; i < num; i++) scanf("%d", factors + i);
    sort(factors, factors + num);

    if(num % 2 == 0) answer = factors[num / 2 - 1] * factors[num / 2];
    else answer = pow(factors[num / 2], 2);
    /*
    맨 처음값과 끝값을 곱해도 같음. 중간일 필요 없음.
    */

    printf("%d\n", answer);

    return 0;
}