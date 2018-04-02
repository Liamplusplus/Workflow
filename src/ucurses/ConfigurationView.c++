#include "ConfigurationView.hpp"
#include <application/Project.hpp>

using namespace ucurses;
using namespace Workflow;

int main()
{
    UCurses gui;
	Window* mainwindow = gui.createWindow();
    Project project;
    project.title = "Liams Project";

	Interface* config_view = new Workflow::ConfigurationView(&project);

    gui.loadConfig("color_scheme.conf");
    config_view->Bind(mainwindow);
    gui.Run();
    
}
