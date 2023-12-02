#include "���.h"


void ClothingInventory::updateStock(const Store& store, const std::string& item, int quantity) {
    if (quantity < 0) {
        std::cout << "����: ������ ������ �� �����ϴ�." << std::endl;
        return;
    }
    std::string key = store.name + ":" + item;
    stock[key] = quantity;
    std::cout << store.name << "���� " << item << "�� ������ " << quantity << "���� ������Ʈ�Ǿ����ϴ�." << std::endl;
}

void ClothingInventory::checkStock(const Store& store, const std::string& item) {
    std::string key = store.name + ":" + item;
    auto it = stock.find(key);
    if (it != stock.end()) {
        std::cout << "Store: " << store.name << ", Item: " << item << ", Stock: " << it->second << std::endl;
    }
    else {
        std::cout << "Store: " << store.name << ", Item: " << item << ", Stock: ���� ����" << std::endl;
    }
}

