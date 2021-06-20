#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

string fourStep(string new_id) {
    string str="";
    if (new_id[0] == '.') {
        if (new_id.size() == 1) return str;
        for (int i = 1; i < new_id.size(); i++) {
            str.push_back(new_id[i]);
        }
    }
    else if (new_id[new_id.size() - 1] == '.') {
        for (int i = 0; i < new_id.size() - 1; i++) {
            str.push_back(new_id[i]);
        }
    }
    return  str;
}
string solution(string new_id) {
    string answer = "";
    //1
    for (int i = 0; i < new_id.size(); i++){
        new_id[i] = tolower(new_id[i]); //소문자를 대문자로 교환.
    }
    //2
    string str = "";
    for (int i = 0; i < new_id.size(); i++) {
        int ascii = ('z' - new_id[i]);// 76 77 27
        if (ascii >= 0 && ascii <= 25) {
            str.push_back(new_id[i]);
        }
        else if (ascii == 76 || ascii == 77 || ascii == 27) {
            str.push_back(new_id[i]);
        }
        else if (ascii > 65 && ascii < 74) {
            str.push_back(new_id[i]);
        }
    }
    new_id = "";
    new_id = str;
    //3
    str = "";
    int flag = 0;
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.') {
            if (flag != 1){
                str.push_back(new_id[i]);
            }
            flag = 1;
        }
        else {
            flag = 0;
            str.push_back(new_id[i]);
        }
    }
    new_id = "";
    new_id = str;
    str = "";

    //4
    while (new_id[0] == '.' || new_id[new_id.size() - 1] == '.') {
       string str = fourStep(new_id);
       new_id = "";
       new_id = str;
       if (new_id == "") break;
    }
 
    //5
    if (new_id == "") {
        new_id = "a";
    }
    
    //6
    str = "";
    if (new_id.size() >= 16) {
        for (int i = 0; i < 15; i++) {
            str.push_back(new_id[i]);
        }
    new_id = "";
    new_id = str;
    }

    while (new_id[0] == '.' || new_id[new_id.size() - 1] == '.') {
        string str = fourStep(new_id);
        new_id = "";
        new_id = str;
    }

    //7
    str = "";
    if (new_id.size() <= 3) {
        char a = new_id[new_id.size()-1];
        while (new_id.size() < 3) {
            new_id.push_back(a);
        }
    }

    answer = new_id;
    return answer;
}

int main() {
    solution("=.=");
}