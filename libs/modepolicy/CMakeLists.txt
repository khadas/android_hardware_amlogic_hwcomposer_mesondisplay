cmake_minimum_required (VERSION 2.6)
project (meson_mode_policy)

SET(SRC_LIST mode_policy.c mode_ubootenv.c mode_util.c)

ADD_DEFINITIONS(-DLINUX_COMPILE)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR})

add_library(meson_mode_policy SHARED ${SRC_LIST})

SET_TARGET_PROPERTIES(meson_mode_policy PROPERTIES SOVERSION 0 VERSION 0.0.0)

install(TARGETS meson_mode_policy LIBRARY DESTINATION ${LIB_DIR})
install(DIRECTORY include/ DESTINATION ${INCLUDE_DIR})
