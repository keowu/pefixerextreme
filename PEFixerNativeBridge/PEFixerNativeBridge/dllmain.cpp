/*
    Desenvolvido por Keowu(João Vitor) eu espero que você aprecie isto e melhore isso
    ou me ajude a melhorar ainda mais, eu fiz isso com carinho espero que seja útil para você
    peço encaricidamente que caso você modifique você deixe uma citação para mim eu ficaria muito grato
    esse projetinho apesar de simples(na visão de quem não entende do assunto) demandou muito tempo e 
    estudo.
*/
#include <iostream>
#include <Windows.h>
#include <sstream>
#include "CFile.h"
#include "CMemSafety.h"
#include "CNUtils.h"
#include "CProgramLogger.h"


/// <summary>
///     Método principal exportado pela DLL para iniciar o procedimento !
/// </summary>
extern "C" __declspec(dllexport) void corrigirArquivoPENativo(
    const char* pePath, const char* logPath, bool opCarrigirAsCaracteristicas,
    bool opCorrigirAlinhamentosRaw, bool opCorrigirTamanhoDaImagem, bool opCorrigirOptionalHeader,
    bool opCorrigiroTamanhoInitDATA, bool opCorrigirInformacoesVersao, bool opCorrigirTamanhoDoHeapDaStack,
    bool opCorrigirDiretorioData, bool opisDLL)
{
    std::cout << "Hello World!\n";

    auto* f = new CFile(pePath, "rb+");
    auto* pLog = new CProgramLogger(logPath);

    auto* buff = CMemSafety::getMemory(sizeof(IMAGE_DOS_HEADER));

    if (!buff)
        throw new std::exception("PROBLEMA AO ALOCAR MEMÓRIA !");


    f->lerArquivo(buff, sizeof(IMAGE_DOS_HEADER));

    auto* imgDos = reinterpret_cast<IMAGE_DOS_HEADER*>(buff);

    if (imgDos->e_magic != 0x5A4D)
        throw new std::exception("ESSE NÃO É UM ARQUIVO PE !");

    f->movePonteiro(imgDos->e_lfanew);

    buff = CMemSafety::getMemory(sizeof(IMAGE_NT_HEADERS));

    if (!buff)
        throw new std::exception("PROBLEMA AO ALOCAR MEMÓRIA !");

    f->lerArquivo(buff, sizeof(IMAGE_NT_HEADERS));

    auto* imgNt = reinterpret_cast<IMAGE_NT_HEADERS*>(buff);

    if (imgNt->Signature != 0x4550)
        throw new std::exception("A ASSINATURA DO CABEÇALHO NT NÃO BATE !");

    if (opCarrigirAsCaracteristicas) {
        bool flag = false;

        if ((imgNt->FileHeader.Characteristics & 0x2000) != 0)
            flag = true;

        //PARA .DLL
        if (!flag && opisDLL) {
            short valor = imgNt->FileHeader.Characteristics + 0x2000;
            f->movePonteiro(imgDos->e_lfanew + 22);
            f->escreverArquivo(valor);
            pLog->al("Foi corrigido as características para essa DLL");
            std::cout << "Foi corrigido as características para essa DLL" << std::endl;
        }

        //PARA .EXE
        if (flag && !opisDLL) {
            short valor = imgNt->FileHeader.Characteristics - 0x2000;
            f->movePonteiro(imgDos->e_lfanew + 22);
            f->escreverArquivo(valor);
            pLog->al("Foi corrigido as características para esse EXE");
            std::cout << "Foi corrigido as características para esse EXE" << std::endl;
        }

    }

    f->movePonteiro(static_cast<long>(imgDos->e_lfanew + 4 + sizeof(IMAGE_FILE_HEADER) + imgNt->FileHeader.SizeOfOptionalHeader));

    buff = CMemSafety::getMemory(imgNt->FileHeader.NumberOfSections * sizeof(IMAGE_SECTION_HEADER));

    if (!buff)
        throw new std::exception("PROBLEMA AO ALOCAR MEMÓRIA !");

    float posicaoDoAquivoContextoAtual = f->getOffsetAtualArquivo();

    f->lerArquivo(buff, sizeof(IMAGE_SECTION_HEADER) * imgNt->FileHeader.NumberOfSections);

    auto* imgSec = reinterpret_cast<IMAGE_SECTION_HEADER*>(buff);

    if (opCorrigirAlinhamentosRaw) {

        for (int i = 0; i < imgNt->FileHeader.NumberOfSections; i++) {

            pLog->al(pLog->formateDataSafe("SEÇÃO IDENTIFICADA: %s", imgSec[i].Name));

            std::cout << imgSec[i].Name << std::endl;

            if (imgSec[i].SizeOfRawData % imgNt->OptionalHeader.FileAlignment != 0) {

                f->movePonteiro(static_cast<long>(
                    posicaoDoAquivoContextoAtual + sizeof(IMAGE_SECTION_HEADER) * i + 16L
                    ));

                int alinhamentoat = imgSec[i].SizeOfRawData % imgNt->OptionalHeader.FileAlignment;

                if (alinhamentoat != 0)
                    alinhamentoat = imgNt->OptionalHeader.FileAlignment - alinhamentoat;

                int novoalinhamento = imgSec[i].SizeOfRawData + alinhamentoat;

                if (i < imgNt->FileHeader.NumberOfSections - 1) {
                    int alinhamentocalculado = imgSec[i + 1].PointerToRawData - imgSec[i].PointerToRawData;
                    if (novoalinhamento > alinhamentocalculado) {
                        novoalinhamento = alinhamentocalculado;
                    }
                }

                f->escreverArquivo(novoalinhamento);
                pLog->al(pLog->formateDataSafe("CORRIGIDO: %X, para %X", i + 1, novoalinhamento));
                std::cout << "CORRIGIDO: " << i + 1 << " para " << novoalinhamento << std::endl;
                imgSec[i].SizeOfRawData = novoalinhamento;
            }

        }
    }

    if (opCorrigirTamanhoDaImagem) {

        if (imgNt->OptionalHeader.SizeOfHeaders % imgNt->OptionalHeader.FileAlignment != 0 || imgNt->OptionalHeader.SizeOfHeaders == 0
            || imgNt->OptionalHeader.SizeOfHeaders > imgSec[0].PointerToRawData) {


            int deslocamentoRaw = imgSec[0].PointerToRawData;
            int alinhamentoCorretoRaw = deslocamentoRaw % imgNt->OptionalHeader.FileAlignment;

            if (alinhamentoCorretoRaw != 0)
                alinhamentoCorretoRaw = imgNt->OptionalHeader.FileAlignment - alinhamentoCorretoRaw;

            deslocamentoRaw += alinhamentoCorretoRaw;
            f->movePonteiro(imgDos->e_lfanew + 84);
            f->escreverArquivo(deslocamentoRaw);

            imgNt->OptionalHeader.SizeOfHeaders = deslocamentoRaw;
            pLog->al(pLog->formateDataSafe("CORRIGIDO O TAMANHO DO CABEÇALHO PARA UM VALOR CALCULADO: %X", deslocamentoRaw));
            std::cout << "CORRIGIDO O TAMANHO DO CABEÇALHO PARA UM VALOR CALCULADO: " << deslocamentoRaw << std::endl;
        }
    }

    int calculadovalorhz = imgNt->OptionalHeader.SizeOfHeaders % imgNt->OptionalHeader.SectionAlignment;

    if (calculadovalorhz != 0)
        calculadovalorhz = imgNt->OptionalHeader.SectionAlignment - calculadovalorhz;

    int calculadoHsumz = imgNt->OptionalHeader.SizeOfHeaders + calculadovalorhz;
    int tempVar1 = 0;
    int tempVar2 = 0;
    int tempVar3 = 0;
    int tempVar4 = 0;
    int tempVar5 = 0;
    for (int i = 0; i < imgNt->FileHeader.NumberOfSections; i++) {

        calculadovalorhz = imgSec[i].Misc.VirtualSize % imgNt->OptionalHeader.SectionAlignment;
        if (calculadovalorhz != 0)
            calculadovalorhz = imgNt->OptionalHeader.SectionAlignment - calculadovalorhz;
        calculadoHsumz = calculadoHsumz + imgSec[i].Misc.VirtualSize + calculadovalorhz;
        int tempVar6 = 0;

        unsigned char ptrReferenceBySection[8]{ 0 };
        CMemSafety::safeMemMove(ptrReferenceBySection, imgSec[i].Name, 8);

        if (((long)imgSec[i].Characteristics & (long)((unsigned long)0xFFFFFFFFFF000000)) == 0x60000000
            && ((imgSec[i].Characteristics & 0xFF) == 32 || (imgSec[i].Characteristics & 0xFF) == 0)) {

            //Validando sequencia de assinatura no IMAGE_SECTION_HEADER: 2E 74 65 78 74 00 00 00
            if (*ptrReferenceBySection == 0x2E && *(ptrReferenceBySection + 1) == 0x74
                && *(ptrReferenceBySection + 2) == 0x65 && *(ptrReferenceBySection + 3) == 0x78
                && *(ptrReferenceBySection + 4) == 0x74 && *(ptrReferenceBySection + 5) == 0
                && *(ptrReferenceBySection + 6) == 0 && *(ptrReferenceBySection + 7) == 0) {

                tempVar6 = 1;

            }
        }

        if (((long)imgSec[i].Characteristics & (long)((unsigned long)0xFFFFFFFFFF000000)) == 0x40000000
            && ((imgSec[i].Characteristics & 0xFF) == 0x40 || (imgSec[i].Characteristics & 0xFF) == 0))
        {
            //Validando sequencia de assinatura no IMAGE_SECTION_HEADER: 2E 72 64 61 74 61 00 00
            if (*ptrReferenceBySection == 0x2E && *(ptrReferenceBySection + 1) == 0x72
                && *(ptrReferenceBySection + 2) == 0x64 && *(ptrReferenceBySection + 3) == 0x61
                && *(ptrReferenceBySection + 4) == 0x74 && *(ptrReferenceBySection + 5) == 0x61
                && *(ptrReferenceBySection + 6) == 0 && *(ptrReferenceBySection + 7) == 0)
            {
                tempVar6 = 2;
            }
        }

        if (((long)imgSec[i].Characteristics & (long)((unsigned long)0xFFFFFFFFFF000000)) == (long)((unsigned long)0xFFFFFFFFC0000000)
            && ((imgSec[i].Characteristics & 0xFF) == 64 || (imgSec[i].Characteristics & 0xFF) == 0))
        {
            //Validando sequencia de assinatura no IMAGE_SECTION_HEADER: 2E 72 64 61 74 61 00 00
            if (*ptrReferenceBySection == 0x2E && *(ptrReferenceBySection + 1) == 0x64
                && *(ptrReferenceBySection + 2) == 0x61 && *(ptrReferenceBySection + 3) == 0x74
                && *(ptrReferenceBySection + 4) == 0x74 && *(ptrReferenceBySection + 5) == 0
                && *(ptrReferenceBySection + 6) == 0 && *(ptrReferenceBySection + 7) == 0)
            {
                tempVar6 = 2;
            }
        }

        if ((imgSec[i].Characteristics & 0xFF) == 32 || tempVar6 == 1)
        {
            tempVar1 += imgSec[i].SizeOfRawData;
            if (tempVar4 == 0)
            {
                tempVar4 = imgSec[i].VirtualAddress;
            }
        }
        if ((imgSec[i].Characteristics & 0xFF) == 64 || tempVar6 == 2)
        {
            tempVar2 += imgSec[i].SizeOfRawData;
            if (tempVar5 == 0)
            {
                tempVar5 = imgSec[i].VirtualAddress;
            }
        }
        if ((imgSec[i].Characteristics & 0xFF) == 128)
        {
            tempVar3 += imgSec[i].SizeOfRawData;
            if (tempVar5 == 0)
            {
                tempVar5 = imgSec[i].VirtualAddress;
            }
        }
    }

    if (opCorrigirTamanhoDaImagem && calculadoHsumz != imgNt->OptionalHeader.SizeOfImage) {
        f->movePonteiro(imgDos->e_lfanew + 80);
        f->escreverArquivo(calculadoHsumz);
        pLog->al(pLog->formateDataSafe("O tamanho correto da imagem: %X", calculadoHsumz));
        std::cout << "O tamanho correto da imagem: " + calculadoHsumz << std::endl;
    }

    if (opCorrigirOptionalHeader) {

        if (tempVar1 != imgNt->OptionalHeader.SizeOfCode && tempVar1 != 0) {
            f->movePonteiro(imgDos->e_lfanew + 28);
            f->escreverArquivo(tempVar1);
            pLog->al(pLog->formateDataSafe("Corrigido OptionalHeader sizeofcode: %X", tempVar1));
            std::cout << "Corrigido OptionalHeader sizeofcode: " << tempVar1 << std::endl;
        }

        if (tempVar3 != imgNt->OptionalHeader.SizeOfUninitializedData) {
            f->movePonteiro(imgDos->e_lfanew + 36);
            f->escreverArquivo(tempVar3);
            pLog->al(pLog->formateDataSafe("Corrigido OptionalHeader SizeOfUninitializedData: %X", tempVar3));
            std::cout << "Corrigido OptionalHeader SizeOfUninitializedData" << std::endl;
        }

        if (CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
            imgNt->OptionalHeader.BaseOfCode,
            imgSec, imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 44);
            f->escreverArquivo(tempVar4);
            pLog->al(pLog->formateDataSafe("Corrigido OptionalHeader BaseOfCode: %X", tempVar4));
            std::cout << "Corrigido OptionalHeader BaseOfCode" << std::endl;
        }


        if (CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
            imgNt->OptionalHeader.BaseOfData,
            imgSec, imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 48);
            f->escreverArquivo(tempVar5);
            pLog->al(pLog->formateDataSafe("Corrigido OptionalHeader BaseOfData: %X", tempVar5));
            std::cout << "Corrigido OptionalHeader BaseOfData: " << std::endl;
        }

    }

    if (opCorrigiroTamanhoInitDATA && tempVar2 != imgNt->OptionalHeader.SizeOfInitializedData) {

        f->movePonteiro(imgDos->e_lfanew + 32);
        f->escreverArquivo(tempVar2);
        pLog->al(pLog->formateDataSafe("Corrigido OptionalHeader SizeOfInitData: %X", tempVar2));
        std::cout << "Corrigido OptionalHeader SizeOfInitData: " << std::endl;
    }


    if (opCorrigirInformacoesVersao) {

        if (imgNt->OptionalHeader.MajorLinkerVersion <= 0 || imgNt->OptionalHeader.MajorLinkerVersion > 100) {
            f->movePonteiro(imgDos->e_lfanew + 26);
            f->escreverArquivo(8);
            pLog->al(pLog->formateDataSafe("Definido OptionalHeader.MajorLinkerVersion para %d", 8));
            std::cout << "Definido OptionalHeader.MajorLinkerVersion para 8" << std::endl;
        }

        if (imgNt->OptionalHeader.MinorLinkerVersion > 100) {
            f->movePonteiro(imgDos->e_lfanew + 27);
            f->escreverArquivo(0);
            pLog->al(pLog->formateDataSafe("Definido OptionalHeader.MinorLinkerVersion para %d", 0));
            std::cout << "Definido OptionalHeader.MinorLinkerVersion para 0" << std::endl;
        }

        if (imgNt->OptionalHeader.MajorOperatingSystemVersion <= 0 || imgNt->OptionalHeader.MajorOperatingSystemVersion > 30) {
            f->movePonteiro(imgDos->e_lfanew + 64);
            f->escreverArquivo(4);
            pLog->al(pLog->formateDataSafe("Definido OptionalHeader.MajorOperatingSystemVersion para %d", 4));
            std::cout << "Definido OptionalHeader.MajorOperatingSystemVersion para 4" << std::endl;
        }

        if (imgNt->OptionalHeader.MinorOperatingSystemVersion < 0 || imgNt->OptionalHeader.MinorOperatingSystemVersion > 30) {
            f->movePonteiro(imgDos->e_lfanew + 66);
            f->escreverArquivo(0);
            pLog->al(pLog->formateDataSafe("Definido OptionalHeader.MinorOperatingSystemVersion para %d", 0));
            std::cout << "Definido OptionalHeader.MinorOperatingSystemVersion para 0" << std::endl;
        }

        if (imgNt->OptionalHeader.MajorImageVersion < 0) {
            f->movePonteiro(imgDos->e_lfanew + 68);
            f->escreverArquivo(0);
            pLog->al(pLog->formateDataSafe("Definido OptionalHeader.MajorImageVersion para %d", 0));
            std::cout << "Definido OptionalHeader.MajorImageVersion para 0" << std::endl;
        }

        if (imgNt->OptionalHeader.MinorImageVersion != 0) {
            f->movePonteiro(imgDos->e_lfanew + 70);
            f->escreverArquivo(0);
            pLog->al(pLog->formateDataSafe("Definido OptionalHeader.MinorImageVersion para %d", 0));
            std::cout << "Definido OptionalHeader.MinorImageVersion para 0" << std::endl;
        }

        if (imgNt->OptionalHeader.MajorSubsystemVersion <= 0 || imgNt->OptionalHeader.MajorSubsystemVersion > 30) {
            f->movePonteiro(imgDos->e_lfanew + 72);
            f->escreverArquivo(4);
            pLog->al(pLog->formateDataSafe("Definido OptionalHeader.MajorSubsystemVersion para %d", 4));
            std::cout << "Definido OptionalHeader.MajorSubsystemVersion para 4" << std::endl;
        }

        if (imgNt->OptionalHeader.MinorSubsystemVersion != 0) {
            f->movePonteiro(imgDos->e_lfanew + 74);
            f->escreverArquivo(0);
            pLog->al(pLog->formateDataSafe("Definido OptionalHeader.MinorSubsystemVersion para %d", 0));
            std::cout << "Definido OptionalHeader.MinorSubsystemVersion para 0" << std::endl;
        }

        if (imgNt->OptionalHeader.Win32VersionValue != 0) {
            f->movePonteiro(imgDos->e_lfanew + 76);
            f->escreverArquivo(0);
            pLog->al(pLog->formateDataSafe("Definido OptionalHeader.Win32VersionValue para %d", 0));
            std::cout << "Definido OptionalHeader.Win32VersionValue para 0" << std::endl;
        }

    }


    if (opCorrigirTamanhoDoHeapDaStack) {


        if (imgNt->OptionalHeader.SizeOfStackReserve != 0x100000)
        {
            f->movePonteiro(imgDos->e_lfanew + 96);
            f->escreverArquivo(0x100000);
            pLog->al("Definido OptionalHeader.SizeOfStackReserve para 0x100000");
            std::cout << "Definido OptionalHeader.SizeOfStackReserve para 0x100000" << std::endl;
        }
        if (imgNt->OptionalHeader.SizeOfStackCommit != 0x1000)
        {
            f->movePonteiro(imgDos->e_lfanew + 100);
            f->escreverArquivo(0x1000);
            pLog->al("Definido OptionalHeader.SizeOfStackCommit para 0x1000");
            std::cout << "Definido OptionalHeader.SizeOfStackCommit para 0x1000" << std::endl;
        }
        if (imgNt->OptionalHeader.SizeOfHeapReserve != 0x100000)
        {
            f->movePonteiro(imgDos->e_lfanew + 104);
            f->escreverArquivo(0x100000);
            pLog->al("Definido OptionalHeader.SizeOfHeapReserve para 0x100000");
            std::cout << "Definido OptionalHeader.SizeOfHeapReserve para 0x100000" << std::endl;
        }
        if (imgNt->OptionalHeader.SizeOfHeapCommit != 0x1000)
        {
            f->movePonteiro(imgDos->e_lfanew + 108);
            f->escreverArquivo(0x1000);
            pLog->al("Definido OptionalHeader.SizeOfHeapCommit para 0x1000");
            std::cout << "Definido OptionalHeader.SizeOfHeapCommit para 0x1000" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY ExportDirectory
    if (imgNt->OptionalHeader.DataDirectory[0].VirtualAddress != 0) {
        if (opCorrigirDiretorioData
            && CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[0].VirtualAddress, imgSec, imgNt->FileHeader.NumberOfSections) == 0) {
            f->movePonteiro(imgDos->e_lfanew + 120);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY ExportDirectory para 0");
            std::cout << "Definido OptionalHeader.DataDirectory.VirtualAddress para 0" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY ImportDirectory
    if (imgNt->OptionalHeader.DataDirectory[1].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[1].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 128);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY ImportDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY ImportDirectory para 0" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY ResourceDirectory
    if (imgNt->OptionalHeader.DataDirectory[2].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[2].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 136);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY ResourceDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY ResourceDirectory para 0" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY ExceptionDirectory
    if (imgNt->OptionalHeader.DataDirectory[3].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[3].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 144);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY ExceptionDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY ExceptionDirectory para 0" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY SecurityDirectory
    if (imgNt->OptionalHeader.DataDirectory[4].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[4].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 152);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY SecurityDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY SecurityDirectory para 0" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY RelocationDirectory
    if (imgNt->OptionalHeader.DataDirectory[5].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[5].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 160);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY RelocationDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY RelocationDirectory para 0" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY DebugDirectory
    if (imgNt->OptionalHeader.DataDirectory[6].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[6].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 168);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY DebugDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY DebugDirectory para 0" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY ArchitectureDirectory
    if (imgNt->OptionalHeader.DataDirectory[7].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[7].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 176);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY ArchitectureDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY ArchitectureDirectory para 0" << std::endl;
        }
    }

    // indice 8 é reservado pela Microsoft -> IMAGE_DATA_DIRECTORY Reserved, não necessário corrigir isso!

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY TLSDirectory
    if (imgNt->OptionalHeader.DataDirectory[9].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[9].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 192);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY TLSDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY TLSDirectory para 0" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY ConfigurationDirectory
    if (imgNt->OptionalHeader.DataDirectory[10].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[10].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 200);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY ConfigurationDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY ConfigurationDirectory para 0" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY BoundImportDirectory
    if (imgNt->OptionalHeader.DataDirectory[11].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[11].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 208);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY BoundImportDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY BoundImportDirectory para 0" << std::endl;
        }
    }

    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY ImportAddressTableDirectory
    if (imgNt->OptionalHeader.DataDirectory[12].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[12].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 216);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY ImportAddressTableDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY ImportAddressTableDirectory para 0" << std::endl;
        }
    }


    //Para corrigir o RVA de IMAGE_DATA_DIRECTORY DelayImportDirectory
    if (imgNt->OptionalHeader.DataDirectory[13].VirtualAddress != 0) {
        if (opCorrigirDiretorioData &&
            CNUtils::converterRelativeVirtualAddressMemoriaParaOffsetArquivo(
                imgNt->OptionalHeader.DataDirectory[13].VirtualAddress, imgSec,
                imgNt->FileHeader.NumberOfSections) == 0)
        {
            f->movePonteiro(imgDos->e_lfanew + 224);
            f->escreverArquivo(0);
            pLog->al("Definido RVA de IMAGE_DATA_DIRECTORY DelayImportDirectory para 0");
            std::cout << "Definido RVA de IMAGE_DATA_DIRECTORY DelayImportDirectory para 0" << std::endl;
        }
    }


    CMemSafety::memFlush(buff);
    CMemSafety::memFlush(imgDos);
    CMemSafety::memFlush(imgNt);
    f->~CFile();
    pLog->~CProgramLogger();
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

