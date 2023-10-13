#include "Item.hpp"

/*
    Default constructor, initalizes a blank Item
*/
Item::Item() {
    this->priv_item_name_ = "";
    this->priv_item_price_ = 0;
    this->priv_item_description_ = "";
    this->priv_item_has_discount_ = false;
    this->priv_item_discount_ = 0;
    this->priv_item_prediscount_price_ = 0;
}

/*
    Parameterized constructors, declares an Item
*/
Item::Item(string name, float price, string description) {
    this->priv_item_name_ = name;
    this->priv_item_price_ = price;
    this->priv_item_description_ = description;
    this->priv_item_has_discount_ = false;
    this->priv_item_discount_ = 0;
    this->priv_item_prediscount_price_ = 0;
}

Item::Item(string name, float price, string description, float discount) {
    this->priv_item_name_ = name;
    this->priv_item_price_ = price;
    this->priv_item_description_ = description;

    /*
        Discounts may optionally be added in decimal form and correlate to percentage
        It can only be between 0 and 1, and cannot be negative
        0.20 = 20% of the price
    */
    if (discount <= 1 && discount >= 0) {
        // Set the discount flag to true
        this->priv_item_has_discount_ = true;

        // Save the discount value
        this->priv_item_discount_ = discount;

        // Save the original price value
        this->priv_item_prediscount_price_ = price;

        // Apply the discount to the price
        this->priv_item_price_ = price * discount;
    } else {
        // If the discount value is wrong, don't do anything with it
        std::cout << "Discount Failed: Invalid Value" << std::endl;
        this->priv_item_has_discount_ = false;
        this->priv_item_discount_ = 0;
        this->priv_item_prediscount_price_ = 0;
    }
}

/*
    Returns the Item's name
*/
string Item::getName() const {
    return this->priv_item_name_;
}

/*
    Set the Item's name to the value of the parameter
*/
void Item::setName(const string &name) {
    this->priv_item_name_ = name;
}

/*
    Returns the Item's price
*/
float Item::getPrice() const {
    return this->priv_item_price_;
}

/*
    Set the Item's price to the value of the parameter
*/
void Item::setPrice(const float &price) {
    this->priv_item_price_ = price;
}

/*
    Returns the Item's description
*/
string Item::getDescription() const {
    return this->priv_item_description_;
}

/*
    Set the Item's description to the value of the parameter
*/
void Item::setDescription(const string &description) {
    this->priv_item_description_ = description;
}

/*
    Returns the Item's discount status
*/
bool Item::hasDiscount() const {
    if (this->priv_item_has_discount_ == true) {
        cout << "Discount Exists: Item Price At " << this->priv_item_discount_ * 100 << "%" << std::endl;
    }
    
    return this->priv_item_has_discount_; 
}

/*
    Set the Item's price depending on the values of the parameters
*/
void Item::setDiscount(const float &discount) {
    // If an Item already has a discount, remove it
    if (this->priv_item_has_discount_ == true) {
        this->priv_item_price_ = this->priv_item_prediscount_price_;
    }

    if (discount <= 1 && discount >= 0) {
        this->priv_item_has_discount_ = true;

        this->priv_item_discount_ = discount;

        this->priv_item_prediscount_price_ = this->priv_item_price_;

        this->priv_item_price_ = this->priv_item_price_ * this->priv_item_discount_;
    } else {
        // If the discount value is wrong, reapply the old discounted value and do nothing else
        std::cout << "Discount Failed: Invalid Value" << std::endl;
        this->priv_item_price_ = this->priv_item_price_ * this->priv_item_discount_;
    }
}

void Item::removeDiscount() {
    if (this->priv_item_has_discount_ == true) {
        this->priv_item_price_ = this->priv_item_prediscount_price_;
    }
}