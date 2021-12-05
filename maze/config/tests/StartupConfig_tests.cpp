#include "StartupConfig.h"

#include <gtest/gtest.h>
#include <string>

char arg0[] = "Program name";
char arg1[] = "--create";
char arg2[] = "--width";
char arg3[] = "10";
char arg4[] = "--height";
char arg5[] = "11";
char arg6[] = "--seed";
char arg7[] = "12";

TEST(StartupConfigTests, validOptions_returnsStartupConfig)
{
    char* argv[] = { &arg0[0], &arg1[0], &arg2[0], &arg3[0], &arg4[0]
                    , &arg5[0], &arg6[0], &arg7[0], NULL };
    const auto config = optionsToStartupConfig(8, argv);
    ASSERT_TRUE(config);
    ASSERT_TRUE(config->m_Create);
    ASSERT_EQ(config->m_Width, 10);
    ASSERT_EQ(config->m_Height, 11);
    ASSERT_EQ(config->m_Seed, 12);
}

TEST(StartupConfigTests, helpOption_returnsEmptyStartupConfig)
{
    char help[] = "--help";
    char* argv[] = { &arg0[0], &help[0], NULL };
    const auto config = optionsToStartupConfig(2, argv);
    ASSERT_FALSE(config);
}

TEST(StartupConfigTests, notAllOptions_throws)
{
    char* argv[] = { &arg0[0], &arg1[0], &arg2[0], NULL };
    ASSERT_ANY_THROW(optionsToStartupConfig(3, argv));
}
