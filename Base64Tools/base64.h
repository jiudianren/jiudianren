#ifndef BASE64_H_
#define BASE64_H_

#define XYSSL_ERR_BASE64_BUFFER_TOO_SMALL -0x0010
#define XYSSL_ERR_BASE64_INVALID_CHARACTER -0x0012

#ifdef __cplusplus
extern "C" {
#endif

/**
* /brief Encode a buffer into base64 format
*
* /param dst destination buffer
* /param dlen size of the buffer
* /param src source buffer
* /param slen amount of data to be encoded
*
* /return 0 if successful, or XYSSL_ERR_BASE64_BUFFER_TOO_SMALL.
* *dlen is always updated to reflect the amount
* of data that has (or would have) been written.
*
* /note Call this function with *dlen = 0 to obtain the
* required buffer size in *dlen
*/
int base64_encode(const unsigned char *src, int slen,unsigned char *dst, int *dlen);

/**
* /brief Decode a base64-formatted buffer
*
* /param dst destination buffer
* /param dlen size of the buffer
* /param src source buffer
* /param slen amount of data to be decoded
*
* /return 0 if successful, XYSSL_ERR_BASE64_BUFFER_TOO_SMALL, or
* XYSSL_ERR_BASE64_INVALID_DATA if the input data is not
* correct. *dlen is always updated to reflect the amount
* of data that has (or would have) been written.
*
* /note Call this function with *dlen = 0 to obtain the
* required buffer size in *dlen
*/
int base64_decode(const unsigned char *src, int slen,unsigned char *dst, int *dlen);

/**
* /brief Checkup routine
*
* /return 0 if successful, or 1 if the test failed
*/
int base64_self_test( int verbose );

#ifdef __cplusplus
}
#endif

#endif /* BASE64_H_ */
