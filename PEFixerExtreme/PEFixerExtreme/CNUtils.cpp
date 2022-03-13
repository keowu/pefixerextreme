/*
	Desenvolvido por Keowu(Jo�o Vitor) eu espero que voc� aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja �til para voc�
	pe�o encaricidamente que caso voc� modifique voc� deixe uma cita��o para mim eu ficaria muito grato
	esse projetinho apesar de simples(na vis�o de quem n�o entende do assunto) demandou muito tempo e
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