function evaluate()

% Le o modelo fuzzy
EvaluationModel = readfis("tecnical_model.fis");

studentsAmount = 0;

while (studentsAmount < 1)
    studentsAmount = input("Digite a quantidade de alunos: ");

    if(studentsAmount < 1)
        fprintf("\nQuantidade invalida de alunos, tente novamente!\n\n");
    end
end

currentStudent = 1;

while (studentsAmount > 0)
    fprintf("=============Aluno %d=============\n", currentStudent);
    nota_prova = input("Insira a nota da PROVA: ");
    nota_trabalho = input("Insira a nota do TRABALHO: ");
    nota_participacao = input("Insira a nota de PARTICIPAÇAO: ");

    nota_final= evalfis(EvaluationModel, [nota_prova, nota_trabalho, nota_participacao]);

    conceito = "";

    if(nota_final < 25)
        conceito = "D";
    elseif(nota_final < 60)
        conceito = "C";
    elseif(nota_final < 88.5)
        conceito = "B";
    else 
        conceito = "A";
    end

    fprintf("Conceito do Aluno %d: %s\n", currentStudent, conceito);
    fprintf("=================================\n");

    studentsAmount = studentsAmount - 1;
    currentStudent = currentStudent + 1;
end
