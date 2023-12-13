#include "기능.h"

int main() {
  // 기능1. 옷가게 위치 확인
  // 지역,옷가게 정의하기
  std::vector<Store> stores = {
      {"엠플레이그라운드", "광주광역시", "동구", "광주광역시 동구 충장로 90"},
      {"광주에이블", "광주광역시", "동구", "광주광역시 동구 충장로안길 25"},
      {"탑텐", "광주광역시", "동구", "광주광역시 동구 충장동 충장로 87"},
      {"댄디", "광주광역시", "동구", "광주광역시 동구 금남로1가"},
      {"데이지", "광주광역시", "동구", "광주광역시 동구 불로동 107-2"},
      {"MODA", "광주광역시", "서구",
       "광주광역시 서구 쌍촌동 상무민주로76번길 11-2"},
      {"구월 의상실", "광주광역시", "북구", "광주광역시 북구 우치로100번길 12"},
      {"착한옷가게", "광주광역시", "남구", "광주광역시 남구 백운동 594-8번지"},
      // 등등...
  };
  std::vector<std::string> majorRegions = {
      "광주광역시",     "서울특별시",     "대전광역시", "대구광역시",
      "울산광역시",     "부산광역시",     "인천광역시", "세종특별자치시",
      "강원특별자치도", "제추특별자치도", "전라남도",   "전라북도",
      "경기도",         "충청북도",       "충청남도",   "경상북도",
      "경상남도"};
  std::map<std::string, std::vector<std::string>> minorRegions = {
      {"광주광역시", {"동구", "남구", "북구", "서구"}},
      {"전라남도", {"목포시", "여수시", "순천시", "나주시","..."}},
      {"전라북도", {"전주시", "군산시", "..."}},
      {"서울특별시", {"강남구", "종로구", "..."}}
      // 등등....
  };

  // 1.1 majorRegions에 담긴 상위지역들의 목록 출력
  printMajorRegions(majorRegions);

  // 1.2 상위지역 입력 받기
  int majorRegionIndex = selectMajorRegion(majorRegions);
  std::string selectedMajorRegion = majorRegions[majorRegionIndex - 1];

  // 1.3 선택된 상위지역에 대한 하위지역 목록 출력
  printMinorRegions(minorRegions, selectedMajorRegion);

  // 1.4  하위지역 입력 받기
  int minorRegionIndex = selectMinorRegion(minorRegions, selectedMajorRegion);
  std::string selectedMinorRegion =
      minorRegions[selectedMajorRegion][minorRegionIndex - 1];

  // 1.5 선택된 지역에 있는 옷가게들의 이름과 주소 출력
  printStores(stores, selectedMajorRegion, selectedMinorRegion);

  ClothingInventory inventory;

  // 2. 옷가게 수량 확인하고, 업데이트하기
  manageInventory(inventory, stores);


  return 0;
}


