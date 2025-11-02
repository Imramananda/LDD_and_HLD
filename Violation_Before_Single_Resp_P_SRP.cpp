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
        vector<Product *> products;

    public:
        ShoppingCart()
        {
            cout<<"Ctor of shopping cart "<<endl;
        }
        void addProduct( Product *p)
        {
            cout << "Setting the product " << endl;
            products.emplace_back(p);
        }
        const vector<Product *> &getProduct()
        {
            cout << "Getting the product " << endl;
            return products;
        }
        void totalPrice()
        {
            cout << "Total price of product is : " << endl;
            int total = 0;
            for (auto p : products)
                total = total + p->price;
            cout << "Total " << total << endl;
        }
        void productName()
        {
            cout << "Name of product : ";
            for (auto p : products)
                cout << p->name << " , ";
            cout << endl;
        }
        void saveTODB()
        {
            cout << "Saving to DB " << endl;
        }
    };

    int main()
    {
        ShoppingCart cart;
        cart.addProduct(new Product("Laptop", 15000));
        cart.addProduct(new Product("Crocs", 5000));
        // cout << "Product " << cart.getProduct() << endl;

        cart.productName();
        cart.totalPrice();
        cart.saveTODB();

        return 0;
    }
