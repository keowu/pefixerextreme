/*
	Desenvolvido por Keowu(João Vitor) eu espero que você aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja útil para você
	peço encaricidamente que caso você modifique você deixe uma citação para mim eu ficaria muito grato
	esse projetinho apesar de simples(na visão de quem não entende do assunto) demandou muito tempo e
	estudo.
*/
#include "CNUtils.h"

int CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(int RelativeVirtualAddress, IMAGE_SECTION_HEADER* imgSec, size_t sectionCount) {
	for (int i = 0; i < sectionCount; i++) {
	
		if (imgSec[i].VirtualAddress <= RelativeVirtualAddress 
			&& imgSec[i].VirtualAddress + imgSec[i].SizeOfRawData >= RelativeVirtualAddress) {
			
			return imgSec[i].PointerToRawData + (RelativeVirtualAddress - imgSec->VirtualAddress);
		
		}

	}

	return 0;
}