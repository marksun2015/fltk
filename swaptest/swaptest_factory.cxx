// classes.cxx (example 3a)

#include <fltk/run.h>
#include <fltk/Window.h>
#include <fltk/Slider.h>
#include <fltk/Button.h>
#include <fltk/IntInput.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>  

using namespace fltk;
using namespace std;  
enum PRODUCTTYPE {str1,str2,str3};  

static void exit_callback(Widget *, void *) {
  exit(0);
}

#if 0
class SampleWindow1 : public Window {
  IntInput intinput;
  Button copy_button;
  Slider slider;
  Button down_button;
  Button up_button;
  Button exit_button;

  inline void copy_callback_i() {
    slider.value(intinput.ivalue());
  }
  static void copy_callback(Widget*, void* v) {
    ((SampleWindow1*)v)->copy_callback_i();
  }

  inline void down_callback_i() {
    slider.value(slider.value()-1);
    intinput.value(slider.value());
  }
  static void down_callback(Widget*, void* v) {
    ((SampleWindow1*)v)->down_callback_i();
  }

  inline void up_callback_i() {
    slider.value(slider.value()+1);
    intinput.value(slider.value());
  }
  static void up_callback(Widget*, void* v) {
    ((SampleWindow1*)v)->up_callback_i();
  }

  inline void slider_callback_i(Slider* slider) {
    intinput.value(slider->value());
  }
  static void slider_callback(Widget* w, void* v) {
    ((SampleWindow1*)v)->slider_callback_i((Slider*)w);
  }

public:

  SampleWindow1(const char* label=0) :
    Window(USEDEFAULT,USEDEFAULT,320,90,label,true),
    intinput(10,10,100,20),
    copy_button(110,10,100,20,"copy to slider"),
    slider(10,35,300,20),
    down_button(50,60,50,20,"down"),
    up_button(150,60,50,20,"up"),
    exit_button(250,60,50,20,"exit")
  {
    copy_button.callback(copy_callback,this);
    down_button.callback(down_callback,this);
    up_button.callback(up_callback,this);
    slider.callback(slider_callback,this);
    slider.set_horizontal(); slider.type(Slider::TICK_ABOVE);
    slider.range(-10,10);
    slider.step(1);
    slider.value(0);
    exit_button.callback(exit_callback);
    end();
  }

  ~SampleWindow1() {
  		printf("destroy...\n");
  }

};
#endif
class SampleWindow : public Window {
#if 0
  IntInput intinput;
  Button copy_button;
  Slider slider;
  Button down_button;
  Button up_button;
  Button exit_button;
#endif
#if 0
  inline void copy_callback_i() {
    slider.value(intinput.ivalue());
  }
  static void copy_callback(Widget*, void* v) {
    ((SampleWindow*)v)->copy_callback_i();
  }

  inline void down_callback_i() {
    slider.value(slider.value()-1);
    intinput.value(slider.value());
  }
  static void down_callback(Widget*, void* v) {
    ((SampleWindow*)v)->down_callback_i();
  }

  inline void up_callback_i() {
    slider.value(slider.value()+1);
    intinput.value(slider.value());
  }
  static void up_callback(Widget*, void* v) {
    ((SampleWindow*)v)->up_callback_i();
  }

  inline void slider_callback_i(Slider* slider) {
    intinput.value(slider->value());
  }
  static void slider_callback(Widget* w, void* v) {
    ((SampleWindow*)v)->slider_callback_i((Slider*)w);
  }
#endif
public:
#if 0
  SampleWindow(const char* label=0) :
    Window(USEDEFAULT,USEDEFAULT,320,90,label,true),
    intinput(10,10,100,20),
    copy_button(110,10,100,20,"copy to slider"),
    slider(10,35,300,20),
    down_button(50,60,50,20,"down"),
    up_button(150,60,50,20,"up"),
    exit_button(250,60,50,20,"exit")
  {
    //copy_button.callback(copy_callback,this);
    //down_button.callback(down_callback,this);
    //up_button.callback(up_callback,this);
    //slider.callback(slider_callback,this);
    //slider.set_horizontal(); slider.type(Slider::TICK_ABOVE);
    //slider.range(-10,10);
    //slider.step(1);
    //slider.value(0);
    //exit_button.callback(exit_callback);
    end();
  }
#endif

  SampleWindow(const char* label):
  Window(30,30,320,90,label,true)
  //Window(30,30,600,400,label)
  {
  }

  ~SampleWindow() {
  		printf("destroy...\n");
  }

};

class SampleWindow1 : public SampleWindow {
	public:
  	SampleWindow1(const char* label=0):
   	SampleWindow(label)
	{
  		Button *btn =new Button(150,60,50,20,"up");
	}
};

class SampleWindow2 : public SampleWindow {
	public:
  	SampleWindow2(const char* label=0):
	SampleWindow(label)
	{
  		Button *btn =new Button(150,60,50,20,"down");
	}
};

#if 1
class Factory  
{   
	public:  
		SampleWindow *windowspage1;
		SampleWindow *windowspage2;
		SampleWindow *windowspage3;
		
		SampleWindow* creatwin(PRODUCTTYPE type,const char *string)
		{  
			switch(type)  
			{  
				case str1:   
  					printf("create str1...\n");
					windowspage1 = new SampleWindow1(string);
					return windowspage1;  
					break;  
				case str2:  
					windowspage2 = new SampleWindow2(string);
					return windowspage2;  
					break;  
				case str3:  
					windowspage1 = new SampleWindow1(string);
					return windowspage1;  
				default:break;  
			}  

		}  
		
		SampleWindow * destroywin(PRODUCTTYPE type)
		{	
			switch(type)  
			{  
				case str1:   
  					printf("del str1...\n");
					delete windowspage1;
					break;  
				case str2:  
  					printf("del str2...\n");
					delete windowspage2;
					break;  
				case str3:  
					break;  
				default:break;  
			}  
		}
};  
#endif


int main(int argc, char ** argv) {

	Factory factory;
	SampleWindow *win1;
	SampleWindow *win2;
	
	win1 = factory.creatwin(str1,"sample1");
	win1->show();
	
	win2 = factory.creatwin(str2,"gogo");
	win2->show();
	
	factory.destroywin(str1);
	win1 = factory.creatwin(str1,"sample1");
	win1->show();
	

#if 0  
  SampleWindow *window1;
  SampleWindow *window2;
  window1 = new SampleWindow("Window 1");
  window2 = new SampleWindow("Window 2");
  
  window1->show();
  window2->show();
#endif 

  return run();
}
