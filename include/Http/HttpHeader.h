#pragma once

namespace OneDrive {
	namespace Http {

		class HttpHeader {

		public:
			HttpHeader() {};
			virtual ~HttpHeader() {};

			virtual void Append(const char* element) = 0;

			virtual void* getHeader() = 0;

		};//class HttpHeader

	}//namespace Http
}//namespace OneDrive
