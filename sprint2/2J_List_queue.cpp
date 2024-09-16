#include <iostream>
#include <vector>
#include <string>

#define ERROR 1005

struct Node {
    Node* next;
    Node* prev;
    int value;
};

Node* createNode(const int &value) {
        Node* n = (Node*)malloc(sizeof(Node));
        n->value = value;
        n->next = n->prev = nullptr;
        return n;
}

class List {
private:
    int size;
    Node* front;
    Node* back;

public:
    List() {
        front = back = nullptr;
        size = 0;
    }

    void put(int value) {
        Node* n = createNode(value);
        if (size == 0) 
            front = back = n;
        
        else {
            back->prev = n;
            n->next = back;
            back = n;
        }
        size++;
    }

    int get() {
        if (size == 0) 
            return ERROR;

        int value = front->value;
        front = front->prev;
        // free(front->next);
        // front->next = nullptr;
        size--;
        return value;
    }

    int get_size() { return size; }
};

int main() {
    List l;

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
        if (comand[i] == "get") {
            int x = l.get();
            if (x == ERROR)
                std::cout << "error" << '\n';
            else
                std::cout << x << '\n';
        }

        else if (comand[i] == "size") {
            std::cout << l.get_size() << '\n';
        }

        else {
            comand[i].erase(0, 3);
            int x = std::stoi(comand[i]);
            l.put(x);
        }        
    }

    return 0;
}