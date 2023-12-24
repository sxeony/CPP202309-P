#include <fstream>

#include "기능.h"

StoreReview::StoreReview(const std::string& storeName) : storeName(storeName) {}

void StoreReview::writeReviewToFile(const std::string& review) {
    std::string filename = storeName + "_reviews.txt";
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << review << "\n";
        file.close();
        std::cout << "리뷰가 파일에 저장되었습니다." << std::endl;
    }
    else {
        std::cout << "파일을 열 수 없습니다." << std::endl;
    }
}

void StoreReview::showReviews() const {
    std::string filename = storeName + "_reviews.txt";
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::cout << "리뷰 목록:" << std::endl;
        while (getline(file, line)) {
            std::cout << "- " << line << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "리뷰가 없거나 파일을 열 수 없습니다." << std::endl;
    }
}

std::string StoreReview::getStoreName() const {
    return storeName;
}