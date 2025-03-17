#include "Event_v3.hxx"

void demoAutoPtr()
{
   gSystem->Load("./libEvent_v3.so");

   auto f = TFile::Open("data_splitlevel0.root");
   auto t = (TTree *)f->Get("t");

   Event *event = nullptr;
   t->SetBranchAddress("event", &event);

   for (int i = 0; i < t->GetEntries(); ++i) {
      t->GetEntry(i);

      std::cout << "Event " << i << ": ";
      if (!event->fPtr)
         std::cout << "(nullptr)" << std::endl;
      else
         std::cout << event->fPtr->fFoo << std::endl;
   }

   f = TFile::Open("data.root");
   t = (TTree *)f->Get("t");

   event = nullptr;
   t->SetBranchAddress("event", &event);

   for (int i = 0; i < t->GetEntries(); ++i) {
      t->GetEntry(i);

      std::cout << "Event " << i << ": ";
      if (!event->fPtr)
         std::cout << "(nullptr)" << std::endl;
      else
         std::cout << event->fPtr->fFoo << std::endl;
   }
}
