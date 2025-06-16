#ifndef MYHEADER
#define MYHEADER

#include <RootMetaSelection.h>
#include <TVirtualCollectionProxy.h>

#include <cstdint>
#include <iostream>
#include <string>
#include <variant>
#include <vector>

struct CustomStruct {
  template <typename T> using MyVec = std::vector<T>;

  float a = 0.0;
  std::vector<float> v1;
  std::vector<std::vector<float>> v2;
  std::string s;
  std::byte b{};

  bool operator<(const CustomStruct &c) const {
    return a < c.a && v1 < c.v1 && v2 < c.v2 && s < c.s;
  }

  bool operator==(const CustomStruct &c) const {
    return a == c.a && v1 == c.v1 && v2 == c.v2 && s == c.s;
  }
};

template <class T, class BASE = std::vector<T>>
class AtlasLikeDataVector : public BASE {};

struct SecondTemplatePlaceHolder {};

struct BasePlaceHolder {};

// Mimicks
// https://gitlab.cern.ch/atlas/athena/-/blob/main/Control/AthContainers/AthContainers/DataVector.h#L2059
template <class T>
class AtlasLikeDataVector<T, SecondTemplatePlaceHolder>
    : public BasePlaceHolder {
  AtlasLikeDataVector() { std::cout << "called!\n"; }
  AtlasLikeDataVector(AtlasLikeDataVector &&) { std::cout << "called!\n"; }
  AtlasLikeDataVector(const AtlasLikeDataVector &) { std::cout << "called!\n"; }
};

namespace ROOT {
namespace Meta {
namespace Selection {

template <class T, class BASE = std::vector<T>>
class AtlasLikeDataVector : KeepFirstTemplateArguments<1>, SelectNoInstance {};

} // namespace Selection
} // namespace Meta
} // namespace ROOT

namespace {
struct DUMMY_INSTANTIATION {
  AtlasLikeDataVector<CustomStruct, SecondTemplatePlaceHolder> dummy1;
  ROOT::Meta::Selection::AtlasLikeDataVector<CustomStruct, SecondTemplatePlaceHolder> dummy4;
//  AtlasLikeDataVector<CustomStruct> dummy2;
//  ROOT::Meta::Selection::AtlasLikeDataVector<int> dummy3;
};
} // namespace

#endif
