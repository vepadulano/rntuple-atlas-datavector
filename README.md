# rntuple-atlas-datavector


Steps to reproduce:
1. `rootcling -f DictCustomStruct.cxx CustomStruct.h`
2. `g++ -g -lROOTNTuple $(root-config --cflags --glibs) DictCustomStruct.cxx repro.cpp -o repro.out`


Output with ROOT master:
```
$: ./repro.out
f1: AtlasLikeDataVector<CustomStruct>
f2: AtlasLikeDataVector<CustomStruct>
f3: AtlasLikeDataVector<std::int32_t>
typeinfo: 19AtlasLikeDataVectorIiSt6vectorIiSaIiEEE
rfield typed: AtlasLikeDataVector<int>
```

Steps to reproduce with loading of shared library:

1. Run the reproducer from the previous part to save the output file
2. `root -b -q -e "gSystem->CompileMacro(\"CustomStruct.h\",\"kfg\")"`
3. `root -b -q test_atlas_datavector.C` 

With ROOT master, the macro from above does not throw an exception.
