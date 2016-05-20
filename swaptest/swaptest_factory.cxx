// classes.cxx (example 3a)
//#include <fltk/Slider.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <config.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/time.h>
#include <iostream>  

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
#include <fltk/IntInput.h>
#include <fltk/Threads.h>
#include <fltk/ToggleButton.h>
#include <fltk/TextDisplay.h>
#include <fltk/PackedGroup.h>

using namespace fltk;
using namespace std;  
enum PRODUCTTYPE {TEXT_TYPE1,TEXT_TYPE2,PNG_TYPE1,PNG_TYPE2,JPEG_TYPE1,JPEG_TYPE2};  

#define WIDTH 800
#define HEIGHT 480 
#define BW 80 
#define BH 40
#define FONT_SIZE 32

Thread prime_thread;

static void exit_callback(Widget *, void *) {
  exit(0);
}

class SampleWindow : public Window {
public:
  SampleWindow(const char* label):
  Window(0,0,800,480,label,true) // Call the Window constructor in the SampleWindow initialization
  {

  }
  
  void textset(Widget *textdisplay,int size,const char *string){
	  textdisplay->labelsize(size); 
	  textdisplay->box(fltk::NO_BOX);
	  textdisplay->copy_label(string);  
	  textdisplay->align(fltk::ALIGN_LEFT|fltk::ALIGN_INSIDE);
  }

  ~SampleWindow() {}
};

class SampleWindowText1 : public SampleWindow {
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
	public:
  	SampleWindowText1(const char* label=0):
	SampleWindow(label){
		group1 = new PackedGroup(20,20,750,320); 
		group1->begin(); 
		textdisplay1 = new Widget(20,20,750,80);
		textdisplay2 = new Widget(20,20,750,80);
		textdisplay3 = new Widget(20,20,750,80);
		textdisplay4 = new Widget(20,20,750,80);	
		group1->end(); 

		group2 = new PackedGroup(300,20,750,320); 
		group2->begin(); 
		textdisplay5 = new Widget(300,20,750,80);
		textdisplay6 = new Widget(300,20,750,80);
		textdisplay7 = new Widget(300,20,750,80);
		textdisplay8 = new Widget(300,20,750,80);
		group2->end(); 
		
		textset(textdisplay1,FONT_SIZE,"hello world!!!");
		textset(textdisplay2,FONT_SIZE,"hello world!!!");
		textset(textdisplay3,FONT_SIZE,"hello world!!!");
		textset(textdisplay4,FONT_SIZE,"hello world!!!");
		textset(textdisplay5,FONT_SIZE,"hello world!!!");
		textset(textdisplay6,FONT_SIZE,"hello world!!!");
		textset(textdisplay7,FONT_SIZE,"hello world!!!");
		textset(textdisplay8,FONT_SIZE,"hello world!!!");
	}

  	~SampleWindowText1() {
		delete textdisplay1;
		delete textdisplay2;
		delete textdisplay3;
		delete textdisplay4;
		delete textdisplay5;
		delete textdisplay6;
		delete textdisplay7;
		delete textdisplay8;
		delete group1;
		delete group2;
	}
};

class SampleWindowText2 : public SampleWindow {
	Widget *textdisplay5;
	Widget *textdisplay6;
	Widget *textdisplay7;
	Widget *textdisplay8;
	PackedGroup *group2; 
	public:
  	SampleWindowText2(const char* label=0):
	SampleWindow(label)
	{
		group2 = new PackedGroup(20,20,750,320); 
		group2->begin(); 
		textdisplay5 = new Widget(20,20,750,80);
		textdisplay6 = new Widget(20,20,750,80);
		textdisplay7 = new Widget(20,20,750,80);
		textdisplay8 = new Widget(20,20,750,80);
		textset(textdisplay5,FONT_SIZE,"weintek lab");
		textset(textdisplay6,FONT_SIZE,"weintek lab");
		textset(textdisplay7,FONT_SIZE,"weintek lab");
		textset(textdisplay8,FONT_SIZE,"weintek lab");
		group2->end(); 
	}
  	
	~SampleWindowText2() {
		delete textdisplay5;
		delete textdisplay6;
		delete textdisplay7;
		delete textdisplay8;
	}
};

class SampleWindowPNG1 : public SampleWindow {
	public:
  	SampleWindowPNG1(const char* label=0):
	SampleWindow(label)
	{
		SharedImage *imagepng1 = pngImage::get("main.png"); 
		this->image((Image*)imagepng1);
	}
  	
	~SampleWindowPNG1() {}
};

class SampleWindowPNG2 : public SampleWindow {
	public:
  	SampleWindowPNG2(const char* label=0):
	SampleWindow(label)
	{
		SharedImage *imagepng2 = pngImage::get("mario.png");
		this->image((Image*)imagepng2);
	}
  	
	~SampleWindowPNG2() {}
};

class SampleWindowJPEG1 : public SampleWindow {
	public:
  	SampleWindowJPEG1(const char* label=0):
	SampleWindow(label)
	{
  		Button *btn =new Button(150,60,50,20,"down");
	}
  	
	~SampleWindowJPEG1() {}
};

class SampleWindowJPEG2 : public SampleWindow {
	public:
  	SampleWindowJPEG2(const char* label=0):
	SampleWindow(label)
	{
  		Button *btn =new Button(150,60,50,20,"down");
	}
  	
	~SampleWindowJPEG2() {}
};

class Factory  
{   
	public:  
		SampleWindow *windowspage1;
		SampleWindow *windowspage2;
		SampleWindow *windowspage3;
		SampleWindow *windowspage4;
		SampleWindow *windowspage5;
		SampleWindow *windowspage6;
		
		SampleWindow* creatwin(PRODUCTTYPE type,const char *string)
		{  
			switch(type)  
			{  
				case TEXT_TYPE1:   
  					//printf("create text type1...\n");
					windowspage1 = new SampleWindowText1(string);
					return windowspage1;  
					break;  
				case TEXT_TYPE2:  
  					//printf("create text type2...\n");
					windowspage2 = new SampleWindowText2(string);
					return windowspage2;  
					break;  
				case PNG_TYPE1:  
					windowspage3 = new SampleWindowPNG1(string);
					return windowspage3;  
					break;  
				case PNG_TYPE2:  
					windowspage4 = new SampleWindowPNG2(string);
					return windowspage4;  
					break;  
				case JPEG_TYPE1:  
					windowspage5 = new SampleWindowJPEG1(string);
					return windowspage5;  
				default:break;  
			}  

		}  
		
		SampleWindow * destroywin(PRODUCTTYPE type)
		{	
			switch(type)  
			{  
				case TEXT_TYPE1:   
  					//printf("delete text type1..\n");
					delete windowspage1;
					break;  
				case TEXT_TYPE2:   
  					//printf("delete text type2..\n");
					delete windowspage2;
					break; 
				case PNG_TYPE1:  
					delete windowspage3;
					break;  
				case PNG_TYPE2:  
					delete windowspage4;
					break;  
				case JPEG_TYPE1:  
					delete windowspage5;
					break;  
				case JPEG_TYPE2:  
					delete windowspage6;
					break;  
				default:break;  
			}  
		}
};  

void* swap_func(void* p)
{
	int count =0,check=0;
	struct timeval t1, t2;
	double timecost;
	printf("Swap func \n");
	
	//start timer
	gettimeofday(&t1, NULL);
	
	Factory factory;
	SampleWindow *windowpage_text;
	fltk::lock();
	windowpage_text = factory.creatwin(TEXT_TYPE2,"text2 page");
	windowpage_text->show();
	fltk::awake((void*)(windowpage_text));  //send to update queue, flush window 
	fltk::unlock();

	for(count=0;count<50;count++){
		usleep(50000);
		fltk::lock();
		if((count%2)==0){
			factory.destroywin(TEXT_TYPE2);
			windowpage_text = factory.creatwin(TEXT_TYPE1,"text1 page");
		}else{
			factory.destroywin(TEXT_TYPE1);
			windowpage_text = factory.creatwin(TEXT_TYPE2,"text2 page");
		}
		windowpage_text->show();
		fltk::awake((void*)(windowpage_text));  //send to update queue, flush window 
		fltk::unlock();

		do {
			//fltk::check();
		} while (!windowpage_text->visible());

	}

	delete windowpage_text;

	SampleWindow *windowpage_png;
	windowpage_png = factory.creatwin(PNG_TYPE2,"png2 page");
	windowpage_png->show();
	
	for(count=0;count<100;count++){
		usleep(50000);
		fltk::lock();
		if((count%2)==0){
			factory.destroywin(PNG_TYPE2);
			windowpage_png = factory.creatwin(PNG_TYPE1,"png1 page");
		}else{
			factory.destroywin(PNG_TYPE1);
			windowpage_png = factory.creatwin(PNG_TYPE2,"png2 page");
		}
		windowpage_png->show();
		fltk::awake((void*)(windowpage_png));  //send to update queue, flush window 
		fltk::unlock();
	}

	//stop timer
	gettimeofday(&t2, NULL);
	timecost = (t2.tv_sec - t1.tv_sec) * 1000.0;    // sec to ms
	timecost += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
	printf("Code time cost: %f\n", timecost/1000);
}

int main(int argc, char ** argv) {
	Window *basewin;	
	basewin= new fltk::Window(0,0,WIDTH, HEIGHT,"base window");
	basewin->begin();
	basewin->end();
	basewin->show();

	fltk::lock();
	fltk::create_thread(prime_thread, swap_func, 0); 

  	return fltk::run();
}
