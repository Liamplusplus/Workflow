#include "ConfigurationView.hpp"
#include "DependancyView.hpp"
#include "BuildView.hpp"
#include "CompilerConfiguration.hpp"

using namespace ucurses;

namespace Workflow {

    void ConfigurationView::Escape(Window* target)
    {
        target->Bind(new ConfigurationView(project));
    }

    ConfigurationView::ConfigurationView(Project* data) : project(data)
    {

    }

    void ConfigurationView::Initialize()
    {
        target->setTitle("Project Configuration");

        title = new Label(target);
        if (project)
            title->setText(project->title);
        title->setPosition(0.5f, 0.2f);
        title->getPosition().x -= title->getText().length() / 2;
        config_options = new Menu(target);
        config_options->setPosition(0.5f, 0.4f);
        config_options->alignMiddle();
        config_options->addItem("Compiler Options");
        config_options->addItem("Dependancies");
        config_options->addItem("Build Project");

        config_options->onSelect = [=] () 
        {
            target->pushCallback('E', std::bind(&ConfigurationView::Escape, this, target));

            switch (config_options->getSelectedIndex())
            {
                case Selections::COMPILER_OPTIONS:
                    target->Bind(new CompilerConfiguration(project));
                    break;
                case Selections::DEPENDANCIES:
                    target->Bind(new DependancyView(project));
                    break;
                case Selections::BUILD:
                    target->Bind(new BuildView(project));
                    break;
            }
            //log << "end of onSelect() " << target << std::endl;
        };

    }
}
