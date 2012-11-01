# TODO: use name of this file as name of package

require File.expand_path("../lib/ogre/version", __FILE__)

ENABLE_C_EXTENSION = true

Gem::Specification.new do |s|
	s.name        = "ogre"
	s.version     = Ogre::VERSION
	s.date        = '2012-09-29'
	s.platform    = Gem::Platform::RUBY
	s.authors     = ["Raven"]
	s.email       = 'AvantFlux.Raven@gmail.com'
	s.homepage    = 'https://github.com/RavensKrag'
	
	s.summary     = "2D game library inspired by Gosu."
	s.description = <<EOS
	Inspired heavily by Gosu.  The word "Gosu" is Korean, meaning something like
	"master", describing someone who posseses great skill.  The name "Meijin"
	was selected because it is similar.  "Meijin" literally means "famous person,"
	but is a title often given to persons of great skill, like high-ranking Go players.
	Similarly, "Gosu" is used to describe high-level Korean Starcraft players, a modern
	strategy game.
EOS
	
	s.required_rubygems_version = ">= 1.3.6"
	
	# lol - required for validation
	#~ s.rubyforge_project         = "newgem"
	
	# If you have other dependencies, add them here
	# s.add_dependency "another", "~> 1.2"
	
	s.files = Dir["{lib}/**/*.rb", "bin/*", "LICENSE", "*.md"]
	
	if ENABLE_C_EXTENSION
		s.files      += Dir["{ext}/**/*.{c,h,rb}", "{ext}/**/*.{txt}"]
		s.extensions = ['ext/meijin/extconf.rb']
	else
		
	end
	puts s.files
	
	s.require_path = 'lib'
	
	# If you need an executable, add it here
	# s.executables = ["newgem"]
	
	
	#~ s.autorequire = "name"
	s.test_files = Dir["{test}/**/*test.rb"]
	s.has_rdoc = true
	#~ s.extra_rdoc_files = ["README"]
	#~ s.add_dependency("dependency", ">= 0.x.x")
end
