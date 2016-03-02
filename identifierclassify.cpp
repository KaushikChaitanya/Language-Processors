#include<iostream>
#include<cctype>
#include<fstream>
#define SIZE 100
using namespace std;
int main()
{
        char c, name[SIZE],cname[SIZE],t;
        int i=0,flag=0,k=0;
        string keyword;
        cout<<"enter the string:";
        cin>>name;

        for(i=0;name[i] != '\0';i++)
        {
                char c = tolower(name[i]);

                if(i==0)
                {
                        if(name[i] != '_' && !(c >= 'a' && c <= 'z'))
                        {
                                flag = 44;
                                break;
                        }
                }
                else if(name[i] == '(' && name[i+1] == ')')
                {
                        if(name[i+2] == '\0')
                        {
                                k = i;
                                t = name[i];
                                break;
                        }
                }
                else if(name[i] == '[' && name[i+1] == ']')
                {
                        if(name[i+2] == '\0')
                        {
                                k = i;
                                t = name[i];
                                break;
                        }
                }
                else if(name[i] != '_' && !(c >= 'a' && c <= 'z') && !(name[i] >= 48 && name[i] <= 57))
                {
                        flag = 44;
                        break;
                }
                k = i+1;
        }

        if(flag == 44)
        {
                cout<<name<<" is not a valid identifer";
                return 0;
        }

        for(i=0;i<k;i++)                // Separating the end () or [] symbols.
        {
                cname[i] = name[i];
        }
        cname[i] = '\0';

        ifstream fhandle;
                        fhandle.open("keywords.txt");
                        if(fhandle.is_open())
                        {
                                while(getline(fhandle , keyword))
                                {
                                        if(keyword==cname)
                                        {
                                        flag=44;
                                        break;
                                        }
                                }
                        }
                                fhandle.close();

if(flag==44)
{
        cout<<name<<" is not a valid identifier";
        return 0;
}

if(t == '(')
        cout<<cname<<" is a function name\n";
else if(t == '[')
 cout<<cname<<" is an array\n";
else
        cout<<cname<<" is a variable\n";


return 0;
}

           
