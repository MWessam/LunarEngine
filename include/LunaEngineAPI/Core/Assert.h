#include "Core/Base.h"
#include "Core/Log.h"
#include <filesystem>
#ifdef LUN_ENABLE_ASSERT

	#define LUN_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { LUN##type##ERROR(msg, __VA_ARGS__); LUN_DEBUGBREAK(); } }
	#define LUN_INTERNAL_ASSERT_WITH_MSG(type, check, ...) LUN_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define LUN_INTERNAL_ASSERT_NO_MSG(type, check) LUN_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", LUN_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define LUN_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define LUN_INTERNAL_ASSERT_GET_MACRO(...) LUN_EXPAND_MACRO( LUN_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, LUN_INTERNAL_ASSERT_WITH_MSG, LUN_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define LUN_ASSERT(...) LUN_EXPAND_MACRO( LUN_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define LUN_CORE_ASSERT(...) LUN_EXPAND_MACRO( LUN_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define LUN_ASSERT(...)
#define LUN_CORE_ASSERT(...)
#endif