#include "���.h"

// 2-5 �Է� �� ���� ó��
bool validNumberInput() {
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "���ڸ� �Է����ּ���." << std::endl;
    return false;
  }
  return true;
}

// ���2 : �� ��� ����
void manageInventory(ClothingInventory& inventory,
                     const std::vector<Store>& stores) {
  while (true) {
    // 2.1 �޴� �����ϱ�
    std::cout << "\n2. �� ��� ����" << endl;
    std::cout << "============================================" << std::endl;
    std::cout << "1. ��� ������Ʈ" << std::endl;
    std::cout << "2. ��� Ȯ��" << std::endl;
    std::cout << "3. ���� ���� Ȯ��" << std::endl;
    std::cout << "4. ����" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "�޴��� �������ּ���: ";

    // ����ڿ��� �޴� ���� �Է¹ޱ�
    int choice;
    std::cin >> choice;
    if (!validNumberInput()) continue;  // ���� �Է� ����
    std::cin.ignore();

    switch (choice) {
      // 2-2. ��� ������Ʈ
      case 1: {
        // ����ڷκ��� ���� �̸�, ��ǰ �̸�, ���� �Է¹ޱ�
        std::string storeName, itemName;
        int quantity;
        std::cout << "���� �̸�: ";
        getline(std::cin, storeName);
        std::cout << "��ǰ �̸�: ";
        getline(std::cin, itemName);
        std::cout << "����: ";
        std::cin >> quantity;
        // ���� �Է� ����
        if (!validNumberInput()) continue;
        std::cin.ignore();

        bool storeFound = false;  // storeFound ��� ���� ���� : ��ġ�ϴ� ���Ը�
                                  // ã�Ҵ��� ���� ����
        for (const auto& store : stores) {
          // store ��ü�� �ʰ��Կ� �̸��� ������ updateStock �Լ� ȣ��
          if (store.name == storeName) {
            inventory.updateStock(store, itemName, quantity);
            storeFound = true;
            break;
          }
        }
        // �����̸��� �ٸ� ��
        if (!storeFound) {
          std::cout << "���Ը� ã�� �� �����ϴ�." << std::endl;
        }
        break;
      }
      // 2-3. ��� Ȯ���ϱ�
      case 2: {
        std::string storeName, itemName;
        std::cout << "���� �̸�: ";
        getline(std::cin, storeName);
        std::cout << "��ǰ �̸�: ";
        getline(std::cin, itemName);

        bool storeFound = false;  // storeFound ��� ���� ���� : ��ġ�ϴ� ���Ը�
                                  // ã�Ҵ��� ���� ����
        for (const auto& store : stores) {
          // store ��ü�� �ʰ��Կ� �̸��� ������ checkStock �Լ� ȣ��
          if (store.name == storeName) {
            inventory.checkStock(store, itemName);
            storeFound = true;
            break;
          }
        }
        // �����̸��� �ٸ� ��
        if (!storeFound) {
          std::cout << "���Ը� ã�� �� �����ϴ�." << std::endl;
        }
        break;
      }
      // 2-4. ���� ���� Ȯ���ϱ�
      case 3: {
        // ����.txt ���� ����
        ifstream file("����.txt");
        string line;

        // ���� ���⸦ �������� ��
        if (!file) {
          cerr << "���� ���¿� �����Ͽ����ϴ�." << endl;
        }
        // ���� ���� �б� �� ���
        else {
          cout << "============================================" << endl;
          cout << "<�� ��� Ȯ��>" << endl;
          // file�� ������ ���� �� �о� �ܼ�â�� ���
          while (getline(file, line)) {
            cout << line << endl;
          }
        }
        // ���� �ݱ�
        file.close();
        break;
      }
      // ���α׷� ����
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
