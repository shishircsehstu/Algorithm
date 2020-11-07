/*
Md. Saddam Hossain
ios developer at Twinbit limited
shishir.cse.hstu@gmail.com
*/
#include<bits/stdc++.h>
using namespace std;

string main_str = "abcdefghijklmnopqrstuvwxyz";

void replace_char(string input_str, int n)
{
    for(int i=0; i<input_str.size(); i++)
    {
        int  position = int(input_str[i])-97; // finding ASCII value
        int total_replace = position+n;

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
}
int main()
{
    int n;
    string input_str;
    cin>>input_str>>n;
    replace_char(input_str,n);

    return 0;

}
