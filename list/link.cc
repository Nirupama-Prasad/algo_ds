#include <iostream>

using namespace std;

class Node{

public:
	Node(){ left = right = NULL;}
	Node *left, *right;
	int data;
};


class Tree {

public:
Node* root;

			Tree(){
				root = NULL;
			}

		void insert(Node* elem, int data){
			cout << "inserting " << endl;
			if (elem == NULL){
								elem = new Node();
								cout << "creating new node" << endl;
								elem->data = data;	
				}
		}

		void update_root(Node*& root, int data){
			cout << "Updating root" << endl;
			root->data = data;
		}

};


int main(int argc, char** argv){
		Tree t1;

		t1.insert(t1.root, 10);
		cout << "root value is " << t1.root->data << endl;
		t1.update_root(t1.root, 20);
		cout << "root value is now " << t1.root->data << endl;
}
