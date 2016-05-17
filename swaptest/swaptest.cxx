/* New this file in fltk test folder and modify makeinclude
 * $(CXX) -I.. $(CXXFLAGS) $< $(LINKFLTK) $(LINKSHARED) $(LINKFLTKIMG) $(LDLIBS) -o $@   
 * 
 * $make swaptest
 *
 */

#include <fltk/SharedImage.h>
#include <fltk/draw.h>
#include <fltk/run.h>
#include <fltk/Window.h>
#include <fltk/Browser.h>
#include <fltk/Widget.h>
#include <fltk/Button.h>
#include <fltk/xpmImage.h>
#include <fltk/Group.h>
#include <fltk/Item.h>
#include <fltk/ItemGroup.h>
#include <fltk/Input.h>
using namespace fltk;

int main (int argc, char *argv[]) {
	Window win(800, 480);
	win.begin();
	Widget box(10, 10, 780, 460);
	SharedImage *image = pngImage::get("main.png");
	//SharedImage *image = jpegImage::get("Ficon.jpg");
	box.image(image);
	win.end();
	win.show();
	return run();
}

