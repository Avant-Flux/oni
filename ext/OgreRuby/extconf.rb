# The primary purpose of this file is to control the building of the
# interface between the C++ backend and the Ruby codebase.

require 'mkmf'

# Might want to use have_library() to check for libraries before adding them
$LIBS << " -lstdc++ -lc"
$CC = "g++"

#~ $CFLAGS = ""
#~ $CPPFLAGS = ""
#~ $LDFLAGS = ""

create_makefile('OgreRuby/OgreRuby')
