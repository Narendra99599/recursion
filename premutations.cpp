#include<bits/stdc++.h>
using namespace std;


void findPremu2(int idx,vector<int>&arr){
    if(idx == arr.size()){
        for(auto ele : arr)
            cout << ele << " ";
        cout << endl;
    }

    for(int i = idx; i < arr.size(); i++){
        swap(arr[i],arr[idx]);
        findPremu2(idx+1,arr);
        swap(arr[i],arr[idx]);
    }
}

void findPremu1(int idx, vector<int>& arr , vector<int>& ans,vector<bool>& vis){
    if(idx == arr.size()){
        for(auto ele : ans)
            cout << ele << " ";
        cout << endl;
    }
    for(int i=0; i<arr.size(); i++){
        if(vis[i] == false){
            vis[i] = true;
            ans.push_back(arr[i]);
            findPremu1(idx+1,arr,ans,vis);
            vis[i] = false;
            ans.pop_back();
        }
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> ans;
    vector<bool> vis(n,false);
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    findPremu1(0,arr,ans,vis);
    findPremu2(0,arr);
}