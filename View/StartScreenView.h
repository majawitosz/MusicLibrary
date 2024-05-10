//
// Created by Maja on 1/17/2024.
//

#ifndef B7727F46_GR05_REPO_STARTSCREENVIEW_H
#define B7727F46_GR05_REPO_STARTSCREENVIEW_H

#include "iostream"
#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/dom/elements.hpp"
#include "../Controller.h"
#include "../Logic/ListLogic.h"
using namespace ftxui;

class StartScreenView {
private:
    Controller controller;
    std::string artist;

    std::string amount;
    std::string price;
    std::string title;
    int selectedGenre = 0;
    int selectedType = 0;
    int physical = 0;
    int digital = 0;
    std::shared_ptr<MusicLibrary> position;
    std::string added;
    int remove = 0;
    std::string fileName;
    int selectedEdit = 0;
    int totalCost = 0;

public:
    StartScreenView(Controller& controller);
    int displayStartScreen();
    void adminView();
    void adminAddPositionView();
    void adminChoseEditView();
    void adminEditView(std::shared_ptr<MusicLibrary> itemEdit);
    std::vector<std::string> displayCatalog();
    void userView();
    void userAddPositionView(); //searches by artist, title and genre
    void userRemoveFromOrder();
    std::vector<std::shared_ptr<Node>> displayDynamicly();
    std::vector<std::string> display();
    void finalizeView(); //saves to file and display price
    void adminRemovePosition();

};


#endif //B7727F46_GR05_REPO_STARTSCREENVIEW_H
