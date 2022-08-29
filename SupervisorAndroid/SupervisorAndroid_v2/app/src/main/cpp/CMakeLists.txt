# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("supervisorandroid_v2")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp
        )

add_library( # Sets the name of the library.
        ControlSupervisor

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ControlSupervisor.cpp
        )

add_library( # Sets the name of the library.
        DataCommunication

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        DataCommunication.cpp
        )

add_library( # Sets the name of the library.
        DataCommunicationAndroid

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        DataCommunicationAndroid.cpp
        )

add_library( # Sets the name of the library.
        List

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        List.cpp
        )

add_library( # Sets the name of the library.
        Node

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        Node.cpp
        )

add_library( # Sets the name of the library.
        ProcessingDataList

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ProcessingDataList.cpp
        )
# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
target_link_libraries( # Specifies the target library.
        native-lib
        ControlSupervisor
        )

target_link_libraries( # Specifies the target library.
        ControlSupervisor
        DataCommunicationAndroid
        )

target_link_libraries( # Specifies the target library.
        ControlSupervisor
        DataCommunication
        )

target_link_libraries( # Specifies the target library.
        ControlSupervisor
        List
        )

target_link_libraries( # Specifies the target library.
        ControlSupervisor
        Node
        )

target_link_libraries( # Specifies the target library.
        ControlSupervisor
        ProcessingDataList
        )

target_link_libraries( # Specifies the target library.
        native-lib
        ControlSupervisor
        DataCommunication
        DataCommunicationAndroid
        List
        Node
        ProcessingDataList

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib} )