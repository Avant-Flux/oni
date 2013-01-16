#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'OgreRuby'

class Window < OgreRuby::Window
	def setup
		@a = OgreRuby::Agent.new(self, "Human_Male", "Human_Male.mesh")
		@a.translate(0, 0, 0)
		
		@a.base_animation = "my_animation"
		
		# Implies that this is where the camera is made
		# This only creates a handle for the camera
		@camera = OgreRuby::Camera.new(self, "main_camera", 0) # TODO: Make z_order=0 by default
		
		@camera.fov = 110
		@camera.position = [0,5,3]
		@camera.look_at [0,0,0]
		@camera.near_clip_distance = 1
	end
	
	def update(dt)
		# puts dt
		@a.update dt
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