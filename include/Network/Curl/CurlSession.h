#pragma once

#include <Network/Curl/Session.h>
#include <curl\include\curl\curl.h>
#include <Utils\ts_deque.h>
#include <string>

namespace OneDrive {
	namespace Network {
		namespace Curl {
			class CurlSession 
			: public Session {

				CurlSession();
				virtual ~CurlSession();

				virtual void* try_pop();

				virtual void push(void* handle);

				virtual int OpenSession(
					const char* userAgent
				);

				virtual void CloseSession();

			private:

				Utils::ts_deque<CURLSH*>	m_sessions;
				std::string					m_userAgent;

			};//class CurlSession
		}//namespace Curl
	}//namespace Network
}//namespace OneDrive
