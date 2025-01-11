#include<iostream>
#include<vector>
using namespace std;
bool issafe(int x ,int y ,int n,vector<vector<int>> visited,vector<vector<int>> &nums){
    if((x >= 0 && x <n) && (y >= 0 && y <n)  && visited[x][y] == 0 && nums[x][y]==1){
        // 4 condtn me hum next step le skte hai uper likha huma hai
        // visited nahi hona chiye and nms me us ghar me 1 hona chiye
        return true;
    }
    else{
        return false;
    }

}

void solve(vector<vector<int>> &nums ,int n , vector<string> &ans , int x , int y ,vector<vector<int>> visited , string path){
    // you have to raeah last ghar
    if( x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    //phele ghar me kadam rakho
    visited[x][y] = 1;
    // raat have 4 choics R ,l , U ,D
     // suraaat down se karte hai yaad rahe kadam wahi rakhna hai jha 1 hoga arr me


     //down
     int newx = x+1; // down janne se row mw chane
     int newy = y ; // col me no change

     if(issafe(newx , newy , n , visited , nums)){
      path.push_back('D'); // agar safe hai path me down  add kar do ki raste me down le sakte hai
      // recurison lga do har bar chech karega down jana sahi ya nahi 
      solve(nums ,n , ans , newx,newy ,visited ,path);
      path.pop_back(); // wapas atte wakt path me jo dale uso hatta do 
      // backtraking hai dry run kar

     }
     //left
      newx = x; // left janne se row me no chane
      newy = y-1 ; // col me  change

     if(issafe(newx , newy , n , visited , nums)){
      path.push_back('L'); // agar safe hai path me down  add kar do ki raste me down le sakte hai
      // recurison lga do har bar chech karega down jana sahi ya nahi 
      solve(nums ,n , ans , newx,newy ,visited ,path);
      path.pop_back(); // wapas atte wakt path me jo dale uso hatta do 
      // backtraking hai dry run kar


}

//right step
     int newx = x; // down janne se row mw no chane
     int newy = y+1 ; // col me  change

     if(issafe(newx , newy , n , visited , nums)){
      path.push_back('R'); // agar safe hai path me down  add kar do ki raste me down le sakte hai
      // recurison lga do har bar chech karega down jana sahi ya nahi 
      solve(nums ,n , ans , newx,newy ,visited ,path);
      path.pop_back(); // wapas atte wakt path me jo dale uso hatta do 
      // backtraking hai dry run kar
     }
//up step
      newx = x-1; // up janne se row mw chane
      newy = y ; // col me no change

     if(issafe(newx , newy , n , visited , nums)){
      path.push_back('U'); // agar safe hai path me down  add kar do ki raste me down le sakte hai
      // recurison lga do har bar chech karega down jana sahi ya nahi 
      solve(nums ,n , ans , newx,newy ,visited ,path);
      path.pop_back(); // wapas atte wakt path me jo dale uso hatta do 
      // backtraking hai dry run kar
}

// jo ghar visit kar gaye uksa jarrut phir par sakta hai agle path ko dhddhne me to
// ab aur tarika chie to janne se phle visited ko phir se zero kar do
visited[x][y] = 0;

}
vector <string> ratinmaze(vector<vector<int>> &nums ,int n ){
   vector<string> ans;
   if(nums[0][0]== 0){
    return ans;

   }

   int srcx = 0;
   int srcy = 0;
   // nums ke size ka ek 2d vector bna diye jo ki record rakhega kon sa ghar visdit kar chuke hai

   vector<vector<int>> visited = nums;
   //intialisde with zero
   for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j< n ;j++){
      visited[i][j] = 0;
    }
   }

   string path = " "; // ek khali string bna diye jo ki har path ko store karega
   solve(nums ,n ,ans ,srcx ,srcy , visited ,path);


}
int main(){
    return 0;

}