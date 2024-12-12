#include <iostream>
#include <map>
#include <vector>

void initBase(std::map<std::string, int>& product) {
    bool over_init = false;
    while (!over_init) {
        std::string art;
        int count;
        std::cout << "Enter the product (x - end)" << std::endl << " article: ";
        std::cin >> art;
        if (art == "x") {
            over_init = true;
        }
        else {
            std::cout << "quantity: ";
            std::cin >> count;
            product.insert(std::pair<std::string, int>(art, count));
        }
    }
};

void printList(std::map<std::string, int>& _list) {
    std::map<std::string, int>::iterator it;
    for (it = _list.begin(); it != _list.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

void addProduct(std::map<std::string, int>& _product, std::map<std::string, int>& _basket, std::string _art, int _count) {
    _basket.insert(std::pair<std::string, int>(_art, _count));
}

void removeProduct(std::map<std::string, int>& _basket, std::string _art, int _count) {
    auto search = _basket.find(_art);
    if (search != _basket.end()) {
        _basket.at(_art) -= _count;
    }
    else {
        std::cout << "Nothing" << std::endl;
        //_product.insert(std::pair<std::string, int> (_art, _count));
    }
};

int main() {
    std::map<std::string, int> product, basket;
    initBase(product);
    //printList(product);
    while (true) {
        std::string action;
        std::cout << "Enter the action (add, remove, print, end): ";
        std::cin >> action;
        if (action == "end") {
            break;
        }
        else if (action == "print") {
            printList(basket);
        }
        else {
            std::string art;
            int count;
            std::cout << "\tarticle: ";
            std::cin >> art;
            std::cout << "\tquantity: ";
            std::cin >> count;
            if (action == "add") {
                addProduct(product, basket, art, count);
            }
            else if (action == "remove") {
                removeProduct(basket, art, count);
            }
        }
    }
}