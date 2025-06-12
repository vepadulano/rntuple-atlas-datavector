#include "CustomStruct.h"
#include <ROOT/RField.hxx>
#include <ROOT/RNTupleReader.hxx>
#include <iostream>
#include <string>

void test_atlas_datavector() {
  using RNTupleReader = ROOT::Experimental::RNTupleReader;
  std::string fileName("test_ntuple_atlas_like_datavector.root");
  auto reader = RNTupleReader::Open("ntpl", fileName);
  auto f2 = reader->GetModel()
                .GetDefaultEntry()
                .GetPtr<AtlasLikeDataVector<CustomStruct>>("f2");

  const auto &desc = reader->GetDescriptor();
  std::cout << "f1: "
            << desc.GetFieldDescriptor(desc.FindFieldId("f1")).GetTypeName()
            << "\n";
  std::cout << "f2: "
            << desc.GetFieldDescriptor(desc.FindFieldId("f2")).GetTypeName()
            << "\n";
  std::cout << "f3: "
            << desc.GetFieldDescriptor(desc.FindFieldId("f3")).GetTypeName()
            << "\n";
  std::cout << "typeinfo: " << typeid(AtlasLikeDataVector<int>).name() << "\n";
  std::cout << "RField<T>::TypeName: "
            << ROOT::RField<AtlasLikeDataVector<int>>::TypeName() << "\n";
}

int main() { test_atlas_datavector(); }
