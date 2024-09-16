#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define EMPTY 100005

class Stack
{
private:
    std::vector<int> value;
public:
    void push(int x) {
        value.push_back(x);
    }

    int pop() {
        if (value.size() == 0) {
            return EMPTY;
        }
        
        int x = value.back();
        value.pop_back();
        return x;
    }

    int get_max() {
        std::vector<int> t = value; 
        if (t.size() == 0) {
            return EMPTY;
        }
        if (t.size() == 1) {
            return t[0];
        }
        if (t.size() == 2) {
            return t[0] > t[1] ? t[0] : t[1];
        }

        std::sort(t.begin(), t.end());
        return t.back();
    }

    int show() {
        for (int i = 0; i < value.size(); i++) {
            std::cout << value[i] << " <- ";
        }
        std::cout << "\n";
    }
};

int main() {
    Stack s;

    // s.push(5);
    // s.push(4);
    // s.push(-1);
    // s.push(5);
    // s.push(2);
    // s.show();
    // std::cout << s.get_max() << '\n';
    // s.pop();
    // s.pop();  
    // s.show();
    // std::cout << s.get_max() << '\n';


    std::vector<std::string> comand;
    std::string str;
    int n = 0;
    std::getline(std::cin, str);
    n = std::stoi(str);
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, str);
        comand.push_back(str);
    }
    for (int i = 0; i < comand.size(); i++) {
        if (comand[i] == "get_max") {
            int t = s.get_max();
            if (t == EMPTY)
                std::cout << "None" << '\n';
            else
                std::cout << t << '\n';
        }
        else if (comand[i] == "pop") {
            int t = s.pop();
            if (t == EMPTY)
                std::cout << "error" << '\n';
        }
        else {
            comand[i].erase(0, 4);
            int x = std::stoi(comand[i]);
            s.push(x);
        }
    }

    return 0;
}