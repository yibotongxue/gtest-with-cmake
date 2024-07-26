find_package(GTest REQUIRED)

add_executable(count_test count_test.cpp)
target_link_libraries(count_test
 PRIVATE
  GTest::GTest
  count)

add_test(count_gtests count_test)

add_executable(fill_test fill_test.cpp)
target_link_libraries(fill_test
 PRIVATE
  GTest::GTest
  fill)

add_test(fill_gtests fill_test)

add_executable(inner_product_test inner_product_test.cpp)
target_link_libraries(inner_product_test
 PRIVATE
  GTest::GTest
   inner_product)

add_test(innerproduct_gtests inner_product_test)