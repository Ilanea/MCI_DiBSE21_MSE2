//
// Created by msyu on 5/21/22.
//

#ifndef FACTORY_PRODUCT_H
#define FACTORY_PRODUCT_H

#include <iostream>

class Product {
public:
    Product(){}

    virtual ~Product(){
        std::cout << "Product Destructor!" << std::endl;
    }

    virtual int getType() = 0;

};

class ProductA : public Product {
public:
    int getType() override;
};

class ProductB : public Product {
public:
    int getType() override;
};

#endif //FACTORY_PRODUCT_H
