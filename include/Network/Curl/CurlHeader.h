#pragma once

#include <Http/HttpHeader.h>
#include <curl/include/curl/curl.h>

namespace OneDrive {
	namespace Network {
		namespace Curl {
			
			class CurlHeader
				: public Http::HttpHeader {

			public:

				CurlHeader();
				~CurlHeader();

				void Append(
					const char* element
				);

				void* getHeader() const;

			private:

				curl_slist * internalHeader = NULL;

			};//class CurlHeader

		}//namespace Curl
	}//namespace Network
}//OneDrive