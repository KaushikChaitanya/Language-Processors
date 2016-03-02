#include<iostream>
#include<string>
using namespace std;
int main()
{
        string line,str;
        int pos;
        cout<<"enter the production:";          //only cfg
        cin>>line;
        str=line[0];
        pos=line.find('/');
        if(str[0]==line[3])
        {
                cout<<"left recursion exists";
                exit(0);
        }
        else
        {
                while(pos!=-1)
                {
                        if(line[pos+1]==str[0])
                        {
                                cout<<"left recursion exists";
                        exit(0);
                        }
                        line=line.substr(pos+1);
                        pos=line.find('/');
                }
                cout<<"left recursion does not exist";
        }
}
