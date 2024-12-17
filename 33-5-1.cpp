#include <iostream>
#include <map>
#include <vector>

void initBase(std::map<std::string, int>& product) {
    bool over_init = false;
    while(!over_init) {
        std::string art;
        int count;
        std::cout << "Enter the product (x - end)" << std::endl << " article: ";
        std::cin >> art;
        if(art == "x") {
            over_init = true;
        } else {
            std::cout << "quantity: ";
            std::cin >> count;
            product.insert(std::pair<std::string, int> (art, count));
        }
    }
};

void checkPoduct (std::map<std::string, int>& base, std::string _art, int _count) {
    auto search = base.find(_art);
    if(search == base.end()) {
        throw std::invalid_argument("The article is missing");
    }
    if(base.at(_art) < _count) {
        throw std::invalid_argument("The quantity is missing");
    }
}

void printList(std::map<std::string, int>& _list) {
    std::map<std::string, int>::iterator it;
    for(it = _list.begin(); it != _list.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

void addProduct(std::map<std::string, int>& _product, std::map<std::string, int>& _basket, std::string _art, int _count) {
    try{
        checkPoduct(_product, _art, _count);
        _basket.insert(std::pair<std::string, int> (_art, _count));
    }
    catch (const std::invalid_argument &er) {
        std::cerr << "Cought exeption: " << er.what() << std::endl;
    }
    catch (const std::runtime_error& er) {
        std::cerr << "Cought exeption: " << er.what() << std::endl;
    }
}

void removeProduct(std::map<std::string, int>& _basket, std::string _art, int _count) {
    try {
        checkPoduct(_basket, _art, _count);
        _basket.at(_art) -= _count;
        if (_basket.at(_art) == 0) { // Delete element if value = 0
            _basket.erase(_art);
        }
    }
    catch (const std::invalid_argument& er) {
        std::cerr << "Cought exeption: " << er.what() << std::endl;
    }
    catch (const std::runtime_error& er) {
        std::cerr << "Cought exeption: " << er.what() << std::endl;
    }
};

int main() {
    std::map<std::string, int> product, basket;
    initBase(product);
    //printList(product);
    bool action_in_basket = true;
    while(action_in_basket) {
        std::string action;
        std::cout <<"Enter the action (add, remove, print, end): ";
        std::cin >> action;
        if(action == "end") {
            action_in_basket = false;
        } else if(action == "print") {
            printList(basket);
        } else if(action == "add" || action == "remove") {
            std::string art;
            int count;
            std::cout << "\tarticle: ";
            std::cin >> art;
            std::cout << "\tquantity: ";
            std::cin >> count;
            if(action == "add") {
                addProduct(product, basket, art, count);
            } else if(action == "remove") {
                removeProduct(basket, art, count);
            }
        }
    }
}