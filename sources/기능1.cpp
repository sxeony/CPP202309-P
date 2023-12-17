#include "기능.h"

// 기능1 : 옷가게 위치 확인
// 1.1 상위 지역의 목록을 출력하는 함수
void printMajorRegions(const std::vector<std::string>& majorRegions) {
  std::cout << "1. 옷 가게 위치 확인하기 " << endl;
  std::cout << "============================================" << std::endl;
  // 반복문을 이용해 majorRegions에 있는 모든 요소들 출력하기
  for (int i = 0; i < majorRegions.size(); i++) {
    std::cout << i + 1 << ": " << majorRegions[i] << std::endl;
  }
  std::cout << "============================================" << std::endl;
}

// 1.2 상위지역 입력 받는 함수
int selectMajorRegion(const std::vector<std::string>& majorRegions) {
  std::cout << "원하는 상위 지역을 선택하세요: ";
  int majorRegionIndex;
  std::cin >> majorRegionIndex;
  std::cout << "============================================" << std::endl;
  return majorRegionIndex;
}

// 1.3 상위 지역에 대한 하위 지역 목록을 사용자에게 출력하는 함수
void printMinorRegions(
    const std::map<std::string, std::vector<std::string>>& minorRegions,
    const std::string& selectedMajorRegion) {
  int i = 1;
  // 반복문을 이용해 selectedMajorRegion에 해당하는 하위 지역들의 벡터를 반환
  for (const auto& region : minorRegions.at(selectedMajorRegion)) {
    std::cout << i++ << ": " << region << std::endl;
  }
  std::cout << "============================================" << std::endl;
}

// 1.4 하위지역 입력 받는 함수
int selectMinorRegion(
    const std::map<std::string, std::vector<std::string>>& minorRegions,
    const std::string& selectedMajorRegion) {
  std::cout << selectedMajorRegion << " 내에서 하위 지역을 선택하세요: ";
  int minorRegionIndex;
  std::cin >> minorRegionIndex;
  std::cout << "============================================" << std::endl;
  return minorRegionIndex;
}

// 1.5 선택된 지역에 있는 옷가게들의 이름과 주소 출력하는 함수
void printStores(const std::vector<Store>& stores,
                 const std::string& majorRegion,
                 const std::string& minorRegion) {
  bool found =
      false;  // found 변수 설정 (주어진 지역내에서 가게를 찾았는지에 대한 여부)
  std::cout << majorRegion << " " << minorRegion
            << "에 있는 옷 가게 목록:" << std::endl;
  // store벡터의 모든 Store 객체를 순서대로 한 번씩 처리하는 반복문
  for (const auto& store : stores) {
    // 찾고자 하는 지역에, 옷가게가 있을 경우 이름과 주소 출력
    if (store.majorRegion == majorRegion && store.minorRegion == minorRegion) {
      std::cout << store.name << ": " << store.address << std::endl;
      found = true;
    }
  }

  // 해당 지역에 옷가게가 없을 경우
  if (!found) {
    std::cout << majorRegion << " " << minorRegion << "에는 옷 가게가 없습니다."
              << std::endl;
  }
}
