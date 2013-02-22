ENV['PATH'] = ENV['PATH'] + ';' + File.expand_path(File.dirname(__FILE__) + '/libs')

puts "load C code..."
require 'oni/oni'
puts "loading ruby code"

class Numeric
	def degrees
		# Assume that this is an angle in radians, and convert to degrees
		# This is so you can write 20.degrees instead of 20.to_deg
		self/ 180.0 * Math::PI
	end
end

module Oni
	class Window
		KEY_ID = [:kb_unassigned, :kb_escape, :kb_1, :kb_2, :kb_3, :kb_4, :kb_5, :kb_6, :kb_7, :kb_8, :kb_9, :kb_0, :kb_minus, :kb_equals, :kb_back, :kb_tab, :kb_q, :kb_w, :kb_e, :kb_r, :kb_t, :kb_y, :kb_u, :kb_i, :kb_o, :kb_p, :kb_lbracket, :kb_rbracket, :kb_return, :kb_lcontrol, :kb_a, :kb_s, :kb_d, :kb_f, :kb_g, :kb_h, :kb_j, :kb_k, :kb_l, :kb_semicolon, :kb_apostrophe, :kb_grave, :kb_lshift, :kb_backslash, :kb_z, :kb_x, :kb_c, :kb_v, :kb_b, :kb_n, :kb_m, :kb_comma, :kb_period, :kb_slash, :kb_rshift, :kb_multiply, :kb_lmenu, :kb_space, :kb_capital, :kb_f1, :kb_f2, :kb_f3, :kb_f4, :kb_f5, :kb_f6, :kb_f7, :kb_f8, :kb_f9, :kb_f10, :kb_numlock, :kb_scroll, :kb_numpad7, :kb_numpad8, :kb_numpad9, :kb_subtract, :kb_numpad4, :kb_numpad5, :kb_numpad6, :kb_add, :kb_numpad1, :kb_numpad2, :kb_numpad3, :kb_numpad0, :kb_decimal, :kb_oem_102, :kb_f11, :kb_f12, :kb_f13, :kb_f14, :kb_f15, :kb_kana, :kb_abnt_c1, :kb_convert, :kb_noconvert, :kb_yen, :kb_abnt_c2, :kb_numpadequals, :kb_prevtrack, :kb_at, :kb_colon, :kb_underline, :kb_kanji, :kb_stop, :kb_ax, :kb_unlabeled, :kb_nexttrack, :kb_numpadenter, :kb_rcontrol, :kb_mute, :kb_calculator, :kb_playpause, :kb_mediastop, :kb_volumedown, :kb_volumeup, :kb_webhome, :kb_numpadcomma, :kb_divide, :kb_sysrq, :kb_rmenu, :kb_pause, :kb_home, :kb_up, :kb_pgup, :kb_left, :kb_right, :kb_end, :kb_down, :kb_pgdown, :kb_insert, :kb_delete, :kb_lwin, :kb_rwin, :kb_apps, :kb_power, :kb_sleep, :kb_wake, :kb_websearch, :kb_webfavorites, :kb_webrefresh, :kb_webstop, :kb_webforward, :kb_webback, :kb_mycomputer, :kb_mail, :kb_mediaselect]
		
		def setup
		end
		
		def update(dt)
		end
		
		def draw
		end
		
		def button_down(id)
			
		end
		
		def button_up(id)
			
		end
		
		def button_id_to_sym(id)
			return KEY_ID[id]
		end
	end
	
	class Animation
		class Track
			def playing?
				return !ended?
			end
		end
	end
end
