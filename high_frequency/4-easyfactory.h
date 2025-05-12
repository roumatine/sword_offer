#include "..\head.h"

typedef enum productType {
    typeA,
    typeB,
    typeC
} productTypeTag;

class Product {
public:
    virtual void show() = 0;
    virtual ~Product() = 0;
};

class ProductA : public Product {
public:
    void show() {
        cout << "ProductA" << endl;
    }
    ~ProductA() {
        cout << "~ProductA" << endl;
    }
};

class ProductB : public Product {
public:
    void show() {
        cout << "ProductB" << endl;
    }
    ~ProductB() {
        cout << "~ProductB" << endl;
    }
};

class ProductC : public Product {
public:
    void show() {
        cout << "ProductC" << endl;
    }
    ~ProductC() {
        cout << "~ProductC" << endl;
    }
};

class Factory {
public:
    Product* createProduct(productType type) {
        switch(type) {
            case typeA:
                return new ProductA();
            case typeB:
                return new ProductB();
            case typeC:
                return new ProductC();
            default:
                return nullptr;
        }
    }
};