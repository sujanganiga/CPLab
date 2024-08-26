#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node * left;
		Node * right;
		Node(int d){
			data=d;
			left=nullptr;
			right=nullptr;
		}
};
Node* conLevel(vector<int>&arr,int N,int i){
	if(i>=N){
		return nullptr;
	}
	Node * root=new Node(arr[i]);
	root->left=conLevel(arr,N,2*i+1);
	root->right=conLevel(arr,N,2*i+2);
	return root;
}
bool isBst(Node * root,int minVal, int maxVal ){
	if(root==nullptr){
		return true;
	}
	if(root->data<=minVal||root->data>=maxVal){
		return false;
	}
	return isBst(root->left,minVal,root->data)&&isBst(root->right,root->data,maxVal);
}
int main(){
	int N;
	cin>>N;
	vector<int>arr(N);
	for(int i=0;i<N;i++ ){
		cin>>arr[i];
	}
	Node * root=conLevel(arr,N,0);
	bool isb=isBst(root,INT_MIN,INT_MAX);
	cout << arr[0] << " " << (isb ? "YES" : "NO") << endl;
}