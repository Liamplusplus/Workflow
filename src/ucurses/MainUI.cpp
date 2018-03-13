#include <ucurses/MainUI.hpp>
#include <application/Application.hpp>

#include <cstdlib>
#include <string>
#include <boost/filesystem.hpp>
namespace bfs = boost::filesystem;

namespace workflow {

    MainUI::MainUI()
    {
    
    }

    void MainUI::Initialize()
    {
        /* Window layout */
        dependancy_view = target;

        dependancy_view->Resize(vec2f(0.333f, 0.5f));
        module_view = target->subWindow(vec2f(0.333f, 0.5f), vec2f(0.3333f, 0.f));
        class_view = target->subWindow(vec2f(0.333f, 0.5f), vec2f(0.6666f, 0.f));

        dependancy_view->setTitle("Dependancies");
        module_view->setTitle("Modules");
        class_view->setTitle("Classes");
        /*                  */

        dependancy_list = new ScrollableMenu(dependancy_view);
        dependancy_list->setRange(10);
        dependancy_list->setPosition(vec2f(0.1f, 0.1f));
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
        
        module_list = new ScrollableMenu(module_view);
        module_list->setPosition(vec2f(0.1f, 0.1f));
        std::string src = bfs::current_path().string();
        src += "/src";
        bfs::path src_path(src);
        if (bfs::is_directory(src_path))
        {
       	    for (auto&& p : bfs::directory_iterator(src_path))
                module_list->addItem(p.path().filename().string());
        }

    }
}
