#include <iostream>
#include <vector>

class Deque
{
private:
    std::vector<int> deque;
    int front;
    int back;
    size_t size;
    size_t capacity;

public:
    Deque(int c) {
        deque.resize(c);
        front = back = size = 0;
        capacity = c;
    }

    int push_back(int value) {
        if (size >= capacity) throw "error";          

        deque[back] = value;
        back = (back + 1) % capacity;
        size++;
        return 0;
    }

    int pop_back() {
        if (size == 0) throw "error";

        if (back == 0) {
            back = capacity;
        }

        back = (back - 1) % capacity;
        int x = deque[back];
        deque[back] = 0;
        size--;
        return x;

    }

    int push_front(int value) {
        if (size >= capacity) throw "error";

        if (front == 0)
            front = capacity;
        front = (front - 1) % capacity;
        deque[front] = value;
        size++;
        return 0;
    }

    int pop_front() {
        if (size == 0) throw "error";

        int x = deque[front];
        deque[front] = 0;
        front = (front + 1) % capacity;
        size--;
        return x;
    }
};

int main() {
    std::vector<std::string> comand;
    std::string str;

    int n = 0;
    std::getline(std::cin, str);
    n = std::stoi(str);

    std::getline(std::cin, str);
    int c = std::stoi(str);
    Deque dq(c);

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, str);
        comand.push_back(str);
    }

    for (int i = 0; i < n; i++) {
        if (comand[i] == "pop_back") {
            int x;
            try {
                x = dq.pop_back();
                std::cout << x << '\n';
            }
            catch(...) {
                std::cout << "error" << '\n';
            }
        }
        else if (comand[i] == "pop_front") {
            int x;
            try {
                x = dq.pop_front();
                std::cout << x << '\n';
            }
            catch(...) {
                std::cout << "error" << '\n';
            }
        }
        else if (comand[i].substr(0, 9) == "push_back") {
            int value = std::stoi(comand[i].substr(10));
            int x;
            try {
                x = dq.push_back(value);
            }
            catch(...) {
                std::cout << "error" << '\n';
            }
        }
        else {
            int value = std::stoi(comand[i].substr(11));
            int x;
            try {
                x = dq.push_front(value);
            }
            catch(...) {
                std::cout << "error" << '\n';
            }
        }
    }
    
    return 0;
}