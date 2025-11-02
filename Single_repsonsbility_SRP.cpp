#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product
{
public:
    Product(const string &s, const int &p)
    {
        cout << "ctor call of product " << endl;
        name = s;
        price = p;
    }
    string name;
    int price;
};

class ShoppingCart
{
private:
    vector<Product *> products;
public:
    ShoppingCart()
    {
        cout << "Ctor of shopping cart " << endl;
    }
    void addProduct(Product *p)
    {
        cout << "Setting the product " << endl;
        products.emplace_back(p);
    }
    const vector<Product *> &getProduct()
    {
        cout << "Getting the product " << endl;
        return products;
    }
};

class ShoppingCartPricePrinter
{
    ShoppingCart *cart;

public:
    ShoppingCartPricePrinter(ShoppingCart *c)
    {
        cart = c;
    }
    void totalPrice()
    {
        cout << "Total price of product is : " << endl;
        int total = 0;
        for (auto p : cart->getProduct())
            total = total + p->price;
        cout << "Total " << total << endl;
    }
};
class ShoppingCartName
{
    ShoppingCart *cart;

public:
    ShoppingCartName(ShoppingCart *c)
    {
        cart = c;
    }
    void nameOfProduct()
    {
        cout << "Total price of product is : " << endl;
        int total = 0;
        for (auto p : cart->getProduct())
            cout << "Name of product  " << p->name << endl;
    }
};

class Database
{
    ShoppingCart *cart;

public:
    Database(ShoppingCart *c)
    {
        cart = c;
    }
    void saveTODB()
    {
        cout << "Saving to DB " << endl;
    }
};

class NameOfProduct
{
    ShoppingCart *cart;

public:
    NameOfProduct(ShoppingCart *c)
    {
        cart = c;
    }
    void productName()
    {
        cout << "Name of product : ";
        for (auto p : cart->getProduct())
            cout << p->name << " , ";
        cout << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 15000));
    cart->addProduct(new Product("Crocs", 5000));
    ShoppingCartPricePrinter *printer = new ShoppingCartPricePrinter(cart);
    printer->totalPrice();
    NameOfProduct *name = new NameOfProduct(cart);
    name->productName();
    Database *db = new Database(cart);
    db->saveTODB();
    return 0;
}
