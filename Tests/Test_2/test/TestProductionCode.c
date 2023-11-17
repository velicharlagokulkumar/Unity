#include "ProductionCode.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ProductionCode);
extern int Counter;

TEST_SETUP(ProductionCode)
{
  //This is run before EACH TEST
  Counter = 0x5a5a;
}

TEST_TEAR_DOWN(ProductionCode)
{
}

TEST(ProductionCode, FindFunction_WhichIsBroken_ShouldReturnZeroIfItemIsNotInList_WhichWorksEvenInOurBrokenCode)
{
  //All of these should pass
  TEST_ASSERT_EQUAL(0, FindFunction_WhichIsBroken(78));
  TEST_ASSERT_EQUAL(0, FindFunction_WhichIsBroken(2));
  TEST_ASSERT_EQUAL(0, FindFunction_WhichIsBroken(33));
  TEST_ASSERT_EQUAL(0, FindFunction_WhichIsBroken(999));
  TEST_ASSERT_EQUAL(0, FindFunction_WhichIsBroken(-1));
}

TEST(ProductionCode, FindFunction_WhichIsBroken_ShouldReturnTheIndexForItemsInList_WhichWillFailBecauseOurFunctionUnderTestIsBroken)
{
  // You should see this line fail in your test summary
  TEST_ASSERT_EQUAL(1, FindFunction_WhichIsBroken(34));
  // Notice the rest of these didn't get a chance to run because the line above failed.
  // Then NEXT test function runs as normal.
  TEST_ASSERT_EQUAL(7, FindFunction_WhichIsBroken(888));
}

TEST(ProductionCode, FunctionWhichReturnsLocalVariable_ShouldReturnTheCurrentCounterValue)
{
    //This should be true because setUp set this up for us before this test
    TEST_ASSERT_EQUAL_HEX(0x5a5a, FunctionWhichReturnsLocalVariable());
    Counter = 0x1234;
    TEST_ASSERT_EQUAL_HEX(0x1234, FunctionWhichReturnsLocalVariable());
}

TEST(ProductionCode, FunctionWhichReturnsLocalVariable_ShouldReturnTheCurrentCounterValueAgain)
{
    //This should be true again because setup was rerun before this test (and after we changed it to 0x1234)
    TEST_ASSERT_EQUAL_HEX(0x5a5a, FunctionWhichReturnsLocalVariable());
}

TEST(ProductionCode, FunctionWhichReturnsLocalVariable_ShouldReturnCurrentCounter_ButFailsBecauseThisTestIsActuallyFlawed)
{
    TEST_ASSERT_EQUAL_HEX(0x5a5a, FunctionWhichReturnsLocalVariable());
}
