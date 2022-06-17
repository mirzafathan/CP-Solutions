#include <bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        if(!node) return NULL;
        Node* clones = new Node(node->val, {});
        queue<Node*> q;
        q.push(node);
        
        mp[node] = clones;
        
        while(!q.empty()) {
            Node* temp = q.front();
            vector<Node*> nb = temp->neighbors;
            q.pop();
            for(int i=0; i<nb.size(); i++) {
                if(!mp[nb[i]]) {
                    q.push(nb[i]);
                    Node* newNb = new Node(nb[i]->val, {});
                    mp[nb[i]] = newNb;
                }
                mp[temp]->neighbors.push_back(mp[nb[i]]);
            }
        }
       /* 
        cout << clones->val << endl;
        for(int i=0; i<clones->neighbors.size(); i++) {
            cout << clones->neighbors[i]->val << " ";
        }
        cout << endl << clones->neighbors[0]->neighbors[0]->val << endl;
        */
        return mp[node];
    }
};