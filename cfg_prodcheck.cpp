#include<iostream>
#include<string>
using namespace std;
int main()
{
        int i,count=0;
        string line;
        cout<<"enter the production:";
        cin>>line;
        if((line[0]>='A'&&line[0]<='Z')&&line[1]=='-'&&line[2]=='>')
        for(i=3;i<line.length();i++)
        if((line[i]>='A'&&line[i]<='Z')||(line[i]>='a'&&line[i]<='z'))
        count=1;
        else
        {
                count=0;
                cout<<"not a cfg";
                exit(0);
        }
        else
        cout<<"not a cfg";
        if(count==1)
        cout<<"it is a cfg";
}
