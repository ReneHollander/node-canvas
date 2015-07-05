#ifndef __X11_BACKEND_H__
#define __X11_BACKEND_H__

#include "Backend.h"
#include <X11/Xlib.h>
#include <cairo-xlib.h>

using namespace std;

class X11Backend : public Backend {
  public:
    virtual cairo_surface_t *createSurface();
    virtual cairo_surface_t *recreateSurface();
    virtual void destroySurface();

    void setWidth(int width);
    void setHeight(int height);

    X11Backend(int width, int height);
    ~X11Backend() { printf("destroying backend\n"); this->destroySurface(); }

    Display *display;
    Window window;

    static Persistent<FunctionTemplate> constructor;
    static void Initialize(Handle<Object> target);
    static NAN_METHOD(New);
};

void cairo_x11_surface_destroy(void *backend);

class X11BackendException : public std::exception {
  private:
    string err_msg;

  public:
    X11BackendException(const string msg) : err_msg(msg) {};
    ~X11BackendException() throw() {};
    const char *what() const throw() { return this->err_msg.c_str(); };
};


#endif
