//XWindows first program
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//XWindows headers:
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <X11/keysym.h>

//OpenGL headers:
#include <GL/gl.h>
#include <GL/glx.h> //Bridging API
#include <GL/glu.h>
#define GL_PI 3.1415f
#include<math.h>

//namespaces
using namespace std;

//global variable declarations
bool bFullscreen=false;
Display *gpDisplay=NULL;
XVisualInfo *gpXVisualInfo=NULL;
Colormap gColormap;
Window gWindow;
int giWindowWidth=1600;
int giWindowHeight=900;

GLXContext gGLXContext; //Rendering context // ..../user/include......(directory)

//entry-point function
int main(void)
{

//function prototypes
void CreateWindow(void);
void ToggleFullscreen(void);
void uninitialize();
void initialize(void);
void resize(int, int);
void display(void);

//variable declarations
int winWidth=giWindowWidth;
int winHeight=giWindowHeight;
bool bDone = false;
char ascii[26]; //For key press funtionality
//Code:
CreateWindow(); //Function to create a window

//Initialize():
initialize();

XEvent event; //To store the message/event
KeySym keysym;
//Game loop
while(bDone == false)
{
while(XPending(gpDisplay))
{
XNextEvent(gpDisplay, &event); //Get next message. Fill 'event' with the address of next event.
switch(event.type) //Switch on event type
{
case MapNotify:
break;
case KeyPress:
keysym = XkbKeycodeToKeysym(gpDisplay, event.xkey.keycode, 0, 0);
switch(keysym)
{
case XK_Escape: //Exit on Esc key press
bDone = true;
default:
break;
}
XLookupString(&event.xkey, ascii, sizeof(ascii), NULL, NULL);
switch(ascii[0])
{
case 'f':
case 'F':
if(bFullscreen == false)
{
ToggleFullscreen();
bFullscreen = true;
}
else
{
ToggleFullscreen();
bFullscreen = false;
}
break;
default:
break;
}
break;
case ButtonPress:
switch(event.xbutton.button)
{
case 1: //Left mouse button
break;
case 2: //Middle mouse button
break;
case 3: //Right mouse button
break;
default:
break;
}
break;
case MotionNotify: //Mouse move
break;
case ConfigureNotify:
winWidth = event.xconfigure.width;
winHeight = event.xconfigure.height;
resize(winWidth, winHeight);
break;
case Expose: //Painting of window
break;
case DestroyNotify:
break;
case 33: //Close press
bDone = true;
break;
default:
break;
}
}

display();
//Spin call here
}
uninitialize();
return(0);
}

void CreateWindow(void)
{
//Function Prototypes:
void uninitialize(void);

//Variable declarations:
XSetWindowAttributes winAttribs;
int defaultScreen; //To get the default screen
int defaultDepth; //To get the default depth
int styleMask;

static int frameBufferAttributes[] =
{
GLX_RGBA,
GLX_RED_SIZE,1,
GLX_GREEN_SIZE,1,
GLX_BLUE_SIZE,1,
None //As a stopper for array
};

//code

gpDisplay = XOpenDisplay(NULL); //Pointer to struct is the return value. It returns default display pointer.
if(gpDisplay == NULL)
{
printf("ERROR: Unable to open X Display.\n Exiting...\n");
uninitialize();
exit(1);
}

defaultScreen = XDefaultScreen(gpDisplay);
gpXVisualInfo = glXChooseVisual(gpDisplay, defaultScreen, frameBufferAttributes);



winAttribs.border_pixel = 0; //Take default value for color
winAttribs.border_pixmap = 0; //Take default pattern
winAttribs.background_pixmap = 0;
winAttribs.colormap = XCreateColormap(gpDisplay, RootWindow(gpDisplay, gpXVisualInfo->screen), gpXVisualInfo->visual, AllocNone);

gColormap = winAttribs.colormap;

winAttribs.background_pixel = BlackPixel(gpDisplay, defaultScreen);
winAttribs.event_mask = ExposureMask | VisibilityChangeMask | ButtonPress | KeyPressMask | PointerMotionMask | StructureNotifyMask;


styleMask = CWBorderPixel | CWBackPixel | CWEventMask | CWColormap;
gWindow = XCreateWindow(gpDisplay,
RootWindow(gpDisplay, gpXVisualInfo->screen), //Parent window handle
0, //Xop
0, //Y
giWindowWidth, //W
giWindowHeight, //H
0, //Thickness of border
gpXVisualInfo->depth,
InputOutput,
gpXVisualInfo->visual,
styleMask,
&winAttribs);
if(!gWindow)
{
printf("ERROR: Failed to create Main Window.\n Exiting...\n");
uninitialize();
exit(1);
}

XStoreName(gpDisplay, gWindow, "Rishikesh Dumbre: Graph_Paper");
Atom windowManagerDelete = XInternAtom(gpDisplay, "WM_DELETE_WINDOW", True); //33 turned on after this protocol
XSetWMProtocols(gpDisplay, gWindow, &windowManagerDelete, 1);
XMapWindow(gpDisplay, gWindow); //ShowWindow(); UpdateWindow(); SetFocus(), etc
}


void ToggleFullscreen(void)
{
//Variable declarations:
Atom wm_state; //To save state of normal screen
Atom fullscreen; //TO save state of full screen
XEvent xev = {0};

//Code:
wm_state = XInternAtom(gpDisplay, "_NET_WM_STATE", False); //Network compliant.
memset(&xev, 0, sizeof(xev)); //Memset to default values

xev.type = ClientMessage; //Custom message
xev.xclient.window = gWindow; //Window for which client message is going(predefined message)
xev.xclient.message_type = wm_state; //Type of message that you are sending(created by you)
xev.xclient.format = 32; //byte size = 32
xev.xclient.data.l[0] = bFullscreen ? 0 : 1;

fullscreen = XInternAtom(gpDisplay, "_NET_WM_STATE_FULLSCREEN", False);
xev.xclient.data.l[1] = fullscreen;

XSendEvent(gpDisplay,
RootWindow(gpDisplay, gpXVisualInfo->screen), //Propagates to your window
False, //If the message be propagated to your children
StructureNotifyMask,
&xev);

}

void initialize(void)
{
//Function protoypes:
void resize(int, int);
void uninitialize(void);

//Code:
gGLXContext = glXCreateContext(gpDisplay, gpXVisualInfo, NULL, GL_TRUE);
if(gGLXContext == NULL)
{
printf("ERROR: Failed to create Rendering Context.\n Exiting...\n");
uninitialize();
exit(1);
}

glXMakeCurrent(gpDisplay, gWindow, gGLXContext);
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
resize(giWindowWidth, giWindowHeight); //Stray resize
}
void resize(int width, int height)
{
//Code:
if(height == 0)
height = 1;
glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void)
{
//Function Declarations

// Variable Declaration
GLfloat x, y, r, i, angle;

//code

glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW); //for Perspective
glLoadIdentity(); //for Perspective

GLfloat x1 = 0.0f, y1 = 1.0f;
GLfloat x2 = -1.0f, y2 = -1.0f;
GLfloat x3 = 1.0f, y3 = -1.0f;
GLdouble PQ, QR, PR, perimeter, semiperimeter;

glBegin(GL_LINES);

glColor3f(1.0f, 0.0f, 0.0f); //
glVertex3f(-1.0f, 0.0f, 0.0f); //x,y,z
glVertex3f(1.0f, 0.0f, 0.0f);

glVertex3f(0.0f, -1.0f, 0.0f); //x,y,z
glVertex3f(0.0f, 1.0f, 0.0f);
//glColor3f(0.0f, 0.0f, 1.0f); // R G B

for (y = 1.0f / 40.0f; y <= 1; y = y + 0.025) // y = total distance / No of lines or y = 0.025
{
glColor3f(0.0f, 0.0f, 1.0f); // R G B
glVertex3f(-1.0f, y, 0.0f); //x,y,z
glVertex3f(1.0f, y, 0.0f);

glColor3f(0.0f, 0.0f, 1.0f); // R G B
glVertex3f(-1.0f, -y, 0.0f); //x,y,z
glVertex3f(1.0f, -y, 0.0f);

for (x = 1.0f / 40.0f; x <= 1; x = x + 0.025) // x = total distance / No of lines or x = 0.025
{
glColor3f(0.0f, 0.0f, 1.0f); // R G B
glVertex3f(x, -1.0f, 0.0f); //x,y,z
glVertex3f(x, 1.0f, 0.0f);

glColor3f(0.0f, 0.0f, 1.0f); // R G B
glVertex3f(-x, -1.0f, 0.0f); //x,y,z
glVertex3f(-x, 1.0f, 0.0f);
}


}
glEnd();
/****************Circle********************/

glScalef(-0.4, 0.6, 0.0);
glBegin(GL_POINTS);
GLint circle_points = 1000;


for (i = 0; i < circle_points; i++)
{
angle = 2 * GL_PI * i / circle_points;
glColor3f(1.0f, 1.0f, 0.0f);
glVertex2f(cos(angle), sin(angle));
}
glEnd();

/**************Rectangle*************************/

glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 0.0f);
glVertex3f(0.7f, 0.7f, 0.0f);
glVertex3f(-0.7f, 0.7f, 0.0f);

glColor3f(1.0f, 1.0f, 0.0f);
glVertex3f(-0.7f, -0.7f, 0.0f);
glVertex3f(0.7f, -0.7f, 0.0f);

glColor3f(1.0f, 1.0f, 0.0f);
glVertex3f(0.7f, -0.7f, 0.0f);
glVertex3f(0.7f, 0.7f, 0.0f);

glColor3f(1.0f, 1.0f, 0.0f);
glVertex3f(-0.7f, -0.7f, 0.0f);
glVertex3f(-0.7f, 0.7f, 0.0f);

glEnd();


PQ = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); //length / distance
QR = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
PR = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

perimeter = PQ + QR + PR;
semiperimeter = perimeter / 2;
x = (x1 * QR + x2 * PR + x3 * PQ) / perimeter; // circle center x part
y = (y1 * QR + y2 * PR + y3 * PQ) / perimeter; // circle center y part

// radius
r = sqrt(((semiperimeter - PQ) * (semiperimeter - QR) * (semiperimeter - PR)) / semiperimeter);


glBegin(GL_LINES);

/*********** Triangle ****************/

glColor3f(1.0f, 1.0f, 0.0f);
glVertex3f(-1.0f, -1.0f, 0);
glVertex3f(1.0f, -1.0f, 0);


glVertex3f(0.0f, 1.0f, 0);
glVertex3f(-1.0f, -1.0f, 0);


glVertex3f(0.0f, 1.0f, 0);
glVertex3f(1.0f, -1.0f, 0);

glEnd();


/*********** Circle ****************/


glBegin(GL_LINE_LOOP);
glColor3f(1.0f, 1.0f, .0f);
for (angle = 0.0f; angle <= 2 * GL_PI; angle = angle + 0.001f)
{
glVertex2f(x + r * cos(angle), y + r * sin(angle));
}

glEnd();

glXSwapBuffers(gpDisplay, gWindow); //Comment/Remove Single buffer
}


void uninitialize(void)
{
GLXContext currentGLXContext;
currentGLXContext = glXGetCurrentContext();

if(currentGLXContext != NULL && currentGLXContext == gGLXContext)
{
glXMakeCurrent(gpDisplay, 0, 0);
}

if(gGLXContext)
{
glXDestroyContext(gpDisplay, gGLXContext);
}

if(gWindow)
{
XDestroyWindow(gpDisplay, gWindow);
}

if(gColormap)
{
XFreeColormap(gpDisplay, gColormap);
}

if(gpXVisualInfo)
{
free(gpXVisualInfo);
gpXVisualInfo = NULL;
}

if(gpDisplay)
{
XCloseDisplay(gpDisplay);
gpDisplay = NULL;
}
}



