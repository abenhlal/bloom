add_executable(test_bloom test_bloom.c)
add_test(test_bloom test_bloom)
target_include_directories(test_bloom PUBLIC ${CMAKE_SOURCE_DIR}/third_party/hash/include)
target_link_libraries(test_bloom PUBLIC cborg-bloom cborg-bitset cborg-hash)