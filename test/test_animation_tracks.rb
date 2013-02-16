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
		
		
		@animation["my_animation"].fade_in(5.frames) do |influence, time|
			# influence = Current influence [0..1]
			# time = milliseconds since the fade started [0..timeout]
			
			# Result of this block becomes the influence for the next frame
			
			# After the time specified, this track will be disabled
			
			# beginning, change, duration
			b = 1
			c = 1
			d = 1
			Oni::Animation.ease_in_cubic(influence, time, b,c,d)
		end
		
		@animation["test"].weight = 1.0
		@animation["test"].start_time = 0.0
		@animation["test"].enabled = true
		@animation["test"].rate = 1.0
		@animation["test"].loop = true # loop is a method, not a real Ruby reserved word
		
		@animation["test"].playing?
		@animation["test"].enabled?
		puts @animation["test"].weight
		puts @animation["test"].rate
		puts @animation["test"].length
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