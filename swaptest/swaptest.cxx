/* New this file in fltk test folder and modify makeinclude
 * $(CXX) -I.. $(CXXFLAGS) $< $(LINKFLTK) $(LINKSHARED) $(LINKFLTKIMG) $(LDLIBS) -o $@   
 * 
 * $make swaptest
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <config.h>
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

SharedImage *image;
SharedImage *imageempty;
SharedImage *imagepng1 = pngImage::get("main.png");
SharedImage *imagepng2 = pngImage::get("mario.png");
SharedImage *imagejpeg = jpegImage::get("Ficon.jpg");
Thread prime_thread;

Window *win;
Widget *box;
Widget *textdisplay1;
Widget *textdisplay2;
Widget *textdisplay3;
Widget *textdisplay4;

Widget *textdisplay5;
Widget *textdisplay6;
Widget *textdisplay7;
Widget *textdisplay8;
PackedGroup *group1; 
PackedGroup *group2; 

void png_cb(Widget *,void *){
	image=imagepng1;
	box->image((Image*)image);
	group1->hide();
	group2->hide();
	box->show();
	win->redraw();
}

void jpeg_cb(Widget *,void *){
	image=imagejpeg;
	box->image((Image*)image);
	group1->hide();
	group2->hide();
	box->show();
	win->redraw();
}

void text_cb(Widget *,void *){
	box->hide(); 
	box->image((Image*)imageempty);
	
	textdisplay1->labelsize(32); 
	textdisplay1->box(fltk::NO_BOX);
	textdisplay1->copy_label("hello word");  
	textdisplay1->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay2->labelsize(32); 
	textdisplay2->box(fltk::NO_BOX);
	textdisplay2->copy_label("hello word");  
	textdisplay2->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay3->labelsize(32); 
	textdisplay3->box(fltk::NO_BOX);
	textdisplay3->copy_label("hello word");  
	textdisplay3->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay4->labelsize(32); 
	textdisplay4->box(fltk::NO_BOX);
	textdisplay4->copy_label("hello word");  
	textdisplay4->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	group1->show();
	win->redraw();
}

void* prime_func(void* p)
{
	int count =0;
	group1->hide();
	group2->hide();

	for (count=0;count<100;count++){
		//printf("show_message....");
		usleep(5000);
		
		if((count%2)==0){
			image=imagepng1;
		}else{
			image=imagepng2;
		}
		fltk::lock();
		box->image((Image*)image);
		box->show();
		fltk::unlock();
		fltk::awake((void*)(box)); 
		win->redraw();
	}
	
	box->hide();
	textdisplay1->labelsize(32); 
	textdisplay1->box(fltk::NO_BOX);
	textdisplay1->copy_label("hello word1");  
	textdisplay1->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay2->labelsize(32); 
	textdisplay2->box(fltk::NO_BOX);
	textdisplay2->copy_label("hello word2");  
	textdisplay2->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay3->labelsize(32); 
	textdisplay3->box(fltk::NO_BOX);
	textdisplay3->copy_label("hello word3");  
	textdisplay3->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay4->labelsize(32); 
	textdisplay4->box(fltk::NO_BOX);
	textdisplay4->copy_label("hello word4");  
	textdisplay4->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay5->labelsize(32); 
	textdisplay5->box(fltk::NO_BOX);
	textdisplay5->copy_label("weintek lab1");  
	textdisplay5->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay6->labelsize(32); 
	textdisplay6->box(fltk::NO_BOX);
	textdisplay6->copy_label("weintek lab2");  
	textdisplay6->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay7->labelsize(32); 
	textdisplay7->box(fltk::NO_BOX);
	textdisplay7->copy_label("weintek lab3");  
	textdisplay7->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
	
	textdisplay8->labelsize(32); 
	textdisplay8->box(fltk::NO_BOX);
	textdisplay8->copy_label("weintek lab4");  
	textdisplay8->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);

	win->redraw();
	for (count=0;count<100;count++){
		usleep(5000);
		fltk::lock();
		if((count%2)==0){
			group2->hide();
			group1->show();
			group1->redraw();
			fltk::unlock();
			fltk::awake((void*)(group1)); 
		}else{
			group1->hide();
			group2->show();
			group2->redraw();
			fltk::unlock();
			fltk::awake((void*)(group2)); 
		}
		win->redraw();
	}
}

int main (int argc, char **argv) 
{
	//fltk::Window* win= new fltk::Window(800, 480,"single thread");
	win= new fltk::Window(800, 480,"single thread");
	//fltk::Widget* box= new fltk::Widget(10, 10, 780, 460);
	//Window* win= new Window(800, 480,"single thread");
	//fltk::Window win(800, 480);
	win->begin();

	//button = new ToggleButton(55,55,300,300,"Pixmap");
	//button->image(image); 

	//Widget* box= new Widget(10, 10, 780, 400);
	box = new Widget(10, 10, 780, 400);

#if 1
	Button* pageswitch1 = new Button(50,420,80,40,"png");
	pageswitch1->callback(png_cb);
	//pageswitch1->when(fltk::WHEN_CHANGED);
	
	Button* pageswitch2 = new Button(200,420,80,40,"jpeg");
	pageswitch2->callback(jpeg_cb);
	//pageswitch2->when(fltk::WHEN_CHANGED);
		
	Button* pageswitch3 = new Button(350,420,80,40,"text");
	pageswitch3->callback(text_cb);
#endif	

	image=imagepng1;
	//win->image(image);
	
	box->image(image);
	box->redraw();  
		
#if 1
	group1 = new PackedGroup(20,20,250,160); 
	group1->begin(); 
	textdisplay1 = new Widget(20,20,250,40);
	textdisplay2 = new Widget(20,20,250,40);
	textdisplay3 = new Widget(20,20,250,40);
	textdisplay4 = new Widget(20,20,250,40);
	group1->end(); 
	
	group2 = new PackedGroup(20,20,250,160); 
	group2->begin(); 
	textdisplay5 = new Widget(200,20,250,40);
	textdisplay6 = new Widget(200,20,250,40);
	textdisplay7 = new Widget(200,20,250,40);
	textdisplay8 = new Widget(200,20,250,40);
	group2->end(); 

	//fltk::create_thread(prime_thread, show_message, box);
#endif	

	//win->resizable(win);
	win->end();
	win->show(argc,argv);
	//create_thread(prime_thread, show_message, box);
	//fltk::run();
	fltk::lock();
	fltk::create_thread(prime_thread, prime_func, box); 
	return fltk::run();
}

