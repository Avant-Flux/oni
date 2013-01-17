# The primary purpose of this file is to control the building of the
# interface between the C++ backend and the Ruby codebase.

require 'open3'

`cmake  -H"./cpp/" -B"./cpp/build_linux"`

def build_cpp_makefile(path, flags="")
	Dir.chdir path do
		stdin, stdout_and_stderr, wait_thr = Open3.popen2e "make " + flags
		
		output = nil
		begin
			output = stdout_and_stderr.gets
			puts output
		end while output
		
		stdin.close
		stdout_and_stderr.close
	end
end

build_cpp_makefile "./cpp/build_linux/", "-j4"


require 'mkmf'
# Might want to use have_library() to check for libraries before adding them
# $LIBS << " -lstdc++ -lOgreBase"
# $CC = "g++"

# $CFLAGS = " -fPIC"
# $LFLAGS = " -fPIC"
# $CXXFLAGS = " -fPIC"
# $CPPFLAGS = " -fPIC" # preprocessor options, but also passed to compiler
$LDFLAGS << " -L#{File.expand_path("./cpp/build_linux/dist/lib")}"
# $LDFLAGS << " -L/home/ravenskrag/Code/GameDev/Libraries/ogre/Samples/Common/include"

# set all object files to $objs before create_makefile.
# $objs = ["my_ext.o", "utils/utils.o"]

puts "CPP LIBRARY FOUND" if have_library("OgreBase")

find_header "OgreInterface.h", File.expand_path("./cpp/cpp_interface/")
 
have_library("stdc++")
have_library("OgreMain")
have_library("OIS")
have_library("OgreBase")


create_makefile('oni/oni')
