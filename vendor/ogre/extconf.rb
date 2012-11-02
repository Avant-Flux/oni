# This file controls building of Ogre itself.
# This is probably a bad way to do things.
# Ogre's CMake build system already works pretty well, so we'll probably just go with that.

require 'mkmf'

$CFLAGS = ""
$CPPFLAGS = ""
#~ $LDFLAGS = "-lglfw -lopenal"
$LDFLAGS = "-logre -lopenal"
#~ $objs = "meijin.o"

create_makefile("ogre/ogre")
