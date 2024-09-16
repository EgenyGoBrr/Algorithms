/*
Ссылка на отчет:
https://contest.yandex.ru/contest/22781/run-report/117074934/

-- ПРИНЦИП РАБОТЫ --
Считываю входное выражение, удалюю пробелы из него
и сохраняю в векторе.
Дальше прохожу в цикле по вектору.
Если встречается число, то добавляю его на вершину стека.
Если встречается знак операции, то достаю из стека два последних числа
и происвожу операцию с ними. Результат возвращаю на вершину стека.
В конце вывожу число с вершины стекаю.

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
Так как входные данные записаны в постфиксной нотации
при встрчи знака операции в стеке находится именно те 
операнды, которые необходимо испольовать при этой операции.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
Считывание и удаление пробелов занимает О(n)
Проход по вектору данных О(m)
Операции над числами и вставка/удаление из стека О(1)


-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
О(n) так как хранится строка с входными данными 
и строка без пробелов.

*/

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

bool is_num(std::string& s);

int main() {
    std::string input;
    std::vector<std::string> split_inp;
    std::getline(std::cin, input);
    std::string t;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ') {
            split_inp.push_back(t);
            t.clear();
            continue;
        }
        t += input[i];
    }
    split_inp.push_back(t);

    std::stack<int> s;

    for (int i = 0; i < split_inp.size(); i++) {
        if (is_num(split_inp[i])) {
            int num = std::stoi(split_inp[i]);
            s.push(num);  
        }
        else {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            if (split_inp[i] == "+") s.push(a + b);
            if (split_inp[i] == "-") s.push(a - b);
            if (split_inp[i] == "*") s.push(a * b);
            if (split_inp[i] == "/" && b!= 0) {
                int c = (int)floor((float)a / b);
            	s.push(c);
            }
        }
    }

    std::cout << s.top();

    return 0;
}

bool is_num(std::string& s) {
    if (s.size() == 1 && s[0] == '-')
        return false;

    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s[i]) && s[i] != '-')
            return false;
    }
    return true;
}