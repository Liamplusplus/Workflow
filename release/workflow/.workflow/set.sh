#!/bin/bash
export WORKFLOW_LIB="$WORKFLOW/libraries"
export WORKFLOWPP="$WORKFLOW/projects/C++"
export OS="Linux"
export CPLUS_INCLUDE_PATH="$WORKFLOW/include"
export PATH="$WORKFLOW/scripts:$WORKFLOW/scripts/workflow:$WORKFLOW/bin:$WORKFLOW/bin/workflow:$PATH"
export LIBRARY_PATH="$WORKFLOW/libraries/C++/mingw32-w64:$WORKFLOW/libraries/C++/mingw32-win32:$LIBRARY_PATH"
export LD_LIBRARY_PATH="$WORKFLOW/libaries/C++/mingw32-w64:$WORKFLOW/libraries/C++/mingw32-win32:$LD_LIBRARY_PATH"

