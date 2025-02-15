#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;


struct Node {
    char data;
    int freq;
    Node *left, *right;
    
    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};


struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};


void printCodes(Node* root, string str) {
    if (!root) return;
    
    if (root->data != '\0') 
    {
        cout << root->data << " : " << str <<  endl;
    }
    
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void huffmanCoding(string S, vector<int> f)
{
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    
    for (int i = 0; i < S.size(); i++)
    {
        minHeap.push(new Node(S[i], f[i]));
    }
    
    while (minHeap.size() > 1) 
    {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();
        
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        
        minHeap.push(newNode);
    }
    
    Node* root = minHeap.top();
    printCodes(root, "");
}

int main() 
{
    string S;
    vector<int> frequencies;
    cout << "Enter the string" << endl;
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        int frequency;
        cout << "enter the frequency of the character " << S[i] << endl;
        cin  >> frequency;
        frequencies.push_back(frequency);
    }
       
    huffmanCoding(S, frequencies);
    return 0;
}
