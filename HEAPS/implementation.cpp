#include<iostream>
#include<queue>
#include<vector>
using namespace std; 


class HEAP {
    public:
    int arr[100];
    int size ;
    //consectructor
     HEAP(){
         arr[0] = -1;//kyki humko indexing 1 se chiye
         size = 0;

    }
   
    void insert(int data){
        // size ko inc kar do ek element to size 1 se inc
        //jitna baar data aayega size 1 se inc hota jayega
        size = size +1;
        int index = size;
        arr[index] = data;
        // data dalnr ke badd maintian bhi to karna hai heap ko

        while(index > 1){
            int parent = index/2;
            // max heap bana rahe hai to root sbse bada
            if(arr[parent] < arr[index]){
                //curr index ko parent se swap kara diye
              swap(arr[parent],arr[index]);
              //cuur index ko parent kar diye ki upper bhi chek karga jab tak starting na pahuch jaye
              // insertion end me hota hai to curr node end wwala hoga
              //chek karke phir apne parnet ko curr node and so on chek
              //karte katre root tak pahuch jayega // while loop ke condition tak
              index = parent;
            }
            else{
                return;// matlab sab kuch sahi hai
            }
       
        }
    }
    void print(){
        for(int i =1 ; i<=size;i++){
            cout << arr[i] <<" ";

        }
        cout <<endl;
    }
    void deletefromheap(){
        if(size== 0){
            cout <<" nothig to delete"<< endl;
            return;
        }
        // delete hamesa root node hi hoga to phele root node me last node ka value daal do
        arr[1] = arr[size];
        size--;
        // last node apne gayab
        //take root node at its coorect posiotn
        //curr hum abhi root pe hai chek kartre karter last tak jana hai
        int i = 1;
        while(i<size){
            int leftchild = 2*i;
            int rightchild = 2*i+1;
            // ab max heap to root bada hona chiye dono child se
            //root matlab cuur index i
            if(leftchild <size && arr[i] < arr[leftchild]){
                swap(arr[i] , arr[leftchild]);
                i = leftchild;// cuur inex ko leftchild tak pahuha diya aur niche tak chek karega na
                // kyki ye bhi to kisika root ho aikta hai
            }
            else if(rightchild <size && arr[i] < arr[rightchild]){
                swap(arr[i],arr[rightchild]);
                i = rightchild; //yaha else if ke hagahif higa shyad dekh lo
            }
            // upper wale line ko dry run karo smjh aa jayyga
            // dono chid me jo max hoga ussi se swap hoga
            // copy me mention hai dekh lo
            else{
                return ; // matlab sahi jagha hi hia
            }
        }
    }

};

void heapify(int arr[] , int n , int i){
    int largestidx = i;// man ke chele cuur node largest hai
    int left = 2*i;
    int right = 2*i +1;
    if(left<=n && arr[largestidx]<arr[left]){
        largestidx = left;
    }
    if(right<=n && arr[largestidx]<arr[right]){
        largestidx = right;
    }
    // jo children bada tha wo largest index me aa gya 
    // largset index wale element ko cuur yani  rroot index wale element se  usse swap kar do kyki asli haqdar wahi hai us position ka

    if(largestidx!= i){//agar ye cond sahi
        // matalb largest index badal chuka
        swap(arr[largestidx],arr[i]);
        // ab largest idx me cuur index ka element pahuch gya to usko bhi
        // hepify hone bhej
        heapify(arr,n,largestidx);//largest naam ka index pass kar rahe hai
        // confuse not
        //kiye curr index hepify ho gya ek pass me ab age balla ho ga
        
    }
}

void heapsort(int arr[],int n){ //yadd rahe arr heap hona chiye tabhi heap sort lageaga agar koi random arr diya ho; to plhe heapify kar lo tab 
//heap sort laagap yaha heap diya hua hi tha isliye nahmi lagaye nhai to phle heapify call from size/2-1 to 1 and then heap sort
    int size = n;
    while(size>1){
        // swap last node with root
        swap(arr[size],arr[1]);
        size--;// swap ke badd last element sahi jagh pahuch gya

        // ab root ko sahi jagh pahucha do hepify
        heapify(arr,size,1);

    }
}

int main() {
    HEAP h;
  /*  h.insert(55);
    h.insert(54);
    h.insert(53);
    h.insert(50);
    h.insert(52);
   h. print();
*/

int arr[6] = {-1,54,53,55,52,50};
int n = 5;
// leaf node alwayas in heap
for(int i = n/2; i>0; i--){
    heapify(arr,n,i);
}


// max from stl
//priority_queue<int> pq;
//pq.push(4);
//pq.push(5);

//cout <<"element at top" << pq.top() << endl;

//min heap
//priority_queue<int ,vector<int> ,greater<int>> minheap;



}