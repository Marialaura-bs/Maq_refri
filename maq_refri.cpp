#include <iostream>
#include <string>
using namespace std;

// Função que verifica se o botão informado é válido.
bool validarBotao(string botao) {

    if (botao == "I50" || botao == "I100" ||
        botao == "A" || botao == "R" ||
        botao == "D" || botao == "Q") {

        return true;
    }

    return false;
}

// Função que atualiza o estado de acordo com o saldo.
void atualizarEstado(int saldo, string &estado) {

    if (saldo == 0) {
        estado = "0,00";
    }
    else if (saldo == 50) {
        estado = "0,50";
    }
    else if (saldo == 100) {
        estado = "1,00";
    }
    else if (saldo == 150) {
        estado = "1,50";
    }
    else if (saldo == 200) {
        estado = "2,00";
    }
    else if (saldo == 250) {
        estado = "2,50";
    }

}

// Função responsável por inserir moedas na máquina.
void inserirMoeda(int &saldo, int &moedasArmazenadas,
                  string botao, string &estado) {

    if (botao == "I50") {

        if (saldo + 50 <= 250) {

            saldo += 50;
            moedasArmazenadas += 50;

            // Atualiza o estado após a inserção da moeda.
            atualizarEstado(saldo, estado);

            cout << "Saldo " << estado << endl;
        }
        else {
            cout << "Moeda devolvida" << endl;
            cout << "Saldo " << estado << endl;
        }

    }

    else if (botao == "I100") {

        if (saldo + 100 <= 250) {

            saldo += 100;
            moedasArmazenadas += 100;

            // Atualiza o estado após a inserção da moeda.
            atualizarEstado(saldo, estado);

            cout << "Saldo " << estado << endl;
        }
        else {
            cout << "Moeda devolvida" << endl;
            cout << "Saldo " << estado << endl;
        }

    }

}

int main() {

    cout << "Aguarde o início..." << endl;

    string botao;

    // Saldo do cliente em centavos.
    int saldo = 0;

    // Estado inicial da máquina.
    string estado = "Desligada";

    int aguasVendidas = 0;
    int refrigerantesVendidos = 0;
    int moedasArmazenadas = 0;

    // Aguarda o comando Q para inicializar a máquina.
    cin >> botao;

    while (estado == "Desligada") {

        if (!validarBotao(botao)) {
            cout << "Botão inválido" << endl;
        }
        else if (botao != "Q") {
            cout << "Botão não funciona para inicializar a máquina" << endl;
        }

        if (botao == "Q") {

            cout << "Máquina funcionando" << endl;

            // Atualiza o estado para o saldo inicial.
            atualizarEstado(saldo, estado);

            cout << "Saldo " << estado << endl;

            break;
        }

        cin >> botao;
    }

    // Executa enquanto a máquina estiver ligada.
    while (estado != "Desligada") {

        cin >> botao;

        // Verifica se o botão informado é válido.
        if (!validarBotao(botao)) {
            cout << "Botão inválido" << endl;
            continue;
        }

        // Trata a inserção de moedas.
        inserirMoeda(saldo, moedasArmazenadas, botao, estado);

        // Compra de água.
        if (botao == "A") {

            if (saldo >= 150) {

                saldo -= 150;
                aguasVendidas++;

                atualizarEstado(saldo, estado);

                cout << "Água entregue" << endl;
                cout << "Saldo " << estado << endl;
            }
            else {
                cout << "Saldo insuficiente" << endl;
            }
        }

        // Compra de refrigerante.
        if (botao == "R") {

            if (saldo >= 200) {

                saldo -= 200;
                refrigerantesVendidos++;

                atualizarEstado(saldo, estado);

                cout << "Refrigerante entregue" << endl;
                cout << "Saldo " << estado << endl;
            }
            else {
                cout << "Saldo insuficiente" << endl;
            }
        }

        // Devolução do saldo.
        if (botao == "D") {

            if (saldo > 0) {

                cout << "Devolvido " << estado << endl;

                moedasArmazenadas -= saldo;
                saldo = 0;

                atualizarEstado(saldo, estado);

                cout << "Saldo " << estado << endl;
            }
            else {
                cout << "Não há saldo a ser devolvido" << endl;
            }
        }

        // Desligamento da máquina.
        if (botao == "Q") {

            if (saldo == 0) {

                // Atualiza o estado da máquina para desligada.
                estado = "Desligada";

                cout << "Resumo das vendas:" << endl;
                cout << aguasVendidas << " Agua" << endl;
                cout << refrigerantesVendidos << " Refrigerante" << endl;
                cout << endl;

                cout << "Total acumulado: "
                     << moedasArmazenadas / 100 << ",";

                if (moedasArmazenadas % 100 < 10) {
                    cout << "0";
                }

                cout << moedasArmazenadas % 100 << endl;

                cout << estado << endl;
            }
            else {
                cout << "Devolva o saldo antes de desligar" << endl;
            }
        }
    }

    return 0;
}