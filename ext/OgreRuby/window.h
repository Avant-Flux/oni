#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>


VALUE Init_OgreWindow(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE show(VALUE klass);
// static VALUE update(VALUE klass, VALUE dt);

static void updater(double dt, void* ruby_window);