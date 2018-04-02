#include <ucurses/OptimizationMenu.hpp>
#include <application/Project.hpp>

using namespace ucurses;

namespace Workflow { 

    OptimizationMenu::OptimizationMenu(Project* data) : project(data)
    {
    
    }
    void OptimizationMenu::Initialize()
    {
        menu = new Menu(target);
        menu->addItem("Level 0 (default)");
        menu->addItem("Level 1");
        menu->addItem("Level 2");
        menu->addItem("Level 3");
        menu->addItem("Size Optimization");
        menu->setPosition(0.33f, 0.33f);
        menu->onSelect = [=]() 
        {
        };

        header = new Label(target);

        header->setPosition(menu->getPosition());
        header->getPosition().y -= 2;
        header->setText("Optimization Level: Higher levels increase execution speed, but increase compilation times.");
    }
}
