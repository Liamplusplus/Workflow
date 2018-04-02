#include "MainUI.hpp"


int main()
{
    UCurses gui;
	Window* mainwindow = gui.createWindow();

	Interface* main_ui = new workflow::MainUI();

    gui.loadConfig("color_scheme.conf");
    main_ui->Bind(mainwindow);
    gui.Run();
    
}
