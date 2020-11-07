#include<bits/stdc++.h>
using namespace std;

string main_str = "abcdefghijklmnopqrstuvwxyz";
int main()
{
    int n,position,total_replace;
    string input_str;
    cin>>input_str>>n;

    for(int i=0; i<input_str.size(); i++)
    {
        position = int(input_str[i])-97; // finding ASCII value
        total_replace = position+n;

        if ((total_replace)<=25) // total character 26 and started from 0 index so 25.
        {
            cout<<main_str[total_replace];
        }
        else
        {
            int div = total_replace/26;
            int new_position = total_replace - (div*26);
            cout<<main_str[new_position];
        }
    }
    return 0;

}
