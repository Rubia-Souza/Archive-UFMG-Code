#include <string>
#include <stdexcept>

#include "ExcecoesPPMReader.h"

#include "Excecao.h"

ExcecoesPPMReader::LeituraException::LeituraException(const std::string mensagem) : Excecao(mensagem) {}

ExcecoesPPMReader::LeituraException::~LeituraException() {}

ExcecoesPPMReader::FormatoInvalidoException::FormatoInvalidoException(const std::string mensagem) : Excecao(mensagem) {}

ExcecoesPPMReader::FormatoInvalidoException::~FormatoInvalidoException() {}

ExcecoesPPMReader::FalhaAbrirArquivoException::FalhaAbrirArquivoException(const std::string mensagem) : Excecao(mensagem) {}

ExcecoesPPMReader::FalhaAbrirArquivoException::~FalhaAbrirArquivoException() {}
