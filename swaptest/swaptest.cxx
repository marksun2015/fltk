/* New this file in fltk test folder and modify makeinclude
 * $(CXX) -I.. $(CXXFLAGS) $< $(LINKFLTK) $(LINKSHARED) $(LINKFLTKIMG) $(LDLIBS) -o $@   
 * 
 * $make swaptest
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

//#include <X11/Xlib.h>
//#include <X11/keysym.h>

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
#include <fltk/Threads.h>
#include <fltk/ToggleButton.h>
#include <fltk/TextDisplay.h>
#include <fltk/PackedGroup.h>
using namespace fltk;

#define KEYCODE XK_A
//fltk::SharedImage *image ;
//fltk::SharedImage *imagepng = fltk::pngImage::get("main.png");
//fltk::SharedImage *imagejpeg = fltk::jpegImage::get("Ficon.jpg");
//fltk::Thread prime_thread;

SharedImage *image ;
SharedImage *imagepng = pngImage::get("main.png");
SharedImage *imagejpeg = jpegImage::get("Ficon.jpg");
SharedImage *imageempty;
Thread prime_thread;
Window *win;
Widget *box;
Widget *textdisplay1;
Widget *textdisplay2;
Widget *textdisplay3;
Widget *textdisplay4;
Widget *textdisplay5;
Widget *textdisplay6;
PackedGroup *group; 

void png_cb(Widget *,void *){
	image=imagepng;
	box->image((Image*)image);
	group->hide();
	box->show();
	win->redraw();
}

void jpeg_cb(Widget *,void *){
	image=imagejpeg;
	box->image((Image*)image);
	group->hide();
	box->show();
	win->redraw();
}

void text_cb(Widget *,void *){
	box->hide(); 
	box->image((Image*)imageempty);
	
	textdisplay1->labelsize(16); 
	textdisplay1->box(fltk::NO_BOX);
	textdisplay1->copy_label("hello word");  
	textdisplay1->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay2->labelsize(16); 
	textdisplay2->box(fltk::NO_BOX);
	textdisplay2->copy_label("hello word");  
	textdisplay2->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay3->labelsize(16); 
	textdisplay3->box(fltk::NO_BOX);
	textdisplay3->copy_label("hello word");  
	textdisplay3->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay4->labelsize(16); 
	textdisplay4->box(fltk::NO_BOX);
	textdisplay4->copy_label("hello word");  
	textdisplay4->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	group->show();
	win->redraw();
}

void show_message(fltk::Button *ptr,void* userdata)
{
	int count =0;
	printf("show_message....");
#if 0	
	//fltk::Widget* box2= (fltk::Widget*) ptr;
	//usleep(1000000);
	//image=imagejpeg;
	//fltk::lock();
	//box2->image(imagejpeg);
	//box2->redraw();
	//fltk::unlock();
	//fltk::awake();
	while(0){
			usleep(1000000);
			if((count%2)==0){
		//		box2.image(imagepng);
		//		box2.redraw();  
			}else{
		//		box.image(imagejpeg);
		//		box.redraw();  
			}
			printf("sleep");
			count++;
	}
#endif
}

int main (int argc, char **argv) 
{
	//fltk::Window* win= new fltk::Window(800, 480,"single thread");
	win= new fltk::Window(800, 480,"single thread");
	//fltk::Widget* box= new fltk::Widget(10, 10, 780, 460);
	//Window* win= new Window(800, 480,"single thread");
	//fltk::Window win(800, 480);
	win->begin();

#if 1	
	//button = new ToggleButton(55,55,300,300,"Pixmap");
	//button->image(image); 

	//Widget* box= new Widget(10, 10, 780, 400);
	box = new Widget(10, 10, 780, 400);

	Button* pageswitch1 = new Button(50,420,80,40,"png");
	pageswitch1->callback(png_cb);
	//pageswitch1->when(fltk::WHEN_CHANGED);
	
	Button* pageswitch2 = new Button(200,420,80,40,"jpeg");
	pageswitch2->callback(jpeg_cb);
	//pageswitch2->when(fltk::WHEN_CHANGED);
		
	Button* pageswitch3 = new Button(350,420,80,40,"text");
	pageswitch3->callback(text_cb);
	
	image=imagepng;
	//win->image(image);
	
	box->image(image);
	box->redraw();  
		
	group = new PackedGroup(0,0,300,300); 
	group->begin(); 
	textdisplay1 = new Widget(20,20,100,40);
	textdisplay2 = new Widget(20,20,100,40);
	textdisplay3 = new Widget(20,20,100,40);
	textdisplay4 = new Widget(20,20,100,40);

	//fltk::lock();
	//fltk::create_thread(prime_thread, show_message, box);
#endif	

	//win->resizable(win);
	win->end();
	win->show(argc,argv);
	//create_thread(prime_thread, show_message, box);
	//fltk::run();
	return fltk::run();
}

