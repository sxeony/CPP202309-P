#include "기능.h"

void manageInventory(ClothingInventory& inventory, const std::vector<Store>& stores) {
    while (true) {
        std::cout << "\n1. 재고 업데이트" << std::endl;
        std::cout << "2. 재고 확인" << std::endl;
        std::cout << "3. 수량 파일 확인" << std::endl;
        std::cout << "4. 종료" << std::endl; 
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        // 1. 재고 업데이트
        case 1: {  
            std::string storeName, itemName;
            int quantity;
            std::cout << "가게 이름: ";
            getline(std::cin, storeName);
            std::cout << "아이템 이름: ";
            getline(std::cin, itemName);
            std::cout << "수량: ";
            std::cin >> quantity;
            std::cin.ignore();

            bool storeFound = false;
            for (const auto& store : stores) {
                if (store.name == storeName) {
                    inventory.updateStock(store, itemName, quantity);
                    storeFound = true;
                    break;
                }
            }

            if (!storeFound) {
                std::cout << "가게를 찾을 수 없습니다." << std::endl;
            }
            break;
        }
        // 2. 재고 확인
        case 2: {  
            std::string storeName, itemName;
            std::cout << "가게 이름: ";
            getline(std::cin, storeName);
            std::cout << "아이템 이름: ";
            getline(std::cin, itemName);

            bool storeFound = false;
            for (const auto& store : stores) {
                if (store.name == storeName) {
                    inventory.checkStock(store, itemName);
                    storeFound = true;
                    break;
                }
            }

            if (!storeFound) {
                std::cout << "가게를 찾을 수 없습니다." << std::endl;
            }
            break;
        }
        // 3. 수량 파일 확인
        case 3: {
            ifstream file("수량.txt");
            string line;

            if (!file) {
                cerr << "파일 오픈에 실패하였습니다." << endl;
            } else {
                cout << "파일 내용:" << endl;
                while (getline(file, line)) {
                    cout << line << endl;
                }
            }
            file.close();
            break;
        }
        // 4. 프로그램 종료
        case 4: {  
            std::cout << "프로그램을 종료합니다." << std::endl;
            return;
        }
        // 잘못 입력했을 때
        default: {
            std::cout << "잘못된 선택입니다. 다시 시도해 주세요." << std::endl;
            break;
        }
        }
    }
}