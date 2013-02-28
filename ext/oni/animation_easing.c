#include "animation_easing.h"
#include <math.h>

void Init_Oni_AnimationEasing(VALUE outer){
	// Create methods as class methods, to be used in a functional-style
	VALUE module = rb_define_class_under(outer, "Ease", rb_cObject);
	
	rb_define_singleton_method(module, "in_quad", 			ease_in_quad,			5);
	rb_define_singleton_method(module, "out_quad", 			ease_out_quad,			5);
	rb_define_singleton_method(module, "in_out_quad", 		ease_in_out_quad,		5);
	rb_define_singleton_method(module, "in_cubic", 			ease_in_cubic,			5);
	rb_define_singleton_method(module, "out_cubic", 		ease_out_cubic,			5);
	rb_define_singleton_method(module, "in_out_cubic", 		ease_in_out_cubic,		5);
	rb_define_singleton_method(module, "in_quart", 			ease_in_quart,			5);
	rb_define_singleton_method(module, "out_quart", 		ease_out_quart,			5);
	rb_define_singleton_method(module, "in_out_quart", 		ease_in_out_quart,		5);
	rb_define_singleton_method(module, "in_quint", 			ease_in_quint,			5);
	rb_define_singleton_method(module, "out_quint", 		ease_out_quint,			5);
	rb_define_singleton_method(module, "in_out_quint", 		ease_in_out_quint,		5);
	
	rb_define_singleton_method(module, "in_sine", 			ease_in_sine,			5);
	rb_define_singleton_method(module, "out_sine", 			ease_out_sine,			5);
	rb_define_singleton_method(module, "in_out_sine", 		ease_in_out_sine,		5);
	rb_define_singleton_method(module, "in_expo", 			ease_in_expo,			5);
	rb_define_singleton_method(module, "out_expo", 			ease_out_expo,			5);
	rb_define_singleton_method(module, "in_out_expo", 		ease_in_out_expo,		5);
	rb_define_singleton_method(module, "in_circ", 			ease_in_circ,			5);
	rb_define_singleton_method(module, "out_circ", 			ease_out_circ,			5);
	rb_define_singleton_method(module, "in_out_circ", 		ease_in_out_circ,		5);
	rb_define_singleton_method(module, "in_elastic", 		ease_in_elastic,		-1);
	rb_define_singleton_method(module, "out_elastic", 		ease_out_elastic,		-1);
	rb_define_singleton_method(module, "in_out_elastic", 	ease_in_out_elastic,	-1);
	rb_define_singleton_method(module, "in_back", 			ease_in_back,			-1);
	rb_define_singleton_method(module, "out_back", 			ease_out_back,			-1);
	rb_define_singleton_method(module, "in_out_back", 		ease_in_out_back,		-1);
	rb_define_singleton_method(module, "in_bounce", 		ease_in_bounce,			5);
	rb_define_singleton_method(module, "out_bounce", 		ease_out_bounce,		5);
	rb_define_singleton_method(module, "in_out_bounce", 	ease_in_out_bounce,		5);
}

static VALUE ease_in_quad(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(c*(t/=d)*t + b);
}

static VALUE ease_out_quad(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(-c *(t/=d)*(t-2) + b);
}

static VALUE ease_in_out_quad(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	if ((t/=d/2) < 1) return rb_float_new(c/2*t*t + b);
	return rb_float_new(-c/2 * ((--t)*(t-2) - 1) + b);
}

static VALUE ease_in_cubic(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(c*(t/=d)*t*t + b);
}

static VALUE ease_out_cubic(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(c*((t=t/d-1)*t*t + 1) + b);
}

static VALUE ease_in_out_cubic(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	if ((t/=d/2) < 1) return rb_float_new(c/2*t*t*t + b);
	return rb_float_new(c/2*((t-=2)*t*t + 2) + b);
}

static VALUE ease_in_quart(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(c*(t/=d)*t*t*t + b);
}

static VALUE ease_out_quart(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(-c * ((t=t/d-1)*t*t*t - 1) + b);
}

static VALUE ease_in_out_quart(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	if ((t/=d/2) < 1) return rb_float_new(c/2*t*t*t*t + b);
	return rb_float_new(-c/2 * ((t-=2)*t*t*t - 2) + b);
}

static VALUE ease_in_quint(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(c*(t/=d)*t*t*t*t + b);
}

static VALUE ease_out_quint(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(c*((t=t/d-1)*t*t*t*t + 1) + b);
}

static VALUE ease_in_out_quint(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	if ((t/=d/2) < 1) return rb_float_new(c/2*t*t*t*t*t + b);
	return rb_float_new(c/2*((t-=2)*t*t*t*t + 2) + b);
}

static VALUE ease_in_sine(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(-c * cos(t/d * (M_PI/2)) + c + b);
}

static VALUE ease_out_sine(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(c * sin(t/d * (M_PI/2)) + b);
}

static VALUE ease_in_out_sine(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(-c/2 * (cos(M_PI*t/d) - 1) + b);
}

static VALUE ease_in_expo(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
}

static VALUE ease_out_expo(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	double output = (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
	return rb_float_new(output);
}

static VALUE ease_in_out_expo(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	if (t==0) return rb_float_new(b);
		if (t==d) return rb_float_new(b+c);
		if ((t/=d/2) < 1) return rb_float_new(c/2 * pow(2, 10 * (t - 1)) + b);
		return rb_float_new(c/2 * (-pow(2, -10 * --t) + 2) + b);
}

static VALUE ease_in_circ(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(-c * (sqrt(1 - (t/=d)*t) - 1) + b);
}

static VALUE ease_out_circ(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(c * sqrt(1 - (t=t/d-1)*t) + b);
}

static VALUE ease_in_out_circ(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	if ((t/=d/2) < 1) return rb_float_new(-c/2 * (sqrt(1 - t*t) - 1) + b);
	return rb_float_new(c/2 * (sqrt(1 - (t-=2)*t) + 1) + b);
}

static VALUE ease_in_elastic(int argc, VALUE *argv, VALUE self) {
	VALUE val_x, val_t, val_b, val_c, val_d, val_s, val_p, val_a;
	rb_scan_args(argc, argv, "53", &val_x, &val_t, &val_b, &val_c, &val_d, 
									&val_s, &val_p, &val_a
				);
	
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);

	double s, p, a;
	
	if(NIL_P(val_s)){
		s = 1.70158;
	}
	else{
		s = NUM2DBL(val_s);
	}
	
	if(NIL_P(val_p)){
		p = 0;
	}
	else{
		p = NUM2DBL(val_p);
	}
	
	if(NIL_P(val_a)){
		a = c;
	}
	else
	{
		a = NUM2DBL(val_a);
	}
	
	if (t==0) return b;  if ((t/=d)==1) return b+c;  if (!p) p=d*.3;
	if (a < abs(c)) { a=c; s=p/4; }
	else s = p/(2*M_PI) * asin (c/a);
	return -(a*pow(2,10*(t-=1)) * sin( (t*d-s)*(2*M_PI)/p )) + b;
}

static VALUE ease_out_elastic(int argc, VALUE *argv, VALUE self) {
	VALUE val_x, val_t, val_b, val_c, val_d, val_s, val_p, val_a;
	rb_scan_args(argc, argv, "53", &val_x, &val_t, &val_b, &val_c, &val_d, 
									&val_s, &val_p, &val_a
				);
	
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);

	double s, p, a;
	
	if(NIL_P(val_s)){
		s = 1.70158;
	}
	else{
		s = NUM2DBL(val_s);
	}
	
	if(NIL_P(val_p)){
		p = 0;
	}
	else{
		p = NUM2DBL(val_p);
	}
	
	if(NIL_P(val_a)){
		a = c;
	}
	else
	{
		a = NUM2DBL(val_a);
	}
	
	if (t==0) return b;  if ((t/=d)==1) return b+c;  if (!p) p=d*.3;
	if (a < abs(c)) { a=c; s=p/4; }
	else s = p/(2*M_PI) * asin (c/a);
	return a*pow(2,-10*t) * sin( (t*d-s)*(2*M_PI)/p ) + c + b;
}

static VALUE ease_in_out_elastic(int argc, VALUE *argv, VALUE self) {
	VALUE val_x, val_t, val_b, val_c, val_d, val_s, val_p, val_a;
	rb_scan_args(argc, argv, "53", &val_x, &val_t, &val_b, &val_c, &val_d, 
									&val_s, &val_p, &val_a
				);
	
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);

	double s, p, a;
	
	if(NIL_P(val_s)){
		s = 1.70158;
	}
	else{
		s = NUM2DBL(val_s);
	}
	
	if(NIL_P(val_p)){
		p = 0;
	}
	else{
		p = NUM2DBL(val_p);
	}
	
	if(NIL_P(val_a)){
		a = c;
	}
	else
	{
		a = NUM2DBL(val_a);
	}
	
	if (t==0) return b;  if ((t/=d/2)==2) return b+c;  if (!p) p=d*(.3*1.5);
	if (a < abs(c)) { a=c; s=p/4; }
	else s = p/(2*M_PI) * asin (c/a);
	if (t < 1) return -.5*(a*pow(2,10*(t-=1)) * sin( (t*d-s)*(2*M_PI)/p )) + b;
	return a*pow(2,-10*(t-=1)) * sin( (t*d-s)*(2*M_PI)/p )*.5 + c + b;
}

static VALUE ease_in_back(int argc, VALUE *argv, VALUE self) {
	
	VALUE val_x, val_t, val_b, val_c, val_d, val_s;
	rb_scan_args(argc, argv, "51", &val_x, &val_t, &val_b, &val_c, &val_d, &val_s);
	if(NIL_P(val_s)){
		val_s = 1.70158;
	}
	
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	double s = NUM2DBL(val_s);
	
	return rb_float_new(c*(t/=d)*t*((s+1)*t - s) + b);
}

static VALUE ease_out_back(int argc, VALUE *argv, VALUE self) {
	
	VALUE val_x, val_t, val_b, val_c, val_d, val_s;
	rb_scan_args(argc, argv, "51", &val_x, &val_t, &val_b, &val_c, &val_d, &val_s);
	if(NIL_P(val_s)){
		val_s = 1.70158;
	}
	
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	double s = NUM2DBL(val_s);
	
	return rb_float_new(c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b);
}

static VALUE ease_in_out_back(int argc, VALUE *argv, VALUE self) {
	
	VALUE val_x, val_t, val_b, val_c, val_d, val_s;
	rb_scan_args(argc, argv, "51", &val_x, &val_t, &val_b, &val_c, &val_d, &val_s);
	if(NIL_P(val_s)){
		val_s = 1.70158;
	}
	
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	double s = NUM2DBL(val_s);
	
	if ((t/=d/2) < 1) return rb_float_new(c/2*(t*t*(((s*=(1.525))+1)*t - s)) + b);
	return rb_float_new(c/2*((t-=2)*t*(((s*=(1.525))+1)*t + s) + 2) + b);
}

static VALUE ease_in_bounce(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	return rb_float_new(c - ease_in_bounce (x, d-t, 0, c, d) + b);
}

static VALUE ease_out_bounce(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	if ((t/=d) < (1/2.75)) {
		return rb_float_new(c*(7.5625*t*t) + b);
	} else if (t < (2/2.75)) {
		return rb_float_new(c*(7.5625*(t-=(1.5/2.75))*t + .75) + b);
	} else if (t < (2.5/2.75)) {
		return rb_float_new(c*(7.5625*(t-=(2.25/2.75))*t + .9375) + b);
	} else {
		return rb_float_new(c*(7.5625*(t-=(2.625/2.75))*t + .984375) + b);
	}
}

static VALUE ease_in_out_bounce(VALUE val_x, VALUE val_t, VALUE val_b, VALUE val_c, VALUE val_d) {
	double x = NUM2DBL(val_x);
	double t = NUM2DBL(val_t);
	double b = NUM2DBL(val_b);
	double c = NUM2DBL(val_c);
	double d = NUM2DBL(val_d);
	
	if (t < d/2) return rb_float_new(ease_in_bounce (x, t*2, 0, c, d) * .5 + b);
	return rb_float_new(ease_out_bounce (x, t*2-d, 0, c, d) * .5 + c*.5 + b);
}