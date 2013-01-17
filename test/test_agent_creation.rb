#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'OgreRuby'

class Window < OgreRuby::Window
	def setup
		@a = OgreRuby::Agent.new(self, "Golem", "Golem.mesh")
		@a.translate(50, 0, 0)
		
		@b = OgreRuby::Agent.new(self, "Golem2", "Golem.mesh")
		@b.translate(-50, 0, 0)
		
		@b = nil
		# @b.visible = false
		# @b.visible = true
	end
	
	def update(dt)
		# puts dt
		
		@a.update dt
		puts @a.visible
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
end

Window.new.show