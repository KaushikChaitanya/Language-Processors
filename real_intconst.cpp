#include<iostream>
using namespace std;
int main()
{
                char str[30];
        cout<<"Enter a String \n";
        cin>>str;
        int i,count=0,count1=0,flag=0;
        for(i=0;str[i]!='\0';i++)
         {
                if(i==0)
                {
                        if(str[i] == '+' || str[i] == '-')
                                continue;
                 }

                if(str[i]=='.')
                         count++;
                        else
                         {
                                if(str[i]<48||str[i]>57)
                                {
                                   count1++;
                                   break;
                                }
                        }
          }
          if(count1 >= 1 || count > 1)
          {
                cout<<str<<" is not a Numerical constant";
          }
          else if(count == 0)
                cout<<str<<" is a Integer constant";
         else if(count == 1)
                cout<<str<<" is a Real constant";

          return 0;
}
