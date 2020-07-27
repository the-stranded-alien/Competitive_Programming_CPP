#include<iostream>
#include<cstring>
#include "01_HashTableClass.h"
using namespace std;

int main() {
    HashTable<int> price_menu;
    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("BurgerPizza", 150);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Coke", 40);
    price_menu.print();
    int* price = price_menu.search("Noodles");
    if(price == NULL) cout << "Not Found !\n";
    else cout << "Price Is : " << (*price) << endl;

    // Operator Overloading !
    // Insert
    price_menu["Dosa"] = 60;
    // Update
    price_menu["Dosa"] += 10;
    // Search
    cout << "Price Of Dosa : " << price_menu["Dosa"] << endl;
    return 0;
}