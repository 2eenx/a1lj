#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    int ID;
    string Name;
    double Price;
    string Category;
};

vector<Product> loadProductData(const string& filename) {
    ifstream file(filename);
    vector<Product> products;

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return products;
    }

    Product product;
    while (file >> product.ID >> product.Name >> product.Price >> product.Category) {
        products.push_back(product);
    }

    file.close();
    return products;
}

void printProduct(const Product& product) {
    cout << "ID: " << product.ID << ", Name: " << product.Name << ", Price: " << product.Price << ", Category: " << product.Category << endl;
}

void printAllProducts(const vector<Product>& products) {
    for (const auto& product : products) {
        printProduct(product);
    }
}

void bubbleSortByPrice(vector<Product>& products) {
    for (size_t i = 0; i < products.size() - 1; ++i) {
        for (size_t j = 0; j < products.size() - i - 1; ++j) {
            if (products[j].Price > products[j + 1].Price) {
                swap(products[j], products[j + 1]);
            }
        }
    }
}

int main() {
    vector<Product> products = loadProductData("product_data.txt");

    if (products.empty()) {
        cerr << "Error: No data loaded. Exiting program." << endl;
        return 1;
    }

    cout << "All Products:" << endl;
    printAllProducts(products);
    cout << endl;

    cout << "Sorting Products by Price..." << endl;
    bubbleSortByPrice(products);
    cout << "Products Sorted by Price:" << endl;
    printAllProducts(products);

    return 0;
}
