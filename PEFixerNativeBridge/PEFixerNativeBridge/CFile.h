/*
	Desenvolvido por Keowu(João Vitor) eu espero que você aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja útil para você
	peço encaricidamente que caso você modifique você deixe uma citação para mim eu ficaria muito grato
	esse projetinho apesar de simples(na visão de quem não entende do assunto) demandou muito tempo e
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
	///		Referência ao arquivo
	/// </summary>
	FILE* fp;

	/// <summary>
	///		Atributo de instância(classe) com o tamanho do arquivo
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
	///		Esse método permite ler dados em um aquivo aberto no contexto do sistema
	/// </summary>
	/// <param name="buffer">Buffer de referência no qual deseja-se trabalhar</param>
	/// <param name="tamanhoLeitura">Tamanho do buffer a trabalhar em bytes</param>
	/// <returns>-</returns>
	bool lerArquivo(unsigned char* buffer, size_t tamanhoLeitura);

	/// <summary>
	///		Esse método permite escrever dados em um aquivo aberto no contexto do sistema - Sobrecarga 2º Deitel Polimorfismo
	/// </summary>
	/// <param name="buffer">Buffer de referência no qual deseja-se trabalhar</param>
	/// <param name="tamanhoLeitura">Tamanho do buffer a trabalhar em bytes</param>
	/// <returns>-</returns>
	bool escreverArquivo(unsigned char* buffer, size_t tamanhoEscrita);

	/// <summary>
	///		Esse método permite escrever dados em um aquivo aberto no contexto do sistema - Sobrecarga 2º Deitel Polimorfismo
	///		! IMPORTANTE: MOVA UM PONTEIRO ANTES DA UTILIZAÇÃO DO MESMO 
	/// </summary>
	/// <param name="short">Dado do tipo primitivo short a ser escrito</param>
	/// <returns>-</returns>
	bool escreverArquivo(short valor);

	/// <summary>
	///		Move o ponteiro de arquivo do contexto do arquivo para um offset pré-definido, ou não caso você não passe nada, aí ele assume zero - 2º Deitel Sobrecarga
	/// </summary>
	bool movePonteiro(long offset = 0x00);

	/// <summary>
	///		Move o ponteiro de arquivo do contexto do arquivo para um offset pré-definido, ou não caso você não passe nada, aí ele assume zero - 2º Deitel Sobrecarga
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

