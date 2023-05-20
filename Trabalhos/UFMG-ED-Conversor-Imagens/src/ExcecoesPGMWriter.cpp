#include <string>
#include <stdexcept>

#include "ExcecoesPGMWriter.h"

#include "Excecao.h"

ExcecoesPGMWriter::CriacaoArquivoSaidaException::CriacaoArquivoSaidaException(const std::string mensagem) : Excecao(mensagem) {}

ExcecoesPGMWriter::CriacaoArquivoSaidaException::~CriacaoArquivoSaidaException() {}
