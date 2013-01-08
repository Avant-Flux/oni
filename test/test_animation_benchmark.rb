#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

require 'OgreRuby'

class Window < OgreRuby::Window
	def setup
		@move_forward = false
		
		@models = []
		120.times do |i|
			model = OgreRuby::Agent.new(self, "Charater_#{i}", "MainCharacter.mesh")
			
			model.base_animation = "walkywalky"
			model.top_animation = "flippyfloppy"
			
			distance = 45
			
			x = distance*2*rand-distance
			z = distance*2*rand-distance
			model.position = [x, 0, z]
			
			@models << model
		end
	end
	
	def update(dt)
		@models.each do |m|
			m.update dt
			
			m.translate 0,0,0.2 if @move_forward
		end
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
	
	def button_down(id)
		puts "#{id} - #{button_id_to_sym(id)}"
		case button_id_to_sym(id)
			when :kb_0
				@move_forward = !@move_forward
		end
		
		@models.each do |m|
			case button_id_to_sym(id)
				when :kb_1
					m.rotate_to 1,0,0
				when :kb_2
					m.rotate_to -1,0,0
				when :kb_3
					m.rotate_to 0,0,1
				when :kb_4
					m.rotate_to 0,0,-1
				
				when :kb_x
					m.pitch 20.degrees
				when :kb_y
					m.yaw 20.degrees
				when :kb_z
					m.roll 20.degrees
				
				when :kb_a
					m.pitch -20.degrees
				when :kb_b
					m.yaw -20.degrees
				when :kb_c
					m.roll -20.degrees
			end	
		end
		
	end
	
	def button_up(id)
		# puts "up: #{button_id_to_sym(id)}"
		
	end
end

Window.new.show