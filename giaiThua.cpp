#include<iostream>

using namespace std;

int giaiThua(int n)
{
	if(n==0||n==1) return 1;
	int kq=1;
	for(int i=2;i<=n;i++) kq=kq*i;
	return kq;
}

main()
{
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	cout<<giaiThua(n);
}