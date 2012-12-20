# The primary purpose of this file is to control the building of the
# interface between the C++ backend and the Ruby codebase.

require 'mkmf'

# Might want to use have_library() to check for libraries before adding them
# $LIBS << " -lstdc++ -lc"
# $CC = "g++"

# $CFLAGS = " "
# $LFLAGS = 
# $CXXFLAGS = ""
# $CPPFLAGS = "" # preprocessor options, but also passed to compiler

$LDFLAGS = " -L#{File.expand_path("./cpp/build_linux/dist/lib")}"

# set all object files to $objs before create_makefile.
# $objs = ["my_ext.o", "utils/utils.o"]

find_header "OgreInterface.h", File.expand_path("./cpp/cpp_interface/")

create_makefile('OgreRuby/OgreRuby')
