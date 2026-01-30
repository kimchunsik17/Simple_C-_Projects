#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int getRnum(int max) { //max 이하 무작위 양의 정수 반환
    srand(time(NULL));
    int rint = rand() % max;
    return rint;
}

bool isDigit(const string& s) { //입력받은 문자열이 숫자로만 구성됐는 여부 판단
    for(const char& c : s) {
        if('0' <= c && c <= '9') continue;
        return false;
    }
    return true;
}

bool gameInit() {
    //시작 메시지
    cout << "게임이 시작되었습니다.\n";
    cout << "100 이하의 숫자를 맞춰보세요.\n";

    //게임 변수 초기화
    string game_input;
    int user_answer;
    int com_answer = getRnum(100);

    while(true) {
        cout << "숫자를 입력하세요!\n입력 : ";
        cin >> game_input;
        if(!isDigit(game_input)) {
            cout << "숫자로 입력해주세요.\n";
            continue;
        }
        
        user_answer = stoi(game_input);

        if(user_answer < 0 || user_answer > 100) {
            cout << "올바른 숫자 범위를 초과하였습니다.\n";
            continue;
        }
        
        if(user_answer == com_answer) break; //정답시 세션 종료
        
        if(user_answer < com_answer) cout << "\n입력보다 큽니다.\n";
        else cout << "\n입력보다 작습니다.\n";
    }

    cout << "정답입니다!\n";
    cout << "게임을 재시작하시겠습니까?(Y) 입력 : ";

    string input;
    cin >> input;
    
    if(input.compare(input)) {
        return true;
    }
    return false;
}

int main() {
    bool isRestart = false;
    while(true) {
        if(gameInit()) break;
    }    
    return 0;
}