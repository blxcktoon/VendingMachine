#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
    int id;
};


struct customer {
    string name;
    double balance;
};


int main(){
    vector<Product> products;

    products.push_back({"Coca-Cola", 15, 8, 1});
    products.push_back({"Fanta", 12, 8, 2});
    products.push_back({"Sprite", 15, 8, 3});
    products.push_back({"Simba", 8, 8, 4});
    products.push_back({"Lays", 10, 8, 5});
    products.push_back({"Doritos", 10, 8, 6});
    products.push_back({"Bar-One", 6, 8, 7});
    products.push_back({"Kit-Kat", 6, 8, 8});
    products.push_back({"Snickers", 6, 8, 9});

    for (const Product& product : products) {
        cout<< product.id << ": " << product.name << " - R" 
        << product.price << " (quantity: " << product.quantity << ")" << "\n";
    }
    vector<customer> customers;

    customers.push_back({"Thabo Mosimane", 2569.38});

    customer& user = customers[0];
    cout << "\nWelcome, " << user.name << ". Your balance is R"
         << user.balance << "\n";

    int productId;
    while (true) {
        cout << "\nEnter the ID of the item to buy (0 to finish): ";
        if (!(cin >> productId)) {
            cerr << "Invalid input. Please enter a number.\n";
            return 1;
        }

        if (productId == 0) {
            break;
        }

        Product* selectedProduct = nullptr;
        for (Product& product : products) {
            if (product.id == productId) {
                selectedProduct = &product;
                break;
            }
        }

        if (selectedProduct == nullptr) {
            cout << "That product ID does not exist.\n";
            continue;
        }

        int quantity;
        cout << "How many would you like to buy? ";
        if (!(cin >> quantity)) {
            cerr << "Invalid input. Please enter a number.\n";
            return 1;
        }

        if (quantity <= 0) {
            cout << "Please enter a quantity greater than zero.\n";
            continue;
        }

        if (quantity > selectedProduct->quantity) {
            cout << "There are only " << selectedProduct->quantity
                 << " available.\n";
            continue;
        }

        double total = selectedProduct->price * quantity;
        if (total > user.balance) {
            cout << "You do not have enough money. Your balance is R"
                 << user.balance << ".\n";
            continue;
        }

        selectedProduct->quantity -= quantity;
        user.balance -= total;
        cout << "Purchased " << quantity << " " << selectedProduct->name
             << "(s) for R" << total << ". Remaining balance: R"
             << user.balance << "\n";
    }

    cout << "Thank you for shopping, " << user.name
         << ". Final balance: R" << user.balance << "\n";

    return 0;
}