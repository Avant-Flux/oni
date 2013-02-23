#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'oni'

class Window < Oni::Window
	def setup
		@a = Oni::Model.new(self, "MainCharacter", "MainCharacter.mesh")
		@a.translate(0, 0, 0)
		
		@b = Oni::Animation.new(@a)
		# @a.top_animation = "my_animation"
		# @b.base_animation = "walkywalky"
		# @b.top_animation = "flippyfloppy"
	end
	
	def update(dt)
		@a.update dt
		@b.update dt
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
end

Window.new.show