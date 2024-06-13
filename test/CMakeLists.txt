add_executable(test_sum test_sum.cpp)
 
# 指定include的目录
target_include_directories(test_sum PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)
 
# 指定lib的目录
target_link_directories(test_sum PUBLIC ${CMAKE_SOURCE_DIR}/lib)
 
target_link_libraries(test_sum lib_sum gtest)
 
# ！！注意！！
# 测试用例的可执行文件的名字必须用 test_ 开始，这样该用例才能够出现在 googleTest 用例树中
# 这个可执行文件并且必须位于 ${workspaceFolder}/bin 目录中，CMake的默认就是输出到这个目录中。
 
# test_sum 是包含googletest用例的可执行文件，add_test 之后可以被CMake来执行
add_test(NAME test COMMAND test_sum)
 
# TODO : 如果有更多的其它可执行文件，可以编译仿照上面的过程编译链接之后通过 add_test 加入到CMake的测试列表中来。
# add_test(NAME test_yourName COMMAND test_yourExeProgram)