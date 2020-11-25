#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
}*root = NULL;

Node* createNode(int newdata) {
    
    queue <Node*> q;

    Node* newNode = new Node();

    newNode->data = newdata;

    if(root == NULL){
        root = newNode;
        cout<<"added"<<newdata<<endl;
        return root;
    }

    q.push(root);
    Node* temp;

    while(1) {
        temp = q.front();
        if(temp->left==NULL){
            temp->left = newNode; 
            cout<<"added"<<newdata<<endl;
            return temp->left;
        }
        else if(temp->right == NULL){
            temp->right = newNode;
            cout<<"added"<<newdata<<endl;
            return temp->right;
        }
        q.push(temp->left);
        q.push(temp->right);
        q.pop();
    }

}

void levelOrder() {
    queue <Node*> q;
    q.push(root);
    Node* temp;
    while(!q.empty()) {
        temp = q.front();
        cout<<temp->data<<", ";
        q.pop();
        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
    }
    cout<<endl;
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

    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    createNode(6);
    createNode(7);
    levelOrder();
    InOrder(root);
    cout<<endl;
    PreOrder(root);
    cout<<endl;
    PostOrder(root);

return 0;
}