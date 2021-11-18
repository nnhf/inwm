#ifndef WM_HPP
#define WM_HPP

extern "C" {
  #include <X11/Xlib.h>
}
#include <memory>

class WindowManager {
  public:
    /*
     * Factory method for establishing a connection to an X server and creating
     * a Window Manager instance.
     */
    static std::unique_ptr<WindowManager> Create();

    /*
     * Disconnect from the X server.
     */
    ~WindowManager();

    void Run();

    /* 
     * Xlib error handler.
     */
    static int OnXError(Display* dpy, XErrorEvent);

  private:
    /*
     * Invoke internally by Create()
     */
    WindowManager(Display* dpy);

    /*
     * Handle to the underlying Xlib Display struct.
     */
    Display* _dpy;

    /*
     * Handle to root window.
     */
    const Window _root;
};

#endif
