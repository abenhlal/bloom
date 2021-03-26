add_library(cborg-bloom bloom.c)
target_link_libraries(cborg-bloom PUBLIC cborg-bloom-h)
install(TARGETS cborg-bloom DESTINATION   ${CMAKE_INSTALL_LIBDIR}/cborg)