#include <fstream>

#include "기능.h"

ClothingItem::ClothingItem(std::string st, std::string t, std::string c,
                           std::string m, std::string s)
    : store(st), type(t), color(c), material(m), size(s) {}

// 옷의 상세정보 출력하는 함수
void ClothingItem::displayDetails() const {
  std::cout << store << " => "
            << "옷 종류: " << type << ", 색깔: " << color
            << ", 재질: " << material << ", 사이즈: " << size << std::endl;
}

void saveCartToFile(const std::vector<ClothingItem>& cart,
                    const std::string& filename) {
  std::ofstream file(filename);

  if (!file) {
    std::cerr << "파일을 열 수 없습니다: " << filename << std::endl;
    return;
  }

  for (const auto& item : cart) {
    file << item.store << "," << item.type << "," << item.color << ","
         << item.size << std::endl;
  }

  file.close();
  std::cout << "장바구니가 파일에 저장되었습니다: " << filename << std::endl;
}