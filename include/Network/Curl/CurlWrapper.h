#pragma once

#include <curl\include\curl\curl.h>
#include <Network/NetworkTransport.h>

namespace OneDrive {
	namespace Network {
		namespace Curl {

			class CurlWrapper :
				public NetworkTransport {
			public:

				CurlWrapper();
				virtual ~CurlWrapper();

				virtual std::shared_ptr<Session>
					OpenSession(
						const char* userAgent
					);

				virtual void CloseSession(
					std::shared_ptr<Session> session
				);

			};//class CurlWriapper

		}//namespace Curl
	}//namespace Network
}//namespace OneDrive
