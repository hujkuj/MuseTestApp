#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MuseSampleApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void MuseSampleApp::setup()
{
}

void MuseSampleApp::mouseDown( MouseEvent event )
{
}

void MuseSampleApp::update()
{
}

void MuseSampleApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( MuseSampleApp, RendererGl )
