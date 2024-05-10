//
// Created by Maja on 1/19/2024.
//

#include "Catalog.h"



void Catalog::addToCatalog(std::shared_ptr<MusicLibrary> item) {
    catalog.push_back(item);

}
List<std::shared_ptr<MusicLibrary>> Catalog::getCatalog() {
    return catalog;
}

void Catalog::editPosition(std::shared_ptr<MusicLibrary> place, std::shared_ptr<MusicLibrary> newItem) {
    place = newItem;
}

std::shared_ptr<MusicLibrary> Catalog::searchByArtist(const std::string& artistName) {
    for(const auto& music : catalog) {
        if(music->getArtist() == artistName) {
            return music;
        }
    }
    return nullptr; // return null if no match was found
}
std::shared_ptr<MusicLibrary> Catalog::searchByTitle(const std::string& title) {
    for(const auto& music : catalog) {
        if(music->getTitle() == title) {
            return music;
        }
    }
    return nullptr; // return null if no match was found
}
std::shared_ptr<MusicLibrary> Catalog::searchByGenre(const int& genre) {
    for(const auto& music : catalog) {
        if(music->getGenreInt() == genre) {
            return music;
        }
    }
    return nullptr; // return null if no match was found
}
std::shared_ptr<MusicLibrary> Catalog::editCatalog(const int &idToRemove) {
    int id = 0;
    for (auto it = catalog.begin(); it != catalog.end(); ++it, ++id) {
        if (id == idToRemove) {
            return *it;
        }
    }

}
void Catalog::removeProduct(const int& idToRemove) {
    int id = 0;
    for (auto it = catalog.begin(); it != catalog.end(); ++it, ++id) {
        if (id == idToRemove) {
            catalog.remove(it);
            return;
        }
    }

}
