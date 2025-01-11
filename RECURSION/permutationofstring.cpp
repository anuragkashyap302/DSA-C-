#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>str , int index ,vector<vector<int>> &ans){
    //base case 
    if(index >= str.size()){
        ans.push_back(str);//2d vector me 1d vector thus diye
        return;
    }
    for(int j = index ; j< str.size(); j++){//str ke har ek element ke liye call 
        swap(str[index],str[j]);
        solve(str,index+1,ans);
        //backtraking
        swap(str[index], str[j]);

    }
}
vector<vector<int>> PERMUTATION(vector<int>&str){
    vector<vector<int>> ans;
    int index = 0;
    solve(str , index  ,ans);
    return ans;
}

int main(){
    vector<int> arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  cout << " printing elemnt of set " << endl;
  for(int i =0 ;i < arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << " printing power set "<< endl;
 
  vector<vector<int>> ans = PERMUTATION(arr);

     for(int i = 0 ; i < ans.size(); i++){
        for(int j =0 ; j<ans[i].size(); j++){
            cout << ans[i][j] << " " ;

        }
        cout << endl;
     }


   

    return 0;
}