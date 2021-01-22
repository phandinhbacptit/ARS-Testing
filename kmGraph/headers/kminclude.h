#ifndef KMINCLUDE_H
#define KMINCLUDE_H

#endif // KMINCLUDE_H

//#define _PLATFORM_WINDOWS
#define _PLATFORM_LINUX
#define _USE_VRSDRAW_TEXT
//#define _USE_VRSDRAW_IMAGE

#ifdef _PLATFORM_LINUX
#undef _PLATFORM_WINDOWS
#endif

#define FONT_DIRECTORY  "kmGraph/fonts/roboto/"

#ifdef _PLATFORM_WINDOWS
#define kmstring	wstring
#else
#define kmstring	string
#endif
