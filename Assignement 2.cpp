#include<bits/stdc++.h>
#define MAXSIZE 3
using namespace std;
int q[MAXSIZE],r=-1,f=-1;
void display (){
	cout<<"\n\n\t"<<"element"<<"\t\t"<<"Position ";
	for(int i=0;i<=r;i++){
		cout<<"\n\n\t"<<q[i]<<"\t\t"<<i;
	}
}
int insert(){
	int ele;
	if(r==MAXSIZE-1){
		cout<<"Q is full \n";
	}
	else{
		r++;
		cout<<"enter the number \n";
		cin>>ele;
		q[r]=ele;
		cout<<ele<<"is inserted at"<<r<<endl<<endl;
	}
}
int del(){
	int ele;
	
	if(r==f){
		cout<<"Q is empty\n";
		}
	else{
		f++;
		q[f]=ele;
		cout<<"\n the number is deleted"<<ele;}	
	}

int main(){
	
	int ch;
	while(true){
	int ch;
	cout<<"1.insert the number\n";
	cout<<"2 delete the number\n";
	cout<<"3.display the output\n";
	cout<<"4.exit\n";
	cin>>ch;
	switch(ch){
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			display();
			break;
		case 4:
			cout<<"exit";
			exit(0);
			break;
		default:
			cout<<"!!!INVALID INPUT";
		}
	}
}
	


