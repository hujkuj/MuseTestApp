#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/CinderMath.h"
#include "MuseListener.h"
#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

class MuseSampleApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    
    MuseListener        mMuseListener;
    std::list<float>    mPlots;
    int                 mCurrentSecond;
};

void MuseSampleApp::setup()
{
    gl::enableAlphaBlending();
    gl::clear( Color( 0.0f, 0.0f, 0.0f) );
    mCurrentSecond = 0;
}

void MuseSampleApp::update()
{
    if (ci::app::getElapsedSeconds() > mCurrentSecond ) {
        mCurrentSecond = ci::app::getElapsedSeconds();
        mPlots.clear();
    }
    mMuseListener.listen();
    while(mMuseListener.hasNextMessage()) {
        vector<float> message = mMuseListener.getNextMessage();
        mPlots.push_back(ci::lmap(message[1], 0.0f, 1682.815f, 0.0f, 100.0f));
    }
}

void MuseSampleApp::draw()
{
    if(mPlots.size() > 0) {
        // clear out the window with black
        gl::color( ColorA(255.0f, 255.0f, 255.0f, 0.9f) );
        std::list<float>::iterator iterator;
        int i = 0;
        int halfWindowWidth = ci::app::getWindowWidth() / 2;
        int halfWindowHeight = ci::app::getWindowHeight() / 2;
        glPointSize(3.0f);
        gl::begin(GL_POINTS);
        for(iterator = mPlots.begin(); iterator != mPlots.end(); ++iterator) {
            float rotation = ci::lmap((float)i, 0.0f, (float)mPlots.size(), 0.0f, (float)(2.0f * M_PI));
            Vec2f point = Vec2f(halfWindowWidth + (sin(*iterator) * rotation * 5.0f), halfWindowHeight + (cos(*iterator) * rotation * 5.0f));
            gl::vertex(point);
            i++;
        }
        gl::end();
    
        gl::color(ColorA(0, 0, 0, 0.3f));
        gl::drawSolidRect(ci::app::getWindowBounds());
    }
}

CINDER_APP_NATIVE( MuseSampleApp, RendererGl )
