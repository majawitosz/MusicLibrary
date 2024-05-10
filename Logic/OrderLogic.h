//
// Created by Maja on 1/19/2024.
//

#ifndef B7727F46_GR05_REPO_ORDERLOGIC_H
#define B7727F46_GR05_REPO_ORDERLOGIC_H
#include "ListLogic.h"
#include "MusicLibrary.h"
#include "iostream"


class OrderLogic {
private:
    List<std::shared_ptr<MusicLibrary>> orders;
public:
    void addProduct(std::shared_ptr<MusicLibrary> item);
    List<std::shared_ptr<MusicLibrary>> getOrders();
    void removeProduct(const int& idToRemove);

};


#endif //B7727F46_GR05_REPO_ORDERLOGIC_H
