typedef void* OGRE_WINDOW;

typedef struct OgreWindowData
{
	/* data */
	OGRE_WINDOW window;
};

VALUE Init_OgreWindow(VALUE outer);

static VALUE initialize(int argc, VALUE *argv, VALUE klass);
static VALUE finalize(int argc, VALUE *argv, VALUE klass);

static VALUE show(VALUE klass);
static VALUE add_time(VALUE klass, VALUE dt);