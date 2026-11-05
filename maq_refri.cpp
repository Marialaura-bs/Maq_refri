
#include <iostream> 
#include <string>  
using namespace std; 

// Função que verifica se o botão informado é válido.
bool validarBotao(string botao) {

    // Verifica se o botão corresponde a alguma das opções permitidas.
    if (botao == "I50" || botao == "I100" ||
        botao == "A" || botao == "R" ||
        botao == "D" || botao == "Q") {

        return true; // Retorna true caso o botão seja válido.
    }

    return false; // Retorna false caso o botão não seja válido.
}

// Função responsável por inserir moedas na máquina.
void inserirMoeda(int &saldo, int &moedasArmazenadas, string botao) {

    // Verifica se a moeda inserida é de 50 centavos.
    if (botao == "I50") {

        // Verifica se a inserção da moeda não ultrapassa o saldo máximo de R$ 2,50.
        if (saldo + 50 <= 250) {

            saldo += 50; // Adiciona 50 centavos ao saldo do cliente.
            moedasArmazenadas += 50; // Adiciona 50 centavos ao total armazenado pela máquina.

            // Exibe a parte inteira do saldo e a vírgula.
            cout << "Saldo " << saldo / 100 << ",";

            // Verifica se os centavos possuem apenas um algarismo.
            if (saldo % 100 < 10) {
                cout << "0"; // Adiciona um zero antes dos centavos.
            }

            // Exibe os centavos e pula para a próxima linha.
            cout << saldo % 100 << endl;
        }
        else {
            // Informa que a moeda foi devolvida por ultrapassar o limite.
            cout << "Moeda devolvida" << endl;
            // Exibe o valor que será devolvido ao cliente.
            cout << "Saldo " << saldo / 100 << ",";

            // Adiciona zero antes dos centavos, se necessário.
            if (saldo % 100 < 10) {
                cout << "0";
            }

            // Exibe os centavos do valor devolvido.
            cout << saldo % 100 << endl;
        }

    }

    // Verifica se a moeda inserida é de 100 centavos (R$ 1,00).
    else if (botao == "I100") {

        // Verifica se a inserção da moeda não ultrapassa R$ 2,50.
        if (saldo + 100 <= 250) {

            saldo += 100; // Adiciona R$ 1,00 ao saldo do cliente.
            moedasArmazenadas += 100; // Adiciona R$ 1,00 ao total armazenado pela máquina.

            // Exibe a parte inteira do saldo e a vírgula.
            cout << "Saldo " << saldo / 100 << ",";

            // Verifica se os centavos possuem apenas um algarismo.
            if (saldo % 100 < 10) {
                cout << "0"; // Adiciona um zero antes dos centavos.
            }

            // Exibe os centavos e pula para a próxima linha.
            cout << saldo % 100 << endl;
        }
        else {
            // Informa que a moeda foi devolvida por ultrapassar o limite.
            cout << "Moeda devolvida" << endl;
        }

    }

}

int main() {

    // Informa que a máquina está aguardando ser ligada.
    cout << "Aguarde o início..." << endl;

    // Declara uma variável que indica se a máquina está ligada.
    // Inicialmente, a máquina está desligada.
    bool Desligada = true;

    // Armazena o botão digitado pelo usuário.
    string botao;

    // Saldo atual do cliente, inicialmente R$ 0,00.
    int saldo = 0;

    // Contador de águas vendidas.
    int aguasVendidas = 0;

    // Contador de refrigerantes vendidos.
    int refrigerantesVendidos = 0;

    // Valor total de moedas armazenadas pela máquina, em centavos.
    int moedasArmazenadas = 0;
    // Lê o primeiro botão digitado pelo usuário.
    cin >> botao;

    while (botao != "Q")
    {
        // Lê botão digitado pelo usuário.
        cin >> botao;
    }
    

    // Se o botão inicial for Q, liga a máquina.
    if (botao == "Q") {

        cout << "Máquina funcionando" << endl; // Informa que a máquina foi ligada.

        Desligada = false; // Atualiza o estado da máquina para ligada.

        // Exibe o saldo inicial do cliente.
        cout << "Saldo " << saldo / 100 << ",";

        // Adiciona zero antes dos centavos, se necessário.
        if (saldo % 100 < 10) {
            cout << "0";
        }

        // Exibe os centavos do saldo inicial.
        cout << saldo % 100 << endl;
    }

    // Executa os comandos enquanto a máquina não estiver desligada.
    while (!Desligada) {

        // Lê o próximo botão digitado pelo usuário.
        cin >> botao;

        // Verifica se o botão informado é válido.
        if (!validarBotao(botao)) {
            cout << "Botão inválido" << endl; // Exibe a mensagem de erro.
            continue; // Volta ao início do while para ler outro botão.
        }

        // Chama a função que trata a inserção de moedas.
        inserirMoeda(saldo, moedasArmazenadas, botao);

        // Verifica se o botão selecionado corresponde à compra de água.
        if (botao == "A") {

            // Verifica se o cliente possui pelo menos R$ 1,50.
            if (saldo >= 150) {

                saldo -= 150; // Desconta R$ 1,50 do saldo do cliente.

                aguasVendidas++; // Aumenta em 1 o contador de águas vendidas.

                cout << "Água entregue" << endl; // Informa que a água foi entregue.

                // Exibe a parte inteira do saldo restante.
                cout << "Saldo " << saldo / 100 << ",";

                // Adiciona zero antes dos centavos, se necessário.
                if (saldo % 100 < 10) {
                    cout << "0";
                }

                // Exibe os centavos do saldo restante.
                cout << saldo % 100 << endl;
            }
            else {
                // Informa que o saldo não é suficiente para comprar água.
                cout << "Saldo insuficiente" << endl;
            }

        }

        // Verifica se o botão selecionado corresponde à compra de refrigerante.
        if (botao == "R") {

            // Verifica se o cliente possui pelo menos R$ 2,00.
            if (saldo >= 200) {

                saldo -= 200; // Desconta R$ 2,00 do saldo do cliente.

                refrigerantesVendidos++; // Aumenta em 1 o contador de refrigerantes vendidos.

                cout << "Refrigerante entregue" << endl; // Informa que o refrigerante foi entregue.

                // Exibe a parte inteira do saldo restante.
                cout << "Saldo " << saldo / 100 << ",";

                // Adiciona zero antes dos centavos, se necessário.
                if (saldo % 100 < 10) {
                    cout << "0";
                }

                // Exibe os centavos do saldo restante.
                cout << saldo % 100 << endl;
            }
            else {
                // Informa que o saldo não é suficiente para comprar refrigerante.
                cout << "Saldo insuficiente" << endl;
            }

        }

        // Verifica se o botão selecionado corresponde à devolução do saldo.
        if (botao == "D") {

            // Verifica se existe algum valor para devolver ao cliente.
            if (saldo > 0){

                // Exibe o valor que será devolvido ao cliente.
                cout << "Devolvido " << saldo / 100 << ",";

                // Adiciona zero antes dos centavos, se necessário.
                if (saldo % 100 < 10) {
                    cout << "0";
                }

                // Exibe os centavos do valor devolvido.
                cout << saldo % 100 << endl;

                // Retira do total armazenado o valor devolvido ao cliente.
                moedasArmazenadas -= saldo;

                // Zera o saldo do cliente após a devolução.
                saldo = 0;

                // Exibe o saldo atualizado do cliente.
                cout << "Saldo " << saldo / 100 << ",";

                // Adiciona zero antes dos centavos, se necessário.
                if (saldo % 100 < 10) {
                    cout << "0";
                }

                // Exibe os centavos do saldo zerado.
                cout << saldo % 100 << endl;
            }
            else{
                // Informa que não existe saldo para devolver.
                cout << "Não há saldo a ser devolvido" << endl;
            }
        }

        // Verifica se o botão selecionado corresponde ao desligamento da máquina.
        if (botao == "Q") {

            // Só permite desligar a máquina quando o saldo do cliente for zero.
            if (saldo == 0) {

                Desligada = true; // Altera o estado da máquina para desligada.

                // Exibe o título do relatório de vendas.
                cout << "Resumo das vendas:" << endl;

                // Exibe a quantidade de águas vendidas.
                cout << aguasVendidas << " Agua" << endl;

                // Exibe a quantidade de refrigerantes vendidos.
                cout << refrigerantesVendidos << " Refrigerante" << endl;

                // Exibe uma linha em branco para separar as informações.
                cout << endl;

                // Exibe a parte inteira do total acumulado pela máquina.
                cout << "Total acumulado: " << moedasArmazenadas / 100 << ",";

                // Adiciona zero antes dos centavos, se necessário.
                if (moedasArmazenadas % 100 < 10) {
                    cout << "0";
                }

                // Exibe os centavos do total acumulado.
                cout << moedasArmazenadas % 100 << endl;

                // Informa que a máquina foi desligada.
                cout << "Desligado" << endl;
            }
            else {
                // Informa que o cliente precisa devolver o saldo antes de desligar.
                cout << "Devolva o saldo antes de desligar" << endl;
            }

        }

    }

    // Finaliza a execução do programa e retorna 0, indicando encerramento normal.
    return 0;
}
