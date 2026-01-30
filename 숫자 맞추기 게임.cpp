#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int getRnum(int max) { //max 이하 무작위 양의 정수 반환
    srand(time(NULL));
    int rint = rand() % max;
    cout << rint;
}

void gameInit() {
    
}

int main() {
    

    return 0;
}