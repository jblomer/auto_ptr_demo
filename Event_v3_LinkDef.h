#ifdef __ROOTCLING__

#pragma link C++ class Track+;
#pragma link C++ class Event+;
#pragma link C++ class Compat::deprecated_auto_ptr<Track>+;

#pragma read sourceClass="std::auto_ptr<Track>" targetClass="Compat::deprecated_auto_ptr<Track>"

#pragma read sourceClass="Event" targetClass="Event" version="[2]" \
  source="Compat::deprecated_auto_ptr<Track> fPtr" target="fPtr" \
  code="{ fPtr.release(); fPtr.reset(onfile.fPtr._M_ptr); }"

#endif
