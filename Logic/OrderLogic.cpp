//
// Created by Maja on 1/19/2024.
//

#include "OrderLogic.h"

void OrderLogic::addProduct(std::shared_ptr<MusicLibrary> item) {
    orders.push_back(item);
}

List<std::shared_ptr<MusicLibrary>> OrderLogic::getOrders() {
    return orders;
}

void OrderLogic::removeProduct(const int& idToRemove) {
    int id = 0;
    for (auto it = orders.begin(); it != orders.end(); ++it, ++id) {
        if (id == idToRemove) {
            orders.remove(it);
            return;
        }
    }

}