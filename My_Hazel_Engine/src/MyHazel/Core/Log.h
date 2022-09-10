#pragma once
#include "MyHazel/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace MyHazel {
	class Log
	{
		public:
			static void Init();

			inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		private:
			static Ref<spdlog::logger> s_CoreLogger;
			static Ref<spdlog::logger> s_ClientLogger;

	};


}

//Core log macros

#define HZ_CORE_TRACE(...)		::MyHazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_ERROR(...)		::MyHazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_WARN(...)		::MyHazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...)		::MyHazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_FATAL(...)		::MyHazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define HZ_CORE_CRITICAL(...)	::MyHazel::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Clinent log macros

#define HZ_TRACE(...)		::MyHazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_ERROR(...)		::MyHazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_WARN(...)		::MyHazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_INFO(...)		::MyHazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_FATAL(...)		::MyHazel::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define HZ_CRITICAL(...)    ::MyHazel::Log::GetClientLogger()->critical(__VA_ARGS__)