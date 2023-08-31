#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void removeLoop(ListNode *head) {
        if (!head || !head->next)
            return;

        ListNode *slow = head;
        ListNode *fast = head;

        // Detect if a loop exists
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        // If loop is found, find the starting node of the loop
        if (slow == fast) {
            slow = head;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = nullptr;  // Remove the loop
        }
    }
};

// Helper function to create a linked list with a loop
ListNode *createLinkedListWithLoop(int arr[], int n, int x) {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    ListNode *loopNode = nullptr;

    for (int i = 0; i < n; ++i) {
        ListNode *newNode = new ListNode(arr[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        if (i + 1 == x)
            loopNode = newNode;
    }

    if (loopNode)
        tail->next = loopNode;

    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode *head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int value[] = {1, 3, 4};
    int N = sizeof(value) / sizeof(value[0]);
    int X = 2;

    ListNode *head = createLinkedListWithLoop(value, N, X);

    Solution solution;
    solution.removeLoop(head);

    cout << "Linked list after removing the loop: ";
    printLinkedList(head);

    return 0;
}
