#pragma once

#include <ucurses/ucurses.hpp>

class ProjectView : public ucurses::Interface
{
    protected:

        void Initialize();

        void SetupProjectList();
        void SetupInfoDisplay();
        void SetupManualEntry();

        void NewProject();

        ucurses::Label* info;
        ucurses::ScrollableMenu* project_list;
        ucurses::TextEntry* create_entry;
};
