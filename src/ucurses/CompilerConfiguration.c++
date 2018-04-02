#include "CompilerConfiguration.hpp"

using namespace ucurses;

int main()
{
    UCurses gui;
	Window* mainwindow = gui.createWindow();

	Interface* compiler_config = new Workflow::CompilerConfiguration();

    gui.loadConfig("color_scheme.conf");
    compiler_config->Bind(mainwindow);
    gui.Run();
    
}
