#pragma link C++ class CustomStruct + ;
#pragma link C++ class BasePlaceHolder + ;
#pragma link C++ class SecondTemplatePlaceHolder + ;
#pragma link C++ class AtlasLikeDataVector < CustomStruct,                     \
    SecondTemplatePlaceHolder> +                                               \
    ;
// #pragma link C++ class AtlasLikeDataVector<CustomStruct>+;
#pragma link C++ class AtlasLikeDataVector < int> + ;
