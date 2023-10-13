# item-class-implementation

This is a project simply meant to refresh my understanding of basic Object-Oriented Programming (OOP). 
It involves the creation of a generic class called "Item," which includes essential data attributes like Name, Price, Tax, etc. 
Additionally, it provides accessor and mutator methods for basic tasks such as retrieving item information and calculating its tax.

The intention is to transform this into an abstract class that can support subclasses, such a "Food" and a "Car" subclass.

The current end goal is to develop a "Shop" class that primarily consists of "Aisles." These Aisles will contain various Food and Car items, and the shop will only sell these two types. This means that a "Vegetable Aisle" and a "Sedan Aisle" can exist within the same shop. Furthermore, users should be able to take in shipments that then gets redistributed to the appropriate Aisle or be put in the miscellaneous Inventory if there is none.

The shipment handling should be user-friendly, allowing users to specify how many duplicates of a given item they want to add to the shipment.

Lastly, items can be bought, and a sales tax will be put on the sum total.
