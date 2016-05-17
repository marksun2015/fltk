#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Image.H>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Mywin : public Fl_Window {
	void resize(int X, int Y, int W, int H) {
		Fl_Window::resize(X,Y,W,H);
		redraw();
		Fl::check();
	}
	public:
	Mywin(int x,int y,int w, int h) : Fl_Window(x,y,w,h) {
	}
};

int main() {
	Mywin* win = new Mywin(20,20,600,400);
	Fl_Box* box = new Fl_Box(100,100,300,200);//for example

	Fl_PNG_Image* pngImg = new Fl_PNG_Image("main.png");
	box->image(pngImg);
	box->show();
	win->end();
	win->show();
	return (Fl::run());
}


