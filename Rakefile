require 'rake/testtask'
require 'rake/clean'
require 'open3'

# generate depend file for gcc dependencies
# sh "gcc -MM *.c > depend"

NAME = 'OgreRuby'

def build_with_make(path, flags="")
	Dir.chdir path do
		stdin, stdout_and_stderr, wait_thr = Open3.popen2e "make " + flags
		
		output = nil
		begin
			output = stdout_and_stderr.gets
			puts output
		end while output
		
		stdin.close
		stdout_and_stderr.close
		
		
		# IO.popen("make " + flags) do |io|
		# 	puts io.read
		# end
	end
end



# the same as before
Rake::TestTask.new do |t|
	# t.libs << 'test'
	# t.test_files = FileList['test/test*.rb']
	
	
	# t.test_files = ["test/test_window_creation.rb"]
	
	# t.test_files = ["test/test_quad_creation.rb"]
	# t.test_files = ["test/test_keyboard_input.rb"]

	# t.test_files = ["test/test_agent_creation.rb"]
	# t.test_files = ["test/test_agent_translation.rb"]
	# t.test_files = ["test/test_agent_rotation.rb"]
	# t.test_files = ["test/test_set_animation.rb"]
	# t.test_files = ["test/test_get_animation.rb"]
	
	t.test_files = ["test/test_camera.rb"]
	
	# t.test_files = ["test/test_animation_benchmark.rb"]
	
	
end

task :cpp_library do
	# Configure CMAKE if build directory does not yet exist
		# Create build dir
		# Set up CMAKE
	
	# Make sure CMAKE files will be cleaned up
	# CLEAN.include "./ext/#{NAME}/cpp/build_linux"
	
	# Run make
	build_with_make "./ext/#{NAME}/cpp/build_linux/", "-j4"
end


# make the :test task depend on the shared
# object, so it will be built automatically
# before running the tests

# rule to build the extension: this says
# that the extension should be rebuilt
# after any change to the files in ext
static_lib = "./ext/#{NAME}/cpp/build_linux/dist/lib/libOgreBase.a"

c_library = "lib/#{NAME}/#{NAME}.so"

file c_library => Dir.glob("ext/#{NAME}/*{.rb,.c}") + ["ext/#{NAME}/extconf.rb", static_lib] do
	Dir.chdir("ext/#{NAME}") do
		# this does essentially the same thing
		# as what RubyGems does
		ruby "extconf.rb"
		sh "make"
	end
	
	cp "ext/#{NAME}/#{NAME}.so", "lib/#{NAME}"
end
# task c_library => :cpp_library


task :test => c_library


# use 'rake clean' and 'rake clobber' to
# easily delete generated files
CLEAN.include('ext/**/*{.o,.log,.so}')
# CLEAN.include('ext/**/Makefile')
CLOBBER.include('lib/**/*.so')



# CLOBBER.include('vendor/build_ogre/dist/bin/OgreApp')
# CLOBBER.include('vendor/build_ogre/dist/bin/ogre.cfg')
# CLOBBER.include('vendor/build_ogre/dist/bin/ogre.log')
# CLOBBER.include('vendor/build_ogre/dist/bin/Ogre.log')
# CLOBBER.include('vendor/build_ogre/dist/lib/*')

desc "Run tests"
task :default => [:cpp_library, :test]
