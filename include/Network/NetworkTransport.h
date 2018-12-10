#pragma once
#include <memory>

namespace OneDrive {

	namespace Http {
		class HttpRequest;
		class HttpResponse;
	}

	namespace Network {
		class Session;
		class NetworkTransport {
		public:
			NetworkTransport() {}
			virtual ~NetworkTransport() {}

			virtual std::shared_ptr<Session>
				OpenSession(
					const char* agent
				) = 0;

			virtual void CloseSession(
				std::shared_ptr<Session> handle
			) = 0;

			virtual int Connect(
				std::shared_ptr<Session> handle
				, const char* host
				, short port
			) = 0;

			virtual void Disconnect() = 0;

			virtual std::shared_ptr<Http::HttpResponse>
				Perform(
					std::shared_ptr<Http::HttpRequest> request
				) = 0;
		
		};//class NetworkTransport
	}//namespace Network
}//namespace OneDrive
