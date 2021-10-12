#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define ll long long

class Node {
public:
    int data;
    Node *next, *pre;
    Node(int data) {
        this->data = data,
              next = NULL, pre = NULL;
    }
};

vector<Node *> create() {
    Node *head = NULL, *tail = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int nodeData; cin >> nodeData;
        Node *newNode = new Node(nodeData);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->pre = tail;
            tail = tail->next;
        }
    }
    vector<Node *> node(2, NULL);
    node[0] = head;
    node[1] = tail;
    return node;
}

void print(Node *head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}

void Pair(vector<Node *> node, int x) {
    Node *head = node[0], *tail = node[1];
    cout << "\nPair Is : " << '\n';
    while (head != tail) {
        int temp = head->data + tail->data;
        if (temp == x) {
            cout << head->data << ' ' << tail->data << endl;
            head = head->next;
        }
        else if (temp > x)
            tail = tail->pre;
        else head = head->next;
    }
}

void triplate(vector<Node *> node, int x) {
    Node *head = node[0], *tail = node[1], *temp = node[0]->next;
    cout << "\nTriplate Is : " << '\n';
    for (auto i = head; i != NULL; i = i->next) {
        temp = i->next, tail = node[1];
        while (temp != tail) {
            int sum = i->data + tail->data + temp->data;
            if (sum == x) {
                cout << i->data << ' ' << temp->data << ' ' << tail->data << endl;
                temp = temp->next;
            }
            else if (sum > x) tail = tail->pre;
            else temp = temp->next;
        }
    }
}

int main() {
    fast_io;
    vector<Node* > node = create(); // create DLL
    print(node[0]); // print DLL
    int x; cin >> x;
    Pair(node, x); // sum of pair given is equal to x
    triplate(node, x); // sum of triplate is equal to x
    return 0;
}
