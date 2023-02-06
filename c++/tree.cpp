#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
};

node* buildtree(node*root){

    int data;
    cout<<"enter data:"<<endl;
    cin>>data;

    if(data==-1){
        return NULL;
    }
    //initialising node
    root=new node(data);

    //initialising left child
    cout<<"enter value of left child of node "<< data<<": "<<endl;
    root->left=buildtree(root->left);
    //initialising right child
    cout<<"enter value of right child of node "<< data<<": "<<endl;
    root->right=buildtree(root->right);

    return root;
}

node* display(node*root){
    if(root==NULL){
        cout<<"EMPTY!!"<<endl;
        return NULL;
    }

    cout<<"Data: "<<root->data<<endl;

    cout<<"Value of left child of "<<root->data<<" :"<<endl;
    root->left=display(root->left);

    cout<<"Value of right child of "<<root->data<<" :"<<endl;
    root->right=display(root->right);

    return root;
}

void leveltraversal(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp=q.front();    // queue ka first element
        // cout<<temp->data<<endl;
        q.pop();

        if(temp==NULL){ //purana level khatam hogaya
            cout<<endl;
        
            if(!q.empty()){
                q.push(NULL);   //still some child left
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){ //temp ka left agar exists karta h toh
            q.push(temp->left);        
            }

            if(temp->right){    //right exists
                q.push(temp->right);
            }

        }
       
    }

    return ;

}

void inorder(node*root){
    //base case
    if(root==NULL){
        return;
    }

    inorder(root->left);    //l
    cout<<root->data<<" ";  //n
    inorder(root->right);   //r

}

void preorder(node*root){
    //follows NLR
    //base case
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*root){
    //follows LRN
    //base case
    if(root==NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
   
}

void buildtreelevelorder(node*&root){
    queue<node*> q;
    int data;
    cout<<"enter root: "<<endl;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();

        cout<<"Enter left node of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        
        cout<<"Enter right node of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }

    }

}


 
int main(){

    node*root=NULL;
    root=buildtree(root);

    // root=display(root);

    leveltraversal(root);
    cout<<"Inorder traversal "<<endl;
    inorder(root);
    cout<<"\npreorder travesal"<<endl;
    preorder(root);
    cout<<"\npostorder travesal"<<endl;
    postorder(root);


    node*root2=NULL;
    buildtreelevelorder(root2);
    leveltraversal(root2);

    
    return 0;
}

//
