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
					m.rotation = 0.degrees
				when :kb_2
					m.rotation = 90.degrees
				when :kb_3
					m.rotation = 180.degrees
				when :kb_4
					m.rotation = 270.degrees
			end	
		end
		
	end
	
	def button_up(id)
		# puts "up: #{button_id_to_sym(id)}"
		
	end
end

Window.new.show