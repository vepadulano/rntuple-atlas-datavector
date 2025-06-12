#include <TClass.h>
#include <iostream>

int main() {
  auto *cl = TClass::GetClass("AtlasLikeDataVector<CustomStruct>");
  if (!cl) {
    std::cout << "Could not find class!\n";
    return 1;
  }
  if (const std::type_info *tid = cl->GetTypeInfo()) {

    std::cout << "cl->GetName()=" << cl->GetName() << "\n";
    std::cout << "demangled=" << ROOT::Internal::GetDemangledTypeName(*tid)
              << "\n";
  } else {
    std::cout << "Could not find type_info from class!\n";
    return 1;
  }
}
