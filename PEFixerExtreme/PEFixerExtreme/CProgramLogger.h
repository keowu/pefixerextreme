/*
	Desenvolvido por Keowu(Jo�o Vitor) eu espero que voc� aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja �til para voc�
	pe�o encaricidamente que caso voc� modifique voc� deixe uma cita��o para mim eu ficaria muito grato
	esse projetinho apesar de simples(na vis�o de quem n�o entende do assunto) demandou muito tempo e
	estudo.
*/
#pragma once
#include "CFile.h"

class CProgramLogger : CFile
{

private:

	/// <summary>
	///		Atributo para armazenar os dados das opera��es de corre��es efetuadas
	/// </summary>
	std::string llog;

public:

	/// <summary>
	///		Construtor da Subclasse CProgramLogger especializa��o de CFile que armazena arquivos de LOG
	/// </summary>
	/// <param name="logPath">Caminho no contexto do sistema para armazenar o arquivo de log</param>
	CProgramLogger(const char* logPath);

	/// <summary>
	///		Esse m�todo d� um append para o atributo de inst�ncia(classe) - 2� Deitel Polimorfismo SOBRECARGA
	/// </summary>
	/// <param name="texto">CSTRING(const char*) com terminador slash n</param>
	void al(const char* texto);

	/// <summary>
	///		Esse m�todo d� um append para o atributo de inst�ncia(classe) - 2� Deitel Polimorfismo SOBRECARGA
	/// </summary>
	/// <param name="texto">CCSTRING(std::string) uma string iostream padr�o CPP</param>
	void al(std::string texto);

	/// <summary>
	///		Esse m�todo formata dados atrav�s de va e organiza, e retorna uma std::string pronto para a utiliza��o
	/// </summary>
	/// <param name="texto">CSTRING(const char*) com terminador slash n | e a devida masc�ra</param>
	/// <param name="...">N argumentos VA, sendo N a quantidade de par�metros que voc� precisa formatar</param>
	/// <returns></returns>
	std::string formateDataSafe(const char* texto, ...);

	
	~CProgramLogger();

};

