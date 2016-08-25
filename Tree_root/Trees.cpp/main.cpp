//
//  main.cpp
//  Trees.cpp
//
//  Created by Nirupama Prasad on 8/20/16.
//  Copyright © 2016 Nirupama Prasad. All rights reserved.
//
#include<iostream>
//#include<conio>
using std::cout;
using std::cin;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

class Tree{
        public:
    Node* root;
    int count;

    Tree(){
        root = NULL;
        count = 1;
    }
    int height(Node* node)
    {
        if (node==NULL)
            return 0;
        else
        {
            /* compute the height of each subtree */
            int lheight = height(node->left);
            int rheight = height(node->right);
            
            /* use the larger one */
            if (lheight > rheight)
                return(lheight+1);
            else return(rheight+1);
        }
    }

    void CTCIq1(Node* node1){
        
        /* compute the height of each subtree */
        int lheight = height(node1->left);
        int rheight = height(node1->right);
        if((lheight-rheight>1)||(rheight-lheight>1))
            cout<<"The tree is not balanced";
        else
            cout<<"The tree is balanced";
    }


    Node *insert(Node *tree,int ele)
    {
        if(tree==NULL)
        {
            tree=new Node;
            tree->left=tree->right=NULL;
            tree->data=ele;
            count++;
        }
        else
            if(count%2==0)
                tree->left=insert(tree->left,ele);
            else
                tree->right=insert(tree->right,ele);
        return(tree);
    }
    
    void create(int elem)
    {
        Node* Node1= new Node;
        if (root == NULL)
        {
            root = new Node;
            root->data = elem;
        }
        int choice = 0;
        while(choice!=2)
        {
            cout<<" Enter 1 to enter new element and 2 to stop ";
            cin>>choice;
            if (choice == 1){
                cout<<"Enter new element ";
                cin>>Node1->data;
                root = insert(root, Node1->data);
            }else if (choice == 2)
            {return;}
            else cout<<"Invalid choice";
        }
    }

    void print(){
        int choice = 0;
        cout<<"1. Preorder"
        <<"\n2. Postorder"
        <<"\n3. Inorder";
        cin>>choice;
        switch(choice)
        {
            case 1: preorder(root);
                break;
            case 2: postorder(root);
                break;
            case 3: inorder(root);
                break;
            default:
                cout<<"Invalid choice! Go back to start. ";
        }
    }
    
    void isMember(int elem){
        

    }
    
    void preorder(struct Node* node1){
        if(node1==NULL){
            cout<<"\n ";            //What the heck?
            return;
        }
        cout<<node1->data;
        preorder(node1->left);
        preorder(node1->right);
    }
    void postorder(struct Node* node1){
        if(node1==NULL){
            cout<<"\n ";
            return;
        }
        postorder(node1->left);
        postorder(node1->right);
        cout<<node1->data;
    }
    void inorder(struct Node* node1){
        if(node1==NULL){
            cout<<"\n ";
            return;
        }
        inorder(node1->left);
        cout<<node1->data;
        inorder(node1->right);
    }
    void DFS(Node *Node1)
        {
            if (Node1)
            {
                if (Node1->left)
                {
                    DFS(Node1->left);
                }
                if (Node1->right)
                {
                    DFS(Node1->right);
                }
                cout<<Node1->data;
            }
        }
    void BFS(Node* root)
    {
        int h = height(root);
        int i;
        for (i=1; i<=h; i++)
            printlevel(root, i);
    }
    
    /* Print nodes at a given level */
    void printlevel(Node* root, int level)
    {
        if (root == NULL)
            return;
        if (level == 1)
           cout<<root->data;
        else if (level > 1)
        {
            printlevel(root->left, level-1);
            printlevel(root->right, level-1);
        }
    }
}T1;

/*Q3*/
struct Q3Node{
    int key;
    Q3Node *left, *right, *parent;
};
    Q3Node* p = NULL, node[100];
    int cnt = 0;
void q3createminitree(Q3Node* &head, Q3Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        q3createminitree(head->left, head, a, start, mid-1);
        q3createminitree(head->right, head, a, mid+1, end);
    }
}

int height(Q3Node *head){
    if(head == NULL) return 0;
    return std::max(height(head->left), height(head->right)) + 1;
}
/*****q5 -- uses q3 logic*/
Q3Node* minimal(Q3Node* no){
    if(no == NULL) return NULL;
    while(no->left)
        no = no->left;
    return no;
}
Q3Node* successor(Q3Node* no){
    if(no == NULL) return NULL;
    if(no->right) return minimal(no->right);
    Q3Node *y = no->parent;
    while(y && y->right==no){
        no = y;
        y = y->parent;
    }
    return y;
}
/******/
int main(){
    
    /* Data variables */
    int a[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8
    };
    Q3Node *head = NULL;
    int ch=10, element;
    
    /* Menu */
    
    do{
        cout<< "\n        Menu   ";
        cout<< "\n        ----   ";
        cout<< "\n 1. Create a tree"
        << "\n 2. Add an element"
        << "\n 3. Search if present"
        << "\n 4. Print the tree"
        << "\n 5. DFS "
        << "\n 6. BFS "
        << "\n 7. CTCI Q1 Solution "
        << "\n 8. CTCI Q3 Solution "
        << "\n 9. CTCI Q5 Solution "
        << "\n 0. Exit ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter root data ";
                cin>>element;
                T1.create(element);
                break;
            case 2:
                cout<<"Enter the element :";
                cin>>element;
                T1.insert(T1.root, element);
                break;
            case 3:
                cout<<"Enter the element :";
                cin>>element;
                T1.isMember(element);
                break;
            case 4:
                T1.print();
                break;
            case 5:
                T1.DFS(T1.root);
                break;
            case 6:
                T1.BFS(T1.root);
                break;
            case 7:
                T1.CTCIq1(T1.root);
                break;
            case 8:
                q3createminitree(head, NULL, a, 0, 8);
                cout<<height(head)<<std::endl;
                break;
            case 9:
                q3createminitree(head, NULL, a, 0, 8);
                cout<<"the head is "<<head->key<<std::endl;
                cout<<"the successor of head is: "<<(successor(head))->key<<std::endl;
                break;
            case 0:
                return 0;
                break;
            default:
                cout<<"\n Invalid choice ";
        }
        }while(ch!=0);
        return 0;
    }