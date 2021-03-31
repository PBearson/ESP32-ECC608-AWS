# ESP32 ECC608 EC2

**Deprecation Warning: This project is no longer maintained and may not worked with newer versions of ESP-IDF. Please use [esp-aws-iot](https://github.com/PBearson/esp-aws-iot) instead.**

### Author: Bryan Pearson

Use this repository to build a MQTT/TLS connection between your ESP32 and a remote AWS server while using an ECC608 for hardware-enforced security and crypto acceleration! The ECC608 is a security coprocessor by Microchip and contains tamper-proof key storage of up to 16 keys, hardware acceleration of ECC, AES, RNG, and many other features. In this project, the lightweight "mbedtls" crypto library has been modified to offload functions to the ECC608 where possible. This results in faster authentication with a remote server (between 3 and 8 times faster on average) and better security for your chip, since malware cannot compromise the security key.

To clone this repository, run **git clone --recursive https<span></span>://github.com/PBearson/ESP32-ECC608-EC2**

To use this repository, you will first need to configure the ECC608 by storing a private ECC-P256 key in slot 0; this can be done using several tools including [ACES CE](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/Atmel%20Crypto%20%20Studio%20(ACES)), or any interface that can communicate with the [Crypto Authentication library](https://github.com/MicrochipTech/cryptoauthlib). You also need a valid certificate; CryptoAuthLib may be used to generate a certificate signing request. Then you will need to ensure that the ESP32 can communicate with the ECC608 over I2C. Also, you will need to make sure that the "main/crypto_settings.h" is changed to reflect your own configuration. Finally, create a "main/certs" directory and add the device certificate, the remote server's root certificate, and a placeholder private key. The private key will not actually be used (since the program will use the private key stored in the ECC608), but it is still required in order to compile successfully. This will hopefully be resolved in a future patch.

The contributions of the ECC608 in this project are as follows:
- The private key will provide a valid signature during the challenge-response step of the TLS handshake.
- If the remote server uses an ECC-based signature algorithm, then the public key (generated from the private key) will perform signature verification.
- If the remote server supports ECDH, the ECC608 can be used to establish a secret key with the server. 
- The bulk of code changes to mbedtls are in the files "ecdsa.c" and "ecdh.c" (found in the "mbedtls/library" subdirectory).
- If for whatever reason, these functions need to be disabled (e.g., server does not support ECDH), you can disable them by going to "port/include/mbedtls/esp_config.h" and commenting out "MBEDTLS_ECDSA_SIGN_ALT", "MBEDTLS_ECDSA_VERIFY_ALT", "MBEDTLS_ECDH_GEN_PUBLIC_ALT", or "MBEDTLS_ECDH_COMPUTE_SHARED_ALT".

This project was tested on ESP-IDF release/4.0. It assumes that various components and features of this branch are available.
