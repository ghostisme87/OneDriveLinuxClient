#pragma once

#include <deque>
#include <thread>
#include <condition_variable>

namespace OneDrive {
	namespace Utils {

		template<typename T>
		class ts_deque {
		public:

			ts_deque() {}
			~ts_deque() {}

			void push(T t) {
				std::lock_guard<std::mutex> lk(m_mutex);
				m_deque.push_front(t);
				m_cv.notify_all();
			}

			T& try_pop() {
				std::unique_lock<std::mutex> lk(m_mutex);
				m_cv.wait(lk, [this]() {
					return !m_deque.empty();
				});

				T& t = m_deque.front();
				m_deque.pop_front();

				return t;
			}

			void push_back(T t) {
				std::lock_guard<std::mutex> lk(m_mutex);
				m_deque.push_back(t);
				m_cv.notify_all();
			}

			T& try_pop_back() {
				std::unique_lock<std::mutex> lk(m_mutex);
				m_cv.wait(lk, [this]() {
					return !m_deque.empty();
				});
				T& t = m_deque.back();
				m_deque.pop_back();
				return t;
			}

			bool empty() {
				std::unique_lock<std::mutex> lk(m_mutex);
				m_cv.wait(lk);
				return m_deque.empty();
			}

			size_t size() {
				std::unique_lock<std::mutex> lk(m_mutex);
				m_cv.wait(lk);
				return m_deque.size();
			}

		private:
			std::deque<T>				m_deque;
			std::mutex					m_mutex;
			std::condition_variable		m_cv;

		};//class ts_deque

	}//namespace Utils
}//namespace OneDrive
