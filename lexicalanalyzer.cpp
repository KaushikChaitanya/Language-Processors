#include<iostream>
#include <string>
#include <cctype>
#include<fstream>
using namespace std;

int main()
{
void print_tokens(const std::string &data);
std::string line;
ifstream xfile("tokens.txt");
if(xfile.is_open())
{
 while(std::getline(xfile,line))
  {
        print_tokens(line);
       std::cout<<line<<std::endl;
    }

    return 0;
}}
void print_tokens(const std::string &data)
{
    enum {
        MODE_OUTSIDE,
        MODE_IN_WORD,
        MODE_SYMBOL
    } mode = MODE_OUTSIDE;
    std::string::size_type x = 0;
    while(x < data.length()) {
        char c = data[x];
        switch(mode) {
        case MODE_OUTSIDE:
            if(std::isspace(c)) {
                x ++;
            }
            else if(std::isalnum(c)) {
                mode = MODE_IN_WORD;
                std::cout << '"';
            }
            else {
                mode = MODE_SYMBOL;
            }
            break;
        case MODE_IN_WORD:
            if(std::isalnum(c)) {
                std::cout << c;
                x ++;
            }
            else {
                std::cout << '"' << std::endl;
                mode = MODE_OUTSIDE;
            }
            break;
        case MODE_SYMBOL:
            if(!std::isalnum(c) && !std::isspace(c)) {
                std::cout << "[" << c << "]\n";
                x ++;
            }
            else {
                mode = MODE_OUTSIDE;
            }
            break;
        }
}
}
~
