#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int flag=0;
int main(){
	//freopen("1618.in","r",stdin);
	int a,b,c; 
    cin>>a>>b>>c;
    int ta,tb,tc;
    for(int n1=1;n1<=9;n1++)
    for(int n2=1;n2<=9;n2++)
    {
	if(n2==n1)continue;
	for(int n3=1;n3<=9;n3++)
	{
    if(n3==n2||n3==n1)continue;
    for(int n4=n1+1;n4<=9;n4++)
    {
    if(n4==n3||n4==n2||n4==n1)continue;
    for(int n5=1;n5<=9;n5++)
    {
    if(n5==n4||n5==n3|n5==n2||n5==n1)continue;
    for(int n6=1;n6<=9;n6++)
    {
    if(n6==n5||n6==n4||n6==n3|n6==n2||n6==n1)continue;
    for(int n7=n4+1;n7<=9;n7++)
    {
    if(n7==n5||n7==n4||n7==n3|n7==n2||n7==n1||n7==n6)continue;
    for(int n8=1;n8<=9;n8++)
    {
    if(n8==n5||n8==n4||n8==n3|n8==n2||n8==n1||n8==n6||n7==n8)continue;
    for(int n9=1;n9<=9;n9++)
    if(n1!=n9
    &&n2!=n9
    &&n3!=n9
    &&n4!=n9
    &&n5!=n9
    &&n6!=n9
    &&n7!=n9
    &&n8!=n9)
    {
    	ta=(n1*100+n2*10+n3);
    	tb=(n4*100+n5*10+n6);
    	tc=(n7*100+n8*10+n9);
    	if(ta/(float)a==tb/(float)b&&tb/(float)b==tc/(float)c)
        {
        	cout<<ta<<" "<<tb<<" "<<tc<<endl;
        	flag=1;
		}
    }
}}}}}}}
    if(flag==0)cout<<"No!!!";
    return 0;
}
