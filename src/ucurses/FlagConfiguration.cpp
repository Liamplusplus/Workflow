#include <ucurses/FlagConfiguration.hpp>
#include <application/Project.hpp>

using namespace ucurses;

namespace Workflow { 

    FlagConfiguration::FlagConfiguration(Project* data) : project(data)
    {
    
    }

	void FlagConfiguration::Initialize()
	{

        header = new Label(target);
        header->setPosition(0.33f, 0.33f);
        header->setText("Common flags");
        header->alignMiddle();

        checklist = new Checklist(target);
        checklist->setPosition(0.33f, 0.33f);
        checklist->getPosition().y += 3;
        checklist->alignMiddle();
        checklist->addItem("Debug");
        checklist->addItem("Warnings");
        checklist->addItem("Extra Warnings");
        checklist->addItem("Pedantic Errors");
        checklist->addItem("Linker Optimization");
        checklist->addItem("Position Independant Code");


        explicit_entry = new TextEntry(target);
        explicit_entry->setPosition(0.7f, 0.33f);
        explicit_entry->alignMiddle();
        explicit_entry->setSubject("Explicit Dependancies");
       
        explicit_entry->onTextEnter = [=] () 
        { explicit_menu->addItem(explicit_entry->getText()); };

        explicit_menu = new Menu(target);
        explicit_menu->setPosition(0.7f, 0.33f);
        explicit_menu->getPosition().y += 2;
        explicit_menu->alignMiddle();
        target->addCommand('E', [=]() { explicit_menu->toggleActive();});
        explicit_menu->setActive(false);

    }
}
