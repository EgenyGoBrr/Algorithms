#include <iostream>
#include <string>
#include <vector>

#define EMPTY 100005

class Stack
{
private:
    std::vector<int> value;
    std::vector<int> maxValue;
public:
    void push(int x) {
        if (value.size() == 0) {
            maxValue.push_back(x);
        }
        else {
            if (x >= maxValue.back()) maxValue.push_back(x);
        }
        value.push_back(x);
    }

    int pop() {
        if (value.size() == 0) {
            return EMPTY;
        }
        
        int x = value.back();
        if (x == maxValue.back())
            maxValue.pop_back();
        value.pop_back();
        return x;
    }

    int get_max() {
        if (maxValue.size() == 0)
            return EMPTY;
        return maxValue.back();
    }

    int show() {
        for (int i = 0; i < value.size(); i++) {
            std::cout << value[i] << " <- ";
        }
        std::cout << "\n";
    }

    int top() {
        if (value.size() == 0) {
            return EMPTY;
        }
        return value.back();
    }
};

int main() {
    Stack s;

    // std::cout << s.pop() << '\n';
    // s.push(1);
    // std::cout << s.get_max() << '\n';
    // s.push(0);
    // std::cout << s.get_max() << '\n';
    // s.push(0);
    // s.pop();
    // std::cout << s.get_max() << '\n';
    // s.push(0);
    // s.show();
    // std::cout << s.get_max() << '\n';
    // s.pop();
    // s.show();
    // s.pop();
    // s.show();
    // std::cout << s.get_max() << '\n';
    // std::cout << s.top() << '\n';
    // s.push(1);
    // s.show();
    // std::cout << s.top() << '\n';

    std::vector<std::string> comand;
    std::string str;
    int n = 0;
    std::getline(std::cin, str);
    n = std::stoi(str);
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, str);
        comand.push_back(str);
    }
    std::cout << '\n';
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
        else if (comand[i] == "top") {
            int t = s.top();
            if (t == EMPTY)
                std::cout << "error" << '\n';
            else 
                std::cout << t << '\n';
        }
        else {
            comand[i].erase(0, 4);
            int x = std::stoi(comand[i]);
            s.push(x);
        }
    }

    return 0;
}