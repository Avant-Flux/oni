#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

class Window < Ogre::Window
	def initialize
		x = Agent.new("name", "name.mesh")
	end
	
	def update
		
	end
	
	def draw
		
	end
end

Window.new.show