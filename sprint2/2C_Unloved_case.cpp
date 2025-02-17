#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#ifndef REMOTE_JUDGE
#include <cassert>
#include <string>

struct Node {  
    std::string value;  
    Node* next;  
    Node(const std::string &value, Node* next) : value(value), next(next) {
        
    }
};
#endif

Node *getNodeByIndex(Node *node, int index) {
    while (index > 0) {
        node = node->next;
        index--;
    }
    return node;
}

Node* solution(Node* head, int idx) {
    if (idx == 0) {
        return head->next;
    }

    Node* prev_node = getNodeByIndex(head, idx - 1);
    Node* del_node = prev_node->next;
    prev_node->next = del_node->next;
    return head;    
}

#ifndef REMOTE_JUDGE
void test() {
    Node node3("node3", nullptr);
    Node node2("node2", &node3);
    Node node1("node1", &node2);
    Node node0("node0", &node1);
    Node* new_head = solution(&node0, 1);
    assert(new_head == &node0);
    assert(new_head->next == &node2);
    assert(new_head->next->next == &node3);
    assert(new_head->next->next->next == nullptr);
    // result is : node0 -> node2 -> node3
}

int main() {
    test();
}
#endif