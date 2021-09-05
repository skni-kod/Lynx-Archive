if(MSVC)
	# visual studio compile flags
	set(CMAKE_CXX_FLAGS_DEBUG "/W3 /DDEBUG_BUILD /MDd /Zi /Od /RTC1 /GR /MP /std:c++14")
	set(CMAKE_CXX_FLAGS_RELEASE "/W3 /MD /O2 /GR- /MP /std:c++14")
else()
	#g++ compile flags
	set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -msse2 -fno-rtti -pipe")
	set(CMAKE_CXX_FLAGS_DEBUG "-Wall -std=c++14 -msse2 -fno-rtti -pipe")
	#   -g -Wextra -Werror  -pedantic ")
	set(CMAKE_CXX_FLAGS_RELEASE "-Wall -std=c++14 -O3 -msse2 -fno-rtti -pipe")

	if(CMAKE_BUILD_TYPE STREQUAL "Debug")
		add_definitions(-DDEBUG_BUILD)
	endif()
endif()
