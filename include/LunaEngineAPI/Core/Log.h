#pragma once

#include "LunaEngineAPI//Core/Base.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"
// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace GeneralAPIs {

    class Log
    {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
    return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
    return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
    return os << glm::to_string(quaternion);
}

// Core log macros
#define LUN_CORE_TRACE(...)    ::GeneralAPIs::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LUN_CORE_INFO(...)     ::GeneralAPIs::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LUN_CORE_WARN(...)     ::GeneralAPIs::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LUN_CORE_ERROR(...)    ::GeneralAPIs::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LUN_CORE_CRITICAL(...) ::GeneralAPIs::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define LUN_TRACE(...)         ::GeneralAPIs::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LUN_INFO(...)          ::GeneralAPIs::Log::GetClientLogger()->info(__VA_ARGS__)
#define LUN_WARN(...)          ::GeneralAPIs::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LUN_ERROR(...)         ::GeneralAPIs::Log::GetClientLogger()->error(__VA_ARGS__)
#define LUN_CRITICAL(...)      ::GeneralAPIs::Log::GetClientLogger()->critical(__VA_ARGS__)