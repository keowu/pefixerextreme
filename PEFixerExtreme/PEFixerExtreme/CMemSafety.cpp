/*
	Desenvolvido por Keowu(João Vitor) eu espero que você aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja útil para você
	peço encaricidamente que caso você modifique você deixe uma citação para mim eu ficaria muito grato
	esse projetinho apesar de simples(na visão de quem não entende do assunto) demandou muito tempo e
	estudo.
*/
#include "CMemSafety.h"


unsigned char* CMemSafety::getMemory(size_t tamanho) {
	return reinterpret_cast<unsigned char*>(malloc(
		tamanho
	));
}

bool CMemSafety::safeMemMove(void* destino, void* origem, size_t tamanho) {
	return memcpy_s(
					destino, tamanho,
					origem, tamanho
					) == 0;
}

void CMemSafety::memFlush(void* mem) {
	free(mem);
}

bool CMemSafety::safeMemMove(const char* origem, void* destino, size_t tamanho) {
	return memcpy_s(
		destino, tamanho,
		origem, tamanho
	) == 0;
}