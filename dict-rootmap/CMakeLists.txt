# Copyright (C) 1995-2023, Rene Brun and Fons Rademakers.
# All rights reserved.
#
# For the licensing terms see $ROOTSYS/LICENSE.
# For the list of contributors see $ROOTSYS/README/CREDITS.

#####################################################################################################################

# Details about integrating ROOT into CMake projects:
#     https://root.cern/manual/integrate_root_into_my_cmake_project/

#####################################################################################################################

# CMakeLists.txt that creates a library with dictionary and a main program
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(atlaslikedatavector_dict_rootmap)

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS Core RIO)

#---Include a CMake module which makes use of the previous variables and loads modules 
#   with useful macros or functions such as ROOT_GENERATE_DICTIONARY
#   For further details: https://root-forum.cern.ch/t/how-to-integrate-root-into-my-project-with-cmake/37175
#   A more modern alternative to the two lines below is in https://github.com/root-project/root/issues/8308#issuecomment-856008466
include(${ROOT_USE_FILE})

#---Add include directory of ROOT to the build
include_directories(${CMAKE_SOURCE_DIR})

# CMake function provided by ROOT, used to generate the dictionary file, G__data2Tree.cxx
#     See this link for further details:
#     https://root.cern/manual/io_custom_classes/#using-cmake
ROOT_GENERATE_DICTIONARY(G__AtlasLikeDataVector AtlasLikeDataVector.hxx LINKDEF AtlasLikeDataVectorLinkDef.hxx)

#---Create a shared library from
#   * the previously generated dictionary, G__data2Tree.cxx
#   * the class implementation
add_library(AtlasLikeDataVectorLib SHARED G__AtlasLikeDataVector.cxx)
target_link_libraries(AtlasLikeDataVectorLib ${ROOT_LIBRARIES}) 
add_dependencies(AtlasLikeDataVectorLib G__AtlasLikeDataVector)

#---Create  a main program using the library
add_executable(test_tclass test_tclass.cpp)
target_link_libraries(test_tclass ${ROOT_LIBRARIES} AtlasLikeDataVectorLib)


