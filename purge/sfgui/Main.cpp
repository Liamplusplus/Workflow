#include "Main.hpp"
#include "Utility.hpp"
#include "LanguageSelect.hpp"
#include "ProjectManagementUI.hpp"
#include "BranchManagementUI.hpp"

namespace workflow { namespace gui {

	Main::Main()
    {
        GlobalLogger::log(TRACE) << "Loading home UI State" << Sentinel::END;
        window->SetAllocation(sf::FloatRect(0,0, 500, 300));
        window->SetTitle("Main");
        Home();

    }

    void Main::Home()
    {
        clear();
        LanguageSelect* ptr = new LanguageSelect;
        addComponent("Language Select", ptr);
        ptr->select->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&Main::Search, this, string(ptr->list->GetSelectedText())));

    }

    void Main::Search(string selection)
    {
        //clear();
        ProjectManagementUI* ptr = new ProjectManagementUI(selection);
        addComponent("Project Browser", ptr);
        ptr->select->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&Main::Project, this, string(ptr->list->GetSelectedText())));
    }

    void Main::Project(string project)
    {
        clear();
        addComponent("Branch Management Interface", new BranchManagementUI(project));
        addComponent("Utility", new Utility);
    }

}} //end of workflow::gui

//end of source file MainMenu
