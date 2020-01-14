cmake_minimum_required(VERSION 3.1)

#set project name and language
project(vf-helpers LANGUAGES CXX)

#Automoc and RCC ON. Needed in QT projects
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#C++ 11 Flag
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Set project Version
set(VfHelpers_VERSION_MAJOR "0")
set(VfHelpers_VERSION_MINOR "0")
set(VfHelpers_VERSION_PATCH "1")

set(PROJECT_VERSION "${VfHelpers_VERSION_MAJOR}.${VfHelpers_VERSION_MINOR}.${VfHelpers_VERSION_PATCH}")

#Adding cmake functions like feature_summary()
include(FeatureSummary)
include(GNUInstallDirs)

#Find dependecies
find_package(Qt5 COMPONENTS Core CONFIG REQUIRED)

#sum up project Files 
file(GLOB SOURCES 
    ${PROJECT_SOURCE_DIR}/*.cpp
    )

file(GLOB HEADER
    ${PROJECT_SOURCE_DIR}/*.h
    )

file(GLOB RESOURCES 
    ${PROJECT_SOURCE_DIR}/*.qrc
    )

#create library 
add_library(VfHelpers SHARED
    ${SOURCES}
    ${HEADER}
    ${RESOURCES}
    )


#link dependencies
target_link_libraries(VfHelpers 
    PRIVATE
    Qt5::Core
    )

# announce headers - target perspective
target_include_directories(VfHelpers 
    PUBLIC
    $<BUILD_INTERFACE:${MY_LIBRARY_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/VfHelpers>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

#set target Version
set_target_properties(VfHelpers PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(VfHelpers PROPERTIES SOVERSION ${VfHelpers_VERSION_MAJOR})

#generate export header
include(GenerateExportHeader)
generate_export_header(VfHelpers)



#install export header
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/vfhelpers_export.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/VfHelpers
    )




# install library
install(TARGETS VfHelpers
    EXPORT VfHelpersExport
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

# configure *ConfigVersion.cmake
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    VfHelpersConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY SameMinorVersion
    )

# configure *Config.cmake
configure_file(VfHelpersConfig.cmake.in VfHelpersConfig.cmake @ONLY)


# install *Config(Version).cmake
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/VfHelpersConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/VfHelpersConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/VfHelpers
    )

# install targets cmake-files
install(EXPORT VfHelpersExport
    FILE VfHelpersTargets.cmake
    NAMESPACE VeinMeta::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/VfHelpers
    )

# install public headers
install(
    FILES ${HEADER}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/VfHelpers
    )

# spawn out some info on configuration
feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)





