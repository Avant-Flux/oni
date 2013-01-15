#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'OgreRuby'

class Window < OgreRuby::Window
	def setup
		@a = OgreRuby::Agent.new(self, "MainCharacter", "MainCharacter.mesh")
		@a.translate(0, 0, 0)
		
		@a.base_animation = "walkywalky"
		@a.top_animation = "flippyfloppy"
		
		
		
		# Call a method? Not very ruby-like
		self.camera.fov = 110
		
		# Magic variable? Counter to my design philosophy...
		@camera.fov = 110
		
		# Manual set from method? Weird because you can't define accessor now
		# Though I'm not sure what use the accessor is...
		@camera = self.camera
		@camera.fov = 110
		
		# Implies that this is where the camera is made
		# This only creates a handle for the camera
		@camera = OgreRuby::Camera.new(self)
		
		# Clear that this is a camera controller, and not a real camera
		@camera = OgreRuby::CameraController.new(self)
		
		
		@camera.fov = 110
		@camera.position = [0,0,0]
		@camera.look_at [0,0,0]
		@camera.near_clip_distance = 5
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