/* ≤‚ ‘¥˙¬Î  
 * SM4/SMS4 algorithm test programme  
 * 2017-4-20  
 */  

#include <string.h>  
#include <stdio.h>  
#include "sm4.h"  

// plain:  0b 0b 2b 4f 54 05 fe f1 e8 a2 64 fc 89 ab 21 0a 0b 0b 2b 4f 54 05 fe f1 e8 a2 64 fc 89 ab 21 0a  
// key:    b1 22 ad 0a 7a 36 2e c3 ab a1 dd ef b3 af 49 15  
// iv:	   11 11 11 11 d1 a1 6c 20 67 70 8a cb d1 a1 6c 20
// ECB cypher: 70 dc 8d 69 65 da 2a 36 7c db a4 63 1c 39 a3 84 70 dc 8d 69 65 da 2a 36 7c db a4 63 1c 39 a3 84 
// CBC cypher: 33 91 0d d4 61 7b f4 3b 17 fc 7c 4c 7c 99 71 9c 6a 85 d9 07 7f 95 87 93 04 9e b0 cd a9 7a a9 ad 

int main()  
{  
	unsigned char key[16] = {0xB1,0x22,0xAD,0x0A,0x7A,0x36,0x2E,0xC3,0xAB,0xA1,0xDD,0xEF,0xB3,0xAF,0x49,0x15}; 
	unsigned char iv[16] = {0x11,0x11,0x11,0x11,0xd1,0xa1,0x6c,0x20,0x67,0x70,0x8a,0xcb,0xd1,0xa1,0x6c,0x20}; 
	unsigned char input[32] =  {0x0B,0x0B,0x2B,0x4F,0x54,0x05,0xFE,0xF1,0xE8,0xA2,0x64,0xFC,0x89,0xAB,0x21,0x0A,
	0x0B,0x0B,0x2B,0x4F,0x54,0x05,0xFE,0xF1,0xE8,0xA2,0x64,0xFC,0x89,0xAB,0x21,0x0A};
	unsigned char output[32];
	sm4_context ctx;  
	unsigned long i;  
	unsigned long len = 32;  

	printf("%-15s","Plain text:");  	
	for(i=0;i<len;i++)  
		printf("%02x ", input[i]);  
	printf("\n");  

	printf("%-15s","Key:");  
	for(i=0;i<16;i++)  
		printf("%02x ", key[i]);  
	printf("\n");  
	
	printf("%-15s","IV:");  
	for(i=0;i<16;i++)  
		printf("%02x ", iv[i]);  
	printf("\n"); 
		
	//sm4 ecb encrypt testing   
	sm4_setkey_enc(&ctx,key);  
	sm4_crypt_ecb(&ctx,1,len,input,output);  

	printf("%-15s","ECB cipher:");  
	for(i=0;i<len;i++)  
		printf("%02x ", output[i]);  
	printf("\n");  

	//sm4 ecb decrypt testing  
	sm4_setkey_dec(&ctx,key);  
	sm4_crypt_ecb(&ctx,0,len,output,output); 
	printf("%-15s","ECB dec plain:");  	
	for(i=0;i<len;i++)  
		printf("%02x ", output[i]);  
	printf("\n");  
	
	//sm4 cbc encrypt testing   
	sm4_setkey_enc(&ctx,key);  
	sm4_crypt_cbc(&ctx,1,len,iv,input,output);  

	printf("%-15s","CBC cipher:");  
	for(i=0;i<len;i++)  
		printf("%02x ", output[i]);  
	printf("\n");  
	
	//sm4 cbc decrypt testing  
	sm4_setkey_dec(&ctx,key);  
	sm4_crypt_cbc(&ctx,0,len,iv,output,output); 
	printf("%-15s","ECB dec plain:");  	
	for(i=0;i<len;i++)  
		printf("%02x ", output[i]);  
	printf("\n");  
	
	return 0;  
} 
