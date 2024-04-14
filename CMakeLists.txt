# to define version pf cmake used for project 

cmake_minimum_required(VERSION 3.22.1)

#define project name and attributes

project(LightYears
    VERSION 1.0.0
    LANGUAGES C CXX
)

#set some attributes 
set(CMAKE_CXX_STANDARD           14)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

#set variable in CMAKE
set(LIGHT_YEARS_GAME_TARGET_NAME    LightYearsGame )

#to include cmake file inside another --> give location where search for cmake file (CmakeLists.txt)
add_subdirectory(LightYear)

#to set the properties of target such as location
set_target_properties(${LIGHT_YEARS_GAME_TARGET_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)


#fetching SFML library

include(FetchContent)

set(SFML_LIB_NAME  SFML)

FetchContent_Declare(
    ${SFML_LIB_NAME}  #libraryName
    GIT_REPOSITORY https://github.com/SFML/SFML.git  #repo link for library
    GIT_TAG 2.5.1    # version of library
    GIT_SHALLOW    FALSE  #to make deep copy
)

FetchContent_MakeAvailable(${SFML_LIB_NAME})  #make libraries available for use 






