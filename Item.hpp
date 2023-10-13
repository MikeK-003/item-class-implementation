#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    Item();
    Item(string name, float price, string description);
    Item(string name, float price, string description, float discount);
    string getName() const;
    void   setName(const string &name);
    float  getPrice() const;
    void   setPrice(const float &price);
    string getDescription() const;
    void   setDescription(const string &description);
    bool   hasDiscount() const;
    void   setDiscount(const float &discount);
    void   removeDiscount();
private:
    string priv_item_name_;
    float  priv_item_price_;
    string priv_item_description_;
    bool   priv_item_has_discount_;
    float  priv_item_discount_;
    float  priv_item_prediscount_price_;
};

#endif