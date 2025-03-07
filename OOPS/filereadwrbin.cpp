#include <iostream>
#include <fstream>
#include <iomanip> //for setfill() and setw()
using namespace std;
#define FILE_NAME "time.dat"
//function to write time into the file
void writeTime(int h, int m, int s){	
	char str[10];
	fstream file;
	file.open(FILE_NAME, ios::out|ios::binary);
	if(!file){
		cout<<"Error in creating file!!!"<<endl;
		return;
	}
	//make string to write
	sprintf(str,"%02d:%02d:%02d",h,m,s);
	//write into file
	file.write(str,sizeof(str));
	cout<<"Time "<<str<<" has been written into file."<<endl;
	//close the file
	file.close();
}
//function to read time from the file
void readTime(int *h,int *m, int *s){
	char str[10];
	int inH,inM,inS;
	fstream finC;
	finC.open(FILE_NAME,ios::in|ios::binary);
	if(!finC){
		cout<<"Error in file opening..."<<endl;
		return;
	}
	if(finC.read((char*)str,sizeof(str))){
		//extract time values from the file
		sscanf(str,"%02d:%02d:%02d",&inH,&inM,&inS);
		//assign time into variables, which are passing in function
		*h=inH;
		*m=inM;
		*s=inS;
	}
	finC.close();	
}

int main(){
	int m,h,s;
	
	cout<<"Enter time\n";
	cout<<"Enter hour: "; 	cin>>h;
	cout<<"Enter minute: "; cin>>m;
	cout<<"Enter second: "; cin>>s;

	//write time into file
	writeTime(h,m,s);
	
	//now, reset the variables
	h=m=s=0;
	
	//read time from the file 
	readTime(&h,&m,&s);
	
	//print the time
	cout<<"The time is "<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<":"<<setw(2)<<setfill('0')<<s<<endl;	
	
	return 0;
}