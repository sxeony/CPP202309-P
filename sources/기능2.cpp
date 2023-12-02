#include "기능.h"


void ClothingInventory::updateStock(const Store& store, const std::string& item, int quantity) {
    if (quantity < 0) {
        std::cout << "오류: 수량은 음수일 수 없습니다." << std::endl;
        return;
    }
    std::string key = store.name + ":" + item;
    stock[key] = quantity;
    std::cout << store.name << "에서 " << item << "의 수량이 " << quantity << "개로 업데이트되었습니다." << std::endl;
}

void ClothingInventory::checkStock(const Store& store, const std::string& item) {
    std::string key = store.name + ":" + item;
    auto it = stock.find(key);
    if (it != stock.end()) {
        std::cout << "Store: " << store.name << ", Item: " << item << ", Stock: " << it->second << std::endl;
    }
    else {
        std::cout << "Store: " << store.name << ", Item: " << item << ", Stock: 정보 없음" << std::endl;
    }
}

