#pragma once

#include <sstream>
#include <string>
#include <cctype>
#include <utility>
#include <unordered_map>

namespace t9spelling {
	template<typename CharType = char>
	using DigitsNumberBySymbol = std::unordered_map<CharType, std::pair<CharType, size_t>>;

	namespace internal {
		const DigitsNumberBySymbol<char> defaultNumberBySymbolDictionary{
			{' ', {'0', 1}},
			{'a', {'2', 1}},
			{'b', {'2', 2}},
			{'c', {'2', 3}},
			{'d', {'3', 1}},
			{'e', {'3', 2}},
			{'f', {'3', 3}},
			{'g', {'4', 1}},
			{'h', {'4', 2}},
			{'i', {'4', 3}},
			{'j', {'5', 1}},
			{'k', {'5', 2}},
			{'l', {'5', 3}},
			{'m', {'6', 1}},
			{'n', {'6', 2}},
			{'o', {'6', 3}},
			{'p', {'7', 1}},
			{'q', {'7', 2}},
			{'r', {'7', 3}},
			{'s', {'7', 4}},
			{'t', {'8', 1}},
			{'u', {'8', 2}},
			{'v', {'8', 3}},
			{'w', {'9', 1}},
			{'x', {'9', 2}},
			{'y', {'9', 3}},
			{'z', {'9', 4}}
		};

		template<typename CharType = char>
		bool validateDigitsNumberMap (const DigitsNumberBySymbol<CharType>& input) {
			if (input.size() == 0) {
				return false;
			}

			for (const auto& [key, pair] : input) {
				if (!std::isdigit(pair.first)) {
					return false;
				}

				if (pair.first == CharType(49)) {
					return false;
				}

				if (pair.second == 0) {
					return false;
				}
			}

			return true;
		}
	}

	class exception : public std::exception {
	public:
		exception(const char* message)
			: std::exception(), msg(message)
		{}

		const char* what () const noexcept override {
			return msg;
		}
	private:
		const char* msg{nullptr};
	};

	template<typename CharType = char>
	std::basic_string<CharType> getDigitsSequenceForString(
		const std::basic_string<CharType>& 		input,
		const DigitsNumberBySymbol<CharType>&	digitsNumberBySymbol = internal::defaultNumberBySymbolDictionary
	) {
		std::basic_stringstream<CharType> result;

		if (!internal::validateDigitsNumberMap(digitsNumberBySymbol)) {
			throw exception("Invalid 'number by symbol' dictionary. Please, check dictionary data: a) no digit '1'; b) no number 0; c) no empty dict; d) digit must be a digit.");
		}

		CharType lastSymbolDigit = '1';

		try {
			for (CharType symbol : input) {
				CharType symbolLowerCase = std::tolower(symbol);

				const auto& [digit, number] = digitsNumberBySymbol.at(symbolLowerCase);

				if (lastSymbolDigit == digit) {
					result << ' ';
				}
				lastSymbolDigit = digit;

				for (size_t i = 0; i < number; ++i) {
					result << digit;
				}
			}
		} catch (std::out_of_range&) {
			throw exception("No expected symbol in dictionary 'number by symbol'. By first, check language of input message.");
		}

		return result.str();
	}
}
