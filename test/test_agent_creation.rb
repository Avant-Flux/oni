#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'oni'

class Window < Oni::Window
	def setup
		@camera = Oni::Camera.new(self, "main_camera", 0) # TODO: Make z_order=0 by default
		@camera.fov = 110
		@camera.position = [0,30,40]
		@camera.look_at [0,0,0]
		@camera.near_clip_distance = 5
		
		@a = Oni::Model.new(self, "Golem", "Golem.mesh")
		@a.translate(50, 0, 0)
		
		@b = Oni::Model.new(self, "Golem2", "Golem.mesh")
		@b.translate(-50, 0, 0)
		
		@b = nil
		# @b.visible = false
		# @b.visible = true
	end
	
	def update(dt)
		# puts dt
		
		@a.update dt
		puts @a.visible?
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
end

Window.new.show