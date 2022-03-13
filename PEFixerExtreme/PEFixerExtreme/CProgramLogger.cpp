/*
	Desenvolvido por Keowu(Jo�o Vitor) eu espero que voc� aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja �til para voc�
	pe�o encaricidamente que caso voc� modifique voc� deixe uma cita��o para mim eu ficaria muito grato
	esse projetinho apesar de simples(na vis�o de quem n�o entende do assunto) demandou muito tempo e
	estudo.
*/
#include "CProgramLogger.h"

CProgramLogger::CProgramLogger(const char* logPath) 
								 : CFile(logPath, "a") {
	this->llog = "";
}

void CProgramLogger::al(const char* texto) {
	this->llog.append(texto).append("\n");
}

void CProgramLogger::al(std::string texto) {
	this->llog.append(texto).append("\n");
}

std::string CProgramLogger::formateDataSafe(const char* mascara, ...) {

	va_list raidenShogunSama;

	__crt_va_start(raidenShogunSama, mascara);

	char formatado[1024] = { 0 };

	vsprintf_s(formatado, mascara, raidenShogunSama);

	__crt_va_end(raidenShogunSama);

	std::string raidenShogunPower(formatado);

	return raidenShogunPower;
}

CProgramLogger::~CProgramLogger() {

	const char* ref = this->llog.c_str();
	this->escreverArquivo((unsigned char *)(ref), this->llog.size());
}