//
// Created by Maja on 1/17/2024.
//

#include "StartScreenView.h"

StartScreenView::StartScreenView(Controller& controller):controller(controller) {}

void StartScreenView::adminAddPositionView() {
    std::vector<std::string> radio_box_list = {
            "pop",
            "rock",
            "jazz",
            "classical",
            "hip hop"
    };
    std::vector<std::string> entriesPhysical = {
            "physical",
            "DVD",
            "CD",
            "vinyl",
            "tape"
    };
    std::vector<std::string> entriesDigital = {
            "digital",
            "mp3",
            "wav"
    };
    auto screen = ScreenInteractive::FitComponent();
    auto back_button = Button("Back", screen.ExitLoopClosure());
    auto confirm_button = Button("confirm", [&screen, this]() {
        screen.ExitLoopClosure()();
        controller.createPosition(artist, title, amount, price, selectedGenre, physical, digital);
        artist = {};
        title = {};
        amount = {};
        price = {};
        physical ={};
        digital ={};
        selectedGenre = {};
    });

    // The basic input components:
    Component input_artist = Input(&artist, "artist");
    Component input_title = Input(&title, "title");

    // We are using `CatchEvent` to filter out non-digit characters.
    Component input_amount = Input(&amount, "amount");
    input_amount |= CatchEvent([&](Event event) {
        return event.is_character() && !std::isdigit(event.character()[0]);
    });
    input_amount |= CatchEvent([&](Event event) {
        return event.is_character() && amount.size() > 10;
    });

    Component input_price = Input(&price, "price");
    input_price |= CatchEvent([&](Event event) {
        return event.is_character() && !std::isdigit(event.character()[0]);
    });
    input_price |= CatchEvent([&](Event event) {
        return event.is_character() && price.size() > 10;
    });
    Component radio_box_genre = Radiobox(&radio_box_list, &selectedGenre);

    Component dropdown_physical = Dropdown(&entriesPhysical, &physical);
    Component dropdown_digital = Dropdown(&entriesDigital, &digital);

    // The component tree:
    auto component = Container::Vertical({
                                                 back_button,
                                                 input_artist,
                                                 input_title,
                                                 input_amount,
                                                 input_price,
                                                 radio_box_genre,
                                                 dropdown_digital,
                                                 dropdown_physical,
                                                 confirm_button
                                         });

    // Tweak how the component tree is rendered:
    auto renderer = Renderer(component, [&] {
        return vbox({
                            back_button->Render(),
                            hbox(text(" Artist : "), input_artist->Render()),
                            hbox(text(" Title  : "), input_title->Render()),
                            hbox(text(" Amount   : "), input_amount->Render()),
                            hbox(text(" Price  : "), input_price->Render()),
                            radio_box_genre->Render(),
                            dropdown_physical->Render(),
                            dropdown_digital->Render(),
                            confirm_button->Render()
                    }) |border;
    });
    screen.Loop(renderer);
}


std::vector<std::string> StartScreenView::displayCatalog() {
    List<std::shared_ptr<MusicLibrary>> catalogList = controller.getCatalog();

    std::vector<std::string> itemsDescriptions;

    for (auto itemIt = catalogList.begin(); itemIt != catalogList.end(); ++itemIt) {
        std::shared_ptr<MusicLibrary> item = *itemIt;
        std::string artist = item->getArtist();
        std::string title = item->getTitle();
        int price = item->getPrice();
        int amount = item->getAmount();
        std::string genre = item->getGenreString();
        std::string itemDescription =  title + " by " + artist + ". Genre: " + genre + ", Price: " + std::to_string(price) + ", Amount: " + std::to_string(amount);
        itemsDescriptions.push_back(itemDescription);
    }
    return itemsDescriptions;
}
void StartScreenView::adminEditView(std::shared_ptr<MusicLibrary> itemEdit) {
    std::string artistEdit = itemEdit->getArtist();
    std::string titleEdit = itemEdit->getTitle();
    int priceEdit = itemEdit->getPrice();
    int amountEdit = itemEdit->getAmount();
    std::string genreEdit = itemEdit->getGenreString();
    std::string editedString =  titleEdit + " by " + artistEdit + ". Genre: " + genreEdit + ", Price: " + std::to_string(priceEdit) + ", Amount: "+ std::to_string(amountEdit);
    std::vector<std::string> radio_box_list = {
            "pop",
            "rock",
            "jazz",
            "classical",
            "hip hop"
    };
    std::vector<std::string> entriesPhysical = {
            "physical",
            "DVD",
            "CD",
            "vinyl",
            "tape"
    };
    std::vector<std::string> entriesDigital = {
            "digital",
            "mp3",
            "wav"
    };
    auto screen = ScreenInteractive::FitComponent();
    auto back_button = Button("Back", screen.ExitLoopClosure());
    auto confirm_button = Button("confirm", [&screen, itemEdit, this ]() {
        screen.ExitLoopClosure()();
        controller.editPosition(artist, title, amount, price, selectedGenre, physical, digital, itemEdit);

    });

    // The basic input components:
    Component input_artist = Input(&artist, "artist");
    Component input_title = Input(&title, "title");

    // We are using `CatchEvent` to filter out non-digit characters.
    Component input_amount = Input(&amount, "amount");
    input_amount |= CatchEvent([&](Event event) {
        return event.is_character() && !std::isdigit(event.character()[0]);
    });
    input_amount |= CatchEvent([&](Event event) {
        return event.is_character() && amount.size() > 10;
    });

    Component input_price = Input(&price, "price");
    input_price |= CatchEvent([&](Event event) {
        return event.is_character() && !std::isdigit(event.character()[0]);
    });
    input_price |= CatchEvent([&](Event event) {
        return event.is_character() && price.size() > 10;
    });
    Component radio_box_genre = Radiobox(&radio_box_list, &selectedGenre);

    Component dropdown_physical = Dropdown(&entriesPhysical, &physical);
    Component dropdown_digital = Dropdown(&entriesDigital, &digital);

    // The component tree:
    auto component = Container::Vertical({
                                                 back_button,
                                                 input_artist,
                                                 input_title,
                                                 input_amount,
                                                 input_price,
                                                 radio_box_genre,
                                                 dropdown_digital,
                                                 dropdown_physical,
                                                 confirm_button
                                         });

    // Tweak how the component tree is rendered:
    auto renderer = Renderer(component, [&] {
        return vbox({
                            back_button->Render(),
                            text("Edit mode"),
                            text(editedString),
                            hbox(text(" Artist : "), input_artist->Render()),
                            hbox(text(" Title  : "), input_title->Render()),
                            hbox(text(" Amount   : "), input_amount->Render()),
                            hbox(text(" Price  : "), input_price->Render()),
                            radio_box_genre->Render(),
                            dropdown_physical->Render(),
                            dropdown_digital->Render(),
                            confirm_button->Render()
                    }) |border;
    });
    screen.Loop(renderer);
}
void StartScreenView::adminChoseEditView() {
    auto screen = ScreenInteractive::FitComponent();
    auto items = displayCatalog();
    auto radio_box = Radiobox(&items, &selectedEdit);
    auto confirm_button = Button("confirm", [this]{
        auto selected = controller.editCatalog(selectedEdit);
        adminEditView(selected);
    });
    auto back_button = Button("Back", screen.ExitLoopClosure());
    auto component = Container::Vertical({
        radio_box,
        confirm_button,
        back_button
    });
    auto renderer = Renderer(component, [&]{
        return vbox({
            text("Chose position to edit")| border,
            back_button->Render(),
            confirm_button->Render(),
            radio_box->Render()
        });
    });
    screen.Loop(renderer);
}
void StartScreenView::adminRemovePosition() {
    auto screen = ScreenInteractive::FitComponent();
    auto back_button = Button("Back", screen.ExitLoopClosure());
    auto confirm_button = Button("confirm", [this]() {
        controller.removeFromCatalog(remove);
        userRemoveFromOrder();
    });
    auto items = display();
    Component radio_box = Radiobox(&items, &remove);
    auto component = Container::Vertical({back_button, radio_box, confirm_button});
    auto renderer = Renderer(component,[&]{
        return vbox({
                            back_button->Render(),
                            confirm_button->Render(),
                            radio_box->Render()
                    });
    });
    screen.Loop(renderer);
}

void StartScreenView::adminView() {
    auto screen = ScreenInteractive::FitComponent();
    auto back_button = Button("Back", screen.ExitLoopClosure());
    auto goto_1 = Button("Add position to catalog", [ this] {  adminAddPositionView(); });
    auto goto_2 = Button("Edit position", [this] { adminChoseEditView(); });
    auto goto_3 = Button("Remove position", [ this] { adminRemovePosition(); });
    auto layout = Container::Vertical({
                                              back_button,
                                              goto_1,
                                              goto_2,
                                              goto_3,
                                      });
    auto renderer = Renderer(layout, [&] {
        return vbox({
                            text("Admin Mode "),
                            separator(),
                            back_button->Render(),
                            goto_1->Render(),
                            goto_2->Render(),
                            goto_3->Render(),
                    }) |
               border;
    });
    screen.Loop(renderer);
}

void StartScreenView::userAddPositionView() {

    auto screen = ScreenInteractive::FitComponent();
    auto back_button = Button("Back", screen.ExitLoopClosure());
    auto search_artist_button = Button("search", [this]() {
        position = controller.searchByArtst(artist);
        userAddPositionView();
    });
    auto search_title_button = Button("search", [this]() {
        position = controller.searchByTitle(title);
        userAddPositionView();
    });
    auto search_genre_button = Button("search", [this]() {
        position = controller.searchByGenre(selectedGenre);
        userAddPositionView();
    });


    auto addToOrder_button = Button("Add to order", [this]() {
        controller.addToOrder(position);
        added = "Position added to order";
    });

    // The basic input components:
    Component input_artist = Input(&artist, "artist");
    Component input_title = Input(&title, "title");

    auto component = Container::Vertical({
                                                 back_button,
                                                 input_artist,
                                                 input_title,
                                                 search_artist_button,
                                                 search_title_button,
                                                 addToOrder_button,

                                         });
    std::string artistFound;
    std::string titleFound;

    if(position){
        artistFound = position->getArtist();
        titleFound = position->getTitle();
    } else {
        artistFound = "No position found";
        titleFound = "No position found";
    }
    auto renderer = Renderer(component, [&] {
        return vbox({
                            back_button->Render(),
                            hbox(text(" Artist : "), input_artist->Render()),
                            search_artist_button->Render(),
                            hbox(text(" Title : "), input_title->Render()),
                            search_title_button->Render(),
                            text(artistFound),
                            text(titleFound),
                            addToOrder_button->Render(),
                            text(added)
                    }) |border;
    });
    screen.Loop(renderer);
}

std::vector<std::shared_ptr<Node>> StartScreenView::displayDynamicly() {
    List<std::shared_ptr<MusicLibrary>> ordersList = controller.getOrders();
    std::vector<std::string> orders;
    int id = 0;
    for (auto orderIt = ordersList.begin(); orderIt != ordersList.end(); ++orderIt) {
        id += 1;
        std::shared_ptr<MusicLibrary> order = *orderIt;
        std::string artist = order->getArtist();
        std::string title = order->getTitle();
        int price = order->getPrice();
        std::string genre = order->getGenreString();
        std::string orderString =  title + " by " + artist + ". Genre: " + genre + ", Price: " + std::to_string(price);
        orders.push_back(orderString);
    }

    std::vector<std::shared_ptr<Node>> items;
    for(const auto& item: orders){
        std::string order = item;
        items.push_back(text(order));
    }
    return items;
}
std::vector<std::string> StartScreenView::display() {
    List<std::shared_ptr<MusicLibrary>> ordersList = controller.getOrders();
    std::vector<std::string> orders;

    for (auto orderIt = ordersList.begin(); orderIt != ordersList.end(); ++orderIt) {

        std::shared_ptr<MusicLibrary> order = *orderIt;
        std::string artist = order->getArtist();
        std::string title = order->getTitle();
        int price = order->getPrice();
        totalCost += price;
        std::string genre = order->getGenreString();
        std::string orderString = title + " by " + artist + ". Genre: " + genre + ", Price: " + std::to_string(price);
        orders.push_back(orderString);
    }
    return orders;
}

void StartScreenView::userRemoveFromOrder() {
    auto screen = ScreenInteractive::FitComponent();
    auto back_button = Button("Back", screen.ExitLoopClosure());
    auto confirm_button = Button("confirm", [this]() {
        controller.removeFromOrder(remove);
        userRemoveFromOrder();
    });
    auto items = display();
    Component radio_box_genre = Radiobox(&items, &remove);
    auto component = Container::Vertical({back_button, radio_box_genre, confirm_button});
    auto renderer = Renderer(component,[&]{
        return vbox({
                    back_button->Render(),
                    confirm_button->Render(),
                    radio_box_genre->Render()
                });
    });
    screen.Loop(renderer);
}
void StartScreenView::finalizeView() {
    auto screen = ScreenInteractive::FitComponent();
    auto pathName_input = Input(&fileName, "path name" );
    auto button_finalize = Button("finalize", [this]() {
        controller.exportOrder(fileName);
    });
    auto component = Container::Vertical({
        pathName_input,
        button_finalize
    });
    std::vector<std::shared_ptr<Node>> items;
    auto orders = display();
    for(const auto& item: orders){
        std::string order = item;
        items.push_back(text(order));
    }
    auto renderer = Renderer([&]{
        return vbox({
                           displayDynamicly()
                    });
    });

    auto renderer1 = Renderer(component, [&]{
        return vbox({
            text(std::to_string(totalCost)),
            pathName_input->Render(),
            button_finalize->Render()
        });
    });
    screen.Loop(Container::Vertical({
        renderer1,
        renderer
    }));
}

void StartScreenView::userView() {
    auto screen = ScreenInteractive::FitComponent();
    auto back_button = Button("Back", screen.ExitLoopClosure());
    auto goto_1 = Button("Add position to order", [ this] {  userAddPositionView(); });
    auto goto_2 = Button("Remove from order", [ this] { userRemoveFromOrder(); });
    auto goto_3 = Button("Finalize order", [ this] { finalizeView(); });
    auto layout = Container::Vertical({
                                              back_button,
                                              goto_1,
                                              goto_2,
                                              goto_3,
                                      });
    auto renderer = Renderer(layout, [&] {
        return vbox({
                            text("User Mode"),
                            separator(),
                            back_button->Render(),
                            goto_1->Render(),
                            goto_2->Render(),
                            goto_3->Render(),
                    }) |
               border;
        //wyswietlanie zamowienie
    });
    screen.Loop(renderer);
}


int StartScreenView::displayStartScreen(){

    auto screen = ScreenInteractive::FitComponent();
    auto button_quit = Button("Quit", screen.ExitLoopClosure());
    auto button_user = Button("User Mode", [this] { userView(); });
    auto button_admin = Button("Admin Mode", [this] { adminView(); });
    screen.Loop(Container::Vertical({
                                            button_quit,
                                            button_user,
                                            button_admin
                                    }));
    return 0;

}


