#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>&wt,vector<int>&p,int N, int W){
	vector<vector<int>>dp(N+1,vector<int>(W+1,0));
	for(int i=1;i<=N;i++){
		for(int w=1;w<=W;w++){
			if(wt[i-1]<=w){
				dp[i][w]=max((p[i-1]+dp[i-1][w-wt[i-1]]),dp[i-1][w]);
			}
			else{
				dp[i][w]=dp[i-1][w];
			}
		}
	}
	return dp[N][W];
}

int main(){
	int N,W;
	cin>>N;
	cin>>W;
	vector<int>p(N);
	vector<int>wt(N);
	for(int i=0;i<N;i++){
		cin>>p[i];
	}
	for(int i=0;i<N;i++){
		cin>>wt[i];
	}
	cout<<knapsack(wt,p,N,W);
	return 0;
}