#include "ProjectView.hpp"

using namespace ucurses;

int main()
{
    UCurses gui;
	Window* mainwindow = gui.createWindow();

	Interface* project_view = new ProjectView();

    gui.loadConfig("color_scheme.conf");
    project_view->Bind(mainwindow);
    gui.Run();
    
}
