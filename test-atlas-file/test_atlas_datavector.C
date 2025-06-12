#include "CustomStruct.h"

void test_atlas_datavector() {
  gSystem->Load("CustomStruct_h");
  using RNTupleReader = ROOT::Experimental::RNTupleReader;
  std::string fileName("test_ntuple_atlas_like_datavector.root");
  auto reader = RNTupleReader::Open("ntpl", fileName);
  auto f2 = reader->GetModel()
                .GetDefaultEntry()
                .GetPtr<AtlasLikeDataVector<CustomStruct>>("f2");
}
