#include <string>
#include <vector>
#include <stdlib.h>>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    //char keypad[4][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'}, {'*','0','#'} };
    int keypad[10][2] = { {3,1 }, { 0,0 }, { 0,1 }, { 0,2 }, { 1,0 }, { 1,1 }, { 1,2 }, { 2,0 }, { 2,1 }, { 2,2 }
};
    int leftHand[2] = { 3,0 };
    int rightHand[2] = { 3,2 };
    int leftDistance;
    int rightDistance;
    int a, b;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer.push_back('L');
            leftHand[0] = keypad[numbers[i]][0];
            leftHand[1] = keypad[numbers[i]][1];

        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer.push_back('R');
            rightHand[0] = keypad[numbers[i]][0];
            rightHand[1] = keypad[numbers[i]][1];
        }
        else {
            a = keypad[numbers[i]][0];
            b = keypad[numbers[i]][1];
            leftDistance = abs(leftHand[0] - a) + abs(leftHand[1] - b);
            rightDistance = abs(rightHand[0] - a) + abs(rightHand[1] - b);
            if (leftDistance > rightDistance) {
                answer.push_back('R');
                rightHand[0] = a;
                rightHand[1] = b;
            }
            else if (leftDistance == rightDistance) {
                if (hand == "right") {
                    answer.push_back('R');
                    rightHand[0] = a;
                    rightHand[1] = b;
                }
                else {
                    answer.push_back('L');
                    leftHand[0] = a;
                    leftHand[1] = b;
                }
            }
            else {
                answer.push_back('L');
                leftHand[0] = a;
                leftHand[1] = b;
            }

        }
    }

    return answer;
}

int main() {
    vector<int> numbers;
    //	[7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], "left"
    numbers.push_back(7);    
    numbers.push_back(0);    
    numbers.push_back(8);    
    numbers.push_back(2);
    numbers.push_back(8);
    numbers.push_back(3);
    numbers.push_back(1);
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(6);
    numbers.push_back(2);
    solution(numbers, "left");
}