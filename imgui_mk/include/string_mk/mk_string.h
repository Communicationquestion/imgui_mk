#pragma once
#include<string>
#include<string_view>
#include <iostream>
namespace mk {
	template<std::size_t N = 15>
	class string {
	public:
		string() {
			std::memset(m_cstr, 0, N);
			m_string = m_cstr;
			size = 0;
		}
		string(string& str) {
			//constexpr size_t count = sizeof(str.m_cstr);
			if constexpr(N >= sizeof(str.m_cstr)) {
				std::snprintf(this->m_cstr, sizeof(m_cstr), str.m_cstr);
				this->m_string = this->m_cstr;
				this->size = str.size;
			} else {
				std::exit(EXIT_FAILURE);
			}
		}
		string(const char* str) {
			std::memset(m_cstr, 0, N);
			if constexpr(N >= sizeof(str)) {
				std::snprintf(this->m_cstr, sizeof(m_cstr), str);
				this->m_string = this->m_cstr;
				this->size = sizeof(str);
			} else {
				std::exit(EXIT_FAILURE);
			}
		}

		string(string&& str) {
			if(this == &str) {
				return *this;
			}

			std::memset(m_cstr, 0, N);
			if constexpr(N >= sizeof(str.m_cstr)) {
				std::cout << "move" << std::endl;
				//std::snprintf(this->m_cstr, sizeof(m_cstr), str);
				//this->m_cstr = str.m_cstr;
				this->m_string = str.m_string;
				this->size = str.size;
				return *this;
			} else {
				std::exit(EXIT_FAILURE);
			}
		}
		string& operator=(string& str) {
			if(this == &str) {
				return *this;
			}
			std::memset(m_cstr, 0, N);
			if constexpr(N >= sizeof(str.m_cstr)) {
				std::snprintf(this->m_cstr, sizeof(m_cstr), str.m_cstr);
				this->m_string = this->m_cstr;
				this->size = str.size;
				return *this;
			} else {
				std::exit(EXIT_FAILURE);
			}
		}
		string& operator=(string&& str) {

			if(this == &str) {
				return *this;
			}

			std::memset(m_cstr, 0, N);
			if constexpr(N >= sizeof(str.m_cstr)) {
				std::cout << "move" << std::endl;
				//std::snprintf(this->m_cstr, sizeof(m_cstr), str);
				//this->m_cstr = str.m_cstr;
				this->m_string = str.m_string;
				this->size = str.size;

				//				str.m_cstr = NULL;
								//str.m_string = nullptr;
				return *this;
			} else {
				std::exit(EXIT_FAILURE);
			}
		}
		string& operator=(char* str) {
			std::memset(m_cstr, 0, N);
			if constexpr(N >= sizeof(str)) {
				std::snprintf(this->m_cstr, sizeof(m_cstr), str);
				this->m_string = this->m_cstr;
				this->size = sizeof(str);
				return *this;
			} else {
				std::exit(EXIT_FAILURE);
			}
		}


		friend std::ostream& operator<<(std::ostream& os, const string& str) {
			return os << str.m_string.data();
		}

		~string() {

		}
		std::string std_str() {
			return std::string(m_cstr);
		}

		std::string_view str_view() {
			return m_string;
		}
		char* data() {
			return m_cstr;
		}
	private:
		char m_cstr[N];
		std::string_view m_string;
		size_t size;
	};


}
