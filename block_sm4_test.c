/* 
 * SM4/SMS4 algorithm test programme  
 * 2018-1-13  
 */  

#include <string.h>  
#include <stdio.h>  
#include "sm4.h"  

#define BLOCK_SIZE 512

int main()  
{  
	unsigned char *key = "SJX6K8N59S1L8X2J"; 
	unsigned char *iv = "9JS7N2M9SY1LA78K"; 
	unsigned char input[BLOCK_SIZE] = {0};
	unsigned char output[BLOCK_SIZE] = {0};
	sm4_context ctx;  
	unsigned long i;  
	unsigned long len;  

    snprintf(input, BLOCK_SIZE, "I am a test string! I am testing sm4 algorithm!");
    len = strlen(input);

	printf("%-15s","Plain text:");  	
	printf("%s\n", input);  
	printf("%-15s","Key:");  
	printf("%s\n", key);  
	printf("%-15s","IV:");  
	printf("%s\n", iv); 
		
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
	printf("%s\n", output);  
	
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
	printf("%s\n", output);  
	
	return 0;  
} 
