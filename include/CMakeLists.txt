add_library(bloom-h INTERFACE)
target_include_directories(bloom-h INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(bloom-h INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/bitset/include)
install(FILES bloom.h DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/cborg)