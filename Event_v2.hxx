#ifndef _EVENT_H
#define _EVENT_H

#include <RtypesCore.h>

#include <memory>
//#include <vector>

struct Track {
   int fFoo;

   ClassDefNV(Track, 2);
};

struct Event {
   std::auto_ptr<Track> fPtr;
   float fBar = 137.0;
   // For testing we also need to test rules
   // applied to whole split collection:
   // std::vector<std::old_class<Track>> fVecPtr;

   ClassDefNV(Event, 2);
};

#endif // _EVENT_H
