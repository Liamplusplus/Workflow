#include "ProjectManagementUI.hpp"


namespace workflow { namespace gui {

	ProjectManagementUI::ProjectManagementUI(string dir) : ManagementUI("Project", dir)
    {

    }

    void ProjectManagementUI::refreshInfo()
    {
    
        if (list->GetSelectedItem() != sfg::ComboBox::NONE)
        {
            string languageDir(refreshdir + "/" + list->GetSelectedText() + "/");
            ctk::file::Directory dir(languageDir); 

            //fill array with directory contents
            vector<string> contents;                     
            dir.copyContents(contents);


            //accumulate contents into one string for the Label to display
            string temp;
            for (auto&& child : contents)
                temp += (child + "\n");

            info->SetText(temp);
        }
    }

    void ProjectManagementUI::Create()
    {
        refreshList();
    }

    void ProjectManagementUI::Delete()
    {
        refreshList();
    }
}}
