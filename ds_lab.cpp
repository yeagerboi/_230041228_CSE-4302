////////////////////stack and queue//////////////////////:

//stack using array:
#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = x;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    top--;
}

void displayStack() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}
//queue using array:
#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return;
    }
    front++;
}

void displayQueue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
        return;
    }
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}

//stack using queue:

#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x) {
    int size = q.size();
    q.push(x);

   
    for (int i = 0; i < size; i++) {
        q.push(q.front());
        q.pop();
    }
}

void pop() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    q.pop();
}


int top() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return q.front();
}


bool isEmpty() {
    return q.empty();
}

//queue using stack:

#include <stack>
using namespace std;

stack<int> s1, s2;

void enqueue(int x) {
    s1.push(x);
}

void dequeue() {
    if (s1.empty() && s2.empty())
        return;

    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
}

int front() {
    if (s1.empty() && s2.empty())
        return -1;

    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
}

bool isEmpty() {
    return s1.empty() && s2.empty();
}

//stack using linked list:
struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop() {
    if (top == NULL) return;
    Node* temp = top;
    top = top->next;
    delete temp;
}
 
//queue using linked list:

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if (front == NULL) return;
    Node* temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete temp;
}

//check for balanced parenthesis:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValid(string s) {
        stack<char> st; 

        for (auto it : s) {
            if (it == '(' || it == '{' || it == '[')
                st.push(it); 
            else {
                if (st.empty()) return false; 
                char ch = st.top();
                st.pop();

               
                if ((it == ')' && ch == '(') ||
                    (it == ']' && ch == '[') ||
                    (it == '}' && ch == '{'))
                    continue;
                else
                    return false;
            }
        }
        return st.empty();  
    }
};

//implement min stack:

#include <stack>
using namespace std;

stack<int> s;
stack<int> minS;

void push(int x) {
    s.push(x);
    if (minS.empty() || x <= minS.top())
        minS.push(x);
}

void pop() {
    if (s.empty())
        return;

    if (s.top() == minS.top())
        minS.pop();

    s.pop();
}

int top() {
    if (s.empty())
        return -1;
    return s.top();
}

int getMin() {
    if (minS.empty())
        return -1;
    return minS.top();
}

bool isEmpty() {
    return s.empty();
}

// Infix to Postfix Conversion:

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char c) {
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result = "";
    for(char c : s) {
        if(isalnum(c)) result += c;
        else if(c=='(') st.push(c);
        else if(c==')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && precedence(st.top()) >= precedence(c))
                { result += st.top(); st.pop(); }
            st.push(c);
        }
    }
    while(!st.empty()) { result += st.top(); st.pop(); }
    return result;
}

//Prefix to Infix Conversion
#include <stack>
#include <string>
using namespace std;

string prefixToInfix(string s) {
    stack<string> st;
    for(int i = s.length()-1; i >= 0; i--) {
        char c = s[i];
        if(isalnum(c)) st.push(string(1,c));
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
    }
    return st.top();
}

//Prefix to Postfix Conversion
string prefixToPostfix(string s) {
    stack<string> st;
    for(int i = s.length()-1; i >= 0; i--) {
        char c = s[i];
        if(isalnum(c)) st.push(string(1,c));
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push(op1 + op2 + c);
        }
    }
    return st.top();
}

//Postfix to Prefix Conversion
string postfixToPrefix(string s) {
    stack<string> st;
    for(char c : s) {
        if(isalnum(c)) st.push(string(1,c));
        else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            st.push(c + op1 + op2);
        }
    }
    return st.top();
}

//Postfix to Infix Conversion
string postfixToInfix(string s) {
    stack<string> st;
    for(char c : s) {
        if(isalnum(c)) st.push(string(1,c));
        else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
    }
    return st.top();
}

//Infix to Prefix Conversion
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

//Next Greater Element (NGE)
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[i] > nums[st.top()]){
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

//Next Greater Element II (Circular Array)
vector<int> nextGreaterElement2(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for(int i = 0; i < 2*n; i++){
        while(!st.empty() && nums[i%n] > nums[st.top()]){
            res[st.top()] = nums[i%n];
            st.pop();
        }
        if(i < n) st.push(i);
    }
    return res;
}

//Next Smaller Element (NSE)
vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[i] < nums[st.top()]){
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

//Number of NGEs to the Right
#include <vector>
#include <stack>
using namespace std;

vector<int> countNGEsToRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    stack<int> st;

    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && st.top() <= nums[i]) st.pop();
        res[i] = st.size();
        st.push(nums[i]);
    }
    return res;
}

//Sliding Window Maximum
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingWindowMax(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res;
    deque<int> dq;

    for(int i = 0; i < n; i++) {
        if(!dq.empty() && dq.front() == i - k) dq.pop_front();
        while(!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}

//LRU Cache (Least Recently Used) — IMPORTANT
#include <unordered_map>
#include <list>
using namespace std;

int capacityLRU;
list<int> dq;
unordered_map<int, pair<int, list<int>::iterator>> mp;

void setCapacityLRU(int cap) { capacityLRU = cap; }

int getLRU(int key) {
    if(mp.find(key) == mp.end()) return -1;
    dq.erase(mp[key].second);
    dq.push_front(key);
    mp[key].second = dq.begin();
    return mp[key].first;
}

void putLRU(int key, int value) {
    if(mp.find(key) != mp.end()) {
        dq.erase(mp[key].second);
    } else if(dq.size() == capacityLRU) {
        int last = dq.back(); dq.pop_back();
        mp.erase(last);
    }
    dq.push_front(key);
    mp[key] = {value, dq.begin()};
}

//LFU Cache (Least Frequently Used)

LFU is a bit more complex: we need frequency + order.

#include <unordered_map>
#include <list>
using namespace std;

struct LFUNode { int key, value, freq; };

int capacityLFU;
int minFreqLFU;
unordered_map<int, list<LFUNode>::iterator> keyMapLFU;
unordered_map<int, list<LFUNode>> freqMapLFU;

void setCapacityLFU(int cap) { capacityLFU = cap; minFreqLFU = 0; }

int getLFU(int key) {
    if(keyMapLFU.find(key) == keyMapLFU.end()) return -1;
    auto it = keyMapLFU[key];
    int val = it->value, freq = it->freq;
    freqMapLFU[freq].erase(it);
    if(freqMapLFU[freq].empty() && minFreqLFU == freq) minFreqLFU++;
    freqMapLFU[freq+1].push_front({key, val, freq+1});
    keyMapLFU[key] = freqMapLFU[freq+1].begin();
    return val;
}

void putLFU(int key, int value) {
    if(capacityLFU == 0) return;
    if(keyMapLFU.find(key) != keyMapLFU.end()) {
        keyMapLFU[key]->value = value;
        getLFU(key);
        return;
    }
    if(keyMapLFU.size() == capacityLFU) {
        auto node = freqMapLFU[minFreqLFU].back();
        keyMapLFU.erase(node.key);
        freqMapLFU[minFreqLFU].pop_back();
    }
    freqMapLFU[1].push_front({key, value, 1});
    keyMapLFU[key] = freqMapLFU[1].begin();
    minFreqLFU = 1;
}

//Implementation of Max-Heap Priority Queue
#include <vector>
using namespace std;

vector<int> heap;

void heapifyUp(int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;
        if(heap[parent] >= heap[index]) break;
        swap(heap[parent], heap[index]);
        index = parent;
    }
}

void heapifyDown(int index) {
    int n = heap.size();
    while(2*index + 1 < n) {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int largest = index;
        if(left < n && heap[left] > heap[largest]) largest = left;
        if(right < n && heap[right] > heap[largest]) largest = right;
        if(largest == index) break;
        swap(heap[index], heap[largest]);
        index = largest;
    }
}

void push(int val) {
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}

void pop() {
    if(heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    if(!heap.empty()) heapifyDown(0);
}

int top() {
    if(heap.empty()) return -1;
    return heap[0];
}

bool empty() {
    return heap.empty();
}

//Min-Heap Priority Queue Implementation
#include <vector>
using namespace std;

vector<int> minHeap;

void heapifyUp(int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;
        if(minHeap[parent] <= minHeap[index]) break;
        swap(minHeap[parent], minHeap[index]);
        index = parent;
    }
}

void heapifyDown(int index) {
    int n = minHeap.size();
    while(2*index + 1 < n) {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int smallest = index;
        if(left < n && minHeap[left] < minHeap[smallest]) smallest = left;
        if(right < n && minHeap[right] < minHeap[smallest]) smallest = right;
        if(smallest == index) break;
        swap(minHeap[index], minHeap[smallest]);
        index = smallest;
    }
}

void pushMin(int val) {
    minHeap.push_back(val);
    heapifyUp(minHeap.size() - 1);
}

void popMin() {
    if(minHeap.empty()) return;
    minHeap[0] = minHeap.back();
    minHeap.pop_back();
    if(!minHeap.empty()) heapifyDown(0);
}

int topMin() {
    if(minHeap.empty()) return -1;
    return minHeap[0];
}

bool emptyMin() {
    return minHeap.empty();
}

//check if it is minheap or not:

#include <vector>
using namespace std;

bool isMinHeap(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i <= (n-2)/2; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < n && arr[i] > arr[left]) return false;
        if(right < n && arr[i] > arr[right]) return false;
    }
    return true;
}


//convert min heap to max heap:
#include <vector>
using namespace std;

void heapifyMax(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void minToMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for(int i = (n-2)/2; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}

//convert max heap to min heap:
#include <vector>
using namespace std;    
void heapifyMin(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest]) smallest = left;
    if(right < n && arr[right] < arr[smallest]) smallest = right;

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void maxToMinHeap(vector<int>& arr) {
    int n = arr.size();
    for(int i = (n-2)/2; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }
}

//Kth Largest Element in an Array
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int x : nums) {
        pq.push(x);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}

//Kth Smallest Element in an Array
int kthSmallest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(int x : nums) {
        pq.push(x);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}

//Sort a K-Sorted Array
vector<int> sortKSortedArray(vector<int>& arr, int k) {
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
        if(pq.size() > k) {
            res.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
//Merge K Sorted Lists
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int val;
    int listIndex;
    int elementIndex;
    bool operator>(const Node& other) const {
        return val > other.val;
    }
};

vector<int> mergeKSortedLists(vector<vector<int>>& lists) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for(int i = 0; i < lists.size(); i++) {
        if(!lists[i].empty()) pq.push({lists[i][0], i, 0});
    }
    vector<int> res;
    while(!pq.empty()) {
        Node node = pq.top(); pq.pop();
        res.push_back(node.val);
        if(node.elementIndex + 1 < lists[node.listIndex].size())
            pq.push({lists[node.listIndex][node.elementIndex + 1], node.listIndex, node.elementIndex + 1});
    }
    return res;
}

//  Task Scheduler (Leetcode 621)
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> freq;
    for(char t : tasks) freq[t]++;
    
    priority_queue<int> pq;
    for(auto it : freq) pq.push(it.second);
    
    int time = 0;
    while(!pq.empty()) {
        vector<int> temp;
        for(int i = 0; i <= n; i++) {
            if(!pq.empty()) {
                temp.push_back(pq.top()-1);
                pq.pop();
            }
        }
        for(int x : temp) if(x > 0) pq.push(x);
        time += pq.empty() ? temp.size() : n+1;
    }
    return time;
}

//AVL TREE:

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n) {
    return (n == NULL) ? 0 : n->height;
}


Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int getBalance(Node* n) {
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}


Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


Node* insert(Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (root->key == key) return true;
    return key < root->key ? search(root->left, key) : search(root->right, key);
}


void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
int main() {
    Node* root = NULL;

    int keys[] = {30, 20, 40, 10, 25};
    for (int key : keys)
        root = insert(root, key);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    root = insert(root, 50);
    cout << "After inserting 50: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;

    cout << "Search 25: " << (search(root, 25) ? "Found" : "Not Found") << endl;
    cout << "Height of tree: " << height(root) << endl;

    return 0;
}


//bianry tree:

//level order traversal of binary tree(bfs):
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

//Level Order Traversal in Spiral Form (Zig-Zag)
#include <iostream>
#include <stack>
using namespace std;

void spiralOrder(Node* root) {
    if (root == NULL) return;

    stack<Node*> s1; // Left to Right
    stack<Node*> s2; // Right to Left

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {

        while (!s1.empty()) {
            Node* curr = s1.top();
            s1.pop();
            cout << curr->data << " ";

            if (curr->left)
                s2.push(curr->left);
            if (curr->right)
                s2.push(curr->right);
        }

        while (!s2.empty()) {
            Node* curr = s2.top();
            s2.pop();
            cout << curr->data << " ";

            if (curr->right)
                s1.push(curr->right);
            if (curr->left)
                s1.push(curr->left);
        }
    }
}
//Iterative Preorder Traversal:
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
void iterativePreorder(Node* root) {
    if (root == NULL) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        cout << curr->data << " ";

        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}
//Iterative Inorder Traversal:
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
void iterativeInorder(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}
//Iterative Postorder Traversal using 2 stacks:
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void postorderTwoStacks(Node* root) {
    if (root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

//Iterative Postorder Traversal using 1 Stack:

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void postorderOneStack(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    Node* lastVisited = NULL;

    while (curr != NULL || !st.empty()) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        } else {
            Node* peekNode = st.top();
            if (peekNode->right != NULL && lastVisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                cout << peekNode->data << " ";
                lastVisited = peekNode;
                st.pop();
            }
        }
    }
}


//Preorder, Inorder & Postorder in One Traversal
void allTraversals(Node* root) {
    if (root == NULL) return;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    cout << "Preorder: ";
    while (!st.empty()) {
        auto &p = st.top();

        if (p.second == 1) {
            cout << p.first->data << " ";
            p.second++;
            if (p.first->left)
                st.push({p.first->left, 1});
        }
        else if (p.second == 2) {
            p.second++;
            if (p.first->right)
                st.push({p.first->right, 1});
        }
        else {
            st.pop();
        }
    }
}


//Height of a Binary Tree
int height(Node* root) {
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}
//Check if Binary Tree is Height Balanced
int check(Node* root) {
    if (root == NULL) return 0;

    int lh = check(root->left);
    if (lh == -1) return -1;

    int rh = check(root->right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
    return check(root) != -1;
}

//Diameter of Binary Tree
int diameterUtil(Node* root, int &diameter) {
    if (root == NULL)
        return 0;

    int lh = diameterUtil(root->left, diameter);
    int rh = diameterUtil(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int diameter(Node* root) {
    int dia = 0;
    diameterUtil(root, dia);
    return dia;
}

//Maximum Path Sum (Node to Node)
int maxPath(Node* root, int &res) {
    if (root == NULL)
        return 0;

    int left = max(0, maxPath(root->left, res));
    int right = max(0, maxPath(root->right, res));

    res = max(res, root->data + left + right);

    return root->data + max(left, right);
}

int maxPathSum(Node* root) {
    int res = INT_MIN;
    maxPath(root, res);
    return res;
}

//Check if Two Trees are Identical
bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}
//Zig Zag Traversal of Binary Tree
vector<int> zigZagTraversal(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            level[index] = curr->data;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        leftToRight = !leftToRight;
        for (int x : level)
            ans.push_back(x);
    }
    return ans;
}
//Boundary Traversal of Binary Tree
void leftBoundary(Node* root, vector<int>& ans) {
    if (!root) return;
    if (root->left) {
        ans.push_back(root->data);
        leftBoundary(root->left, ans);
    } else if (root->right) {
        ans.push_back(root->data);
        leftBoundary(root->right, ans);
    }
}

void rightBoundary(Node* root, vector<int>& ans) {
    if (!root) return;
    if (root->right) {
        rightBoundary(root->right, ans);
        ans.push_back(root->data);
    } else if (root->left) {
        rightBoundary(root->left, ans);
        ans.push_back(root->data);
    }
}

void leaves(Node* root, vector<int>& ans) {
    if (!root) return;
    if (!root->left && !root->right) {
        ans.push_back(root->data);
        return;
    }
    leaves(root->left, ans);
    leaves(root->right, ans);
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    ans.push_back(root->data);
    leftBoundary(root->left, ans);
    leaves(root->left, ans);
    leaves(root->right, ans);
    rightBoundary(root->right, ans);

    return ans;
}
//Vertical Order Traversal

vector<int> verticalOrder(Node* root) {
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    vector<int> ans;

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        Node* node = p.first;
        int hd = p.second;

        mp[hd].push_back(node->data);

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto x : mp)
        for (int v : x.second)
            ans.push_back(v);

    return ans;
}
//Top View of Binary Tree

vector<int> topView(Node* root) {
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    vector<int> ans;

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        Node* node = p.first;
        int hd = p.second;

        if (mp.find(hd) == mp.end())
            mp[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto x : mp)
        ans.push_back(x.second);

    return ans;
}
//Bottom View of Binary Tree
vector<int> bottomView(Node* root) {
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    vector<int> ans;

    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        Node* node = p.first;
        int hd = p.second;

        mp[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto x : mp)
        ans.push_back(x.second);

    return ans;
}
//Left View of Binary Tree
void leftViewUtil(Node* root, int level, vector<int>& ans) {
    if (!root) return;

    if (level == ans.size())
        ans.push_back(root->data);

    leftViewUtil(root->left, level + 1, ans);
    leftViewUtil(root->right, level + 1, ans);
}

vector<int> leftView(Node* root) {
    vector<int> ans;
    leftViewUtil(root, 0, ans);
    return ans;
}
// Right View of Binary Tree
void rightViewUtil(Node* root, int level, vector<int>& ans) {
    if (!root) return;

    if (level == ans.size())
        ans.push_back(root->data);

    rightViewUtil(root->right, level + 1, ans);
    rightViewUtil(root->left, level + 1, ans);
}

vector<int> rightView(Node* root) {
    vector<int> ans;
    rightViewUtil(root, 0, ans);
    return ans;
}
//Symmetric Binary Tree
bool isMirror(Node* t1, Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return true;

    if (t1 == NULL || t2 == NULL)
        return false;

    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

bool isSymmetric(Node* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}
//lca:
Node* lca(Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    Node* left = lca(root->left, p, q);
    Node* right = lca(root->right, p, q);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

//Maximum Width of a Binary Tree

int maxWidth(Node* root) {
    if (root == NULL)
        return 0;

    queue<Node*> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        maxWidth = max(maxWidth, levelSize);

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return maxWidth;
}

//Search in a Binary Search Tree recursive sol:
bool searchBST(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

//Search in a Binary Search Tree iterative sol:
bool searchBST(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

//Find Minimum in a BST
int findMin(Node* root) {
    if (root == NULL)
        return -1;   // or INT_MIN / error

    while (root->left != NULL)
        root = root->left;

    return root->data;
}
//Find Maximum in a BST

int findMax(Node* root) {
    if (root == NULL)
        return -1;   // or INT_MAX / error

    while (root->right != NULL)
        root = root->right;

    return root->data;
}


//basic node:
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
//Ceil in a Binary Search Tree
int ceilBST(Node* root, int key) {
    int ceil = -1;

    while (root) {
        if (root->data == key)
            return root->data;
        if (root->data > key) {
            ceil = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ceil;
}
//Floor in a Binary Search Tree
int floorBST(Node* root, int key) {
    int floor = -1;

    while (root) {
        if (root->data == key)
            return root->data;
        if (root->data < key) {
            floor = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}
//Insert a Node in BST
Node* insertBST(Node* root, int key) {
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insertBST(root->left, key);
    else if (key > root->data)
        root->right = insertBST(root->right, key);

    return root;
}
//delete a node in BST
Node* minValue(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}

Node* deleteBST(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteBST(root->left, key);
    else if (key > root->data)
        root->right = deleteBST(root->right, key);
    else {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;

        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}
//K-th Smallest Element in BST
int kthSmallest(Node* root, int &k) {
    if (!root) return -1;

    int left = kthSmallest(root->left, k);
    if (left != -1) return left;

    k--;
    if (k == 0) return root->data;

    return kthSmallest(root->right, k);
}

//K-th Largest Element in BST
int kthLargest(Node* root, int &k) {
    if (!root) return -1;

    int right = kthLargest(root->right, k);
    if (right != -1) return right;

    k--;
    if (k == 0) return root->data;

    return kthLargest(root->left, k);
}
//Check if a Tree is BST or not

bool isBSTUtil(Node* root, long minVal, long maxVal) {
    if (!root) return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}
//LCA in Binary Search Tree
Node* lcaBST(Node* root, int n1, int n2) {
    while (root) {
        if (n1 < root->data && n2 < root->data)
            root = root->left;
        else if (n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}
//Construct BST from Preorder Traversal
Node* buildBST(int preorder[], int &idx, int bound, int n) {
    if (idx == n || preorder[idx] > bound)
        return NULL;

    Node* root = new Node(preorder[idx++]);
    root->left = buildBST(preorder, idx, root->data, n);
    root->right = buildBST(preorder, idx, bound, n);

    return root;
}

Node* bstFromPreorder(int preorder[], int n) {
    int idx = 0;
    return buildBST(preorder, idx, INT_MAX, n);
}
//Inorder Successor in BST
Node* inorderSuccessor(Node* root, Node* p) {
    Node* succ = NULL;

    while (root) {
        if (p->data < root->data) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}
//Inorder Predecessor in BST
Node* inorderPredecessor(Node* root, Node* p) {
    Node* pred = NULL;

    while (root) {
        if (p->data > root->data) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}
//Merge Two BSTs
void inorder(Node* root, vector<int>& v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

vector<int> mergeBST(Node* root1, Node* root2) {
    vector<int> a, b, res;
    inorder(root1, a);
    inorder(root2, b);

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) res.push_back(a[i++]);
        else res.push_back(b[j++]);
    }
    while (i < a.size()) res.push_back(a[i++]);
    while (j < b.size()) res.push_back(b[j++]);

    return res;
}


//https://github.com/yeagerboi

Introduction to LinkedList

Concepts:

LinkedList is a data structure where each element (node) contains data and a pointer to the next node.

Struct in C/C++ is often used to define a node:

struct Node {
    int data;
    Node* next;
};


Node representation:

[data | next] -> [data | next] -> NULL


Difficulty: Easy
Resources: Solve, Editorial, YouTube

2. Inserting a Node in LinkedList

Concepts:

Insertion at:

Beginning

End

Specific position

Example (insert at beginning in C++):

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


Difficulty: Easy
Resources: Solve, Editorial, YouTube

3. Deleting a Node in LinkedList

Concepts:

Deletion at:

Beginning

End

Specific position or by value

Example (delete first node in C++):

void deleteFirstNode(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}


Difficulty: Easy
Resources: Solve, Editorial, YouTube

4. Find the Length of LinkedList

Concepts:

Traversal: go through each node until NULL

Count nodes to get length

Example:

int length(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}


Difficulty: Easy
Resources: Solve, YouTube

5. Search an Element in LinkedList

Concepts:

Traverse and compare each node’s data with the target

Example (C++):

bool search(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}


Difficulty: Easy
Resources: Solve, YouTube

If you want, I can make a complete C++ cheat sheet for all these linked list operations with code for insertion, deletion, traversal, search, and length—ready to copy and practice.

Do you want me to do that?

Introduction to DLL, learn about struct, and how is node represented
Solve	Editorial	
PostLink
YouTube
---
Add Note
Easy
	
Insert a node in DLL
Solve	Editorial	
PostLink
YouTube
---
Add Note
Easy
	
Delete a node in DLL
Solve	Editorial	
PostLink
YouTube
---
Add Note
Easy
	
Reverse a DLL

Perfect! You’ve moved on to Doubly Linked Lists (DLL). Let’s break it down clearly and include node structure, insertion, deletion, and reversal. I’ll make it beginner-friendly with examples in C++.

1. Introduction to Doubly Linked List (DLL)

Concepts:

A DLL is like a regular linked list, but each node has two pointers:

next → points to the next node

prev → points to the previous node

This allows traversal in both directions.

Struct Representation in C++:

struct Node {
    int data;
    Node* next;
    Node* prev;
};


Visual Representation:

NULL <- [prev | data | next] <-> [prev | data | next] <-> [prev | data | next] -> NULL


Difficulty: Easy
Resources: Solve, Editorial, YouTube

2. Inserting a Node in DLL

Common Cases:

At the beginning

At the end

At a specific position

Example: Insert at beginning

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}


Example: Insert at end

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


Difficulty: Easy
Resources: Solve, Editorial, YouTube

3. Deleting a Node in DLL

Common Cases:

Delete the first node

Delete the last node

Delete a node with a specific value

Example: Delete a node by value

void deleteNode(Node*& head, int key) {
    Node* temp = head;

    // Find the node to delete
    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) return; // Node not found

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next; // Node is head

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}


Difficulty: Easy
Resources: Solve, Editorial, YouTube

4. Reverse a Doubly Linked List

Concept:

Swap next and prev for each node

Move head to the last node

Example:

void reverseDLL(Node*& head) {
    Node* temp = nullptr;
    Node* current = head;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr)
        head = temp->prev;
}

1. Middle of a LinkedList [Tortoise-Hare / Slow-Fast Pointer Method]

Concept:

Use two pointers:

slow → moves 1 step

fast → moves 2 steps

When fast reaches the end, slow is at the middle.

Example:

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // Middle node
}


Time Complexity: O(n), Space: O(1)

2. Reverse a LinkedList
Iterative
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev; // New head
}

Recursive
Node* reverseRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return rest;
}


Time Complexity: O(n), Space Complexity: O(n) for recursion

3. Detect a Loop in LinkedList

Floyd’s Cycle Detection

bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}


Time Complexity: O(n), Space: O(1)

4. Find Starting Point of Loop
Node* findLoopStart(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Detect loop
    do {
        if (!fast || !fast->next) return nullptr;
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // Find start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

5. Length of Loop
int loopLength(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            int len = 1;
            Node* temp = slow;
            while (temp->next != slow) {
                temp = temp->next;
                len++;
            }
            return len;
        }
    }
    return 0; // No loop
}

6. Check if LL is Palindrome

Method:

Find middle (Tortoise-Hare)

Reverse second half

Compare both halves

7. Segregate Odd and Even Nodes

Move even nodes after odd nodes

Maintain relative order

8. Remove Nth Node from End
Node* removeNthFromEnd(Node* head, int n) {
    Node dummy;
    dummy.next = head;
    Node* first = &dummy;
    Node* second = &dummy;

    for (int i = 0; i <= n; i++) first = first->next;
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    Node* toDelete = second->next;
    second->next = second->next->next;
    delete toDelete;

    return dummy.next;
}

9. Delete Middle Node

Use Tortoise-Hare to find middle

Remove middle node by adjusting pointers

10. Sort LinkedList

Approach: Merge sort (O(n log n))

For 0,1,2 nodes: counting or link rearrangement

11. Intersection of Y-shaped LL

Calculate lengths of both lists

Move longer list pointer forward by difference

Traverse together to find intersection

12. Add 1 / Add 2 numbers represented by LL

Reverse the LL

Add number with carry

Reverse back

1. Delete All Occurrences of a Key in DLL (Hard)

Concept:

Traverse the DLL and delete every node with the given value.

Handle head, tail, and middle nodes carefully.

C++ Example:

void deleteAllOccurrences(Node*& head, int key) {
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;

        if (current->data == key) {
            if (current->prev != nullptr)
                current->prev->next = current->next;
            else
                head = current->next; // current is head

            if (current->next != nullptr)
                current->next->prev = current->prev;

            delete current;
        }

        current = nextNode;
    }
}


Time Complexity: O(n)
Space Complexity: O(1)

2. Find Pairs with Given Sum in DLL (Medium)

Concept:

Use two pointers (start and end) because DLL allows backward traversal.

Move pointers toward each other to find all pairs that sum up to a given value.

C++ Example:

void findPairs(Node* head, int target) {
    Node* start = head;
    Node* end = head;

    // Move end to last node
    while (end->next != nullptr) end = end->next;

    while (start != nullptr && end != nullptr && start != end && end->next != start) {
        int sum = start->data + end->data;
        if (sum == target) {
            cout << "(" << start->data << ", " << end->data << ")\n";
            start = start->next;
            end = end->prev;
        } else if (sum < target) {
            start = start->next;
        } else {
            end = end->prev;
        }
    }
}


Time Complexity: O(n)
Space Complexity: O(1)

3. Remove Duplicates from Sorted DLL

Concept:

Traverse the list and remove consecutive nodes with the same value.

C++ Example:

void removeDuplicates(Node* head) {
    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = duplicate->next;
            if (duplicate->next != nullptr)
                duplicate->next->prev = current;
            delete duplicate;
        } else {
            current = current->next;
        }
    }
}


#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool findSumBST(Node* root, int target, unordered_set<int>& s) {
    if (!root) return false;

    if (s.find(target - root->data) != s.end())
        return true;

    s.insert(root->data);

    return findSumBST(root->left, target, s) || findSumBST(root->right, target, s);
}

bool isSumExists(Node* root, int target) {
    unordered_set<int> s;
    return findSumBST(root, target, s);
}