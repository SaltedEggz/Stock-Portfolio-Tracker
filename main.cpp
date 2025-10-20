#include <iostream>
#include <fstream>
#include <string>


using std::cin;
using std::cout; 
using std::ios;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;


void displayPortfolio()
{
    string stock;
    int shares;
    double price;  
    double total = 0;
    cout<<endl;
    ifstream stockFile("portfolio.txt");
        if(!stockFile){
            cout<<"Could not open portfolio.txt"<<endl;   
        }
    

        cout<<"--- Your Portfolio ---"<<endl;
        while(stockFile >> stock >> price >> shares){
            cout<<stock<<": $"<<price<< " x " <<shares<<endl;
            total += price * shares;
        }

        cout<<"Total portfolio value: $"<<total<<endl;
}


void addStock()
{
    string stock;
    int shares;
    double price;  

    cout<<endl;
    ofstream outFile("portfolio.txt", ios::app);
    if(!outFile){
        cout<<"Could not open portfolio.txt"<<endl;
           
    }
    cout<<"Symbol: ";
    cin>>stock;
    cout<<"Price: ";
    cin>>price;
    cout<<"Shares: ";
    cin>>shares;
    outFile<<stock<<" "<<price<<" "<<shares<<endl;
    outFile.close();
    cout<<"Added sucessfully"<<endl<<endl;
}


void removeStock(){
    string stockToRemove;
    cout<<"Symbol of stock to remove: ";
    cin>>stockToRemove;

    ifstream inFile("portfolio.txt");
    if(!inFile){
        cout<<"Could not open txt"<<endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if(!tempFile){
        cout<<"ERROR tempFile could not be created."<<endl;
        return;
    }

    string stock;
    double price;
    int shares;
    bool found = false;

    while(inFile>>stock>>price>>shares){
        if(stock != stockToRemove){
            tempFile<<stock<<" "<<price<<" "<<shares<<endl;        
        }else{
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    if(found){
        remove("portfolio.txt");
        rename("temp.txt", "portfolio.txt");
        cout<<"Stock removed"<<endl;
    }else{
        remove("temp.txt");
        cout<<"Stock not found";
    }
}


void updateStock() {
    string stockToUpdate;
    cout << "Stock to update: ";
    cin >> stockToUpdate;

    ifstream inFile("portfolio.txt");
    if (!inFile) {
        cout << "Could not open portfolio.txt" << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cout << "Could not create temporary file" << endl;
        return;
    }

    string stock;
    double price;
    int shares;
    bool found = false;

    while (inFile >> stock >> price >> shares) {
        if (stock == stockToUpdate) {
            double newPrice;
            int newShares;
            cout << "New price: ";
            cin >> newPrice;
            cout << "New shares: ";
            cin >> newShares;
            price = newPrice;
            shares = newShares;
            found = true;
        }
        tempFile << stock << " " << price << " " << shares << endl;
    }

    inFile.close();
    tempFile.close();

    if (found) {
        remove("portfolio.txt");
        rename("temp.txt", "portfolio.txt");
        cout << "Stock updated successfully!" << endl;
    } else {
        remove("temp.txt");
        cout << "Stock not found." << endl;
    }
}



int main()
{   
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
                displayPortfolio();
                break;
            case 2:
                addStock();
                break;
            case 3:
                removeStock();
                break;
            case 4:
                updateStock();
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
