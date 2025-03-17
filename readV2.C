#include "Event_v2.hxx"

void readV2()
{
   gSystem->Load("./libEvent_v2.so");

   auto f = TFile::Open("data_splitlevel0.root");
   auto t = (TTree *)f->Get("t");

   Event *event = nullptr;
   t->SetBranchAddress("event", &event);

   for (int i = 0; i < t->GetEntries(); ++i) {
      t->GetEntry(i);

      if (!event->fPtr.get())
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

      if (!event->fPtr.get())
         std::cout << "(nullptr)" << std::endl;
      else
         std::cout << event->fPtr->fFoo << std::endl;
   }
}
