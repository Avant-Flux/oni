#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'OgreRuby'

class Window < OgreRuby::Window
	def setup
		@a = OgreRuby::Agent.new(self, "Golem", "Golem.mesh")
		@a.translate(0, 0, 0)
		
		@a.top_animation = "my_animation"
		# @a.top_animation = ""
		
		puts "animation list: #{@a.animations}"
	end
	
	def update(dt)
		@a.update dt
		
		# puts "top: #{@a.top_animation}"
		# puts "base: #{@a.base_animation}"
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
end

Window.new.show
