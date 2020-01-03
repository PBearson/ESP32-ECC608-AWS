cmake_minimum_required(VERSION 3.5)

set(
	srcs
	"lib/cryptoauthlib.c"
	"lib/atca_cfgs.c"
	"lib/atca_command.c"
	"lib/atca_device.c"
	"lib/atca_execution.c"
	"lib/atca_iface.c"

	"lib/basic/atca_basic.c"
	"lib/basic/atca_basic_sign.c"
	"lib/basic/atca_basic_verify.c"
	"lib/basic/atca_basic_nonce.c"
	"lib/basic/atca_basic_random.c"
	"lib/basic/atca_basic_read.c"
	"lib/basic/atca_basic_genkey.c"
	
	"lib/hal/atca_hal.c"
	"lib/hal/hal_esp32_i2c.c"
	"lib/hal/hal_esp32_timer.c"
	
	"lib/crypto/atca_crypto_sw_ecdsa.c"
	"lib/crypto/atca_crypto_sw_rand.c"
	
	"lib/crypto/hashes/sha1_routines.c"
	"lib/crypto/hashes/sha2_routines.c"
	
	"lib/host/atca_host.c")
set(
	dirs
	"lib")

set(
	priv_dirs
	"lib/basic"
	"lib/hal"
	"lib/crypto"
	"lib/crypto/hashes"
	"lib/host")

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS "${dirs}"
	PRIV_INCLUDE_DIRS "${priv_dirs}")

target_compile_options(
	${COMPONENT_LIB} PRIVATE -DESP32 -DATCA_HAL_I2C -DATCA_PRINTF)
