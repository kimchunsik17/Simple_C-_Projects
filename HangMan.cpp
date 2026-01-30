#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>

void clearScreen() {
    // \033[2J : 화면 전체 지우기
    // \033[1;1H : 커서를 맨 왼쪽 위(1,1)로 이동
    std::cout << "\033[2J\033[1;1H"; 
}

int getRnum(int max) { //max 이하 무작위 양의 정수 반환
    srand(time(NULL));
    int rint = rand() % max;
    return rint;
}

std::string getWord() { //dictionary로부터 word 출력
    std::ifstream in("hangman_resource/dictionary.txt");

    int rint = getRnum(8) + 1;

    std::string word;

    if(in.is_open()) {
        for(int i = 0; i < rint; i++) in >> word;
    } else std::cout << "\n파일이 존재하지 않습니다.\n";
    return word;
}

void printPicture(int idx) {
    std::ifstream in("hangman_resource/pictures/" + std::to_string(idx) + ".txt");

    if(!in.is_open()) std::cout << "\n파일이 존재하지 않습니다.\n";
    char buf[100];
    while(in) {
        in.getline(buf, 100);
        std::cout << std::endl;
        std::cout << buf;
    }
}

int readWord(const std::string& s, std::vector<char>& d, const int& size) {
    char input;
    int correct = 0;
    std::cin >> input;
    for(int i = 0; i < size; i++) {
        if(input == s[i]) {
            d[i] = input;
            correct++;
        } 
    }
    return correct;
}

void gameInit() {
    int count = 0; //진행도
    std::string word = getWord();
    int size = word.size();
    std::vector<char> display(size, '_');
    int cor_count = 0; //맞춘 개수;

    while(count <= 5 && cor_count < size) {
        printPicture(count);
        std::cout << "\nword : " + std::string(display.begin(), display.end());
        std::cout << "\ninput : ";

        int cor = readWord(word, display, size);

        clearScreen();
        std::cout << std::endl;
        if(cor > 0) std::cout << cor << " words found\n";
        else {
            std::cout << "0 word found\n";
            count++;
        }
        cor_count += cor;
        
    }

    if(cor_count == size) std::cout << "You won";
    else {
        std::cout << "Game Over";
        printPicture(5);
    } 
}

int main() {
    gameInit();
    std::cin.get();
}