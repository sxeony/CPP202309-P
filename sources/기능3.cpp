#include <fstream>

#include "기능.h"

ClothingItem::ClothingItem(std::string st, std::string t, std::string c,
                           std::string m, std::string s)
    : store(st), type(t), color(c), material(m), size(s) {}

// 옷의 상세정보 출력하는 함수
void ClothingItem::displayDetails() {
  std::cout << store << " => "
            << "옷 종류: " << type << ", 색깔: " << color
            << ", 재질: " << material << ", 사이즈: " << size << std::endl;
}

// 옷을 장바구니(파일)에 담는 함수
void saveToCart(const std::vector<ClothingItem>& cart,
                const std::string& filename) {
  std::ofstream file(filename);

  for (const auto& item : cart) {
    file << item.type << "," << item.color << "," << item.material << ","
         << item.size << std::endl;
  }

  file.close();
}
