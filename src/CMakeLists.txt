file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES}  "Controller.cpp" "Board.cpp"   "Object.cpp" "Mouse.cpp" "Icons.cpp" "../include/Road.h" "../include/Road.h" "../include/NormalCat.h" "Cat.cpp" "../include/SoundManager.h")

