#include <Http/HttpClient.h>

namespace OneDrive {
	namespace Http {
		HttpClient::HttpClient()
		{
		}

		HttpClient::~HttpClient()
		{
		}

		std::shared_ptr<Network::Session> 
			HttpClient::OpenSession(
				const char * agent
				, const char * host
				, const char * port
			){
			return std::shared_ptr<Network::Session>();
		}

		void HttpClient::CloseSession(
			std::shared_ptr<Network::Session> handle
		){
		}

		std::shared_ptr<HttpResponse> 
			HttpClient::Performe(
				std::shared_ptr<HttpRequest> request
			){
			return std::shared_ptr<HttpResponse>();
		}

		std::shared_ptr<HttpRequest>
			HttpClient::OpenRequest(
				std::shared_ptr<Network::Session>
				, const char* uri
				, short port
				, const char* body
				, unsigned long long length
			) {

		}

		std::shared_ptr<HttpHeader> 
			HttpClient::AppendHeader(
				std::shared_ptr<HttpHeader> header
				, const char * element
			){
			return std::shared_ptr<HttpHeader>();
		}


	}//namespace Http
}//namespace OneDrive