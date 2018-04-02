#include "BuildView.hpp"
#include <application/Project.hpp>

using namespace ucurses;

namespace Workflow {

    BuildView::BuildView(Project* data) : project(data)
    {
    
    }

    void BuildView::Initialize()
    {

        target->setTitle("Build Window");

        output = new Label(target);
        output->setText("Build output");
        output->setPosition(0.1f, 0.1f);

        target_list = new Menu(target); 
        target_list->setPosition(0.f, 0.5f);
        target_list->getPosition().x += 2;
        target_list->addItem("Build all");
        target_list->addItem("Build selected");

        target_entry = new TextEntry(target); 
        target_entry->setSubject(">");
        target_entry->setPosition(target_list->getPosition());
        target_entry->getPosition().y -= 1;

        target->addTip("n: New Project");
        target->addTip("R: Rename Project");

    }
}
