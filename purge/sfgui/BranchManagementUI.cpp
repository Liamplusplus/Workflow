#include "BranchManagementUI.hpp"
#include "application/Application.hpp"

namespace workflow { namespace gui {

using namespace workflow::application;

	BranchManagementUI::BranchManagementUI(string inProjectDir) : sfapp::gui::ManagementUI("Branch", inProjectDir + "/src")
    {
        projectDir = inProjectDir;
        GlobalLogger::log(TRACE) << "Constructing BranchManagementUI" << Sentinel::END;

        className = sfg::Entry::Create("File Name");
        createClass = sfg::Button::Create("Add File");
        isClass = sfg::ToggleButton::Create("Class");

        right->Pack(className);
        right->Pack(isClass);
        right->Pack(createClass);
        
        createClass->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&BranchManagementUI::addClass, this));

    }

    
    // Fills list with all files in projectDirectory/src/
    void BranchManagementUI::refreshInfo()
    {
        if (list->GetSelectedItem() != sfg::ComboBox::NONE)
        {
            string branchdir(refreshdir + "/" + list->GetSelectedText() + "/");
            ctk::file::Directory branch(branchdir); 

            //fill array with directory contents
            vector<string> contents;                     
            branch.copyContents(contents);


            //accumulate contents into one string for the Label to display
            string temp;
            for (auto&& child : contents)
                temp += (child + "\n");

            info->SetText(temp);
        } 
    }
    
    /*
     * Deletes directory selected from list ComboBox
     */
    void BranchManagementUI::Delete()
    {
        string branchdir(refreshdir + "/" + list->GetSelectedText() + "/");
        path branch(branchdir);

        if (is_directory(branch))
        {
            GlobalLogger::log(TRACE) << "Deleting branch" << branchdir << Sentinel::END;
            remove_all(branch);
        }
        else
        {
            GlobalLogger::log(INFO) << "Couldn't find branch to delete: " << branchdir << Sentinel::END;
        }
        refreshList();
    }

    void BranchManagementUI::Create()
    {
        CppProject temp(projectDir);
        string name = className->GetText();
        temp.createBranch(name);

        refreshList();
    }

    void BranchManagementUI::addClass()
    {
        CppProject temp(projectDir);
        string name = nameEntry->GetText();
        bool isclass = isClass->IsActive();
        string branch = list->GetSelectedText();
        temp.generateTemplate(name, isclass, branch);
    }


}}
