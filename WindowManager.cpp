#include "WindowManager.hpp"
#include <cstdio>
using std::unique_ptr;


/*
 * Factory method for establishing a connection to an X server and creating
 * a Window Manager instance.
 */
std::unique_ptr<WindowManager> WindowManager::Create() {
  /* Open the X display. */
  Display* dpy = XOpenDisplay(nullptr);
  if (dpy == nullptr) {
    printf("Unable to start X Display.\n");
    return nullptr;
  }

  return unique_ptr<WindowManager> (new WindowManager(dpy));
}

/*
 * Invoke internally by Create()
 */
WindowManager::WindowManager(Display* dpy)
: _dpy (dpy),
  _root(DefaultRootWindow(_dpy)) {
}


/*
 * Disconnect from the X server.
 */
WindowManager::~WindowManager() {
  XCloseDisplay(_dpy);
}

void WindowManager::Run() {
  

}
