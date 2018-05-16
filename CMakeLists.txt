cmake_minimum_required(VERSION 3.7)
project(Lab5_12)

set(CMAKE_CXX_STANDARD 14)


find_package(Qt5Widgets)

# Add the include directories for the Qt 5 Widgets module to
# the compile lines.
include_directories(${Qt5Widgets_INCLUDE_DIRS})

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Add compiler flags for building executables (-fPIE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

qt5_generate_moc(main.cpp main.moc)

# Tell CMake to create the qtlayoutexample executable
add_executable(Lab5_12 main.cpp adoption_list.cpp adoption_list.h Comparator.h controller.cpp controller.h CSV_adoption_list.cpp CSV_adoption_list.h dog_validator.h dog_validator.cpp domain.cpp domain.h dynamic_array.h file_adoption_list.h file_adoption_list.cpp HTMLAdoptionList.h HTMLAdoptionList.cpp repository.h repository.cpp ui.cpp ui.h utils.cpp utils.h MyGui.cpp MyGui.h)

#Link the qtlayoutexample executable to the Qt 5 widgets library.
target_link_libraries(Lab5_12 Qt5::Widgets)