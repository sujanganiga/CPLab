#include<iostream>
#include<vector>
using namespace std;

vector<int> rotate(vector <int> arr,int k){
    int n=arr.size();
    k=k%n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        v[(i+n-k)%n]=arr[i];
    }
    return v;
}

void display(vector <int> v){

    for(int i=0; i<v.size();i++){
        cout<<v[i]<<"\t";
    }

}
int main(){
    vector<int> arr={1,2,3,4,5};
    int k=2;
    cout<<"original array -->"<<endl;
    display(arr);
    cout<<endl<<"rotated array -->"<<endl;
    display(rotate(arr,k));    

}