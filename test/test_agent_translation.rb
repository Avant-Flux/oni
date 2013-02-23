	#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'oni'

class Window < Oni::Window
	def setup
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
		
		
		@a = Oni::Model.new(self, "Human_Male", "Human_Male.mesh")
		@a.translate(0, 0, 0)
		
		@b = Oni::Animation.new(@a)
		# @b.base_animation = "my_animation"
		# @a.base_animation = "walkywalky"
		# @a.top_animation = "flippyfloppy"
		
		@moving = false
		@move_constant = 0.1
		@move_direction = nil
	end
	
	def update(dt)
		@a.update dt
		
		if @moving
			case @move_direction
				when :right
					@a.translate(@move_constant,0,0)
				when :left
					@a.translate(-@move_constant,0,0)
				when :up
					@a.translate(0,0,-@move_constant)	# into scene
				when :down
					@a.translate(0,0,@move_constant)	# out of scene
			end
		end
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
	
	def button_down(id)
		puts "down: #{id} - #{button_id_to_sym(id)}"
		# case button_id_to_sym(id)
		# 	when :kb_right
		# 		@a.translate(1,0,0)
		# 	when :kb_left
		# 		@a.translate(-1,0,0)
		# end
		
		case button_id_to_sym id
			when :kb_x
				@a.position = [0,0,0]
		end
		
		
		if id == 205 # right
			@move_direction = :right
			@moving = true
		end
		
		if id == 203 # left
			@move_direction = :left
			@moving = true
		end
		
		if id == 200 #up
			@move_direction = :up
			@moving = true
		end
		
		if id == 208 #down
			@move_direction = :down
			@moving = true
		end
	end
	
	def button_up(id)
		# puts "up: #{button_id_to_sym(id)}"
		if id == 205 || id == 203 || id == 200 || id == 208
			@moving = false
		end
	end
end

Window.new.show