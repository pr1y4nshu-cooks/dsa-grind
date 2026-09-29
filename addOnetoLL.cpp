#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Solution {
public:
    Node* addOne(Node* head) {
        if (head == nullptr) {
            return new Node(1);
        }
        Node* current = head;
        Node* lastNonNine = nullptr;
        while (head != )
        

        return head;
    }
};

Node* makeList(const vector<int>& digits) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int digit : digits) {
        Node* newNode = new Node(digit);

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    return head;
}

vector<int> toVector(Node* head) {
    vector<int> digits;

    while (head != nullptr) {
        digits.push_back(head->data);
        head = head->next;
    }

    return digits;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

void runTest(const vector<int>& input, const vector<int>& expected, int testNumber) {
    Solution solution;
    Node* inputList = makeList(input);
    Node* result = solution.addOne(inputList);
    vector<int> actual = toVector(result);

    cout << "Test " << testNumber << ": "
         << (actual == expected ? "PASSED" : "FAILED") << '\n';

    if (actual != expected) {
        cout << "Expected: ";
        for (int digit : expected) {
            cout << digit << ' ';
        }

        cout << "\nGot:      ";
        for (int digit : actual) {
            cout << digit << ' ';
        }

        cout << '\n';
    }

    deleteList(result);
}

int main() {
    runTest({1, 2, 3}, {1, 2, 4}, 1);
    runTest({1, 2, 9}, {1, 3, 0}, 2);
    runTest({9, 9}, {1, 0, 0}, 3);
    runTest({7}, {8}, 4);

    return 0;
}