#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

class Window < OgreRuby::Window
	def setup
		@a = OgreRuby::Agent.new(self, "Golem", "Golem.mesh")
		@a.translate(50, 0, 0)
		
		@b = OgreRuby::Agent.new(self, "Golem2", "Golem.mesh")
		@b.translate(-50, 0, 0)
		
		@b = nil
	end
	
	def update(dt)
		puts dt
		
		@a.update dt
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
end

Window.new.show