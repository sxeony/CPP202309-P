#include <fstream>

#include "���.h"

StoreReview::StoreReview(const std::string& storeName) : storeName(storeName) {}

void StoreReview::writeReviewToFile(const std::string& review) {
    std::string filename = storeName + "_reviews.txt";
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << review << "\n";
        file.close();
        std::cout << "���䰡 ���Ͽ� ����Ǿ����ϴ�." << std::endl;
    }
    else {
        std::cout << "������ �� �� �����ϴ�." << std::endl;
    }
}

void StoreReview::showReviews() const {
    std::string filename = storeName + "_reviews.txt";
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::cout << "���� ���:" << std::endl;
        while (getline(file, line)) {
            std::cout << "- " << line << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "���䰡 ���ų� ������ �� �� �����ϴ�." << std::endl;
    }
}

std::string StoreReview::getStoreName() const {
    return storeName;
}