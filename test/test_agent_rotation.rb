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
		
		@a = Oni::Model.new(self, "MainCharacter", "MainCharacter.mesh")
		@a.translate(0, 0, 0)
		
		@b = Oni::Animation.new(@a)
		# @b.base_animation = "walkywalky"
		# @b.top_animation = "flippyfloppy"
		
		@move_forward = false
	end
	
	def update(dt)
		# puts dt
		@a.update dt
		
		@a.translate 0,0,0.2 if @move_forward
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
	
	def button_down(id)
		puts "down: #{button_id_to_sym(id)}"
		
		case button_id_to_sym(id)
			when :kb_0
				@move_forward = !@move_forward
			
			when :kb_1
				@a.rotation_3D = [20,20,20]
			
			when :kb_x
				@a.pitch 20.degrees
			when :kb_y
				@a.yaw 20.degrees
			when :kb_z
				@a.roll 20.degrees
			
			when :kb_a
				@a.pitch -20.degrees
			when :kb_b
				@a.yaw -20.degrees
			when :kb_c
				@a.roll -20.degrees
		end
	end
	
	def button_up(id)
		puts "up: #{button_id_to_sym(id)}"
	end
end

Window.new.show