When running at a root prompt

```
ROOT::Internal::GetDemangledTypeName(typeid(AtlasLikeDataVector<CustomStruct>))
```

twice, the second time it will display the full class with 2 template arguments. See the following:

```
root [0] ROOT::Internal::GetDemangledTypeName(typeid(AtlasLikeDataVector<CustomStruct>))
ROOT_prompt_0:1:45: error: too few template arguments for class template 'AtlasLikeDataVector'
ROOT::Internal::GetDemangledTypeName(typeid(AtlasLikeDataVector<CustomStruct>))
                                            ^
Forward declarations from ./libAtlasLikeDataVector.rootmap:4:44: note: template is declared here
template <typename T, typename BASE> class AtlasLikeDataVector;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~       ^
root [1] ROOT::Internal::GetDemangledTypeName(typeid(AtlasLikeDataVector<CustomStruct>))
(std::string) "AtlasLikeDataVector<CustomStruct,vector<CustomStruct> >"
```

Note that when I want to type the second command, I notice a lag on my machine, I'm assuming this
is due to the autoloading happening in the background.

This behaviour does not happen with the same code run via a precompiled executable using `TClass::GetClass`.

At the root prompt, if a `gSystem->Load` of the shared library is called beforehand, then the type name
from the following call will have only one template argument
