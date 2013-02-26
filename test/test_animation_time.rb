#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'oni'

require 'test/unit'

class Window < Oni::Window
	def setup
		@camera = Oni::Camera.new(self, "main_camera", 0) # TODO: Make z_order=0 by default
		@camera.fov = 110
		@camera.position = [0,30,40]
		@camera.look_at [0,0,0]
		@camera.near_clip_distance = 5
		
		@a = Oni::Model.new(self, "Human_Male", "Human_Male.mesh")
		@a.translate(0, 0, 0)
		
		@b = Oni::Animation.new(@a)
		
		
		animation = @b["idle"]
		animation.enable
		
		puts "====================================="
		animation.time = 0.2
		puts animation.time
		if animation.time == 0.2
			puts "LOOKING GOOOD~~~~~~~~~~"
		else
			puts "ERROR!!!!!!"
		end
		
		# assert_equal(animation.time, 0.2)
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