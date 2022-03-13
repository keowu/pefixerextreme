/*
	Desenvolvido por Keowu(João Vitor) eu espero que você aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja útil para você
	peço encaricidamente que caso você modifique você deixe uma citação para mim eu ficaria muito grato
	esse projetinho apesar de simples(na visão de quem não entende do assunto) demandou muito tempo e
	estudo.
*/
#pragma once
#include "CFile.h"

class CProgramLogger : CFile
{

private:

	/// <summary>
	///		Atributo para armazenar os dados das operações de correções efetuadas
	/// </summary>
	std::string llog;

public:

	/// <summary>
	///		Construtor da Subclasse CProgramLogger especialização de CFile que armazena arquivos de LOG
	/// </summary>
	/// <param name="logPath">Caminho no contexto do sistema para armazenar o arquivo de log</param>
	CProgramLogger(const char* logPath);

	/// <summary>
	///		Esse método dá um append para o atributo de instância(classe) - 2º Deitel Polimorfismo SOBRECARGA
	/// </summary>
	/// <param name="texto">CSTRING(const char*) com terminador slash n</param>
	void al(const char* texto);

	/// <summary>
	///		Esse método dá um append para o atributo de instância(classe) - 2º Deitel Polimorfismo SOBRECARGA
	/// </summary>
	/// <param name="texto">CCSTRING(std::string) uma string iostream padrão CPP</param>
	void al(std::string texto);

	/// <summary>
	///		Esse método formata dados através de va e organiza, e retorna uma std::string pronto para a utilização
	/// </summary>
	/// <param name="texto">CSTRING(const char*) com terminador slash n | e a devida mascára</param>
	/// <param name="...">N argumentos VA, sendo N a quantidade de parâmetros que você precisa formatar</param>
	/// <returns></returns>
	std::string formateDataSafe(const char* texto, ...);

	
	~CProgramLogger();

};

