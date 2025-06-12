#include <ROOT/RField.hxx>
#include <ROOT/RFieldBase.hxx>
#include <ROOT/RNTupleModel.hxx>
#include <ROOT/RNTupleReader.hxx>
#include <ROOT/RNTupleWriter.hxx>

#include <string>

#include "CustomStruct.h"

using RNTupleWriter = ROOT::Experimental::RNTupleWriter;
using RNTupleReader = ROOT::Experimental::RNTupleReader;
using RNTupleModel = ROOT::Experimental::RNTupleModel;
using RFieldBase = ROOT::Experimental::RFieldBase;

int main() {
  std::string fileName("test_ntuple_atlas_like_datavector.root");

  {
    auto model = RNTupleModel::Create();

    // f1
    auto f1 = model->MakeField<AtlasLikeDataVector<CustomStruct>>("f1");
    *f1 = AtlasLikeDataVector<CustomStruct>{{CustomStruct{}, CustomStruct{}}};

    // f2
    model->AddField(
        RFieldBase::Create("f2", "AtlasLikeDataVector<CustomStruct>").Unwrap());

    // f3
    auto f3 = model->MakeField<AtlasLikeDataVector<int>>("f3");

    auto writer = RNTupleWriter::Recreate(std::move(model), "ntpl", fileName);
    writer->Fill();
  }

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
            << ROOT::Experimental::RField<AtlasLikeDataVector<int>>::TypeName()
            << "\n";
}
