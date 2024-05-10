//
// Created by Maja on 1/17/2024.
//

#include "MusicLibrary.h"

std::shared_ptr<MusicLibrary> DigitalProduct::addProductCatalog(std::string& artist, std::string& title, std::string& amount,std::string& price, int& selected, int& type) {
    std::shared_ptr<DigitalProduct> item = std::make_shared<DigitalProduct>();
    item->artist = artist;
    item->title = title;
    item->amount = std::stoi(amount);
    item->price = std::stoi(price);
    switch(selected){
        case 0:
            item->genre = pop;
            break;
        case 1:
            item->genre = rock;
            break;
        case 2:
            item->genre = jazz;
            break;
        case 3:
            item->genre = classical;
            break;
        case 4:
            item->genre = hip_hop;
            break;
        default:
            break;
    }
    switch (type) {
        case 1:
            item->type = mp3;
            break;
        case 2:
            item->type = wav;
            break;
        default:
            break;
    }
    return item;
}


std::shared_ptr<MusicLibrary> PhysicalProduct::addProductCatalog(std::string& artist, std::string& title, std::string& amount,std::string& price, int& selected, int& type) {
    std::shared_ptr<PhysicalProduct> item = std::make_shared<PhysicalProduct>();
    item->artist = artist;
    item->title = title;
    item->amount = std::stoi(amount);
    item->price = std::stoi(price);
    switch(selected){
        case 0:
            item->genre = pop;
            break;
        case 1:
            item->genre = rock;
            break;
        case 2:
            item->genre = jazz;
            break;
        case 3:
            item->genre = classical;
            break;
        case 4:
            item->genre = hip_hop;
            break;
        default:
            break;
    }
    switch (type) {
        case 1:
            item->format = DVD;
            break;
        case 2:
            item->format = CD;
            break;
        case 3:
            item->format = vinyl;
            break;
        case 4:
            item->format = tape;
            break;
        default:
            break;
    }
    return item;
}


std::string MusicLibrary::getGenreString() const {
    switch(genre) {
        case pop: return "pop";
        case rock: return "rock";
        case jazz: return "jazz";
        case classical: return "classical";
        case hip_hop: return "hip hop";
        default: return "unknown genre";
    }
}
int MusicLibrary::getGenreInt() const {
    switch(genre) {
        case pop: return 0;
        case rock: return 1;
        case jazz: return 2;
        case classical: return 3;
        case hip_hop: return 4;
        default: break;
    }
}

