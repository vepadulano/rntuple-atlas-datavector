#include "CustomStruct.h"

void test() {
  AtlasLikeDataVector<CustomStruct, std::vector<CustomStruct>> a;
  std::cout << ROOT::Internal::GetDemangledTypeName(typeid(a)) << "\n";
}
