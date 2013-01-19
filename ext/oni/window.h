#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

VALUE Init_Oni_Window(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE show(VALUE klass);


// Callbacks
static void update(double dt, void* ruby_window);
static void buttonDown(unsigned int key_id, void* ruby_window);
static void buttonUp(unsigned int key_id, void* ruby_window);