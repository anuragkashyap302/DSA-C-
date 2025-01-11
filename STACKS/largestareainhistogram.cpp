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
vector< int> prevsmaller(int arr[],int n){
    stack< int> s;
    vector <int> ans(n);
    s.push(-1);
for(int i=0; i<n ; i++) {
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

int largestarea(int arr[],int n){
    vector<int> next(n);
    next = nextsmaller(arr,n);

    vector<int> prev(n);
    next = prevsmaller(arr,n);
    

    int area = INT16_MIN;

     for(int i=0; i<n; i++) {
            int l = arr[i];
            //agar next me -1 hai matlab arr ke cuur se koi chota element
            //hai nahi to us curr length ka rec to pure size ka ban sakta hai na
            //width us rect ka pura arr ka size ho jayega 
            if(next[i] == -1) {
                next[i] = n;
            }

            // prav me smaller mil gya matlab khani katham us length se chota koi hai hi
            //nhi prev to rect us traf nhi extend ho sakta hai                                     
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }


int main(){
    int arr[] = {2,1,4,3};
    int n = 4;
    vector<int> res1 = nextsmaller(arr,n);
    vector<int> res2 = prevsmaller(arr,n);
    for(int i = 0;i<res1.size();i++){
        cout  <<  res1 [i] <<" ";
    }
  cout <<endl;
    for(int i = 0;i<res2.size();i++){
        cout  <<  res2 [i]  <<" ";
    }
     
    

}