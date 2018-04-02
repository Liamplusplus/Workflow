#include <ucurses/MainUI.hpp>
#include <application/Application.hpp>

#include <cstdlib>
#include <string>
#include <boost/filesystem.hpp>
#include <ctk/math/Vec2.hpp>

namespace bfs = boost::filesystem;
using namespace ctk;

namespace Workflow {

    /* Initialization */

    void MainUI::Initialize()
    {
        Window* build_window = target->subWindow(Vec2f(0.35f, 0.5f), Vec2f(0.65f, 0.5f));
        build_view.Bind(build_window);
        Window* project_window = target->subWindow(Vec2f(0.4f, 0.5f), Vec2f(0.0f, 0.0f));
        project_view.Bind(project_window);

        //setupDependancyView();
        //setupModuleView();
        //setupClassView();
        //setupTerminalOutput();
        target->addTip("e: Open Error Log");
    }
    
    void MainUI::setupDependancyView()
    {
        dependancy_view= target->subWindow(Vec2f(0.25f, 0.5f), Vec2f(0.75f, 0.f));

        dependancy_view->setTitle("Dependancies");
        dependancy_view->addTip("e: Add External");

        dependancy_list = new Checklist(dependancy_view);
        dependancy_list->setPosition(0.1f, 0.1f);

        // Add text entry widget for libraries that are not in $WORKFLOW_LIB
        dependancy_entry = new TextEntry(dependancy_view);
        dependancy_entry->setPosition(0.1f, 0.4f);
        dependancy_entry->setSubject(">");
        // Lambda
        //dependancy_entry->onTextEnter = []() { entry_list->addItem(getText()); }

        // std::bind on class function
        dependancy_entry->onTextEnter = std::bind(&MainUI::RefreshDependancyList, this);

        entry_list = new Menu(dependancy_view);
        coord2d pos = dependancy_entry->getPosition();
        pos.y += 1;
        entry_list->setPosition(pos.x, pos.y);
        entry_list->setActive(false); 
       
        // Populate dependancy list with libraries in WORKFLOW_LIB
        if (const char* libpath = std::getenv("WORKFLOW_LIB"))
        {
            std::string temp(libpath);
            temp += "/C++";
            bfs::path library_path(temp);
            if (bfs::is_directory(library_path))
            {
       	        for (auto&& p : bfs::directory_iterator(library_path))
            	    dependancy_list->addItem(p.path().filename().string()); 
            }
        }
    }

    void MainUI::setupModuleView()
    {
        module_view = target->subWindow(Vec2f(0.25f, 0.5f), Vec2f(0.f, 0.5f));

        module_view->setTitle("Branches");
        module_view->addTip("n: New Module");
    
        module_list = new Checklist(module_view);
        module_list->setPosition(0.1f, 0.1f);
        std::string src = bfs::current_path().string();
        src += "/src";
        bfs::path src_path(src);

        //module_list->addItem("All");
        // Add all directories in src/ directory to module list widget
        if (bfs::is_directory(src_path))
        {
       	    for (auto&& p : bfs::directory_iterator(src_path))
                module_list->addItem(p.path().filename().string());
        }

        // When new module is selected, load contents of directory into class list
        
        module_list->onRefresh = [=]()
        { 
            class_list->removeAll();
            std::string module_path = "src/" + module_list->getSelectedText();
            if (bfs::exists(module_path))
            {
       	        for (auto&& p : bfs::directory_iterator(bfs::path(module_path)))
            	    class_list->addItem(p.path().filename().string()); 
            }
        };
    }

    void MainUI::setupClassView()
    {
        class_view = target->subWindow(Vec2f(0.4f, 0.5f), Vec2f(0.25f, 0.5f));

        class_view->setTitle("Classes");
        class_view->addTip("n: New Class");
        class_view->addTip("t: New Test");
        class_list = new Checklist(class_view);
        class_list->setPosition(0.1f, 0.1f);
    }
            
    void MainUI::RefreshDependancyList()
    {
        entry_list->addItem(dependancy_entry->getText());
    }
            
    void MainUI::setupTerminalOutput()
    {
        terminal_output = new Label(target);
        terminal_output->setPosition(0.05f, 0.5f);
        terminal_output->getPosition().y += 1;
        terminal_output->setText("Output");
    }

    // Every time new module is highlighted, refresh class list with branch contents
    void MainUI::RefreshClassList()
    {
    
    }
            
}
