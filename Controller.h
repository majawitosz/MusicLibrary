//
// Created by Maja on 1/17/2024.
//

#ifndef B7727F46_GR05_REPO_CONTROLLER_H
#define B7727F46_GR05_REPO_CONTROLLER_H

#include "iostream"
#include "fstream"
#include "Logic/MusicLibrary.h"
#include "Logic/ListLogic.h"
#include "Data/Catalog.h"
#include "Logic/OrderLogic.h"
#include "memory"


class Controller {
private:
    std::shared_ptr<MusicLibrary> position;
    Catalog catalog;
    OrderLogic order;
public:
    void createPosition(std::string& artist, std::string& title, std::string& amount,std::string& price, int& selected, int& physical, int& digital);
    std::shared_ptr<MusicLibrary> searchByArtst(const std::string& artistName);
    std::shared_ptr<MusicLibrary> searchByTitle(const std::string& title);
    std::shared_ptr<MusicLibrary> searchByGenre(const int& genre);
    List<std::shared_ptr<MusicLibrary>> getOrders();
    List<std::shared_ptr<MusicLibrary>> getCatalog();
    void exportOrder(const std::string& pathName);
    void removeFromOrder(const int& idToRemove);
    void removeFromCatalog(const int& idToRemove);
    std::shared_ptr<MusicLibrary> editCatalog(const int& idToEdit);
    void editPosition(std::string& artist, std::string& title, std::string& amount,std::string& price, int& selected, int& physical, int& digital, std::shared_ptr<MusicLibrary> item);
    void addToOrder(std::shared_ptr<MusicLibrary> position);
};


#endif //B7727F46_GR05_REPO_CONTROLLER_H
