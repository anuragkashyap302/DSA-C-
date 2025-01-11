#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int> &arr,vector<int>output,int index , vector<vector<int>> &ans){
    //base case
    if(index>= arr.size()){
        ans.push_back(output);
        return;
        
    }
    //exculiding curent element jo power set banga
    solve(arr,output ,index+1,ans);

    //including cuureent element jo power set banega uso solave by recursion
    int element = arr[index];
    output.push_back(element); //cuur element ko power set me include kar diye
    solve(arr,output,index+1 ,ans); //agle element ke liye call


}
vector<vector<int>> POWERSET(vector<int> &arr){
    //output me 2d vector hai ek vectoir ke andar sabhi power set vector {{},{1},{1,2}.....} so on
    vector<vector<int>> ans;
    // har ek power set isme store hoga single power set to 1d vector hi hai na 
    vector<int> output;
    int index = 0; 
    solve(arr,output , index , ans);
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
 
  vector<vector<int>> ans = POWERSET(arr);

     for(int i = 0 ; i < ans.size(); i++){
        for(int j =0 ; j<ans[i].size(); j++){
            cout << ans[i][j] << " " ;

        }
        cout << endl;
     }


   



    return 0;
}