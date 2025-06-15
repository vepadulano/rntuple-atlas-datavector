When running at a root prompt

```
ROOT::Internal::GetDemangledTypeName(typeid(AtlasLikeDataVector<CustomStruct>))
```

twice, the second time it will display the full class with 2 template arguments.

This behaviour does not happen with the same code run via a precompiled executable using `TClass::GetClass`.

At the root prompt, if a `gSystem->Load` of the shared library is called beforehand, then the type name
from the following call will have only one template argument
