#
# This is a common Makefile for code examples from the book
# "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
#

#
# Usage:
#     make        - Build all examples
#     make clean  - Clean all examples
#     make test   - Run the test suite
#

INCLUDES = -I"$(BOOST)"
LIBS     = -lstdc++
CXXFLAGS = $(INCLUDES) -Wall -time -O3 -DNDEBUG
LIBFLAGS = 
AR       = ar

# NOTE: If you get a linking error on unability to find library boost_regex,
#       either change the following name accordingly to the full name of the 
#       library present in your installation e.g. boost_regex-gcc34-mt
#       or create a symbolic link with the above name to appropriate version
#       of the library: 
#       ln -s /usr/lib/libboost_regex-gcc34-mt.a ./libboost_regex.a
LIBS := $(LIBS) -lboost_regex

.SUFFIXES: .cpp .o

# Create a list of source files.
SOURCES  = $(shell ls *.cpp)
# Create a list of object files from the source file lists.
OBJECTS = ${SOURCES:.cpp=.o}     
# Create a list of targets.
TARGETS = ${SOURCES:.cpp=.exe}     

# Build all targets by default
all: 	$(TARGETS)

# Files with extension .no-link.cpp are not intended for linking
%.no-link.exe: %.no-link.o
	@echo Linking skipped for $@
	@echo ================================================================================
	@echo Done building $@
	@echo ================================================================================
	@echo
	@echo

# A rule to build .exe file out of a .o file
%.exe: %.o
	$(CXX) -o $@ $(LIBFLAGS) $< $(LIBS)
	@echo ================================================================================
	@echo Done building $@
	@echo ================================================================================
	@echo
	@echo

# A rule to build .o file out of a .cpp file
%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# A rule to clean all the intermediates and targets
clean:	
	rm -rf $(TARGETS) $(OBJECTS) *.out *.stackdump

# A rule to run set of tests
test:
	@for file in *.exe; do \
	    name=`basename $$file .exe` ; \
	    name=`basename $$name .crash` ; \
	    if (ls $$name.crash.exe >/dev/null 2>&1) ; then \
	        continue ; \
	    fi ; \
	    echo ======================================== [ $$file ] ; \
	    if (ls $$name.*in >/dev/null 2>&1) ; then \
	        for f in $$name.*in; do \
	            echo ; \
	            echo ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ { "$$f" } ; \
	            cat "$$f" ; \
	            echo ; \
	            echo ---------------------------------------- ; \
	            ./$$file < "$$f" ; \
	        done ; \
	    else \
	      ./$$file ; \
	    fi \
	done ; \
	echo -n 
