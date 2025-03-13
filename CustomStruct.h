#ifndef MYHEADER
#define MYHEADER

#include <TVirtualCollectionProxy.h>
#include <RootMetaSelection.h>

#include <cstdint>
#include <string>
#include <variant>
#include <vector>

// namespace ROOT
// {
//    namespace Meta
//    {
//       namespace Selection
//       {

//          template <class T, class BASE = std::vector<T>>
//          class AtlasLikeDataVector;

//       }
//    }
// }

struct CustomStruct
{
   template <typename T>
   using MyVec = std::vector<T>;

   float a = 0.0;
   std::vector<float> v1;
   std::vector<std::vector<float>> v2;
   std::string s;
   std::byte b{};

   bool operator<(const CustomStruct &c) const { return a < c.a && v1 < c.v1 && v2 < c.v2 && s < c.s; }

   bool operator==(const CustomStruct &c) const { return a == c.a && v1 == c.v1 && v2 == c.v2 && s == c.s; }
};

template <class T, class BASE = std::vector<T>>
class AtlasLikeDataVector : public BASE
{
   /// Instantiate the dictionary selection rule object
   // typedef typename ROOT::Meta::Selection::AtlasLikeDataVector<T, BASE>::self self;
};

namespace ROOT
{
   namespace Meta
   {
      namespace Selection
      {

         template <class T, class BASE = std::vector<T>>
         class AtlasLikeDataVector : KeepFirstTemplateArguments<1>, SelectNoInstance
         {
         public:
            /// A helper typedef
            // typedef AtlasLikeDataVector<T, BASE> self;
         };

      }
   }
}

namespace {
   struct DUMMY_INSTANTIATION {
      AtlasLikeDataVector<int> dummy1;
      ROOT::Meta::Selection::AtlasLikeDataVector<int> dummy2;
   };
}


#endif
