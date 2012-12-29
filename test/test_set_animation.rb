#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

class Window < OgreRuby::Window
	def setup
		@a = OgreRuby::Agent.new(self, "MainCharacter", "MainCharacter.mesh")
		@a.translate(0, 0, 0)
		
		# @a.top_animation = "my_animation"
		@a.base_animation = "walkywalky"
		@a.top_animation = "flippyfloppy"
	end
	
	def update(dt)
		@a.update dt
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
end

Window.new.show