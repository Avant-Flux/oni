#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

void Init_Oni_AnimationEasing(VALUE outer);

/* Easing equations ported from jQuery easing v1.3, originally in JavaScript
 * ============================================================
 * jQuery Easing v1.3 - http://gsgd.co.uk/sandbox/jquery/easing/
 *
 * Open source under the BSD License.
 *
 * Copyright © 2008 George McGinley Smith
 * All rights reserved.
 * https://raw.github.com/danro/jquery-easing/master/LICENSE
 * ======================================================== */
 // t: current time, b: begInnIng value, c: change In value, d: duration
 
 // x = value to be changed
 // t = parametric parameter
 // b = low end of output
 // c = range of output
	// output varies between b and b + c
 // d = maximum value of t
	 // t varies between 0 and t
 
 // note: it seem that only the bounce equations vary with x, so it would would totally possible to omit that parameter entirely
 
static VALUE ease_in_quad(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_out_quad(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_in_out_quad(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);

static VALUE ease_in_cubic(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_out_cubic(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_in_out_cubic(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);

static VALUE ease_in_quart(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_out_quart(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_in_out_quart(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);

static VALUE ease_in_quint(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_out_quint(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_in_out_quint(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);


static VALUE ease_in_sine(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_out_sine(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_in_out_sine(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);

static VALUE ease_in_expo(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_out_expo(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_in_out_expo(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);

static VALUE ease_in_circ(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_out_circ(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
static VALUE ease_in_out_circ(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);

static VALUE ease_in_elastic(int argc, VALUE *argv, VALUE self);
static VALUE ease_out_elastic(int argc, VALUE *argv, VALUE self);
static VALUE ease_in_out_elastic(int argc, VALUE *argv, VALUE self);

static VALUE ease_in_back(int argc, VALUE *argv, VALUE self);
static VALUE ease_out_back(int argc, VALUE *argv, VALUE self);
static VALUE ease_in_out_back(int argc, VALUE *argv, VALUE self);

// static VALUE ease_in_bounce(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
// static VALUE ease_out_bounce(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
// static VALUE ease_in_out_bounce(VALUE klass, VALUE x, VALUE t, VALUE b, VALUE c, VALUE d);
	
/*
 *
 * TERMS OF USE - EASING EQUATIONS
 * 
 * Open source under the BSD License. 
 * 
 * Copyright © 2001 Robert Penner
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 * 
 * Redistributions of source code must retain the above copyright notice, this list of 
 * conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list 
 * of conditions and the following disclaimer in the documentation and/or other materials 
 * provided with the distribution.
 * 
 * Neither the name of the author nor the names of contributors may be used to endorse 
 * or promote products derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY 
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED 
 * OF THE POSSIBILITY OF SUCH DAMAGE. 
 *
 */