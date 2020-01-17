#ifndef GTEST_TEST_H
#define GTEST_TEST_H

#include <string>
#include "gtest/gtest.h"

#if defined (__cplusplus)
extern "C" {
#endif

#ifndef TEST

/* Just for code recognition in the IDE. */
#error "GTest not properly included."
#define DDSCXX_TEST_NAME(suite, test)   DDSCXX_TEST__##suite##_##test
#define DDSCXX_TEST_DECL(suite, test)   void DDSCXX_TEST_NAME(suite, test) (void)
#define DDSCXX_TEST(suite, test, ...)   DDSCXX_TEST_DECL(suite, test)
#define DDSCXX_TEST_F(suite, test, ...) DDSCXX_TEST_DECL(suite, test)
#define DDSCXX_TEST_P(suite, test, ...) DDSCXX_TEST_DECL(suite, test)

#else

#define DDSCXX_TEST(test_suite_name, test_name, ...) \
  TEST(test_suite_name, test_name)

#define DDSCXX_TEST_F(test_fixture, test_name, ...) \
  TEST_F(test_fixture, test_name)

#define DDSCXX_TEST_P(test_case_name, test_name, ...) \
  TEST_P(test_case_name, test_name)

#endif

#if defined (__cplusplus)
}
#endif

#endif /* GTEST_TEST_H */
