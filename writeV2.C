#include "Event_v2.hxx"

void writeV2()
{
   gSystem->Load("./libEvent_v2.so");

   auto f = TFile::Open("data.root", "RECREATE");
   auto t = new TTree("t", "");

   Event event;
   t->Branch("event", &event);

   event.fPtr = std::auto_ptr<Track>(new Track{1});
   t->Fill();
   event.fPtr = std::auto_ptr<Track>(nullptr);
   t->Fill();
   event.fPtr = std::auto_ptr<Track>(new Track{3});
   t->Fill();

   t->Scan();

   t->Write();
   f->Close();

   f = TFile::Open("data_splitlevel0.root", "RECREATE");
   t = new TTree("t", "");
   t->Branch("event", &event, 32000, 0);

   event.fPtr = std::auto_ptr<Track>(new Track{1});
   t->Fill();
   event.fPtr = std::auto_ptr<Track>(nullptr);
   t->Fill();
   event.fPtr = std::auto_ptr<Track>(new Track{3});
   t->Fill();

   t->Scan();

   t->Write();
   f->Close();
}
