#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

class Window < OgreRuby::Window
	def setup
		
	end
	
	def update(dt)
		
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
	
	def button_down(id)
		puts "down: #{button_id_to_sym(id)}"
	end
	
	def button_up(id)
		puts "up: #{button_id_to_sym(id)}"
	end
end

Window.new.show