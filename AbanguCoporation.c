int main() {
    int anoAtual, numDependentes, tempoEmpresa;
    float salarioBase, salarioFinal, acrescimoDependente = 0, acrescimoTempo = 0, acrescimoBissexto = 0;

    // Inserção de dados nas variáveis
    printf("Digite o salario base do funcionario: ");
    scanf("%f", &salarioBase);

    printf("Digite o numero de dependentes do funcionario: ");
    scanf("%d", &numDependentes);

    printf("Digite o tempo de empresa do funcionario (em anos): ");
    scanf("%d", &tempoEmpresa);

    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);

    // Definição do número máximo de dependentes para cálculo
    int dependentesCalculados = numDependentes;
    if (numDependentes > 5) {
        dependentesCalculados = 5;  // Defininindo o valor máximo para dependentes
    }

    // Acréscimo por dependentes (3% do salário base por dependente, até no máximo 5)
    if (dependentesCalculados > 0) {
        acrescimoDependente = dependentesCalculados * (salarioBase * 0.03);
    }

    // Definição do percentual de acréscimo por tempo de serviço
    float percentual;
    if (numDependentes >= 4) {
        percentual = 0.05;
    } else {
        percentual = 0.03;
    }

    // Acréscimo por tempo de empresa (apenas para quem tem 6 anos ou mais)
    if (tempoEmpresa >= 6) {
        int fator = (tempoEmpresa - 6) / 6 + 1; // A cada 6 anos completos, recebe um adicional
        acrescimoTempo = fator * (salarioBase * percentual);
    }

    // Acréscimo por ano bissexto (1% do salário base)
    if ((anoAtual % 4 == 0 && anoAtual % 100 != 0) || (anoAtual % 400 == 0)) {
        acrescimoBissexto = salarioBase * 0.01;
    }

    // Cálculo do salário final
    salarioFinal = salarioBase + acrescimoDependente + acrescimoTempo + acrescimoBissexto;

    // Exibição dos resultados
    printf("------------------------------------------------------------\n");
    printf("Salario base do funcionario: %.2f R$\n", salarioBase);
    printf("Acréscimo por ano bissexto: %.2f R$\n", acrescimoBissexto);
    printf("Acréscimo para dependentes: %.2f R$\n", acrescimoDependente);
    printf("Acréscimo por tempo de empresa: %.2f R$\n", acrescimoTempo);
    printf("************************************************************\n");
    printf("Salario final: %.2f R$\n", salarioFinal);
    printf("------------------------------------------------------------\n");

    return 0;
}
