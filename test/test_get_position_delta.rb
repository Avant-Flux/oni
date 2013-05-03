require 'rubygems'
require 'gl'
require 'glu'

require 'oni'

class Window < Oni::Window
	def initialize
		super("Get position delta")
		
		@camera = Oni::Camera.new(self, "main_camera", 0) # TODO: Make z_order=0 by default
		@camera.fov = 110
		scale = 7
		@camera.position = [0,30/scale,40/scale]
		@camera.look_at [0,0,0]
		@camera.near_clip_distance = 5
		
		@light = Oni::Light.new self, "Light"
		@light.type = :point
		@light.position = [-10, 40, 20]
		@light.specular = [1.0, 1.0, 1.0]
		

		name = "Human_Male"
		
		@model = Oni::Model.new self, "#{name}", "#{name}.mesh"
		
		@animation = Oni::Animation.new @model
		
		@animation_list = [
			@animation["idle"],
			@animation["sword_r-l"]
		]
		
		@animation_list[0].enable
		
		@counter = 0
	end
	
	def update(dt)
		@model.update dt
		@animation.update dt
		
		p @animation.bone("hips").position_delta
		# p @animation.bone("hips").orientation_delta
		
		@model.position = [0,0,0]
		@model.rotation = Math::PI/2
		delta = @animation.bone("hips").position_delta
		@model.translate -delta[0], -delta[1], -delta[2], :local
		
		
		@counter += 1
		@counter = @counter % 100
		GC.start if @counter == 0
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
	
	def button_down(id)
		@animation_list.each {|a| a.disable}
		
		case button_id_to_sym id
			when :kb_1
				@animation_list[0].enable
			when :kb_2
				@animation_list[1].enable
		end
	end
	
	def button_up(id)
		# puts "up: #{button_id_to_sym(id)}"
		
	end
end

Window.new.show