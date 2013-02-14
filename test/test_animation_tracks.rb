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
		
		@move_forward = false
		
		@model = Oni::Model.new(self, "Human_Male", "Human_Male.mesh")
		@animation = Oni::Animation.new(@model)
		
		@animation.load(0, "my_animation")
		# Fade as soon as fade call is made
		@animation.track(0).fade_out(5.frames) do |influence, time|
			# influence = Current influence [0..1]
			# time = milliseconds since the fade started [0..timeout]
			
			# Result of this block becomes the influence for the next frame
			
			# After the time specified, this track will be disabled
		end
		
		# @animation.track(0).fade_in(100, &Oni::Animation::LINEAR_IN)-
		@animation.load(1, "walk")
		@animation.track(1).fade_in(200, &Oni::Animation::QuadraticFade.new(some, params))
		
		
		
		
		
		@animation["my_animation"].fade_in(5.frames) do |influence, time|
			
		end
	end
	
	def update(dt)
		@model.update dt
		@animation.update dt
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
	
	def button_down(id)
		# puts "#{id} - #{button_id_to_sym(id)}"
		
	end
	
	def button_up(id)
		# puts "up: #{button_id_to_sym(id)}"
		
	end
end

Window.new.show