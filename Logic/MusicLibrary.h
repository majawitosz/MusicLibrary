//
// Created by Maja on 1/17/2024.
//

#ifndef B7727F46_GR05_REPO_MUSICLIBRARY_H
#define B7727F46_GR05_REPO_MUSICLIBRARY_H


#include <stdio.h>
#include <iostream>
#include <string>
#include "../Data/Catalog.h"


class MusicLibrary {
protected:
    std::string artist;
    enum Genre {pop, rock, jazz, classical, hip_hop };
    int amount;
    float price;
    std::string title;
    Genre genre;
public:
    std::string getArtist() const { return artist; }
    std::string getTitle() const { return title; }
    int getPrice() const {return price;}
    int getAmount() const {return amount;}
    std::string getGenreString() const;
    int getGenreInt() const;
    virtual std::shared_ptr<MusicLibrary> addProductCatalog(std::string& artist, std::string& title, std::string& amount,std::string& price, int& selected, int& type) = 0;
    virtual ~MusicLibrary() = default;
};

class DigitalProduct : public MusicLibrary {
private:
    enum MediumType {mp3, wav };
    MediumType type;
public:
    std::shared_ptr<MusicLibrary> addProductCatalog(std::string& artist, std::string& title, std::string& amount,std::string& price, int& selected, int& type);

};

class PhysicalProduct : public MusicLibrary {
    enum Format { CD, DVD, vinyl, tape};
    Format format;
public:
    std::shared_ptr<MusicLibrary> addProductCatalog(std::string& artist, std::string& title, std::string& amount,std::string& price, int& selected, int& type);
};



#endif //B7727F46_GR05_REPO_MUSICLIBRARY_H
