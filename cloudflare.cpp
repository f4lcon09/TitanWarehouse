#include <iostream>

// A DOR: Dados espalhados criam confusão mental.
// A SOLUÇÃO: Agrupar o estado do servidor em uma única "caixa" (Struct).
struct Servidor
{
    int requisicoes_atuais;
    int capacidade_maxima;
    bool status_overload;
    bool status_manutencao;
};

// A DOR: Cópia de dados pesados e falta de controle central.
// A SOLUÇÃO: Usar ponteiros (controles remotos) para agir direto na memória original.
void distribuir_carga(Servidor *s1, Servidor *s2)
{
    if (s1->status_overload && s2->status_overload || s1->status_manutencao && s2->status_manutencao || s1->status_overload && s2->status_manutencao || s2->status_overload &&  s1->status_manutencao)
    {
        std::cout << "[SISTEMA COLAPSADO: TODOS OS SERVIDORES OFFLINE]" << std::endl;
        return;
    }

    // Tradução: "Se o Norte está vivo E (ele é menor OU o outro está morto)" o !seguido por uma boleana verifica o estado de normalidade dela (se não está sobrecarregado)
    if (!s1->status_overload && (s1->requisicoes_atuais <= s2->requisicoes_atuais || s2->status_overload))
    {
        s1->requisicoes_atuais++; // AÇÃO

        // 2. SEGURANÇA: Checa apenas quem recebeu a carga.
        if (s1->requisicoes_atuais > s1->capacidade_maxima)
        {
            s1->status_overload = true;
            std::cout << "[ALERTA] Servidor NORTE atingiu o limite crítico!" << std::endl;
        }
    }
    else 
    {
        s2->requisicoes_atuais++; // AÇÃO

        if (s2->requisicoes_atuais > s2->capacidade_maxima)
        {
            s2->status_overload = true;
            std::cout << "[ALERTA] Servidor SUL atingiu o limite crítico!" << std::endl;
        }
    }
}


int main()
{
    int sinal_neural = 1;
    if (sinal_neural == 1)
    {
        Servidor norte = {10, 12, false}; // Capacidade baixa para testarmos o erro
        Servidor sul = {5, 12, false};

        // O "Dashboard" (Único lugar onde o ruído de números é permitido)
        for (int i = 0; i < 10; i++)
        {
            distribuir_carga(&norte, &sul);

            std::cout << "--- CICLO " << i + 1 << " ---" << std::endl;
            std::cout << "Norte: " << norte.requisicoes_atuais << " | Sul: " << sul.requisicoes_atuais << std::endl;
        }
    } else {
        std::cout << "[ACESSO BLOQUEADO: SINAL NEURAL INATIVO]" << std::endl;
    }

    // Inicialização Limpa

    return 0;
}