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
      {"전라남도", {"목포시", "여수시", "순천시", "나주시", "..."}},
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

  // 기능 2. 옷가게 수량 확인하고, 업데이트하기
  ClothingInventory inventory;
  manageInventory(inventory, stores);

  std::vector<ClothingItem> menu{
      // 예시 아이템 목록
      ClothingItem("탑텐", "니트", "빨간색", "면", "M"),
      ClothingItem("탑텐", "자켓", "갈색", "가죽", "L"),
      ClothingItem("데이지", "자켓", "검은색", "가죽", "L"),
      ClothingItem("MODA", "가디건", "갈색", "가죽", "M"),
      ClothingItem("구월 의상실", "청바지", "연청", "데님", "S"),
      // ... 나머지 아이템들
  };

  std::vector<ClothingItem> cart;
  std::vector<StoreReview> storeReviews{
      StoreReview("탑텐"), StoreReview("데이지")
      // ... 기타 매장 추가
  };

  std::string storeName;
  std::string review;
  int mainChoice = -1;
  int subChoice;

  // 기능 3~4 : 옷 장바구니에 담고, 리뷰쓰기
  while (mainChoice != 0) {
    std::cout << "\n3~4. 옷 장바구니 담는 기능, 리뷰 쓰는 기능 선택하기 "
              << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "1: 옷 장바구니 담기" << std::endl;
    std::cout << "2: 리뷰 작성하기" << std::endl;
    std::cout << "0: 종료" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "옵션을 선택해주세요: ";
    std::cin >> mainChoice;

    switch (mainChoice) {
      // 기능3 : 옷 장바구니에 담기
      case 1: {
        subChoice = -1;
        while (subChoice != 0) {
          std::cout << "\n3. 장바구니 메뉴" << std::endl;
          std::cout << "============================================"
                    << std::endl;
          std::cout << "1: 옷 상품 보기" << std::endl;
          std::cout << "2: 장바구니에 담기" << std::endl;
          std::cout << "0: 메인메뉴 돌아가기" << std::endl;
          std::cout << "============================================"
                    << std::endl;
          std::cout << "옵션을 선택해주세요: ";
          std::cin >> subChoice;

          // 3.1 옷 상세정보 출력하기
          if (subChoice == 1) {
            // 옷 상품 보기
            for (size_t i = 0; i < menu.size(); ++i) {
              std::cout << i + 1 << ": ";
              menu[i].displayDetails();
            }
          }
          // 3.2 장바구니에 담기
          else if (subChoice == 2) {
            // 장바구니에 담기
            std::cout << "담을 옷 상품의 번호를 입력하세요: ";
            int index;
            std::cin >> index;
            --index;

            if (index >= 0 && index < menu.size()) {
              cart.push_back(menu[index]);
              std::cout << "상품이 장바구니에 담겼습니다." << std::endl;
            } else {
              std::cout << "유효하지 않는 번호입니다." << std::endl;
            }
            saveCartToFile(cart, "cart.txt");
          }
        }
        break;
      }
      // 기능4 : 리뷰 작성하고 확인하기
      case 2: {
        subChoice = -1;
        while (true) {
          std::cout << "\n4. 리뷰 메뉴" << std::endl;
          std::cout << "============================================"
                    << std::endl;
          std::cout << "1: 리뷰 작성하기" << std::endl;
          std::cout << "2: 리뷰 확인하기" << std::endl;
          std::cout << "0: 메인 메뉴 돌아가기" << std::endl;
          std::cout << "============================================"
                    << std::endl;
          std::cout << "옵션을 선택해주세요: ";
          std::cin >> subChoice;

          if (subChoice == 0) break;

          switch (subChoice) {
            // 4.1 리뷰 작성하기
            case 1:
              std::cin.ignore();
              std::cout << "매장 이름을 입력하세요: ";
              std::getline(std::cin, storeName);
              std::cout << "리뷰를 입력하세요: ";
              std::getline(std::cin, review);

              // 입력한 매장이름과 일치하는 매장 정보 찾기
              for (auto& reviewObj : storeReviews) {
                if (reviewObj.getStoreName() == storeName) {
                  reviewObj.writeReviewToFile(review);
                  break;
                }
              }
              break;

            // 4.2 리뷰 확인하기
            case 2:
              std::cin.ignore();
              std::cout << "매장 이름을 입력하세요: ";
              std::getline(std::cin, storeName);

              // 입력한 매장이름과 일치하는 매장 정보 찾기
              for (auto& reviewObj : storeReviews) {
                if (reviewObj.getStoreName() == storeName) {
                  reviewObj.showReviews();
                  break;
                }
              }
          }
        }
      }
        // 프로그램 종료
      case 0:
        std::cout << "프로그램을 종료합니다." << std::endl;
        break;

      default:
        std::cout << "잘못된 선택입니다. 다시 시도해주세요." << std::endl;
        return 0;
    }
  }
  }
