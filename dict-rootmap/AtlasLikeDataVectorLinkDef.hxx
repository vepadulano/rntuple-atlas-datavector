#pragma link C++ class CustomStruct+;
#pragma link C++ class BasePlaceHolder+;
#pragma link C++ class SecondTemplatePlaceHolder+;
#pragma link C++ class AtlasLikeDataVector<CustomStruct, SecondTemplatePlaceHolder>+;
// Should not be necessary because of the rule to strip the second template argument
// #pragma link C++ class AtlasLikeDataVector<CustomStruct>+;
