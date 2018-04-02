#include "CompilerConfiguration.hpp"
#include "FlagConfiguration.hpp"
#include "OptimizationMenu.hpp"
#include "StdConfiguration.hpp"
#include <application/Project.hpp>

using namespace ucurses;

namespace Workflow {

    void Escape(Window* target, Project* data)
    {
        target->Bind(new CompilerConfiguration(data));
    }
            
    CompilerConfiguration::CompilerConfiguration(Project* data) : project(data)
    {
    
    }

    void CompilerConfiguration::Initialize()
    {
        header = new Label(target);
        header->setText("Compiler Configuration");
        header->setPosition(0.5f, 0.2f);
        header->getPosition().x -= header->getText().length() / 2;

        menu = new Menu(target);
        menu->setPosition(0.5f, 0.4f);
        menu->getPosition().x -= 8;
        menu->addItem("C++ Standard");
        menu->addItem("Optimization Level");
        menu->addItem("Compiler Flags");
        menu->onSelect = [=] ()
        {
            target->pushCallback('E', std::bind(Escape, target, project));
            switch (menu->getSelectedIndex())
            {
                case Selection::STD:
                    target->Bind(new StdConfiguration(project));
                    break;
                case Selection::OPT:
                    target->Bind(new OptimizationMenu(project));
                    break;
                case Selection::FLAG:
                    target->Bind(new FlagConfiguration(project));
                    break;
            }
        };
    }
}
