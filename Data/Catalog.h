//
// Created by Maja on 1/19/2024.
//

#ifndef B7727F46_GR05_REPO_CATALOG_H
#define B7727F46_GR05_REPO_CATALOG_H
#include "../Logic/ListLogic.h"
#include "../Logic/MusicLibrary.h"
#include "iostream"
#include "memory"

class MusicLibrary;
class Catalog {
private:
    List<std::shared_ptr<MusicLibrary>> catalog;
public:
    void addToCatalog(std::shared_ptr<MusicLibrary> item);
    std::shared_ptr<MusicLibrary> searchByArtist(const std::string& artistName);
    std::shared_ptr<MusicLibrary> searchByTitle(const std::string& title);
    std::shared_ptr<MusicLibrary> searchByGenre(const int& genre);
    std::shared_ptr<MusicLibrary> editCatalog(const int& idToRemove);
    void editPosition(std::shared_ptr<MusicLibrary> place, std::shared_ptr<MusicLibrary> newItem);
    List<std::shared_ptr<MusicLibrary>> getCatalog();
    void removeProduct(const int& idToRemove);
};


#endif //B7727F46_GR05_REPO_CATALOG_H
