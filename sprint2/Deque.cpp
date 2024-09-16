/*
Ссылка на отчет:
https://contest.yandex.ru/contest/22781/run-report/117080660/

-- ПРИНЦИП РАБОТЫ --
В начале считываю все команды и сохраняю их в vector.
Дальше обрабатываю их в цикле.

В основе дека лежит кольцевой буфер реализованный с помощью вектора.
Также имеется два числа, с помощью которых запоминается индекс начала
и конца дека.

Принцип работы дека понял из этой статьи:
https://srdja.github.io/2017/06/06/deque-as-a-circular-buffer/

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Так как в основе дека лежит массив, вставка и удаление происходит за О(1)
из-за обращения по индексу.
Для положительных индексов, которые выходят за границы массива
использую деление по модулю
Для отрицательных индексов проверяю переход через 0.
Так как при вставке или удалении индекс сдвигается всегда на один элемент,
я вручную переношу индекс в конец массива.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Считывание команд m и создание дека размером n
происходит за О(m + n)
Вставка и удаление происходит за О(1),
так как все операции выполняются по индексу,
который уже хранится в памяти

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Хранение команд m и дека размером n занимает О(m + n)
*/

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
        // так? первый раз этим пользуюсь
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