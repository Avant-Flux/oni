require 'rubygems'
require 'gl'
require 'glu'

require 'oni'

class Numeric
	def to_px
		# Convert from meters to pixels
		(self*Physics.scale).to_i
	end
	
	def to_meters
		# Convert from pixels to meters
		self/(Physics.scale.to_f) #Insure that integer division is not used
	end
	
	def to_em(font)
		# Convert from pixels to ems
		# Font assumed to be Gosu::Font object
		self/font.text_width('m')
	end
	
	#Code taken from MoreChipmunkAndRMagick.rb from the gosu demos
	def radians_to_vec2
		CP::Vec2.new(Math::cos(self), Math::sin(self))
	end
	
	# Convert from degrees to radians
	def to_rad
		self * Math::PI / 180
	end
	
	# Convert from radians to degrees
	def to_deg
		self / Math::PI * 180
	end
end

class Window < Oni::Window
	def initialize
		super("Lighting test")
		
		@camera = Oni::Camera.new(self, "main_camera", 0) # TODO: Make z_order=0 by default
		# @camera.fov = 110
		@camera.position = [50,30,0]
		@camera.look_at [0,0,0]
		@camera.near_clip_distance = 5
		
		@model = Oni::Model.new self, "Ninja", "ninja.mesh"
		@model.cast_shadows = true
		@model.scale = [0.1, 0.1, 0.1]
		
		@ground = Oni::Model.new self, "Ground", "Ground.mesh"
		@ground.cast_shadows = false
		# @ground.scale = [0.1, 0.1, 0.1]
		
		@point_light = Oni::Light.new self, "point"
		@point_light.type = :point
		@point_light.position = [0, 150, 250]
		
		@point_light.diffuse = [1.0, 0.0, 0.0]
		@point_light.specular = [1.0, 0.0, 0.0]
		
		
		@directional_light = Oni::Light.new self, "directional"
		@directional_light.type = :directional
		@directional_light.position = [0, 0, 0]
		
		@directional_light.diffuse = [0.25, 0.25, 0.0]
		@directional_light.specular = [0.25, 0.25, 0.0]
		
		@directional_light.direction = [0, -1, 1]
		
		
		@spot_light = Oni::Light.new self, "spot"
		@spot_light.type = :spot
		@spot_light.position = [300, 300, 0]
		
		@spot_light.diffuse = [0.0, 0.0, 1.0]
		@spot_light.specular = [0.0, 0.0, 1.0]
		
		@spot_light.direction = [-1, -1, 0]
		
		@spot_light.spotlight_range = [35.to_rad, 50.to_rad, 1]
	end
	
	def update(dt)
		
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