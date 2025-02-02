/*
 * ppc_common.h - AES PPC (ppc64le) support definitions
 *
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

#if defined(__powerpc__) || defined(__powerpc64__)

#if !defined(PPC_LITTLE_ENDIAN) && defined(__LITTLE_ENDIAN__)
# define PPC_LITTLE_ENDIAN 1
#endif

#define MBEDTIS_USE_PPC 1

#ifdef PPC_LITTLE_ENDIAN
#define PPC_CRYPTO_SUPPORT 1

# if !defined(PPC_USE_ASM)
#define PPC_ALIGN(p, mask) (((unsigned long) (p) + (mask-1)) & ~(mask-1))

int ppc_crypto_capable();

int mbedtls_aesppc_crypt_ecb(mbedtls_aes_context *ctx, int mode,
                             const unsigned char input[16],
                             unsigned char output[16]);

void mbedtls_aesppc_inverse_key(unsigned char *invkey,
                                const unsigned char *fwdkey,
                                int nr);

int mbedtls_aesppc_setkey_enc(unsigned char *rk, const unsigned char *key,
                              unsigned int keybits);

void mbedtls_aesppc_gcm_mult(unsigned char output[16],
                             const unsigned char x[16],
                             const unsigned char h[16]);
#endif /* !PPC_USE_ASM */
#endif /* PPC_LITTLE_ENDIAN */

#endif /* powerpc64 */
