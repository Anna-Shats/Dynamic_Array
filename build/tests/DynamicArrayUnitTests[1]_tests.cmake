add_test([=[DynamicArrayTest.ConstructorSizeAndValue]=]  /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/bin/DynamicArrayUnitTests [==[--gtest_filter=DynamicArrayTest.ConstructorSizeAndValue]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DynamicArrayTest.ConstructorSizeAndValue]=]  PROPERTIES WORKING_DIRECTORY /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DynamicArrayTest.CopyConstructor]=]  /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/bin/DynamicArrayUnitTests [==[--gtest_filter=DynamicArrayTest.CopyConstructor]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DynamicArrayTest.CopyConstructor]=]  PROPERTIES WORKING_DIRECTORY /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DynamicArrayTest.MoveConstructor]=]  /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/bin/DynamicArrayUnitTests [==[--gtest_filter=DynamicArrayTest.MoveConstructor]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DynamicArrayTest.MoveConstructor]=]  PROPERTIES WORKING_DIRECTORY /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DynamicArrayTest.MoveAssignmentOperator]=]  /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/bin/DynamicArrayUnitTests [==[--gtest_filter=DynamicArrayTest.MoveAssignmentOperator]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DynamicArrayTest.MoveAssignmentOperator]=]  PROPERTIES WORKING_DIRECTORY /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DynamicArrayTest.SubscriptOperator]=]  /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/bin/DynamicArrayUnitTests [==[--gtest_filter=DynamicArrayTest.SubscriptOperator]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DynamicArrayTest.SubscriptOperator]=]  PROPERTIES WORKING_DIRECTORY /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[DynamicArrayTest.AdditionOperator]=]  /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/bin/DynamicArrayUnitTests [==[--gtest_filter=DynamicArrayTest.AdditionOperator]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DynamicArrayTest.AdditionOperator]=]  PROPERTIES WORKING_DIRECTORY /Users/annashats/Desktop/homework/oop_hwk/DynamicArray/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  DynamicArrayUnitTests_TESTS DynamicArrayTest.ConstructorSizeAndValue DynamicArrayTest.CopyConstructor DynamicArrayTest.MoveConstructor DynamicArrayTest.MoveAssignmentOperator DynamicArrayTest.SubscriptOperator DynamicArrayTest.AdditionOperator)
