#include <Network\Curl\CurlHeader.h>

namespace OneDrive {
	namespace Network {
		namespace Curl{

			

			CurlHeader::CurlHeader()
			{
			}

			CurlHeader::~CurlHeader()
			{
				if (NULL != internalHeader) {
					curl_slist_free_all(internalHeader);
				}
			}

			void CurlHeader::Append(const char * element)
			{
				internalHeader = curl_slist_append(
					internalHeader
					, element
				);
			}

			void * CurlHeader::getHeader() const
			{
				return static_cast<void*>(internalHeader);
			}

		}//namespace Curl
	}//namespace Network
}//namespace OneDrive