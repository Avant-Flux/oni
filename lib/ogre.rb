#~ require 'automaton/automaton' # Load c extension files
#~ require 'automaton/animation' # Require ruby files
require 'meijin/meijin'

module Meijin
	class Window
		ObjectSpace.define_finalizer(self, proc {
			Meijin::Window.finalize
		})
		
		def restart
			puts "restart?"
			
			if @needs_restart
				puts "restarting"
				# Set to false to prevent infinite restart loop
				@needs_restart = false
				
				@width = 500
				@height = 500
				
				return true
			else
				return false
			end
		end
	end
end
