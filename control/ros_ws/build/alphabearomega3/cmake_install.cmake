# Install script for directory: /home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/src/alphabearomega3

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/install")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/build/alphabearomega3/catkin_generated/installspace/alphabearomega3.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/alphabearomega3/cmake" TYPE FILE FILES
    "/home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/build/alphabearomega3/catkin_generated/installspace/alphabearomega3Config.cmake"
    "/home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/build/alphabearomega3/catkin_generated/installspace/alphabearomega3Config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/alphabearomega3" TYPE FILE FILES "/home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/src/alphabearomega3/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/alphabearomega3" TYPE PROGRAM FILES "/home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/build/alphabearomega3/catkin_generated/installspace/sim.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/alphabearomega3" TYPE PROGRAM FILES "/home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/build/alphabearomega3/catkin_generated/installspace/leg_kine.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/alphabearomega3" TYPE PROGRAM FILES "/home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/build/alphabearomega3/catkin_generated/installspace/sim_leg_kine.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/alphabearomega3" TYPE DIRECTORY FILES "/home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/src/alphabearomega3/launch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/alphabearomega3" TYPE DIRECTORY FILES "/home/thomas-xavier/github/Alpha-Bear-Omega-3/control/ros_ws/src/alphabearomega3/worlds")
endif()

