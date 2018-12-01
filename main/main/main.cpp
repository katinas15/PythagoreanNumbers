#include <stdio.h>
#include <iostream>

int main() {

	__declspec(align(16))float fmas[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	__declspec(align(16))float fgmas[16];
	int imsize = sizeof(fmas) / sizeof(float);

	float * fptr;
	float * fgptr;

	for (int i = 0; i < imsize; i += 4) {
		fptr = fmas + i;
		fgptr = fgmas + i;
			__asm {
			mov eax, fptr
			movaps xmm0,[eax]
			sqrtps xmm0,xmm0
			mov eax,fgptr
			movaps [eax],xmm0
		}
	}
	for (int i = 0; i < 16; i++) {
		std::cout << fmas[i] << " " << fgmas[i] << std::endl;
	}
	system("pause");

}