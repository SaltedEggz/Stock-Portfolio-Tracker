#include <iostream>
#include <fstream>
#include <string>


using std::cin;
using std::cout; 
using std::endl;
using std::ifstream;
using std::string;

int main()
{
    ifstream stockFile("portfolio.txt");
    if(!stockFile){
        cout<<"Could not open portfolio.txt"<<endl;
        return 1;

    }

    string stock;
    double price, total = 0;

    cout<<"Your portfolio: "<<endl;
    while(stockFile >> stock >> price){
        cout<<stock<<": $"<<price<<endl;
        total += price;
    }

    cout<<"Total portfolio value: $"<<total<<endl;

    return 0;
}