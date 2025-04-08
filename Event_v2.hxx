#ifndef _EVENT_H
#define _EVENT_H

#include <RtypesCore.h>

#include <memory>

struct Track {
   int fFoo;

   ClassDefNV(Track, 2);
};

struct Event {
   std::auto_ptr<Track> fPtr;
   float fBar = 137.0;

   ClassDefNV(Event, 2);
};

#endif // _EVENT_H
