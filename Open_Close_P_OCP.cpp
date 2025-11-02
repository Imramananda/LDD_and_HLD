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

//abstarct class
class DataBase
{
public:
    virtual void saveTODB() = 0;
};

class SQLDB : public DataBase
{
    ShoppingCart *cart;

public:
    SQLDB(ShoppingCart *p)
    {
        cout << "Ctor SQLDB " << endl;
        cart = p;
    }
    void saveTODB() override
    {
        cout << "Save to SQLDB " << endl;
    }
};
class MongoDB : public DataBase
{
    ShoppingCart *cart;

public:
    MongoDB(ShoppingCart *p)
    {
        cout << "Ctor MongoDB " << endl;
        cart = p;
    }
    void saveTODB() override
    {
        cout << "Save to MongoDB " << endl;
    }
};
class FIleSave : public DataBase
{
    ShoppingCart *cart;

public:
    FIleSave(ShoppingCart *p)
    {
        cout << "Ctor FIleSave " << endl;
        cart = p;
    }
    void saveTODB() override
    {
        cout << "Save to FIle " << endl;
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
    DataBase *dbsql = new SQLDB(cart);
    dbsql->saveTODB();
    DataBase *dbm = new MongoDB(cart);
    dbm->saveTODB();
    DataBase *file = new FIleSave(cart);
    file->saveTODB();

    return 0;
}