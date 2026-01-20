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
