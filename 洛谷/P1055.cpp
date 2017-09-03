#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numbers[9];
    int scom = 0;
    string input;
    cin>>input;
    int count = 0;
    for (int i=0; i<input.length(); i++)
    {
        if (input[i] == 'X')
            scom = 10;
        else if (input[i] >= '0' && input[i] <= '9')
        {
            if (count < 9)
            {
                numbers[count] = input[i] - '0';
                count++;
            }
            else
            {
                scom *= 10;
                scom += (int)(input[i] - '0');
            }
        }
    }
    int sum = 0;
    for (int i=0; i<9; i++)
    {
        sum += (i + 1) * numbers[i];
    }
    if (scom == sum % 11)
        cout<<"Right";
    else
    {
        cout<<numbers[0]<<"-"<<numbers[1]<<numbers[2]<<numbers[3]<<"-"<<numbers[4]<<numbers[5]<<numbers[6]<<numbers[7]<<numbers[8]<<"-";
        if (sum % 11 == 10)
            cout<<"X";
        else cout<<(sum % 11);
    }
    //getchar();getchar();
    return 0;
}
