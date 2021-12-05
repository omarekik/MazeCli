#pragma once

#include <cstdint>
#include <optional>

struct StartupConfig {
    const bool m_Create;
    const int m_Width;
    const int m_Height;
    const int m_Seed;
    const bool m_Solve;
};

std::optional<const StartupConfig> optionsToStartupConfig(int argc, char* argv[]);
