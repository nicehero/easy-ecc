#include "ecc.h"
#include "stdio.h"
int main()
{
	uint8_t p_publicKey[ECC_BYTES+1];
	uint8_t p_privateKey[ECC_BYTES];
	ecc_make_key(p_publicKey,p_privateKey);
	uint8_t p_hash[ECC_BYTES]={3,2,1};
	uint8_t p_signature[ECC_BYTES*2];
	int ret1 = ecdsa_sign(p_privateKey, p_hash,p_signature);
	printf("ret1:%d\n",ret1);
	int ret2 = ecdsa_verify(p_publicKey,p_hash,p_signature);
	printf("ret2:%d\n",ret2);
	p_signature[0] = 0;
	int ret3 = ecdsa_verify(p_publicKey,p_hash,p_signature);
	printf("ret3:%d\n",ret3);
	return 0;
}