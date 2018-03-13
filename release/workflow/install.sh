#!/bin/bash

printf "Please enter desired installation directory: (Default = $HOME) "
read i
if [ -z "$i" ]
then
    i=$HOME
fi
   
if [ ! -d "$i" ]
then
    echo "$i is not a valid install directory"
    exit
fi

prefix=$i/workflow

if [ -e "$prefix" ]
then
    printf "$prefix already exists, Overwrite? [y/n] (Default = no) "
    read a
    if [ "$a" = "y" ]
    then
        rm -r $prefix
        echo "#!/bin/bash" > ./.workflow/env.sh
        echo "export WORKFLOW="$prefix"" >> ./.workflow/env.sh
        if [ ! -d "$HOME/.workflow" ]
        then
            echo "" >> ~/.bashrc
            echo "source ~/.workflow/env.sh" >> ~/.bashrc
            echo "source ~/.workflow/set.sh" >> ~/.bashrc
        fi
        cp -r .workflow $HOME
        source ~/.bashrc

        echo "Installing workflow at $prefix"
        mkdir -p $prefix
        mkdir -p $prefix/fonts
        mkdir -p $prefix/graphics
        mkdir -p $prefix/include
        mkdir -p $prefix/libraries/C++
        cp -r licenses $prefix
        cp -r scripts $prefix
        cp -r config $prefix
        cp  ./doc/* $prefix
        mkdir -p $prefix/projects/C++
        mkdir -p $prefix/sounds
        printf "Successfully installed to $prefix\n"
        printf "Simply delete $prefix to uninstall, all workflow files are under this directory\n"
    fi
else
    echo "#!/bin/bash" > ./.workflow/env.sh
    echo "export WORKFLOW="$prefix"" >> ./.workflow/env.sh
    if [ ! -d "$HOME/.workflow" ]
    then
        echo "" >> ~/.bashrc
        echo "source ~/.workflow/env.sh" >> ~/.bashrc
        echo "source ~/.workflow/set.sh" >> ~/.bashrc
    fi
    cp -r .workflow $HOME
    source ~/.bashrc
    echo "Installing workflow at $prefix"
    mkdir -p $prefix
    mkdir -p $prefix/fonts
    mkdir -p $prefix/graphics
    mkdir -p $prefix/include
    mkdir -p $prefix/libraries/C++
    cp -r licenses $prefix
    cp -r scripts $prefix
    cp -r config $prefix
    cp  ./doc/* $prefix
    mkdir -p $prefix/projects/C++
    mkdir -p $prefix/sounds
    printf "Successfully installed to $prefix\n"
    printf "Simply delete $prefix to uninstall, all workflow files are under this directory\n"
fi

