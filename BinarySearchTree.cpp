#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
}*root=NULL;

Node* insert(Node* temp, int newdata) {
    Node* newNode = new Node();
    newNode->data = newdata;

    if(root == NULL) {
        root = newNode;
    }
    if(temp == NULL) {
        temp = newNode;
        cout<<temp->data<<endl;
        return newNode;
    }
    if(newdata < temp->data) {
        temp->left = insert(temp->left, newdata);
    }
    else if(newdata > temp->data) {
        temp->right = insert(temp->right, newdata);
    }
    return temp;
}

void levelOrder(Node* temp) {
    queue <Node*> q;
    q.push(temp);
    int x;
    while(!q.empty()) {
        temp = q.front();
        cout<<temp->data<<", ";
        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
        q.pop();
    }
}

void InOrder(Node* temp) {
    if(temp==NULL) {
        return;
    }
    InOrder(temp->left);
    cout<<temp->data<<", ";
    InOrder(temp->right);
}

void PreOrder(Node* temp) {
    if(temp==NULL) {
        return;
    }
    cout<<temp->data<<", ";
    PreOrder(temp->left);
    PreOrder(temp->right);
}

void PostOrder(Node* temp) {
    if(temp==NULL) {
        return;
    }
    PostOrder(temp->left);
    PostOrder(temp->right);
    cout<<temp->data<<", ";
}

int main() {
    insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);
    levelOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PreOrder(root);
    cout<<endl;
    PostOrder(root);
    return 0;
}