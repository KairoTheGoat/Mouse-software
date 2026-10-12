#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Xenta Mouse Configurator");
    window.setFramerateLimit(60);


    tgui::Gui gui{window};


    auto colorBox = tgui::Panel::create();
    colorBox->setSize(200, 200);
    colorBox->setPosition(450, 180);
    colorBox->getRenderer()->setBackgroundColor(tgui::Color::Red);
    gui.add(colorBox);


    auto label = tgui::Label::create("Vyber barvu podsviceni:");
    label->setPosition(150, 140);
    label->setTextSize(16);
    label->getRenderer()->setTextColor(tgui::Color::White);
    gui.add(label);


    auto colorList = tgui::ListBox::create();
    colorList->setSize(200, 120);
    colorList->setPosition(150, 180);
    colorList->addItem("Cervena");
    colorList->addItem("Zelena");
    colorList->addItem("Modra");
    colorList->setSelectedItem("Cervena");
    gui.add(colorList);

    
    auto saveButton = tgui::Button::create("Ulozit nastaveni");
    saveButton->setSize(200, 45);
    saveButton->setPosition(150, 335);
    gui.add(saveButton);

    
    sf::Color selectedColor = sf::Color::Red;

    
    colorList->onItemSelect([&]() {
        std::string selected = colorList->getSelectedItem().toStdString();
        if (selected == "Cervena") {
            selectedColor = sf::Color::Red;
            colorBox->getRenderer()->setBackgroundColor(tgui::Color::Red);
        } else if (selected == "Zelena") {
            selectedColor = sf::Color::Green;
            colorBox->getRenderer()->setBackgroundColor(tgui::Color::Green);
        } else if (selected == "Modra") {
            selectedColor = sf::Color::Blue;
            colorBox->getRenderer()->setBackgroundColor(tgui::Color::Blue);
        }
        std::cout << "Zvolena barva v GUI: " << selected << "\n";
    });

    
    saveButton->onPress([&]() {
        std::cout << "[OK] Kliknuto na Ulozit! Odesilam do myši (RGB: " 
                  << (int)selectedColor.r << ", " 
                  << (int)selectedColor.g << ", " 
                  << (int)selectedColor.b << ")\n";
          });

    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            gui.handleEvent(event); 

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(30, 30, 30)); 
        gui.draw();
        window.display();
    }

    return 0;
}

