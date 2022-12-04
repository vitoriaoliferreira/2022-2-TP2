#include "ConsoleText.h"
#include <vector>

int ConsoleText::getIntOption(bool(validateEntrada)(int), const std::string &erroMessage)
{
    std::string opSelect;
    std::getline(std::cin, opSelect);

    try
    {
        int op = std::stoi(opSelect, nullptr, 10);
        if (validateEntrada(op))
        {
            throw std::invalid_argument(erroMessage);
        }

        return op;
    }
    catch (const std::invalid_argument &e)
    {
        if (std::string(e.what()) == "stoi")
        {
            std::cerr << "Informe apenas o digito.\nTente Novamente: ";
        }
        else
        {
            std::cerr << e.what();
        }

        return ConsoleText::getIntOption(validateEntrada, erroMessage);
    }
}

bool ConsoleText::validateOpInt(int op)
{
    return (op < 1 || op > 2);
}

bool ConsoleText::validateOpInt2(int op)
{
    return (op < 1 || op > 3);
}

bool ConsoleText::notValidate(int op)
{
    return false;
}

int ConsoleText::printMenuAcessoCadastro()
{
    std::cout << "===== SELECIONE O TIPO DE ACESSO =====\n";
    std::cout << "1 - Acessar\n";
    std::cout << "2 - Cadastrar\n";
    std::cout << "Informe o numero: ";

    return ConsoleText::getIntOption(
        ConsoleText::validateOpInt, "O valor deve ser 1 ou 2.\nTente Novamente: ");
}

int ConsoleText::printMenuSelectUserType()
{
    std::cout << "===== SELECIONE O TIPO DE USUARIO =====\n";
    std::cout << "1 - Doador\n";
    std::cout << "2 - Receptor\n";
    std::cout << "Informe o numero: ";
    return ConsoleText::getIntOption(
        ConsoleText::validateOpInt,
        "O valor deve ser 1 ou 2.\nTente Novamente: ");
}

void ConsoleText::printMenuAutenticaUsuario(std::string &login, std::string &password)
{
    std::cout << "===== LOGUE NO SISTEMA =====\n";
    std::cout << "Informe o usuario: ";
    std::getline(std::cin, login);
    std::cout << "Informe a senha: ";
    std::getline(std::cin, password);
}

void ConsoleText::printMenuCadastraUsuario(std::string &name, std::string &login, std::string &password, int &document, std::string &adress)
{
    std::cout << "===== CADASTRE-SE =====\n";
    std::cout << "Informe o Nome: ";
    std::getline(std::cin, name);
    std::cout << "Informe o Login: ";
    std::getline(std::cin, login);
    std::cout << "Informe a Senha: ";
    std::getline(std::cin, password);
    std::cout << "Informe o Numero do seu documento CPF ou CNPJ (APENAS NUMEROS): ";
    document = ConsoleText::getIntOption(ConsoleText::notValidate, "");
    std::cout << "Informe o endereco de coleta: ";
    std::getline(std::cin, adress);
}

void ConsoleText::printBemVindo(User &user)
{
    std::cout << "Bem vindo(a), " << user.getName()
              << "!\nDocumento: " << user.getDocument()
              << std::endl;
}

void ConsoleText::printEndereco(User &user, std::string &data, std::string &horario)
{
    std::cout << " === AGENDAMENTO === \n";
    std::cout << "Agendamento marcado para o dia " << data << " as " << horario << std::endl;
    std::cout << "O local de entrega sera no seguinte endereco: \n"
              << user.getAdress() << std::endl;
}

int ConsoleText::printMenuOqueFazer(int userType)
{

    std::cout << "===== O QUE DESEJA FAZER =====\n";
    std::cout << "1 - Doar/Coletar um residuo\n";
    std::cout << "2 - Editar perfil\n";

    if (userType == 1)
    {
        std::cout << "3 - Agendar entrega de residuos\n";
    }
    else
    {
        std::cout << "3 - Agendar coleta\n";
    }
    std::cout << "Informe o numero: ";
    return ConsoleText::getIntOption(
        ConsoleText::validateOpInt2,
        "O valor deve ser entre 1 e 3.\nTente novamente: ");
}

// mostrar a lista de residuos cadastrados e definir qual residuo o doador tem pra doar.

int ConsoleText::printGerenciarResiduos(int userType)
{
    std::cout << "===== GERENCIAMENTO DE RESIDUOS =====\n";

    if (userType == 1)
    {
        std::cout << "1 - Doar um residuo\n";
        std::cout << "2 - Adicionar um novo residuo\n";
    }
    else
    {
        std::cout << "1 - Coletar um residuo\n";
        std::cout << "2 - Cadastrar um novo residuo\n";
    }
    std::cout << "Informe o numero: ";
    return ConsoleText::getIntOption(
        ConsoleText::validateOpInt2,
        "O valor deve ser entre 1 e 3.\nTente novamente: ");
}

int ConsoleText::printCadastroResiduos()
{
    std::cout << "===== CADASTRO RESIDUOS =====\n";
    std::cout << "1 - Residuo Solido\n";
    std::cout << "2 - Residuo Liquido\n";
    std::cout << "Informe o numero: ";
    return ConsoleText::getIntOption(
        ConsoleText::validateOpInt,
        "O valor deve ser entre 1 e 2.\nTente novamente: ");
}

void ConsoleText::printCadastroResiduoSolido(std::string &name, std::string &help)
{
    std::cout << "===== RESIDUO SOLIDO =====\n";
    std::cout << "Nome do residuo: ";
    std::getline(std::cin, name);
    std::cout << "Descreva a forma correta de descarte do residuo " << name << ": ";
    std::getline(std::cin, help);
}

void ConsoleText::printCadastroResiduoLiquido(std::string &name, std::string &help)
{
    std::cout << "===== RESIDUO LIQUIDO =====\n";
    std::cout << "Nome do residuo: ";
    std::getline(std::cin, name);
    std::cout << "Descreva a forma correta de descarte do residuo " << name << ": ";
    std::getline(std::cin, help);
}

/*
void ConsoleText::printCadastroPontoColeta(std::string &nameRua, std::string &nameBairro, std::string &cep, std::string &referencia)
{
    std::cout << "===== CADASTRAR PONTO DE COLETA ===== \n";
    std::cout << "Insira os dados de localizaçao:\n";
    std::cout << "Rua: ";
    std::getline(std::cin, nameRua);
    std::cout << "Bairro: ";
    std::getline(std::cin, nameBairro);
    std::cout << "CEP: ";
    std::getline(std::cin, cep);
    std::cout << "Ponto de referencia: ";
    std::getline(std::cin, referencia);
}
*/

int ConsoleText::printEditProfile()
{
    std::cout << "===== EDITAR PERFIL =====\n";
    std::cout << "1 - Editar o endereco de coleta\n";
    std::cout << "2 - Editar o nome\n";
    std::cout << "Informe o numero: ";
    return ConsoleText::getIntOption(
        ConsoleText::validateOpInt2,
        "O valor deve ser entre 1 e 3.\nTente novamente: ");
}

int ConsoleText::printMenuAgendamento()
{
    std::cout << "===== AGENDAMENTOS =====\n";

    if (userType == 1)
    {
        std::cout << "1 - Criar um agendamento para entrega\n";
        std::cout << "2 - Verificar agendamentos pendentes\n";
    }
    else
    {
        std::cout << "1 - Criar um agendamento para coleta\n";
        std::cout << "2 - Verificar agendamentos pendentes\n";
        std::cout << "3 - Atualizar status do agendamento\n";
    }
    std::cout << "Informe o numero: ";
    return ConsoleText::getIntOption(
        ConsoleText::validateOpInt2,
        "O valor deve ser entre 1 e 3.\nTente novamente: ");
}

void ConsoleText::printAgendamentoColeta(std::string &data, std::string &horario, int &local)
{
    std::cout << "===== AGENDAMENTO DE COLETA ===== \n";
    std::cout << "Insira o dia e o horario ideal para voce realizar essa coleta: \n";
    std::cout << "Dia (DD/MM/AAAA): ";
    std::getline(std::cin, data);
    std::cout << "Horario (HH:MM): ";
    std::getline(std::cin, horario);
    std::cout << "== LOCAL ==\n";
    std::cout << "1 - Levar no local do receptor\n";
    std::cout << "2 - Entregar no meu local de coleta\n";
    std::cout << "Informe o número: ";

    local = ConsoleText::getIntOption(
        ConsoleText::validateOpInt,
        "O número deve estar entre 1 e 2.");
}
