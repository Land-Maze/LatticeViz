#include <catch2/catch_test_macros.hpp>
#include <lml/mlwe-fast.h>

// FIXME: After implementing the actual key generation logic, this test should be updated to check for valid keys instead of just 0xFF values
TEST_CASE("MLWE-KEM Key Generation", "[mlwe_fast_kem_keypair]") {
	uint8_t pk[MLWE_FAST_PUBLICKEYBYTES];
	uint8_t sk[MLWE_FAST_SECRETKEYBYTES];

	const int result = mlwe_fast_kem_keypair(pk, sk);
	REQUIRE(result == MLWE_FAST_ERROR_NONE);

	for (const uint8_t i : pk) {
		REQUIRE(i == 0xFF);
	}
	for (const uint8_t i : sk) {
		REQUIRE(i == 0xFF);
	}
}