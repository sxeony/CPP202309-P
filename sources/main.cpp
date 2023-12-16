#include "���.h"

int main() {
  // ���1. �ʰ��� ��ġ Ȯ��
  // ����,�ʰ��� �����ϱ�
  std::vector<Store> stores = {
      {"���÷��̱׶���", "���ֱ�����", "����", "���ֱ����� ���� ����� 90"},
      {"���ֿ��̺�", "���ֱ�����", "����", "���ֱ����� ���� ����ξȱ� 25"},
      {"ž��", "���ֱ�����", "����", "���ֱ����� ���� ���嵿 ����� 87"},
      {"���", "���ֱ�����", "����", "���ֱ����� ���� �ݳ���1��"},
      {"������", "���ֱ�����", "����", "���ֱ����� ���� �ҷε� 107-2"},
      {"MODA", "���ֱ�����", "����",
       "���ֱ����� ���� ���̵� �󹫹��ַ�76���� 11-2"},
      {"���� �ǻ��", "���ֱ�����", "�ϱ�", "���ֱ����� �ϱ� ��ġ��100���� 12"},
      {"���ѿʰ���", "���ֱ�����", "����", "���ֱ����� ���� �� 594-8����"},
      // ���...
  };
  std::vector<std::string> majorRegions = {
      "���ֱ�����",     "����Ư����",     "����������", "�뱸������",
      "��걤����",     "�λ걤����",     "��õ������", "����Ư����ġ��",
      "����Ư����ġ��", "����Ư����ġ��", "���󳲵�",   "����ϵ�",
      "��⵵",         "��û�ϵ�",       "��û����",   "���ϵ�",
      "��󳲵�"};
  std::map<std::string, std::vector<std::string>> minorRegions = {
      {"���ֱ�����", {"����", "����", "�ϱ�", "����"}},
      {"���󳲵�", {"������", "������", "��õ��", "���ֽ�", "..."}},
      {"����ϵ�", {"���ֽ�", "�����", "..."}},
      {"����Ư����", {"������", "���α�", "..."}}
      // ���....
  };

  // 1.1 majorRegions�� ��� ������������ ��� ���
  printMajorRegions(majorRegions);

  // 1.2 �������� �Է� �ޱ�
  int majorRegionIndex = selectMajorRegion(majorRegions);
  std::string selectedMajorRegion = majorRegions[majorRegionIndex - 1];

  // 1.3 ���õ� ���������� ���� �������� ��� ���
  printMinorRegions(minorRegions, selectedMajorRegion);

  // 1.4  �������� �Է� �ޱ�
  int minorRegionIndex = selectMinorRegion(minorRegions, selectedMajorRegion);
  std::string selectedMinorRegion =
      minorRegions[selectedMajorRegion][minorRegionIndex - 1];

  // 1.5 ���õ� ������ �ִ� �ʰ��Ե��� �̸��� �ּ� ���
  printStores(stores, selectedMajorRegion, selectedMinorRegion);

  ClothingInventory inventory;

  // 2. �ʰ��� ���� Ȯ���ϰ�, ������Ʈ�ϱ�
  manageInventory(inventory, stores);

  std::vector<ClothingItem> menu{
      ClothingItem("��Ʈ", "������", "  ", "M"),
      ClothingItem("����", "����", "  ", "L"),
      // ... ���⿡ �߰� �� �׸���� ���� �� �ֽ��ϴ�.
  };

  std::vector<ClothingItem> cart;
  int choice = -1;

  while (choice != 0) {
    std::cout << "1: �� ��ǰ ����, 2: ��ٱ��� ���, 3: ����" << std::endl;
    std::cin >> choice;

    switch (choice) {
      case 1:
        for (auto& item : menu) {
          item.displayDetails();  
        }
        break;
      case 2:
        std::cout << "�� ��ǰ�� ��ٱ��Ͽ� ����ּ���: ";
        int index;
        std::cin >> index;
        if (index >= 0 && index < menu.size()) {
          cart.push_back(menu[index]);
          std::cout << "��ǰ�� ��ٱ��Ͽ� �����ϴ�." << std::endl;
        } else {
          std::cout << "��ȿ���� �ʴ� ���Դϴ�." << std::endl;
        }
        break;
      case 3:
        saveToCart(cart, "cart.txt");
        std::cout << "��ٱ��Ͽ� ���� ����Ǿ����ϴ�. " << std::endl;
        break;
      default:
        std::cout << "�ٽ� �� �� �õ����ּ���" << std::endl;
    }
  }
}


