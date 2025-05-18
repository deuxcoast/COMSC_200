#include <iostream>

using namespace std;

const size_t NUM_PRODUCTS = 5;

class Inventory {
   private:
    int itemNumber{};  // This is an id number of the product
    int numOfItem{};   // This is the number of items in stock

   public:
    Inventory() = default;
    Inventory(int id, int stock) : itemNumber{id}, numOfItem{stock} {};

    virtual ~Inventory() = default;

    int getId() { return itemNumber; };
    void setId(int id) { itemNumber = id; };

    int getAmount() { return numOfItem; };
    void setAmount(int stock) { numOfItem = stock; };

    virtual void display() {
        cout << "Item number " << getId() << " has " << getAmount()
             << " items in stock" << endl;
    };
};

class Book : public Inventory {
   public:
    Book() = default;
    Book(int id, int stock) : Inventory{id, stock} {};
    void display() override {
        cout << "Book ";
        Inventory::display();
    };
};

class CD : public Inventory {
   public:
    CD() = default;
    CD(int id, int stock) : Inventory{id, stock} {}
    void display() override {
        cout << "CD ";
        Inventory::display();
    };
};

class DVD : public Inventory {
   public:
    DVD() = default;
    DVD(int id, int stock) : Inventory{id, stock} {}
    void display() override {
        cout << "DVD ";
        Inventory::display();
    };
};

int main() {
    // instantiate various inventory items
    DVD* item_1 = new DVD{432, 24};
    Book* item_2 = new Book{986, 8};
    CD* item_3 = new CD{635, 15};
    DVD* item_4 = new DVD{233, 99};
    Book* item_5 = new Book{422, 1000};

    Inventory* products[NUM_PRODUCTS];

    products[0] = item_1;
    products[1] = item_2;
    products[2] = item_3;
    products[3] = item_4;
    products[4] = item_5;

    for (size_t i{}; i < NUM_PRODUCTS; ++i) {
        products[i]->display();
    }
    return 0;
}
