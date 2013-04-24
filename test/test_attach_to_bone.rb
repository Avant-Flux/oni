require 'rubygems'
require 'gl'
require 'glu'

require 'oni'

class Window < Oni::Window
	def initialize
		super("Attach model to bone")
		
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
		
		name = "Falchion"
		@sword = Oni::Model.new self, "#{name}", "#{name}.mesh"
		@model.attach_object_to_bone "hand.R", @sword
	end
	
	def update(dt)
		# [@model, @animation, @sword].each do |x|
		# 	x.update dt
		# end
		@model = nil
		@animation = nil
		@sword = nil
		GC.start
	end
	
	def draw
		# 2D drawing system with OpenGL
		# Useful for drawing UI and such;
	end
	
	def button_down(id)
		
	end
	
	def button_up(id)
		# puts "up: #{button_id_to_sym(id)}"
		
	end
end

Window.new.show