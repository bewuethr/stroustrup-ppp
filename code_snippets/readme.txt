
Programming -- Principles and Practice Using C++
by Bjarne Stroustrup

Building Examples

  Windows

    If you have Microsoft Visual C++ of versions 7.1, 8.0 or 9.0 installed on
    your computer, simply run
    
        build.bat 
        
    from the command prompt. This will build all the examples from all the 
    chapters using the most recent MSVC compiler installed. If you have 
    multiple versions of Visual C++ installed and would like to build all 
    the examples using a particular version, simply pass to build.bat one 
    of the following arguments: msvc71, msvc80, msvc90; e.g:

        build.bat msvc71

    To clean up all the examples built, simply run: 
    
        build.bat clean
        
    And to build a single example or a set of examples, list names of the 
    executables that would have to be created as arguments to build.bat.
    For example:

        build chapter.12.3.exe chapter.12.7.7.exe

    If you have GNU C++ compiler installed, you can also build all the 
    examples with the provided Makefile as described below.

  Unix

    Each chapter contains its own Makefile which can be ran independently.
    To build examples from all the chapters, simply run 
    
        make 
        
    in the corresponding directory. We would like to point out that all 
    the Makefiles were made to work in both Unix-based systems and in 
    Windows under Cygwin. The later one requires executables to have 
    extension .exe, which is why Makefiles generate executable binaries 
    with the extension .exe. This also means that if you would like to 
    build a few selective examples, you should mention target names with 
    the extension exe in a call to make e.g.:
    
        make chapter.12.3.exe chapter.12.7.7.exe

Requirements

  FLTK

    There is a copy of FLTK library source in this archive. You will need to 
    build them first using instructions provided by the library developers.
    NOTE: if you have FLTK of version 2 or higher, you will not be able
    to build these source examples against your version of FLTK. Please use
    the provided older version of FLTK instead.

    We will search for the FLTK sources in path specified by the environment 
    variable FLTK. If no such variable was specified, we will try to use a
    local copy from this archive. As an example, if you installed FLTK into 
    its default director /usr/local, than its headers were put inside 
    /usr/local/include, thus you have to make FLTK=/usr/local/include

  Boost

    Examples in chapter 23 use boost/regex and thus require boost library to
    be installed. The library can be found at http://www.boost.org/. If path
    to the boost library is not found by your compiler, you may use the 
    environment variable BOOST to specify it.

    Additionally it came to our attention that recent versions of boost do not
    necessarily create generic symbolic links for the most recent version of a 
    particular library during installation (boost_regex in this case), in which
    case you may get linking errors while compiling code from chapter 23. To fix
    this, either modify the Makefile of chapter 23 to refer the proper library
    provided by your boost installation (e.g. boost_regex-gcc34-mt) or create a 
    symbolic link with the name libboost_regex.a to the appropriate version
    of the library e.g.: 

        ln -s /usr/lib/libboost_regex-gcc34-mt.a ./libboost_regex.a

Conventions

    Certain suffixes in file names were used to indicate some properties of
    the source file to the scripts:

      - *.no-link.cpp: these source files are not intended for linking after
        compilation as they don't provide entry point to the application.
      - *.crash.cpp: these source files contain snippets with undefined
        behavior in C++. The snippets are documented in the corresponding 
        chapter of the book. Running executables produced from these files
        may result in a crash of the application.

Feedback

    Support site of the book: http://www.stroustrup.com/Programming/
    Please send all the comments to me at bs@cs.tamu.edu
