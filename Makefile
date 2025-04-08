all: libEvent_v2.so libEvent_v3.so

dict2.cxx: Event_v2.hxx Event_v2_LinkDef.h
	rootcling -f dict2.cxx Event_v2.hxx Event_v2_LinkDef.h ; 

libEvent_v2.so: dict2.cxx 
	g++ -Wno-deprecated-declarations -o libEvent_v2.so --shared -fPIC `root-config --cflags --libs` dict2.cxx

dict3.cxx: Event_v3.hxx Event_v3_LinkDef.h
	rootcling -f dict3.cxx Event_v3.hxx Event_v3_LinkDef.h 

libEvent_v3.so: dict3.cxx
	g++ -o libEvent_v3.so dict3.cxx `root-config --cflags --libs` -fPIC --shared
