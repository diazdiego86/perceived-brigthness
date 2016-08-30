
set(libcolor_SRCS
    mathUtils.h
    SRGBColor.h
    SRGBColor.cpp
)

# Declare the library
add_library(libcolor STATIC
    ${libcolor_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(libcolor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
