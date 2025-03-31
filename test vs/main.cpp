#include <iostream>

int main() {

	enum class CountryCode { Russia = 7, China = 86, SriLanka = 94, Andorra = 376 };
	using enum CountryCode;
	CountryCode code = Russia;
	std::cout <<static_cast<int>(code) << std::endl;;

	/*if (7 == Russia) {
		std::cout << 10 << std::endl;
	}*/

	return 0;
}

//int num(CountryCode c) {
//
//}