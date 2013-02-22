# The primary purpose of this file is to control the building of the
# interface between the C++ backend and the Ruby codebase.

require 'mkmf'

require 'open3'

if RUBY_PLATFORM.downcase.include?("linux")
		
	elsif RUBY_PLATFORM.downcase.include?("mswin32")

	elsif RUBY_PLATFORM.downcase.include?("mingw")
		
	elsif RUBY_PLATFORM.downcase.include?("darwin")

	end

def define_platform()
	if RUBY_PLATFORM.downcase.include?("linux")
		"linux"
	elsif RUBY_PLATFORM.downcase.include?("mswin32")

	elsif RUBY_PLATFORM.downcase.include?("mingw")
		# "windows-mingw32"
		"windows-mingw-msys"
	elsif RUBY_PLATFORM.downcase.include?("darwin")

	end
end

def set_library_paths(platform)
	if RUBY_PLATFORM.downcase.include?("linux")
		
	elsif RUBY_PLATFORM.downcase.include?("mswin32")

	elsif RUBY_PLATFORM.downcase.include?("mingw")
		dir_config(
			"OgreMain", 
			"C:/ogre/lib/ogre/include/OGRE", 
			"C:/ogre/lib/ogre/lib/release", 
		)
		
		dir_config(
			"OgreBase",
			File.expand_path("./cpp/cpp_interface"),
			File.expand_path("./cpp/lib")
		)
	elsif RUBY_PLATFORM.downcase.include?("darwin")

	end
end

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

def cmake_build(platform)
	opts = if RUBY_PLATFORM.downcase.include?("linux")
		`cmake  -H"./cpp/" -B"./cpp/build_#{platform}"`
	elsif RUBY_PLATFORM.downcase.include?("mswin32")

	elsif RUBY_PLATFORM.downcase.include?("mingw")
		# `cmake -G"MSYS Makefiles" -H"./cpp/" -B"./cpp/build_#{platform}"`
		build_cpp_makefile "./cpp/build_#{platform}/", "-j4"
	elsif RUBY_PLATFORM.downcase.include?("darwin")

	end
end


platform = define_platform()
set_library_paths platform

# Run cmake
cmake_build platform



# Might want to use have_library() to check for libraries before adding them
# $LIBS << " -lstdc++ -lOgreBase"
# CONFIG['CC'] = "g++"

# $CFLAGS = " -fPIC"
# $LFLAGS = " -fPIC"
# $CXXFLAGS = " -fPIC"
# $CPPFLAGS = " -fPIC" # preprocessor options, but also passed to compiler
# $LDFLAGS << " -L#{File.expand_path("./cpp/build_linux/dist/lib")}"
# $LDFLAGS << " -L/home/ravenskrag/Code/GameDev/Libraries/ogre/Samples/Common/include"

# set all object files to $objs before create_makefile.
# $objs = ["my_ext.o", "utils/utils.o"]

# $LDFLAGS << " -L#{File.expand_path("./cpp/lib")}"

# puts "CPP LIBRARY FOUND" if have_library("OgreBase")

find_header "OgreInterface.h", File.expand_path("./cpp/cpp_interface/")

have_library("stdc++")
have_library("OgreMain")
have_library("OIS")
have_library("OgreBase")


create_makefile('oni/oni')
