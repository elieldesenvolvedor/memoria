#define MAX 50

int sorte[50];
int nivel = 0;
int acertou = 6;
int errou;
int i, teste;
int mostrar = 1;

  // vetor de MAX posições para guardar o número em binário
  int vet_bin[MAX];
  // variáveis de controle de loop
  int j;
  // aux_num serve para guardar num para mostrar posteriormente
  int aux_num = nivel;

int bin;

void setup() {
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
  
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  
    pinMode(acertou, OUTPUT);

    //Embaralhar
    randomSeed(analogRead(0));

    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);

    teste = 0;
}

void loop() {

    if (sorte[0] == 0) { // Se ainda não foi sorteado

        for (i = 0; i <= 50; i++) {
            sorte[i] = random(8, 12);
        }
    
    apagaleds();
    
    }

    if (errou == 1) { // se errou

        // acende todas 4
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);



  // enquanto "num" for maior que 0
  i=0;
  while(nivel > 0)
  {
    // obtém o resto da divisão de num por 2
    vet_bin[i] = nivel % 2;
    i++;    
    nivel = nivel / 2;
  }

  if (vet_bin[0] == 1){
    digitalWrite(A5, HIGH);
  }
  if (vet_bin[1] == 1){
    digitalWrite(A4, HIGH);
  }
  if (vet_bin[2] == 1){
    digitalWrite(A3, HIGH);
  }
  if (vet_bin[3] == 1){
    digitalWrite(A2, HIGH);
  }
  if (vet_bin[4] == 1){
    digitalWrite(A1, HIGH);
  }

    }else{

    if (mostrar == 1){
      
      apagaleds();
      
      for (i = 0; i <= teste; i++) {
        
        delay(500);
        digitalWrite(sorte[i], HIGH);
        delay(1000);
        apagaleds();
        
      }
      mostrar = 0;
      teste = 0;
    }
    
    for (i = 1; i <= 4; i++) {
      
      apagaleds();
      if (digitalRead(i) == LOW) {
        digitalWrite(i+7, HIGH);
        if (sorte[teste] == (i+7)) {
          digitalWrite(acertou, HIGH);
          delay(300);       
          if (teste == nivel) {
            nivel++;
            mostrar = 1;
          }
          teste++;
        } else {
          errou = 1;
        }
      }
    
    }
    
  }

    

}

void apagaleds() { // Função apaga os 4 leds  // alterado
    digitalWrite(6, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
}
