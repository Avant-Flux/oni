#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

class Window < OgreRuby::Window
	def setup
		@a = OgreRuby::Agent.new(self, "Golem", "Golem.mesh")
		@a.translate(50, 0, 0)
		
		@a = OgreRuby::Agent.new(self, "Golem2", "Golem.mesh")
		@a.translate(-50, 0, 0)
	end
	
	def update(dt)
		
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
end

Window.new.show