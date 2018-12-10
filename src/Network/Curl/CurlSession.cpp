#include <Network\Curl\CurlSession.h>

namespace OneDrive {
	namespace Network {
		namespace Curl {
			CurlSession::~CurlSession()
			{
			}

			void * CurlSession::try_pop()
			{
				return static_cast<void*>(m_sessions.try_pop());
			}

			void CurlSession::push(void * handle)
			{
				m_sessions.push(static_cast<CURLSH*>(handle));
			}

			int CurlSession::OpenSession(const char * userAgent)
			{
				m_userAgent = userAgent;

				for (unsigned i = 0; i < 4; ++i) {
					CURLSH* handle = curl_share_init();
					if (NULL == handle) {
						return 2;
					}

					curl_share_setopt(
						handle
						, CURLSHOPT_SHARE
						, CURL_LOCK_DATA_CONNECT
					);

					m_sessions.push(handle);
				}

				return 0;
			}

			void CurlSession::CloseSession()
			{
				while (m_sessions.empty()) {
					CURLSH* handle = m_sessions.try_pop();
					
					curl_share_setopt(
						handle
						, CURLSHOPT_UNSHARE
						, CURL_LOCK_DATA_CONNECT
					);

					curl_share_cleanup(handle);
				}
			}
		}//namespace Curl
	}//namespace Network
}//namespace OneDrive