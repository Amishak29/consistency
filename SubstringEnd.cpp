/*Print each string letter one time*/
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string str = "GeeksforGeeks";
 
    for (int i = 0; i < str.size(); i++)
    {
        int flag = 0,counter=0;
        for (int j = 0; j < str.size(); j++)
        {
            // checking if two characters are equal
            if (str[i] == str[j] and i != j)
            {
                flag++;
                counter++;
            }
        }
        if (flag == 0 || flag==1){
            cout << str[i];
        }
        // if(flag>=1){
        //     cout<<str[i];
        // }
        //     break;
        flag=0;
    }
 
    return 0;
} 
