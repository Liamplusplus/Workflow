#include "ProjectView.hpp"

using namespace ucurses;

void ProjectView::Initialize()
{
    target->setTitle("Project Management");

    SetupProjectList(); 
    SetupInfoDisplay(); 
    SetupManualEntry(); 

    target->addCommand('n', std::bind(&ProjectView::NewProject, this));
    target->addTip("Enter: Load Project");
    target->addTip("n: New Project");
    target->addTip("R: Rename Project");
}

void ProjectView::SetupProjectList()
{
    project_list = new ScrollableMenu(target); 
    project_list->setPosition(0.07f, 0.3f);
    project_list->getPosition().x += 2;
    project_list->setRange(16);

    // See if environmental variable is set
    if (const char* libpath = std::getenv("WORKFLOW")) 
    {
        std::string temp(libpath);
        temp += "/projects";
        bfs::path project_path(temp);
        if (bfs::is_directory(project_path))
        {
            for (auto&& p : bfs::directory_iterator(project_path))
                project_list->addItem(p.path().filename().string()); 
        }
    }
}

void ProjectView::SetupInfoDisplay()
{
    info = new Label(target);
    info->setPosition(project_list->getPosition());
    info->getPosition().x += 20;
   
    // Display project readme on menu select
    project_list->onRefresh = [=] ()
    {
        std::string project_dir = std::getenv("WORKFLOW"); 
        project_dir += "/projects/" + project_list->getSelectedItem();
        bfs::path readme(project_dir + "/readme");
        if (bfs::exists(readme))
        {
            std::ifstream file(readme.string());
            std::stringstream buffer;
            buffer << file.rdbuf();
            info->setText(buffer.str());
        }
        else
        {
            info->setText("No description");
        }
    };

    if (!project_list->noneSelected())
        project_list->onRefresh();
}
void ProjectView::SetupManualEntry()
{
    create_entry = new TextEntry(target); 
    create_entry->setSubject(">");
    create_entry->setPosition(project_list->getPosition());
    create_entry->getPosition().y -= 1;
}
        
void ProjectView::NewProject()
{
   if (create_entry->getText().empty())
        create_entry->getInput();
   else
       // Create project
       // Create directory
       // Generate project.workflow
       // Copy makefile template and fill in blanks
       ;
}
