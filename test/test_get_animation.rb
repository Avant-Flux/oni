#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

class Window < Ogre::Window
	def initialize
		x = Agent.new("name", "name.mesh")
		
		x.animation_names.each do |name|
			puts name
		end
	end
	
	def update
		
	end
	
	def draw
		
	end
end

Window.new.show