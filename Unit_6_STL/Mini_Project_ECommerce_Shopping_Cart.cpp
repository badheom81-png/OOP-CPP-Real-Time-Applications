#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Product {
    int id;
    string name;
    string category;
    double price;
    double discount;
};

struct CartItem {
    Product product;
    int quantity;
};

int main() {
    map<int, Product> catalog{
        {101, {101, "Laptop", "Electronics", 55000, 10}},
        {102, {102, "Mouse", "Electronics", 800, 20}},
        {103, {103, "Shoes", "Fashion", 2500, 15}},
        {104, {104, "Backpack", "Fashion", 1800, 25}}
    };

    vector<CartItem> cart;

    cart.push_back({catalog[101], 1});
    cart.push_back({catalog[102], 2});
    cart.push_back({catalog[104], 1});

    set<string> categories;

    for (const auto& item : cart) {
        categories.insert(item.product.category);
    }

    cout << "=== Product Categories ===" << endl;

    for (const auto& category : categories) {
        cout << category << endl;
    }

    priority_queue<pair<double, string>> featuredProducts;

    for (const auto& item : catalog) {
        featuredProducts.push({
            item.second.discount,
            item.second.name
        });
    }

    cout << "\n=== Featured Products by Discount ===" << endl;

    for (int i = 0;
         i < 3 && !featuredProducts.empty();
         i++) {

        cout << featuredProducts.top().second
             << " | Discount: "
             << featuredProducts.top().first
             << "%" << endl;

        featuredProducts.pop();
    }

    sort(cart.begin(), cart.end(),
         [](const CartItem& first, const CartItem& second) {
             return first.product.price <
                    second.product.price;
         });

    cout << "\n=== Cart Items Sorted by Price ===" << endl;

    double total = 0.0;

    for (const auto& item : cart) {
        double itemTotal =
            item.product.price * item.quantity;

        total += itemTotal;

        cout << item.product.name
             << " | Price: Rs. "
             << item.product.price
             << " | Quantity: "
             << item.quantity
             << " | Total: Rs. "
             << itemTotal << endl;
    }

    cout << "\n=== Invoice ===" << endl;
    cout << "Grand Total: Rs. " << total << endl;

    return 0;
}