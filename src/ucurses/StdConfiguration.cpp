#include <ucurses/StdConfiguration.hpp>

using namespace ucurses;

namespace Workflow { 

    StdConfiguration::StdConfiguration(Project* data) : project(data)
    {
    
    }

	void StdConfiguration::Initialize()
	{

        header = new Label(target);
        header->setPosition(0.5f, 0.33f);
        header->setText("C++ Standard");
        header->alignMiddle();

        menu = new Menu(target);
        menu->addItem("C++ 98");
        menu->addItem("C++ 0x");
        menu->addItem("C++ 11");
        menu->addItem("C++ 14");
        menu->addItem("C++ 17");
        menu->setPosition(header->getPosition());
        menu->getPosition().y += 2;
        menu->onSelect = [=]() 
        {
            if (project)
                project->std[menu->getSelectedIndex()] = true;
        };

        
    }

}
