require 'rake/testtask'
require 'rake/clean'
require 'open3'

# generate depend file for gcc dependencies
# sh "gcc -MM *.c > depend"

NAME = 'ogre'
ENABLE_C_EXTENSION = true

def build_c_extension(name)
	# rule to build the extension: this says
	# that the extension should be rebuilt
	# after any change to the files in ext
	file "lib/#{name}/#{name}.so" =>
    Dir.glob("ext/#{name}/*{.rb,.c}") do
		Dir.chdir("ext/#{name}") do
			# this does essentially the same thing
			# as what RubyGems does
			ruby "extconf.rb"
			sh "make"
		end
		
		cp "ext/#{name}/#{name}.so", "lib/#{name}"
	end
end

# if ENABLE_C_EXTENSION
# 	# make the :test task depend on the shared
# 	# object, so it will be built automatically
# 	# before running the tests
# 	c_library = "lib/#{NAME}/#{NAME}.so"
	
# 	file c_library do
# 		build_c_extension NAME
# 	end
	
# 	task :test => c_library
	
	
# 	# use 'rake clean' and 'rake clobber' to
# 	# easily delete generated files
# 	CLEAN.include('ext/**/*{.o,.log,.so}')
# 	CLEAN.include('ext/**/Makefile')
# 	CLOBBER.include('lib/**/*.so')
# end

# the same as before
Rake::TestTask.new do |t|
  t.libs << 'test'
end


Dir.chdir "./vendor/build_ogre/" do
	stdin, stdout_and_stderr, wait_thr = Open3.popen2e "make -j4"
	
	output = nil
	begin
		output = stdout_and_stderr.gets
		puts output
	end while output
	
	stdin.close
	stdout_and_stderr.close
end


desc "Run tests"
task :default => :test
# task :default => ["./vendor/build_ogre/dist/lib/libOgreBase.a", :test]
task :default => ["./vendor/build_ogre/dist/lib/libOgreBase.a"]
