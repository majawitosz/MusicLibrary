//
// Created by Maja on 1/17/2024.
//

#include "Controller.h"

void Controller::removeFromOrder(const int &idToRemove) {
order.removeProduct(idToRemove);
}
std::shared_ptr<MusicLibrary> Controller::editCatalog(const int &idToEdit) {
    auto selected = catalog.editCatalog(idToEdit);
    return selected;
}
void Controller::removeFromCatalog(const int &idToRemove) {
    catalog.removeProduct(idToRemove);
}

void Controller::createPosition(std::string& artist, std::string& title, std::string& amount,std::string& price, int& selected, int& physical, int& digital) {
    if(physical == 0){
        this->position = std::make_shared<DigitalProduct>();
        std::shared_ptr<MusicLibrary> item = position->addProductCatalog(artist, title, amount, price, selected, digital);
        catalog.addToCatalog(item);
    } else {
        this->position = std::make_shared<PhysicalProduct>();
        std::shared_ptr<MusicLibrary> item = position->addProductCatalog(artist, title, amount, price, selected, physical);
        catalog.addToCatalog(item);
    }
}
void Controller::editPosition(std::string &artist, std::string &title, std::string &amount, std::string &price,
                              int &selected, int &physical, int &digital, std::shared_ptr<MusicLibrary> place) {
    if(physical == 0){
        this->position = std::make_shared<DigitalProduct>();
        std::shared_ptr<MusicLibrary> newItem = position->addProductCatalog(artist, title, amount, price, selected, digital);
        catalog.editPosition(place, newItem);
    } else {
        this->position = std::make_shared<PhysicalProduct>();
        std::shared_ptr<MusicLibrary> newItem = position->addProductCatalog(artist, title, amount, price, selected, physical);
        catalog.editPosition(place, newItem);
    }
}
std::shared_ptr<MusicLibrary> Controller::searchByArtst(const std::string& artistName) {
    std::shared_ptr<MusicLibrary> position = catalog.searchByArtist(artistName);
    return position;
}
std::shared_ptr<MusicLibrary> Controller::searchByTitle(const std::string &title) {
    std::shared_ptr<MusicLibrary> position = catalog.searchByTitle(title);
    return position;
}
std::shared_ptr<MusicLibrary> Controller::searchByGenre(const int& genre) {
    std::shared_ptr<MusicLibrary> position = catalog.searchByGenre(genre);
    return position;
}


void Controller::addToOrder(std::shared_ptr<MusicLibrary> position) {
    order.addProduct(position);
}
List<std::shared_ptr<MusicLibrary>> Controller::getOrders() {
    List<std::shared_ptr<MusicLibrary>> orders = order.getOrders();
    return orders;
}
List<std::shared_ptr<MusicLibrary>> Controller::getCatalog() {
    List<std::shared_ptr<MusicLibrary>> catalogGet = catalog.getCatalog();
    return catalogGet;
}
void Controller::exportOrder(const std::string& pathName) {
    std::ofstream file(pathName);

    if (!file) {
        std::cerr << "Unable to open file for writing." << std::endl;
        return;
    }

    file << "Your order: " << std::endl << std::endl;

    // Get the List of orders.
    List<std::shared_ptr<MusicLibrary>> orders = order.getOrders();

    for (auto& position : orders) {
        // Use getters to access the data of each item
        file << "Artist: " << position->getArtist() << std::endl;
        file << "Title: " << position->getTitle() << std::endl;
        file << "Price: " << position->getPrice() << std::endl;
        file << "Genre: " << position->getGenreString() << std::endl;
        file << std::endl;
    }

    file.close();
}