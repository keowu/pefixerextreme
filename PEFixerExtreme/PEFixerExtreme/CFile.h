/*
	Desenvolvido por Keowu(Jo�o Vitor) eu espero que voc� aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja �til para voc�
	pe�o encaricidamente que caso voc� modifique voc� deixe uma cita��o para mim eu ficaria muito grato
	esse projetinho apesar de simples(na vis�o de quem n�o entende do assunto) demandou muito tempo e
	estudo.
*/
#pragma once
#include <iostream>

class CFile
{

private:

	/// <summary>
	///		Calcula o tamanho do arquivo
	/// </summary>
	void calculeteFileSZ();

	/// <summary>
	///		Refer�ncia ao arquivo
	/// </summary>
	FILE* fp;

	/// <summary>
	///		Atributo de inst�ncia(classe) com o tamanho do arquivo
	/// </summary>
	long tamanhoArquivo;


public:
	/// <summary>
	///		Construtor da classe CFile utilizada para trabalhar com arquivos de maneira otimizada e organizada
	/// </summary>
	/// <param name="path">Caminho no contexto do sistema para o arquivo que deseja trabalhar</param>
	/// <param name="modo">Modo de acesso</param>
	CFile(const char* path, const char* modo);

	
	/// <summary>
	///		Esse m�todo permite ler dados em um aquivo aberto no contexto do sistema
	/// </summary>
	/// <param name="buffer">Buffer de refer�ncia no qual deseja-se trabalhar</param>
	/// <param name="tamanhoLeitura">Tamanho do buffer a trabalhar em bytes</param>
	/// <returns>-</returns>
	bool lerArquivo(unsigned char* buffer, size_t tamanhoLeitura);

	/// <summary>
	///		Esse m�todo permite escrever dados em um aquivo aberto no contexto do sistema - Sobrecarga 2� Deitel Polimorfismo
	/// </summary>
	/// <param name="buffer">Buffer de refer�ncia no qual deseja-se trabalhar</param>
	/// <param name="tamanhoLeitura">Tamanho do buffer a trabalhar em bytes</param>
	/// <returns>-</returns>
	bool escreverArquivo(unsigned char* buffer, size_t tamanhoEscrita);

	/// <summary>
	///		Esse m�todo permite escrever dados em um aquivo aberto no contexto do sistema - Sobrecarga 2� Deitel Polimorfismo
	///		! IMPORTANTE: MOVA UM PONTEIRO ANTES DA UTILIZA��O DO MESMO 
	/// </summary>
	/// <param name="short">Dado do tipo primitivo short a ser escrito</param>
	/// <returns>-</returns>
	bool escreverArquivo(short valor);

	/// <summary>
	///		Move o ponteiro de arquivo do contexto do arquivo para um offset pr�-definido, ou n�o caso voc� n�o passe nada, a� ele assume zero - 2� Deitel Sobrecarga
	/// </summary>
	bool movePonteiro(long offset = 0x00);

	/// <summary>
	///		Move o ponteiro de arquivo do contexto do arquivo para um offset pr�-definido, ou n�o caso voc� n�o passe nada, a� ele assume zero - 2� Deitel Sobrecarga
	/// </summary>
	/// <param name="origem">Offset de origem</param>
	/// <param name="offset">Offset de destino</param>
	/// <returns>-</returns>
	bool movePonteiro(int origem = 0, long offset = 0x00);

	/// <summary>
	///		Retorna o atual offset de um arquivo aberto
	/// </summary>
	long getOffsetAtualArquivo();

	
	~CFile();

};

