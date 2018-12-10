#include <Network/Curl/CurlWrapper.h>
#include <Network/Curl/CurlSession.h>

namespace OneDrive {
	namespace Network {
		namespace Curl {
			CurlWrapper::CurlWrapper(){}
			CurlWrapper::~CurlWrapper()
			{
			}
			std::shared_ptr<Session> CurlWrapper::OpenSession(const char * userAgent)
			{
				std::shared_ptr<Session> handle;

				try {
					 handle =
						std::make_shared<CurlSession>();
					handle->OpenSession(userAgent);
				}
				catch (std::bad_alloc e) {
					return nullptr;
				}

				return handle;
			}
		}//namespace Curl
	}//namespace Network
}//namespace OneDrive