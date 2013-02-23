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
				@a.rotate_to 1,0,0
			when :kb_2
				@a.rotate_to -1,0,0
			when :kb_3
				@a.rotate_to 0,0,1
			when :kb_4
				@a.rotate_to 0,0,-1
			
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