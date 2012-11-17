#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

class Window < Ogre::Window
	def initialize
		x = Agent.new("name", "name.mesh")
		
		x.reset_animations = true
		x.animation = x.animation_names[0]
	end
	
	def update
		
	end
	
	def draw
		
	end
end

Window.new.show