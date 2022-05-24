README
======

It is highly recommended to read this file before starting the
development of your project. It is also highly recommended to study
the inline comments in the provided source files.

Directory structure
-------------------

    src folder 
    ----------
    contains the source files of the project.

    main.c
    ------
    contains the main function that will be used to examine your
    project (you can perform any changes you want for debugging
    purposes but when submitted your project should work with the
    default main.c).

    among_us.h 
    ---------
    contains the function declaration's needed by main.c as well as
    the structure definitions you will need to implement the project.

    among_us.c 
    ---------
    contains empty function definitions for the functions declared in
    among_us.h

    You can either implement the project in among_us.c or simply purge
    this file and implement your project in any file you would like
    (except main.c and among_us.h).  In the top directory there is
    also a Makefile.  You don't have to understand what is going on in
    the Makefile or how it works.  All you need to know is that if you
    put any files with '.c' extension in the src directory the
    Makefile will compile them with the rest and produce an executable
    'among_us'.

    If you don't want to use the Makefile you can compile the code
    with:
    'gcc -Wall -o among_us src/*.c'

Makefile (optional)
-------------------

    To use the provided Makefile to build your project all you need is
    3 commands.

    $ make

    this will build the project and produce a file 'among_us' which is
    the program executable with which you can test your
    project. i.e. './among_us testfile1'.

    $ make clean

    this will erase any intermediate files produced during the compilation.

    $ make distclean

    this is the same with 'make clean' except that it also erases
    'among_us'.

    During compilation the Makefile will produce two directories, obj and
    dep. You don't have to worry about this directories. To remove them
    execute 'make clean'.
