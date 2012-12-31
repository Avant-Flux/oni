	#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'OgreRuby'

class Window < OgreRuby::Window
	def setup
		@a = OgreRuby::Agent.new(self, "MainCharacter", "MainCharacter.mesh")
		@a.translate(0, 0, 0)
		
		# @a.top_animation = "my_animation"
		@a.base_animation = "walkywalky"
		# @a.top_animation = "flippyfloppy"
	end
	
	def update(dt)
		@a.update dt
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
		
		case id
			when 205 # right
				@a.translate(1,0,0)
			when 203 # left
				@a.translate(-1,0,0)
			when 200 #up
				@a.translate(0,0,-1)	# into scene
			when 208 #down
				@a.translate(0,0,1)		# out of scene
		end
	end
	
	def button_up(id)
		# puts "up: #{button_id_to_sym(id)}"
		
	end
end

Window.new.show