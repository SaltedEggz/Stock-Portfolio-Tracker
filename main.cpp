#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
using std::cin;
using std::cout; 
using std::ios;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

struct Stock{
    string symbol;
    double price;
    int shares;
};

void loadPortfolio(vector<Stock>& portfolio){
    ifstream inFile("portfolio.txt");
    if(!inFile){
        cout<<"No exsisting portfolio found. Starting new.\n";
    }

    Stock s;
    while(inFile >> s.symbol>>s.price>>s.shares){
        portfolio.push_back(s);
    }
    inFile.close();
}

void savePortfolio(const vector<Stock>& portfolio) {
    ofstream outFile("portfolio.txt");
    if (!outFile) {
        cout << "Error saving portfolio.\n";
        return;
    }

    for (const Stock& s : portfolio) {
        outFile << s.symbol << " " << s.price << " " << s.shares << endl;
    }

    outFile.close();
}






void displayPortfolio(const vector<Stock>& portfolio)
{
    double total = 0;
    cout<<"--- Your Portfolio ---"<<endl;
    for(const Stock& s : portfolio){
        cout<<s.symbol<<": $"<<s.price<< " x " <<s.shares<<endl;
        total += s.price * s.shares;
    }
    cout<<"Total portfolio value: $"<<total<<endl;
}


void addStock(vector<Stock>& portfolio)
{
    Stock s; 
    cout<<"Symbol: ";
    cin>>s.symbol;
    cout<<"Price: ";
    cin>>s.price;
    cout<<"Shares: ";
    cin>>s.shares;
    
    portfolio.push_back(s);
    cout<<"Added sucessfully"<<endl<<endl;
}


void removeStock(vector<Stock>& portfolio)
{
    string symbol;
    cout<<"Symbol of stock to remove: ";
    cin>>symbol;

    bool found = false;

    for(auto it = portfolio.begin(); it !=portfolio.end(); ++it){
        if(it->symbol == symbol){
            portfolio.erase(it);
            cout<<"Stock removed.\n";
            found = true;
            break;
        }
    }
    if(!found) cout<<"Stock not found.\n";
}


void updateStock(vector<Stock>& portfolio) {
    string symbol;
    cout << "Stock to update: ";
    cin >> symbol;

    bool found = false;
    for (Stock& s : portfolio) {
        if (s.symbol == symbol) {
            cout << "New price: "; cin >> s.price;
            cout << "New shares: "; cin >> s.shares;
            found = true;
            break;
        }
    }
    if (found) cout << "Stock updated successfully!" << endl;
    else cout << "Stock not found." << endl;
}



int main()
{   
    vector<Stock> portofolio;
    loadPortfolio(portofolio);
    
    int choice;
    
    do {
        cout <<"\n=== Stock Portfolio Menu ====\n";
        cout<<"1. Display Portfolio\n";
        cout<<"2. Add Stock\n";
        cout<<"3. Remove Stock\n";
        cout<<"4. Update Stock\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                displayPortfolio(portofolio);
                break;
            case 2:
                addStock(portofolio);
                break;
            case 3:
                removeStock(portofolio);
                break;
            case 4:
                updateStock(portofolio);
                break;
            case 5:
                cout<<"Exiting...."<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
            }
     }while(choice != 5);

    return 0;

 }
