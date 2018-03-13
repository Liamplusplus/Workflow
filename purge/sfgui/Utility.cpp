#include "Utility.hpp"


namespace workflow { namespace gui {

	Utility::Utility()
    {
        buttons = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5);
        entries = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5);

        master->Pack(buttons);
        master->Pack(entries);

        stash = sfg::Button::Create("Stash"); 
        stashname = sfg::Entry::Create("Implementation"); 

        buttons->Pack(stash);
        entries->Pack(stashname);

        fetch = sfg::Button::Create("Fetch"); 
        fetchname = sfg::Entry::Create("Implementation"); 
        
        buttons->Pack(fetch);
        entries->Pack(fetchname);

        main = sfg::Button::Create("new main()"); 
        copy = sfg::Button::Create("Copy headers"); 

        buttons->Pack(main);
        buttons->Pack(copy);
        
        //main->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&ctk::file::generateMain, this));

    }

	Utility::~Utility(){}

}} //end of workflow::gui

//end of source file Utility
