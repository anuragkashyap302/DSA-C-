#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector< int> nextsmaller(int arr[],int n){
    stack< int> s;
    vector <int> ans(n);
    s.push(-1);
for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
    
}
int main(){
    int arr[] = {2,1,4,3};
    int n = 4;
    vector<int> res = nextsmaller(arr,n);
    
     
    

}