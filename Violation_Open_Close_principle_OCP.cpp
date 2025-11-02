#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Product
{
public:
    string name;
    int price;
    Product(const string &s, const int &p)
    {
        cout << "Ctor Product  " << endl;
        name = s;
        price = p;
    }
};
class ShoppingCart
{
    vector<Product *> products;

public:
    ShoppingCart()
    {
        cout << "Ctor Shopping Cart " << endl;
    }
    void addProduct(Product *p)
    {
        cout << "Adding product : " << endl;
        products.emplace_back(p);
    }
    vector<Product *> &getProducts()
    {
        cout << "Get the products from cart" << endl;
        return products;
    }
};
class ProductName
{
    ShoppingCart *cart;

public:
    ProductName(ShoppingCart *p)
    {
        cout << "Ctor productName " << endl;
        cart = p;
    }
    void nameOfProduct()
    {
        for (auto i : cart->getProducts())
            cout << "Name : " << i->name << " Price : " << i->price << endl;
    }
};
class CartTotalPrice
{
    ShoppingCart *cart;

public:
    CartTotalPrice(ShoppingCart *p)
    {
        cout << "Ctor CartTotalPrice " << endl;
        cart = p;
    }
    void TotalCartPrice()
    {
        int total = 0;
        for (auto i : cart->getProducts())
            total = total + i->price;
        cout << "Totla cart price : " << total << endl;
    }
};
class DataBase
{
    ShoppingCart *cart;

public:
    DataBase(ShoppingCart *p)
    {
        cout << "Ctor DataBase " << endl;
        cart = p;
    }
    void saveTOSQL()
    {
        cout << "Save to SQL " << endl;
    }
    void saveTOFile()
    {
        cout << "Save to saveTOFile " << endl;
    }
    void saveTOMongoDB()
    {
        cout << "Save to saveTOMongoDB " << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("jeans", 2000));
    cart->addProduct(new Product("Shoes", 5000));
    ProductName *name = new ProductName(cart);
    name->nameOfProduct();
    CartTotalPrice *total = new CartTotalPrice(cart);
    total->TotalCartPrice();
    DataBase *db = new DataBase(cart);
    db->saveTOFile();
    db->saveTOMongoDB();
    db->saveTOSQL();

    return 0;
}