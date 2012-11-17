#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

class Window < Ogre::Window
	def initialize
		q = Ogre::Plane.new()
	end
	
	def update
		
	end
	
	def draw
		
	end
end

Window.new.show