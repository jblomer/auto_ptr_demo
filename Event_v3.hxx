#ifndef _EVENT_H
#define _EVENT_H

#include <RtypesCore.h>

#include <memory>

namespace Compat {

template <typename T>
struct deprecated_auto_ptr
{
   // We use compat_auto_ptr only to assign the wrapped raw pointer to a unique pointer in an I/O customization rule.
   // Therefore, we don't delete on destruction (because ownership gets transferred to the unique pointer).
   // ~deprecated_auto_ptr() { delete _M_ptr; }

   T *_M_ptr = nullptr;
};

} // namespace Compat

struct Track {
   int fFoo;

   ClassDefNV(Track, 2)
};

struct Event {
   std::unique_ptr<Track> fPtr;
   float fBar = 137.0;

   ClassDefNV(Event, 3)
};

#endif // _EVENT_H
