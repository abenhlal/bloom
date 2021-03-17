add_library(bloom bloom.c)
target_link_libraries(bloom PUBLIC bloom-h)
install(TARGETS bloom DESTINATION   ${CMAKE_INSTALL_LIBDIR}/cborg)