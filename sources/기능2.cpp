#include "기능.h"

// 2-5 입력 값 오류 처리
bool validNumberInput() {
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "숫자만 입력해주세요." << std::endl;
    return false;
  }
  return true;
}

// 기능2 : 옷 재고 관리
void manageInventory(ClothingInventory& inventory,
                     const std::vector<Store>& stores) {
  while (true) {
    // 2.1 메뉴 선택하기
    std::cout << "\n2. 옷 재고 관리" << endl;
    std::cout << "============================================" << std::endl;
    std::cout << "1. 재고 업데이트" << std::endl;
    std::cout << "2. 재고 확인" << std::endl;
    std::cout << "3. 수량 파일 확인" << std::endl;
    std::cout << "4. 종료" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "메뉴를 선택해주세요: ";

    // 사용자에게 메뉴 선택 입력받기
    int choice;
    std::cin >> choice;
    if (!validNumberInput()) continue;  // 숫자 입력 검증
    std::cin.ignore();

    switch (choice) {
      // 2-2. 재고 업데이트
      case 1: {
        // 사용자로부터 가게 이름, 상품 이름, 수량 입력받기
        std::string storeName, itemName;
        int quantity;
        std::cout << "가게 이름: ";
        getline(std::cin, storeName);
        std::cout << "상품 이름: ";
        getline(std::cin, itemName);
        std::cout << "수량: ";
        std::cin >> quantity;
        // 숫자 입력 검증
        if (!validNumberInput()) continue;
        std::cin.ignore();

        bool storeFound = false;  // storeFound 라는 변수 선언 : 일치하는 가게를
                                  // 찾았는지 여부 추적
        for (const auto& store : stores) {
          // store 객체의 옷가게와 이름이 같으면 updateStock 함수 호출
          if (store.name == storeName) {
            inventory.updateStock(store, itemName, quantity);
            storeFound = true;
            break;
          }
        }
        // 가게이름이 다를 때
        if (!storeFound) {
          std::cout << "가게를 찾을 수 없습니다." << std::endl;
        }
        break;
      }
      // 2-3. 재고 확인하기
      case 2: {
        std::string storeName, itemName;
        std::cout << "가게 이름: ";
        getline(std::cin, storeName);
        std::cout << "상품 이름: ";
        getline(std::cin, itemName);

        bool storeFound = false;  // storeFound 라는 변수 선언 : 일치하는 가게를
                                  // 찾았는지 여부 추적
        for (const auto& store : stores) {
          // store 객체의 옷가게와 이름이 같으면 checkStock 함수 호출
          if (store.name == storeName) {
            inventory.checkStock(store, itemName);
            storeFound = true;
            break;
          }
        }
        // 가게이름이 다를 때
        if (!storeFound) {
          std::cout << "가게를 찾을 수 없습니다." << std::endl;
        }
        break;
      }
      // 2-4. 수량 파일 확인하기
      case 3: {
        // 수량.txt 파일 열기
        ifstream file("수량.txt");
        string line;

        // 파일 열기를 실패했을 때
        if (!file) {
          cerr << "파일 오픈에 실패하였습니다." << endl;
        }
        // 파일 내용 읽기 및 출력
        else {
          cout << "============================================" << endl;
          cout << "<옷 재고 확인>" << endl;
          // file의 내용을 한줄 씩 읽어 콘솔창에 출력
          while (getline(file, line)) {
            cout << line << endl;
          }
        }
        // 파일 닫기
        file.close();
        break;
      }
      // 프로그램 종료
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
