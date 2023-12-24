#include <fstream>

#include "���.h"

ClothingItem::ClothingItem(std::string st, std::string t, std::string c,
                           std::string m, std::string s)
    : store(st), type(t), color(c), material(m), size(s) {}

// ���� ������ ����ϴ� �Լ�
void ClothingItem::displayDetails() const {
  std::cout << store << " => "
            << "�� ����: " << type << ", ����: " << color
            << ", ����: " << material << ", ������: " << size << std::endl;
}

void saveCartToFile(const std::vector<ClothingItem>& cart,
                    const std::string& filename) {
  std::ofstream file(filename);

  if (!file) {
    std::cerr << "������ �� �� �����ϴ�: " << filename << std::endl;
    return;
  }

  for (const auto& item : cart) {
    file << item.store << "," << item.type << "," << item.color << ","
         << item.size << std::endl;
  }

  file.close();
  std::cout << "��ٱ��ϰ� ���Ͽ� ����Ǿ����ϴ�: " << filename << std::endl;
}