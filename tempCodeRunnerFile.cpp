#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<stdlib.h>
using namespace std;
struct node{
	char  data;
	node* left;
	node* right;
};
void postorder(node* root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
int main(){
	int n;cout<<"enter n :";
	cin>>n;

	vector<char>preorder;
    queue<char>inorder; 
    stack<node*>stackback;

	cout<< "PREORDER INPUT" <<endl;
	for(int i=0;i<n;i++){
		char a;cin>>a;preorder.push_back(a);
	}
    cout<<"INORDER INPUT"<<endl;

	for(int i=0;i<n;i++){
		char a;
        cin>>a;
        inorder.push(a);
	}
	node *root= new node;
	root->data=preorder[0];
    root->right=root->left=0;

	stackback.push(root); 

	int cnt=0;bool left=0,right=0;
	
    while(cnt<n){
		node *ptr,*prev;
		if(!(left+right)){
            ptr = stackback.top();
            stackback.pop();
        }
		else{
            ptr=new node;
            ptr->data=preorder[cnt];
            ptr->left=ptr->right=0;
		    prev=stackback.top();
        }

		//insert into the tree
		if(left){
            prev->left=ptr;
            }
		else if(right){
            prev->right=ptr;
            stackback.pop();
            }
		//equality check
		if(ptr->data == inorder.front()){
			inorder.pop();
			if(!stackback.empty()){
				if(inorder.front()==stackback.top()->data)
				left=right=0;

				else {
                left=0;right=1;cnt++;
                stackback.push(ptr);
                }
			}
			else {left=0;right=1;cnt++;stackback.push(ptr);}
		}
		else
			{right=0;left = 1;cnt++;stackback.push(ptr);}
	}
	postorder(root);
}