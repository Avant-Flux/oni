require 'mkmf'

$CFLAGS = ""
$CPPFLAGS = ""
#~ $LDFLAGS = "-lglfw -lopenal"
$LDFLAGS = "-logre -lopenal"
#~ $objs = "meijin.o"

create_makefile("ogre/ogre")
