#include <iostream>
#include <string>
#include <cstring>

int main(){
    int N;
    std::string temp;

    getline(std::cin, temp);

    while(temp.length() > 0){
        N = std::stoi(temp);
        int cnt = 1, remain = 1 % N;

        while(remain != 0){
            cnt++;
            remain = (remain * 10 + 1) % N;
        }
        std::cout << cnt << "\n";
        getline(std::cin, temp);
    }

    return 0;
}