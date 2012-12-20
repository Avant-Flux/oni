require 'rake/testtask'
require 'rake/clean'
require 'open3'

# generate depend file for gcc dependencies
# sh "gcc -MM *.c > depend"

NAME = 'OgreRuby'
ENABLE_C_EXTENSION = true

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
  t.libs << 'test/test_window_creation.rb'
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

task :c_extension do
	if ENABLE_C_EXTENSION
		# make the :test task depend on the shared
		# object, so it will be built automatically
		# before running the tests
		
		# rule to build the extension: this says
		# that the extension should be rebuilt
		# after any change to the files in ext
		c_library = "lib/#{NAME}/#{NAME}.so"
		
		file c_library =>
	    Dir.glob("ext/#{NAME}/*{.rb,.c}") do
			Dir.chdir("ext/#{NAME}") do
				# this does essentially the same thing
				# as what RubyGems does
				ruby "extconf.rb"
				sh "make"
			end
			
			cp "ext/#{NAME}/#{NAME}.so", "lib/#{NAME}"
		end
		
		task :test => c_library
		
		
		# use 'rake clean' and 'rake clobber' to
		# easily delete generated files
		CLEAN.include('ext/**/*{.o,.log,.so}')
		CLEAN.include('ext/**/Makefile')
		CLOBBER.include('lib/**/*.so')
	end
end

# CLOBBER.include('vendor/build_ogre/dist/bin/OgreApp')
# CLOBBER.include('vendor/build_ogre/dist/bin/ogre.cfg')
# CLOBBER.include('vendor/build_ogre/dist/bin/ogre.log')
# CLOBBER.include('vendor/build_ogre/dist/bin/Ogre.log')
# CLOBBER.include('vendor/build_ogre/dist/lib/*')

desc "Run tests"
task :default => [:cpp_library, :c_extension, :test]
