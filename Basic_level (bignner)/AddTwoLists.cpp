/*
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0

*/

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin >> val;

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


typedef struct Node Node;

Node* reverse(Node *head) {
    Node *Next = NULL , *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
    }
    return head = prev;
}
Node *add(Node *head, Node *s) {
    Node* res = head;
    Node *temp, *prev = NULL;

    int carry = 0, sum;

    while (head != NULL && s != NULL)
    {

        sum = carry + head->data + s->data;


        carry = (sum >= 10) ? 1 : 0;


        sum = sum % 10;


        head->data = sum;


        temp = head;
        head = head->next;
        s = s->next;
    }
    while (head != NULL) {
        if (carry > 0) {
            sum = carry + head->data;
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;
            head->data = sum;
            temp = head;
        }
        else {
            temp->next = head;
            temp = head;
        }
        head = head->next;
    }
    while (s != NULL)
    {
        if (carry > 0) {
            sum = carry + s->data;
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;
            Node *t = new Node(sum);
            temp->next = t;
            temp = t;
        }
        else {
            temp->next = s;
            temp = s;
        }
        s = s->next;
    }

    if (carry > 0)
        temp->next = new Node(carry);


    return res;

}

class Solution
{
public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        first = add(first, second);
        return reverse(first);

    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node* first = buildList(n);

        cin >> m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
