/*
	Desenvolvido por Keowu(Jo�o Vitor) eu espero que voc� aprecie isto e melhore isso
	ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja �til para voc�
	pe�o encaricidamente que caso voc� modifique voc� deixe uma cita��o para mim eu ficaria muito grato
	esse projetinho apesar de simples(na vis�o de quem n�o entende do assunto) demandou muito tempo e
	estudo.
*/
#include "CFile.h"

CFile::CFile(const char* path, const char* modo)
{
	fopen_s(&this->fp, path, modo);
}


bool CFile::lerArquivo(unsigned char* buffer, size_t tamanhoLeitura) {
	return fread_s(buffer, tamanhoLeitura, 1, tamanhoLeitura, this->fp) == tamanhoLeitura;
}


bool CFile::escreverArquivo(unsigned char* buffer, size_t tamanhoEscrita) {
	return fwrite(buffer, 1, tamanhoEscrita, this->fp) == tamanhoEscrita;
}


bool CFile::escreverArquivo(short valor) {
	return fwrite(&valor, sizeof(short), 1, this->fp) == sizeof(short);
}

bool CFile::movePonteiro(long offset) {
	/* NULL � O MESMO QUE O FILE_BEGIN DE ACORDO COM A IMPLEMENTA��O QUE � UMA MACRO PARA ZERO
	*  ACHOU RUIM ? declara a #include <Windows.h> e usa a macro ent�o
	*/
	return fseek(this->fp, offset, NULL) == 0; 
}

bool CFile::movePonteiro(int origem, long offset) {
	return fseek(this->fp, offset, origem) == 0;
}

void CFile::calculeteFileSZ() {
	this->movePonteiro(0L, SEEK_END);

	this->tamanhoArquivo = ftell(this->fp);
	this->movePonteiro(0x00);
}

long CFile::getOffsetAtualArquivo() {
	return ftell(this->fp);
}

CFile::~CFile()
{
	this->movePonteiro(0);
	fclose(fp);
}