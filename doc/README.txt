Welcome to workflow,

What this program IS;

Workflow is ideal for the programmer who wants to migrate to a shell environment, or eliminate
the redundant work of interacting with a compiler, compiling and installing software.

This lightweight program has many great features such as being very compact, customised, and extendable.
It also takes the liberty of maintaining tidy file hierachies for projects and libraies, making 
every project created cross-platform, in the way users can use git to pull code on any operating system 
and modify and build the code for Linux or Windows.

If you like dot points, here is a list of features that makes this IDE different from others:

	- Very small download size; Tiny compared to more heavy IDEs.
	- Open source; Users can modify as they please, all functionality is implemented using C++ and GNU Make
	- Does not install files to any system directories such as /usr/* on Linux or System32 on windows.
	- All files are kept under the one workflow directory, you can remove the whole IDE by deleting one folder.
	
What this program ISNT;

Workflow does not include a text editor or any compilers. This is because there are already great text editors out there (Vim is my favourite)
and most Linux distros come pre-loaded with the GNU suite. Windows users must download the mingw-w64 compiler and it is also recommended 
they download CoreUtils and a text editor capables of interpreting UNIX style (\n) line-endings such as Notepad++.

Links for windows users;
	http://gnuwin32.sourceforge.net/packages/coreutils.htm
	https://mingw-w64.org/doku.php * Select x86_64 option in installer

By ignoring system directories and storing everything in workflow/ provides two benefits as follows:
	
	Keeps the users projects seperate from system programs, making it much easier to keep track of work.
	Relying on system specific environment variables like LIBRARY_PATH on Linux makes the build process less cross platform.

Directory schema:

bin: Binaries, a script is provided to put this in the PATH variables so programs may be executed from anywhere in a shell.

config: All configuration files made by the user in one place. It's useful to have a back up of edited config files in case something goes wrong
	or the user is on a new system.

dormant: The recycle bin for development stuff.

fonts: Self explanatory

graphics: Resource directory

include: Workflow will make sure your system searches this path for headers so there is no need to explicitly tell make

licenses: Software licenses that workflow can fetch for any project a user may start.

projects: Where one should start (and hopefully finish) all their projects.

sounds: Audio files
