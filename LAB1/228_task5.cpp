#include<iostream>
using namespace std;

int main(){
int n,first,second,third;
cout<<"Enter initial geese count:";
cin>>n;

first=((n*13)/2)+1;
cout<<"Geese count after year 1:"<<first+n<<endl;

second=((((first+n)*13))/2)+1;
cout<<"Geese count after year 2:"<<second+first+n<<endl;


third=((((second+first+n)*13))/2)+1;
cout<<"Geese count after year 3:"<<second+third+n+first;


}