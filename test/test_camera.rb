#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'oni'

class Window < Oni::Window
	def initialize
		super("Test camera")
		
		@light = Oni::Light.new self, "Light"
		@light.type = :point
		@light.position = [-10, 40, 20]
		@light.specular = [1.0, 1.0, 1.0]
		
		@a = Oni::Model.new(self, "Human_Male", "Human_Male.mesh")
		@a.translate(0, 0, 0)
		
		@b = Oni::Animation.new(@a)
		# @b.base_animation = "my_animation"
		
		# Implies that this is where the camera is made
		# This only creates a handle for the camera
		@camera = Oni::Camera.new(self, "main_camera", 0) # TODO: Make z_order=0 by default
		
		@camera.fov = 110
		
		scale = 1.5
		
		r = 3*scale
		angle = 22.degrees
		
		x = r*Math.sin(angle)
		z = r*Math.cos(angle)
		@camera.position = [x,4*scale,z]

		@camera.look_at [0,0,0]
		@camera.near_clip_distance = 1
	end
	
	def update(dt)
		# puts dt
		@a.update dt
		@b.update dt
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