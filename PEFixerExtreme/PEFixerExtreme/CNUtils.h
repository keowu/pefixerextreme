/*
	Desenvolvido por Keowu(Jo�o Vitor) eu espero que voc� aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja �til para voc�
	pe�o encaricidamente que caso voc� modifique voc� deixe uma cita��o para mim eu ficaria muito grato
	esse projetinho apesar de simples(na vis�o de quem n�o entende do assunto) demandou muito tempo e
	estudo.
*/
#pragma once
#include <Windows.h>

namespace CNUtils
{
	/// <summary>
	///		Esse m�todo static permite converter um RVA(Relative Virtual Address) para um Offset de arquivo !
	/// </summary>
	/// <param name="RelativeVirtualAddress">RVA, Relative Virtual Address</param>
	/// <param name="imgSec">Ponteiro para a struct IMAGE_SECTION_HEADER</param>
	/// <param name="sectionCount">Quantidade de se��es dispon�veis no arquivo PE</param>
	/// <returns>O Offset correto</returns>
	int converterRelativeVirtualAddressMemoriaParaOffsetArquivo(int RelativeVirtualAddress, IMAGE_SECTION_HEADER *imgSec, size_t sectionCount);

};