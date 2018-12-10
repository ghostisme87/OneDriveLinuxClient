#pragma once

namespace OneDrive {
	namespace Network {
		class Session {
		public:
			Session() {};
			virtual ~Session() {};

			virtual void* try_pop() = 0;

			virtual void push(void* handle) = 0;

			virtual int OpenSession(
				const char* userAgent
			) = 0;

			virtual void CloseSession() = 0;
		};
	}//namespace Network
}//namespace OneDrive