#include <iostream>
using namespace std;

int main()
{
	int input[32]={0};
	
input:
	int i=0;
	do
	{
		i++;
		cin>>input[i];
	}
	while(input[i]!=-1);
	i--;
	
	//test input
	/*for(int j=1;j<=i;j++)
		cout<<input[j]<<endl;*/
		
	return 0;
}

int calc()
{
	
}
