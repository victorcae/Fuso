const int ena = 2; // habilita o motor
const int dir = 7; // determina a direção
const int pul = 4; // executa um passo
const int intervalo = 600; // intervalo entre os pulsos
const int passosPorVolta = 400; // número de passos por volta
boolean pulso = LOW; // estado do pulso

void setup() {
    Serial.begin(9600); // Inicializa a comunicação serial
    pinMode(ena, OUTPUT);
    pinMode(dir, OUTPUT);
    pinMode(pul, OUTPUT);
    digitalWrite(ena, LOW); // habilita em low (invertida) 
ec
    // Adiciona um delay de 2 segundos antes de começar a movimentação
    delay(2000); // espera 2000 milissegundos (2 segundos)

    // Chama a função para realizar as voltas
    realizarVoltas(57, "S");
}

void loop() {
    // Loop principal vazio, pois o movimento já foi realizado na configuração
}

void realizarVoltas(int numeroDeVoltas, const char* direcaoInput) {
    // Define a direção com base na entrada
    bool direcao;
    if (strcmp(direcaoInput, "S") == 0) {
        direcao = true;  // CW
    } else if (strcmp(direcaoInput, "D") == 0) {
        direcao = false; // CCW
    } else {
        Serial.println("Direção inválida! Use 'S' para subir ou 'D' para descer.");
        return; // Sai da função se a direção for inválida
    }

    digitalWrite(dir, direcao); // Atualiza a direção no driver

    // Imprime a direção inicial
    Serial.println("Direção inicial: " + String(direcao ? "CW" : "CCW"));

    for (int volta = 1; volta <= numeroDeVoltas; volta++) {
        // Executa os passos para a volta atual
        for (int i = 0; i < passosPorVolta; i++) {
            pulso = !pulso; // inverte o estado do pulso
            digitalWrite(pul, pulso); // atribui o novo estado à porta
            delayMicroseconds(intervalo); // aguarda o intervalo
        }

        // Mantém a mesma direção durante as voltas
        digitalWrite(dir, direcao); // Atualiza a direção no driver

        // Imprime a nova direção e a volta atual
        Serial.println("Volta " + String(volta) + ": " + String(direcao ? "CW" : "CCW"));
        
        // Sem pausa entre as voltas
        // delay(1000); // espera 1 segundo (removido)
    }
}



