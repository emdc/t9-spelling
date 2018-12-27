#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <t9spelling.hpp>

TEST_CASE("1. Letters on same digit", "[single-file]") {
	std::string expectedResult = "44 444";
	std::string result = t9spelling::getDigitsSequenceForString<char>("hi");
	
	REQUIRE(result == expectedResult);
}

TEST_CASE("2. Letters on different digits", "[single-file]") {
	std::string expectedResult = "999337777";
	std::string result = t9spelling::getDigitsSequenceForString<char>("yes");

	REQUIRE(result == expectedResult);
}

TEST_CASE("3. Two words", "[single-file]") {
	std::string expectedResult = "4433555 555666096667775553";
	std::string result = t9spelling::getDigitsSequenceForString<char>("hello world");

	REQUIRE(result == expectedResult);
}

TEST_CASE("4. Two words with multiple spaces", "[single-file]") {
	std::string expectedResult = "333666 6660 022 2777";
	std::string result = t9spelling::getDigitsSequenceForString<char>("foo  bar");

	REQUIRE(result == expectedResult);
}

TEST_CASE("5. Empty input string", "[single-file]") {
	std::string expectedResult = "";
	std::string result = t9spelling::getDigitsSequenceForString<char>("");

	REQUIRE(result == expectedResult);
}

TEST_CASE("6. Empty 'number by symbols' dictionary", "[single-file]") {
	REQUIRE_THROWS(t9spelling::getDigitsSequenceForString<char>("result", {}));
}

TEST_CASE("7. 'Number by symbols' dictionary contains digit '1'", "[single-file]") {
	REQUIRE_THROWS(t9spelling::getDigitsSequenceForString<char>("result", {{'a', {'1', 1}}}));
}

TEST_CASE("8. 'Number by symbols' dictionary contains number '0'", "[single-file]") {
	REQUIRE_THROWS(t9spelling::getDigitsSequenceForString<char>("result", {{'a', {'2', 0}}}));
}

TEST_CASE("9. Capital letters don't affect the result", "[single-file]") {
	std::string expectedResult = "999337777";
	std::string result = t9spelling::getDigitsSequenceForString<char>("YeS");

	REQUIRE(result == expectedResult);
}
