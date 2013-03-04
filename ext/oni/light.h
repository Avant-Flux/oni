#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>

#include <OgreInterface.h>

void Init_Oni_Light(VALUE outer);

static VALUE alloc(VALUE class);

static VALUE initialize(VALUE self, VALUE window, VALUE name);
static VALUE update(VALUE self, VALUE dt);

static VALUE getVisible(VALUE self);
static VALUE setVisible(VALUE self, VALUE visible);

static VALUE setType(VALUE self, VALUE light_type);
static VALUE setPosition(VALUE self, VALUE pos);

static VALUE setDiffuseColor(VALUE self, VALUE color);
static VALUE setSpecularColor(VALUE self, VALUE color);
