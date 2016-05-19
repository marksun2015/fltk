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
#include <sys/time.h>

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

#define WIDTH 800
#define HEIGHT 480 
#define BW 80 
#define BH 40
#define FONT_SIZE 64 

Thread prime_thread;

SharedImage *image;
SharedImage *imageempty;
SharedImage *imagepng1 = pngImage::get("main.png");
SharedImage *imagepng2 = pngImage::get("mario.png");
SharedImage *imagejpeg = jpegImage::get("Ficon.jpg");

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

void textset(Widget *textdisplay,int size,const char *string){
	textdisplay->labelsize(size); 
	textdisplay->box(fltk::NO_BOX);
	textdisplay->copy_label(string);  
	textdisplay->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
}

void text_cb(Widget *,void *){
	box->hide(); 
	box->image((Image*)imageempty);
	textset(textdisplay1,FONT_SIZE,"hello world!!!");
	textset(textdisplay2,FONT_SIZE,"hello world!!!");
	textset(textdisplay3,FONT_SIZE,"hello world!!!");
	textset(textdisplay4,FONT_SIZE,"hello world!!!");
	group1->show();
	win->redraw();
}

void* prime_func(void* p)
{
	int count =0;
	struct timeval t1, t2;
	double timecost;
	
	group1->hide();
	group2->hide();

	//start timer
	gettimeofday(&t1, NULL);

	for (count=0;count<500;count++){
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
	
	//win->redraw();
	for (count=0;count<500;count++){
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

	// stop timer
	gettimeofday(&t2, NULL);
	timecost = (t2.tv_sec - t1.tv_sec) * 1000.0;    // sec to ms
	timecost += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	printf("Code time cost: %f\n", timecost/1000);

}

int main (int argc, char **argv) 
{
	win= new fltk::Window(WIDTH, HEIGHT,"single thread");
	win->begin();

	box = new Widget(10, 10, WIDTH-20, HEIGHT-80);

	Button* pageswitch1 = new Button(50,HEIGHT-60,BW,BH,"png");
	pageswitch1->callback(png_cb);
	
	Button* pageswitch2 = new Button(200,HEIGHT-60,BW,BH,"jpeg");
	pageswitch2->callback(jpeg_cb);
		
	Button* pageswitch3 = new Button(350,HEIGHT-60,BW,BH,"text");
	pageswitch3->callback(text_cb);

	image=imagepng1;
	
	box->image(image);
	box->redraw();  
		
	group1 = new PackedGroup(20,20,750,320); 
	group1->begin(); 
	textdisplay1 = new Widget(20,20,750,80);
	textdisplay2 = new Widget(20,20,750,80);
	textdisplay3 = new Widget(20,20,750,80);
	textdisplay4 = new Widget(20,20,750,80);
	group1->end(); 
	
	group2 = new PackedGroup(20,20,750,320); 
	group2->begin(); 
	textdisplay5 = new Widget(20,20,750,80);
	textdisplay6 = new Widget(20,20,750,80);
	textdisplay7 = new Widget(20,20,750,80);
	textdisplay8 = new Widget(20,20,750,80);
	group2->end(); 
	
	textset(textdisplay1,FONT_SIZE,"hello world hello world");
	textset(textdisplay2,FONT_SIZE,"hello world hello world");
	textset(textdisplay3,FONT_SIZE,"hello world hello world");
	textset(textdisplay4,FONT_SIZE,"hello world hello world");

	textset(textdisplay5,FONT_SIZE,"weintek lab iEXE series");
	textset(textdisplay6,FONT_SIZE,"weintek lab iEXE series");
	textset(textdisplay7,FONT_SIZE,"weintek lab iEXE series");
	textset(textdisplay8,FONT_SIZE,"weintek lab iEXE series");
	
	group1->hide();
	group2->hide();

	win->end();
	win->show(argc,argv);
	fltk::lock();
	fltk::create_thread(prime_thread, prime_func, box); 
	return fltk::run();
}

