//
//  main.cpp
//  BibliotekaMuzyczna
//
//  Created by Maja Witosz on 05/12/2023.
//

#include "iostream"
#include "Controller.h"
#include "View/StartScreenView.h"

int main(int argc, const char * argv[]) {

    Controller controller;
    StartScreenView view(controller);
    view.displayStartScreen();

    return 0;
}
