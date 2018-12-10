#pragma once
#include <memory>

namespace OneDrive {

	namespace Network {
		class Session;
	}

	namespace Http {

		class HttpHeader;

		class HttpRequest {
		public:
			HttpRequest();
			~HttpRequest();



		private:
			std::shared_ptr<HttpHeader> m_header;
			std::shared_ptr<Network::Session> m_session;
		};

	}//namespace Http
}//namespace OneDrive
