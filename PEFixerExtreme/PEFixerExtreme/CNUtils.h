/*
	Desenvolvido por Keowu(João Vitor) eu espero que você aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja útil para você
	peço encaricidamente que caso você modifique você deixe uma citação para mim eu ficaria muito grato
	esse projetinho apesar de simples(na visão de quem não entende do assunto) demandou muito tempo e
	estudo.
*/
#pragma once
#include <Windows.h>

namespace CNUtils
{
	/// <summary>
	///		Esse método static permite converter um RVA(Relative Virtual Address) para um Offset de arquivo !
	/// </summary>
	/// <param name="RelativeVirtualAddress">RVA, Relative Virtual Address</param>
	/// <param name="imgSec">Ponteiro para a struct IMAGE_SECTION_HEADER</param>
	/// <param name="sectionCount">Quantidade de seções disponíveis no arquivo PE</param>
	/// <returns>O Offset correto</returns>
	int converterRelativeVirtualAddressMemoriaParaOffsetArquivo(int RelativeVirtualAddress, IMAGE_SECTION_HEADER *imgSec, size_t sectionCount);

};