#pragma once
#include <memory>

namespace OneDrive {
	namespace Network {
		class Session;
	}
	namespace Http {

		class HttpRequest;
		class HttpResponse;
		class HttpHeader;

		class HttpClient {

		public:
			HttpClient();
			~HttpClient();

			std::shared_ptr<Network::Session>
				OpenSession(
					const char* agent
					, const char* host
					, const char* port
				);

			void CloseSession(
				std::shared_ptr<Network::Session> handle
			);

			std::shared_ptr<HttpResponse>
				Performe(
					std::shared_ptr<HttpRequest> request
				);

			std::shared_ptr<HttpRequest>
				OpenRequest(
					std::shared_ptr<Network::Session>
					, const char* uri
					, short port
					, const char* body
					, unsigned long long length
				);			

			std::shared_ptr<HttpHeader>
				AppendHeader(
					std::shared_ptr<HttpHeader> header
					, const char* element
				);
		};//class HttpClient
	}//namespace Http
}//namespace OneDrive
