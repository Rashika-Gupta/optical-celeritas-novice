# Install script for directory: /Users/r1i/Desktop/project/optical-celeritas-novice/OpNovice

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/r1i/Desktop/project/optical-celeritas-novice/OpNovice/build/OpNovice")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/OpNovice" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/OpNovice")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/r1i/Desktop/project/og-git-celeritas/requirements/spack/opt/spack/darwin-m1/zlib-ng-2.2.4-twticoau6hr6bj626ntoe3qfscdlmx6s/lib"
      -delete_rpath "/Users/r1i/Desktop/project/og-git-celeritas/requirements/spack/var/spack/environments/celeritas/.spack-env/view/lib"
      -delete_rpath "/Users/r1i/Desktop/project/forked/celeritas/lib"
      -delete_rpath "/Users/r1i/Desktop/project/og-git-celeritas/requirements/spack/opt/spack/darwin-m1/clhep-2.4.7.1-go2puaxrlioqvr6ihhjticcuscoehfl7/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/OpNovice")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/OpNovice")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/Users/r1i/Desktop/project/optical-celeritas-novice/OpNovice/build/CMakeFiles/OpNovice.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES
    "/Users/r1i/Desktop/project/optical-celeritas-novice/OpNovice/gdml/NoviceExample.gdml"
    "/Users/r1i/Desktop/project/optical-celeritas-novice/OpNovice/gui.mac"
    "/Users/r1i/Desktop/project/optical-celeritas-novice/OpNovice/optPhoton.mac"
    "/Users/r1i/Desktop/project/optical-celeritas-novice/OpNovice/vis.mac"
    "/Users/r1i/Desktop/project/optical-celeritas-novice/OpNovice/OpNovice.in"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/Users/r1i/Desktop/project/optical-celeritas-novice/OpNovice/build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/Users/r1i/Desktop/project/optical-celeritas-novice/OpNovice/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
