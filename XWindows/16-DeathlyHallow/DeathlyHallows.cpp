#define _USE_MATH_DEFINES

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <X11/keysym.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <math.h>
#define GL_PI 3.1415f


bool isFullscreen = false;
bool isCloseButtonClicked = false;
bool isEscapeKeyPressed = false;

int windowWidth = 800;
int windowHeight = 600;

GLfloat angle = 0.0f;
GLfloat speed = 0.1f;
GLfloat xTrans = -1;
GLfloat yTrans = -1;
GLfloat xcTrans = 1;
GLfloat ycTrans = -1;
GLfloat ylTrans = 1;

Display *gDisplay = NULL;
XVisualInfo *visualInfo = NULL;
Colormap colormap;
Window window;
typedef GLXContext (*glXCreateContextAttribsARBProc)(Display *display, GLXFBConfig fbConfig, GLXContext sharedContext, Bool direct, const int* attributes);
glXCreateContextAttribsARBProc glXCreateContextAttribsARB = NULL;
GLXFBConfig glxFBConfig;
GLXContext glxContext;

void createWindow(void);
void initialize(void);
void cleanup(void);
void handleEvent(XEvent *event);
void update(void);
void display(void);
void deathlyHallowsSymbol(void);
void drawInvisibilityCloak(void);
void drawResurrectionStone(void);
void drawElderWand(void);
void resize(int width, int height);
void toggleFullscreen(bool isFullscreen);

int main(void)
{
    XEvent event;
    bool done = false;

    createWindow();
    initialize();

    while(!done)
    {
        while(XPending(gDisplay))
        {
            XNextEvent(gDisplay, &event);
            handleEvent(&event);
        }

        done = (isCloseButtonClicked || isEscapeKeyPressed);
        update();
        display();
    }

    cleanup();
    return EXIT_SUCCESS;
}

void createWindow(void)
{
    XSetWindowAttributes windowAttributes;     // This is an array of all available FBConfig matching to frameBufferAttributes.
    GLXFBConfig *pGLXFBConfigs = NULL;
    XVisualInfo *pTempXVisualInfo = NULL;
    int numberOfFBConfigs = 0;
    int defaultScreen = 0;
    int styleMask = 0;
    int counter = 0;

    static int frameBufferAttributes[] = {
        GLX_RED_SIZE, 8,
        GLX_GREEN_SIZE, 8,
        GLX_BLUE_SIZE, 8,
        GLX_ALPHA_SIZE, 8,
        GLX_DEPTH_SIZE, 24,
        GLX_STENCIL_SIZE, 8,
        GLX_DOUBLEBUFFER, True,
        GLX_X_RENDERABLE, True,
        GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
        GLX_RENDER_TYPE, GLX_RGBA_BIT,
        // GLX_SAMPLE_BUFFERS, 1,
        // GLX_SAMPLES, 4,
       None
    };

    gDisplay = XOpenDisplay(NULL);

    if(gDisplay == NULL)
    {
        printf("Error: Unable to open XgDisplay.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    defaultScreen = XDefaultScreen(gDisplay);

    // Get the frame buffer configuration list as per our requirement specified in frameBufferAttributes array.
    pGLXFBConfigs = glXChooseFBConfig(gDisplay, defaultScreen, frameBufferAttributes, &numberOfFBConfigs);

    if(pGLXFBConfigs == NULL)
    {
        printf("Error: Unable to get valid frame buffer configurations.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    printf("Total frame buffer configurations: %d\n", numberOfFBConfigs);

    // Select that FBConfig/visual which have the maximum samples per pixel.
    int bestFrameBufferConfig = -1;
    int worstFrameBufferConfig = -1;
    int bestNumberOfSamples = -1;
    int worstNumberOfSamples = 999;

    for(counter = 0; counter < numberOfFBConfigs; ++counter)
    {
        pTempXVisualInfo = glXGetVisualFromFBConfig(gDisplay, pGLXFBConfigs[counter]);

        if(pTempXVisualInfo)
        {
            int sampleBuffer = 0;
            int samples = 0;

            glXGetFBConfigAttrib(gDisplay, pGLXFBConfigs[counter], GLX_SAMPLE_BUFFERS, &sampleBuffer);
            glXGetFBConfigAttrib(gDisplay, pGLXFBConfigs[counter], GLX_SAMPLES, &samples);

            printf("----------------------------------------\n");
            printf("Frame Buffer Config: %d\n", counter);
            printf("Visual ID: 0x%lu\n", pTempXVisualInfo->visualid);
            printf("Sample Buffers: %d\n", sampleBuffer);
            printf("Samples: %d\n", samples);
            printf("----------------------------------------\n");

            if(bestFrameBufferConfig < 0 || sampleBuffer && samples > bestNumberOfSamples)
            {
                bestFrameBufferConfig = counter;
                bestNumberOfSamples = samples;
            }

            if(worstFrameBufferConfig < 0 || !sampleBuffer || samples < worstNumberOfSamples)
            {
                worstFrameBufferConfig = counter;
                worstNumberOfSamples = samples;
            }
        }

        XFree(pTempXVisualInfo);
    }

    // Set the global glxFBConfig to best found.
    glxFBConfig = pGLXFBConfigs[bestFrameBufferConfig];

    // Free the frame buffer configuration list.
    XFree(pGLXFBConfigs);

    visualInfo = glXGetVisualFromFBConfig(gDisplay, glxFBConfig);

    if(visualInfo == NULL)
    {
        printf("Error: Unable to choose visual.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    printf("----------------------------------------\n");
    printf("Selected Visual ID: 0x%lu\n", visualInfo->visualid);
    printf("----------------------------------------\n");

    windowAttributes.border_pixel = 0;
    windowAttributes.border_pixmap = 0;
    windowAttributes.background_pixel = BlackPixel(gDisplay, defaultScreen);
    windowAttributes.background_pixmap = 0;
    windowAttributes.colormap = XCreateColormap(gDisplay, XRootWindow(gDisplay, visualInfo->screen), visualInfo->visual, AllocNone);
    windowAttributes.event_mask = ExposureMask | VisibilityChangeMask | ButtonPressMask | KeyPressMask | PointerMotionMask | StructureNotifyMask;

    styleMask = CWBorderPixel | CWBackPixel | CWEventMask | CWColormap;
    colormap = windowAttributes.colormap;

    window = XCreateWindow(gDisplay, XRootWindow(gDisplay, visualInfo->screen), 0, 0, windowWidth, windowHeight, 0, visualInfo->depth, InputOutput, visualInfo->visual, styleMask, &windowAttributes);

    if(!window)
    {
        printf("Error: Failed to create main window.");
        cleanup();
        exit(EXIT_FAILURE);
    }

    XStoreName(gDisplay, window, "CG - Deathly Hallows Rotation");

    Atom windowManagerDelete = XInternAtom(gDisplay, "WM_DELETE_WINDOW", True);
    XSetWMProtocols(gDisplay, window, &windowManagerDelete, 1);
    XMapWindow(gDisplay, window);
}

void initialize(void)
{
    // Create new GL context 4.5 for rendering.
    glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc)glXGetProcAddressARB((GLubyte *)"glXCreateContextAttribsARB");

    if(glXCreateContextAttribsARB == NULL)
    {
        printf("Error: Unable to get glXCreateContextAttribsARBProc address.");
        cleanup();
        exit(EXIT_FAILURE);
    }

    GLint attributes[] = {
        GLX_CONTEXT_MAJOR_VERSION_ARB, 4,
        GLX_CONTEXT_MINOR_VERSION_ARB, 5,
        GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
        None
    };

    glxContext = glXCreateContextAttribsARB(gDisplay, glxFBConfig, 0, True, attributes);

    // Not able to get context for OpenGL version 4.5, fallback to old version.
    if(!glxContext)
    {
        printf("Failed to get GLX Context for OpenGL version 4.5, using old version.\n");

        // When a context version below 3.0 is requested, implementation will return
        // the newest context version compatible with OpenGL version less than 3.0
        GLint attributes[] = {
            GLX_CONTEXT_MAJOR_VERSION_ARB, 1,
            GLX_CONTEXT_MINOR_VERSION_ARB, 0,
            None
        };

        glxContext = glXCreateContextAttribsARB(gDisplay, glxFBConfig, 0, True, attributes);
    }
    else
    {
        printf("GLX Context for OpenGL version 4.5 is created.\n");
    }

    // Check do we have a direct context so that we get hardware rendering.
    if(!glXIsDirect(gDisplay, glxContext))
    {
        printf("Indirect GLX rendering context is used.\n");
    }
    else
    {
        printf("Direct GLX rendering context is used, hardware rendering is available.\n");
    }

    glXMakeCurrent(gDisplay, window, glxContext);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // Always cull back face for performance gain.
    // glEnable(GL_CULL_FACE);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    resize(windowWidth, windowHeight);
}

void handleEvent(XEvent *event)
{
    KeySym keySymbol;

    switch(event->type)
    {
        case MapNotify: // Window created.
        break;

        case KeyPress: // Key events.
            keySymbol = XkbKeycodeToKeysym(gDisplay, event->xkey.keycode, 0, 0);

            switch(keySymbol)
            {
                case XK_Escape:
                    isEscapeKeyPressed = true;
                break;

                case XK_F:
                case XK_f:
                    isFullscreen = !isFullscreen;
                    toggleFullscreen(isFullscreen);
                break;

                case XK_9:
                    speed = 0.9f;
                break;

                default:
                break;
            }

            if(keySymbol > XK_0 && keySymbol < XK_9)
            {
                speed = 0.1f * (keySymbol - XK_0);
            }
        break;

        case ButtonPress: // Mouse event.
            switch(event->xbutton.button)
            {
                case 1: // Left button.
                break;

                case 2: // Middle button.
                break;

                case 3: // Right button.
                break;

                case 4: // Mouse wheel up.
                break;

                case 5: // Mouse wheel down.
                break;
            }

        break;

        case MotionNotify: // Mouse move event.
        break;

        case ConfigureNotify: // Window configuration change, like resize.
            windowWidth = event->xconfigure.width;
            windowHeight = event->xconfigure.height;
            resize(windowWidth, windowHeight);
        break;

        case Expose: // Paint window.
        break;

        case DestroyNotify: // Window destroyed, cleanup resources.
        break;

        case 33: // Windows close button event.
            isCloseButtonClicked = true;
        break;

        default:
        break;
    }
}

void update(void)
{
    angle -= speed;

    if(angle <= -360.0f)
    {
        angle = 0.0f;
    }
}
/*
void display(void)
{ //Variable Declaration
    GLfloat x, y, r, angle;
    //static GLfloat tangle = 0.0f;


    GLfloat x1 = 0.0f, y1 = 1.0f;
    GLfloat x2 = -1.0f, y2 = -1.0f;
    GLfloat x3 = 1.0f, y3 = -1.0f;
    GLdouble PQ, QR, PR, perimeter, semiperimeter;

    //code
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);



    PQ = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));    //length / distance 
    QR = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    PR = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

    perimeter = PQ + QR + PR;
    semiperimeter = perimeter / 2;
    x = (x1 * QR + x2 * PR + x3 * PQ) / perimeter;      // circle center x part
    y = (y1 * QR + y2 * PR + y3 * PQ) / perimeter;    // circle center y part

                                        // radius
    r = sqrt(((semiperimeter - PQ) * (semiperimeter - QR) * (semiperimeter - PR)) / semiperimeter);

    
    glBegin(GL_LINES);

 /************ Triangle *****************/
/*
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0);
    glVertex3f(1.0f, -1.0f, 0);


    glVertex3f(0.0f, 1.0f, 0);
    glVertex3f(-1.0f, -1.0f, 0);


    glVertex3f(0.0f, 1.0f, 0);
    glVertex3f(1.0f, -1.0f, 0);

    glEnd();
    

    
    
/************ Circle *****************/

   // Variable Declaration
    //GLfloat x, y, r, angle;

    //code
 /*   
    GLint circle_points = 1000;

    
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);


    
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, .0f);
    for (angle = 0.0f; angle <= 2 * GL_PI; angle = angle + 0.01f)
    {
        glVertex2f(x + r * cos(angle), y + r * sin(angle));
    }

    glEnd();
    
    
    
/*************Vertical Line***************/
/*
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);
    

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex3f(0.0f, 1.0f, 0.0f);;
    glVertex3f(0.0f, -1.0f, 0.0f);

    glEnd();

    glXSwapBuffers(gDisplay, window);
}
*/
void display(void)
{
    // Variable Declaration
    GLfloat x, y, r, angle;
    //static GLfloat tangle = 0.0f;


    GLfloat x1 = 0.0f, y1 = 1.0f;
    GLfloat x2 = -1.0f, y2 = -1.0f;
    GLfloat x3 = 1.0f, y3 = -1.0f;
    GLdouble PQ, QR, PR, perimeter, semiperimeter;

    //code
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);


    // spnning triangle
    glTranslatef(xTrans, yTrans, 0.0f);
    if (xTrans > 0)
    {
        xTrans = 0.0f;

    }
    if (yTrans > 0)
    {
        yTrans = 0.0f;
    }



    PQ = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));    //length / distance 
    QR = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    PR = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

    perimeter = PQ + QR + PR;
    semiperimeter = perimeter / 2;
    x = (x1 * QR + x2 * PR + x3 * PQ) / perimeter;      // circle center x part
    y = (y1 * QR + y2 * PR + y3 * PQ) / perimeter;    // circle center y part

                                        // radius
    r = sqrt(((semiperimeter - PQ) * (semiperimeter - QR) * (semiperimeter - PR)) / semiperimeter);


    glBegin(GL_LINES);

    /************ Triangle *****************/

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0);
    glVertex3f(1.0f, -1.0f, 0);


    glVertex3f(0.0f, 1.0f, 0);
    glVertex3f(-1.0f, -1.0f, 0);


    glVertex3f(0.0f, 1.0f, 0);
    glVertex3f(1.0f, -1.0f, 0);

    glEnd();




    /************ Circle *****************/

       // Variable Declaration
        //GLfloat x, y, r, angle;

        //code

    GLint circle_points = 1000;


    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);


    glTranslatef(xcTrans, ycTrans, 0.0f);
    if (xcTrans < 0)
    {
        xcTrans = 0.0f;

    }
    if (ycTrans > 0)
    {
        ycTrans = 0.0f;
    }

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, .0f);
    for (angle = 0.0f; angle <= 2 * GL_PI; angle = angle + 0.01f)
    {
        glVertex2f(x + r * cos(angle), y + r * sin(angle));
    }

    glEnd();



    /*************Vertical Line***************/

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);

    glTranslatef(0.0f, ylTrans, 0.0f);

    if (ylTrans < 0)
    {
        ylTrans = 0.0f;
    }

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex3f(0.0f, 1.0f, 0.0f);;
    glVertex3f(0.0f, -1.0f, 0.0f);

    glEnd();

    //angle = angle + 5.0f;
    glXSwapBuffers(gDisplay, window);

    xTrans = xTrans + 0.0001f;
    yTrans = yTrans + 0.0001f;
    xcTrans = xcTrans - 0.0001f;
    ycTrans = ycTrans + 0.0001f;
    //xlTrance = xlTrance - 0.001f;
    ylTrans = ylTrans - 0.0001f;

}


/*
void deathlyHallowsSymbol(void)
{
    drawInvisibilityCloak();
    drawResurrectionStone();
    drawElderWand();
}

void drawInvisibilityCloak(void)
{
    glBegin(GL_LINE_LOOP);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);

    glEnd();
}

void drawResurrectionStone(void)
{
    GLint circlePoints = 10000;
    GLfloat angle = 0.0f;
    glLineWidth(1.0f);

    glBegin(GL_LINE_LOOP);

    glColor3f(1.0f, 1.0f, 1.0f);

    for (int counter = 0; counter < circlePoints; ++counter)
    {
        angle = 2.0f * M_PI * counter / circlePoints;
        glVertex3f(cos(angle) * 0.61f, (sin(angle) * 0.61f) - 0.39f, 0.0f);
    }

    glEnd();
}

void drawElderWand(void)
{
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);

    glEnd();
}
*/
void resize(int width, int height)
{
    if(height == 0)
    {
        height = 1;
    }

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 1.0f, 100.0f);
}

void toggleFullscreen(bool isFullscreen)
{
    Atom wmStateNormal;
    Atom wmStateFullscreen;
    XEvent event = {0};

    wmStateNormal = XInternAtom(gDisplay, "_NET_WM_STATE", False);
    wmStateFullscreen = XInternAtom(gDisplay, "_NET_WM_STATE_FULLSCREEN", False);

    memset(&event, 0, sizeof(event));
    event.type = ClientMessage;
    event.xclient.window = window;
    event.xclient.message_type = wmStateNormal;
    event.xclient.format = 32;
    event.xclient.data.l[0] = isFullscreen ? 1 : 0;
    event.xclient.data.l[1] = wmStateFullscreen;

    XSendEvent(gDisplay, XRootWindow(gDisplay, visualInfo->screen), False, StructureNotifyMask, &event);
}

void cleanup(void)
{
    GLXContext currentContext = glXGetCurrentContext();

    if(currentContext != NULL && currentContext == glxContext)
    {
        glXMakeCurrent(gDisplay, 0, 0);
    }

    if(glxContext)
    {
        glXDestroyContext(gDisplay, glxContext);
    }

    if(window)
    {
        XDestroyWindow(gDisplay, window);
    }

    if(colormap)
    {
        XFreeColormap(gDisplay, colormap);
    }

    if(visualInfo)
    {
        free(visualInfo);
        visualInfo = NULL;
    }

    if(gDisplay)
    {
        XCloseDisplay(gDisplay);
        gDisplay = NULL;
    }
}




