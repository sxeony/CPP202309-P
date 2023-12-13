#include "���.h"

void manageInventory(ClothingInventory& inventory, const std::vector<Store>& stores) {
    while (true) {
        std::cout << "\n1. ��� ������Ʈ" << std::endl;
        std::cout << "2. ��� Ȯ��" << std::endl;
        std::cout << "3. ���� ���� Ȯ��" << std::endl;
        std::cout << "4. ����" << std::endl; 
        std::cout << "����: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        // 1. ��� ������Ʈ
        case 1: {  
            std::string storeName, itemName;
            int quantity;
            std::cout << "���� �̸�: ";
            getline(std::cin, storeName);
            std::cout << "������ �̸�: ";
            getline(std::cin, itemName);
            std::cout << "����: ";
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
                std::cout << "���Ը� ã�� �� �����ϴ�." << std::endl;
            }
            break;
        }
        // 2. ��� Ȯ��
        case 2: {  
            std::string storeName, itemName;
            std::cout << "���� �̸�: ";
            getline(std::cin, storeName);
            std::cout << "������ �̸�: ";
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
                std::cout << "���Ը� ã�� �� �����ϴ�." << std::endl;
            }
            break;
        }
        // 3. ���� ���� Ȯ��
        case 3: {
            ifstream file("����.txt");
            string line;

            if (!file) {
                cerr << "���� ���¿� �����Ͽ����ϴ�." << endl;
            } else {
                cout << "���� ����:" << endl;
                while (getline(file, line)) {
                    cout << line << endl;
                }
            }
            file.close();
            break;
        }
        // 4. ���α׷� ����
        case 4: {  
            std::cout << "���α׷��� �����մϴ�." << std::endl;
            return;
        }
        // �߸� �Է����� ��
        default: {
            std::cout << "�߸��� �����Դϴ�. �ٽ� �õ��� �ּ���." << std::endl;
            break;
        }
        }
    }
}