#include "AtlasLikeDataVector.hxx"
#include <TGenericClassInfo.h>
#include <iostream>

int main() {
  auto typeName = ROOT::Internal::GetDemangledTypeName(
      typeid(AtlasLikeDataVector<CustomStruct>));
 
  std::cout << "typename=" << typeName << "\n";
}
