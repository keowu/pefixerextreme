/*
	Desenvolvido por Keowu(Jo�o Vitor) eu espero que voc� aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja �til para voc�
	pe�o encaricidamente que caso voc� modifique voc� deixe uma cita��o para mim eu ficaria muito grato
	esse projetinho apesar de simples(na vis�o de quem n�o entende do assunto) demandou muito tempo e
	estudo.
*/
#pragma once
#include <iostream>
#include <Windows.h>

namespace CMemSafety
{
	/// <summary>
	///		Aloca mem�ria de maneira segura e retorna reinterpretado com unsigned char*
	/// </summary>
	/// <param name="tamanho">Tamanho da aloca��o</param>
	/// <returns>Retorna um ponteiro para o in�cio da loca��o reinterpretada como UCHAR*</returns>
	unsigned char* getMemory(size_t tamanho);

	/// <summary>
	///		Move o conte�do do inicio da aloca��o de uma mem�ria para o inicio da loca��o de outra e com base no tamanho copia os bytes - 2� Deitel Polimorfismo Sobrecarga
	/// </summary>
	/// <param name="destino">Refer�ncia de mem�ria alocada</param>
	/// <param name="origem">Refer�ncia de mem�ria alocada</param>
	/// <param name="tamanho">Tamanho de mem�ria alocada</param>
	/// <returns>True se foi poss�vel mover corretamente e False como nega��o matem�tica da condi��o alterior</returns>
	bool safeMemMove(void *destino, void* origem, size_t tamanho);

	/// <summary>
	///		Move o conte�do do inicio da aloca��o de uma mem�ria para o inicio da loca��o de outra e com base no tamanho copia os bytes - 2� Deitel Polimorfismo Sobrecarga
	/// </summary>
	/// <param name="origem">Refer�ncia de mem�ria alocada reinterpretado como const char*</param>
	/// <param name="destino">Refer�ncia de mem�ria alocada</param>
	/// <param name="tamanho">Tamanho de mem�ria alocada</param>
	/// <returns>True se foi poss�vel mover corretamente e False como nega��o matem�tica da condi��o alterior</returns>
	bool safeMemMove(const char* origem, void* destino, size_t tamanho);

	/// <summary>
	///		Libera uma regi�o mapeada e alocada
	/// </summary>
	/// <param name="mem">Refer�ncia de mem�ria alocada</param>
	void memFlush(void* mem);

};

