set(Main_SRCS  main.cpp)

add_executable(perceived-brightness ${Main_SRCS})

# Specify here the libraries this program depends on
target_link_libraries(perceived-brightness libcolor)

install(TARGETS perceived-brightness DESTINATION bin)