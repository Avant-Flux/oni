#!/usr/bin/env ruby
require 'rubygems'
require 'gl'
require 'glu'

class Window < Ogre::Window
	def initialize
		x = Agent.new
		x.pitch(0, Ogre::LOCAL)
		
		x.translate(0, 0, 0)
		x.translate([0,0,0])
		x.translate(Ogre::Vector3(0,0,0))
		
		x.setBaseAnimation()
	end
	
	def update
		
	end
	
	def draw
		
	end
end
