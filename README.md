# CP2 - Monitoramento de Ambiente para Adegas :wine_glass:

![banner](https://github.com/L-A-N-E/CP2_Edge_1SEM/assets/153787379/132308ff-27a0-45e7-8323-80d9103f2390)


## Índice :page_with_curl:

  * [Descrição do Projeto](#descrição-do-projeto-memo)
     * [Introdução](#introdução-left_speech_bubble)
     * [Inicialização](#inicialização-star2)
     * [Luminosidade](#luminosidade-bulb)
     * [Temperatura](#temperatura-thermometer)
     * [Umidade](#umidade-droplet)
  * [Acesso ao projeto](#acesso-ao-projeto-file_folder)
  * [Ferramenta utilizada](#ferramenta-utilizada-hammer_and_wrench)
  * [Bibliotecas utilizadas](#bibliotecas-utilizadas-books)
  * [Componentes necessários](#componentes-necessários-toolbox)
  * [Montagem](#montagem-wrench)
     * [Cuidados durante a montagem](#cuidados-durante-a-montagem-warning)
  * [Reprodução](#reprodução-gear)
  * [Pessoas Desenvolvedoras do Projeto](#pessoas-desenvolvedoras-do-projeto-globe_with_meridians)

## Descrição do projeto :memo:

<h3>Introdução :left_speech_bubble:</h3>
<p>
  Nós, L.A.N.E., após a entrega da primeira parte do projeto, recebemos um feedback da Vinheria Agnello, no qual solicitaram novas funcionalidades para o dispositivo, que consistiam em mostrar os dados em um display (LCD) e captar, além da luminosidade, os valores de umidade e temperatura. Isso ocorre porque o sabor do vinho não é alterado apenas pela exposição à muita luminosidade, mas também pela umidade e temperatura. Com isso em mente, nesta segunda parte, implementamos essas funções e aprimoramos o projeto.
</p>
<h3>Inicialização :star2:</h3>
<p>
  Ao ligar o dispositivo, o logo da nossa empresa aparece no display (LCD). Em seguida, ele mostra os valores da luminosidade, temperatura e umidade 10 vezes cada. Depois, exibe a média desses valores. E então, o ciclo recomeça.
</p>
<h3>Luminosidade :bulb:</h3>
<p>
  Como discutido na primeira parte do projeto, a exposição à luminosidade excessiva e à penumbra pode causar danos à qualidade do vinho. Levando isso em consideração, além da indicação se o ambiente está escuro, com meia luz ou iluminado pelos LEDs, essa informação será visível no display (LCD), assim como a quantidade de luminosidade em lux. Por fim, a buzina (Buzzer) que emitia o alarme apenas por 3 segundos agora tocará continuamente.
</p>
<h3>Temperatura :thermometer:</h3>
<p>
  O vinho, quando exposto ao calor excessivo, tem sua vida encurtada, além de que variações de temperatura superiores a 3°C podem resultar no aparecimento de aromas indesejáveis. Por essas razões, implementamos um sensor que captura a temperatura da adega, o DHT11, além de indicar se o local está com uma temperatura alta, baixa ou na faixa ideal, entre 10°C e 15°C. Essas informações são visíveis no display (LCD) do dispositivo. Quando a temperatura do ambiente estiver fora da situação ideal, o LED amarelo será aceso e a buzina (Buzzer) tocará continuamente.
</p>
<h3>Umidade :droplet:</h3>
<p>
  Além da temperatura, a ausência de umidade pode resultar na secagem do vedante, ocasionando uma vedação inadequada da garrafa e aumentando o risco de oxidação do líquido. Enquanto isso, um excesso de umidade pode causar danos aos rótulos e favorecer o crescimento de fungos. Portanto, o nível ideal de umidade deve ser em torno de 70%, com uma margem de variação entre 50% e 70%.
</p>
<p>
  Diante disso, utilizamos o mesmo sensor, o DHT11, que captura a temperatura da adega, já que ele também captura a umidade do ambiente. Além disso, indicará se a umidade está alta, baixa ou na faixa ideal, entre 50% e 70%. Essas informações também são mostradas no display (LCD). Quando a umidade estiver fora da situação ideal, o LED vermelho será aceso e a buzina (Buzzer) tocará continuamente.
</p>

## Acesso ao projeto :file_folder:

Você pode acessar o [código do projeto]() ou a [simulação feita no Wooki](https://wokwi.com/projects/395351900975891457)

## Ferramenta utilizada :hammer_and_wrench:

- ``Arduino IDE``
  
## Bibliotecas utilizadas :books:

- ``LiquidCrystal_I2C``
- ``DHT sensor library``
  
## Componentes necessários :toolbox:

|   Componente   | Quantidade |
|:--------------:|:----------:|
| Arduino Uno R3 |      1     |
| 220 Ω Resistor |      3     |
|     DHT11      |      1     |
|    LED verde   |      1     |
|   LED amarelo  |      1     |
|  LED vermelho  |      1     |
| Buzzer (Piezo) |      1     |
| Módulo LDR - 4 terminais |      1     |
|   LCD 16x2 com módulo I2C    |      1     |
|      Cabo      |     19     |
|    Cabo USB    |      1     |

## Montagem :wrench:

<details>
  <summary>Imagem da Montagem</summary>
  <img src="https://github.com/L-A-N-E/CP2_Edge_1SEM/assets/101829188/f222851c-31ac-4af2-ae67-96aba71d051a" alt="imagem-montagem">
</details>

<h3>Cuidados durante a montagem :warning:</h3>

- ``1.`` Conectando os LED’s e o Buzzer:
   - ``1.1.`` Ambos possuem polaridade, então precisamos ter cuidado na hora de conectar-los aos cabos;
   - ``1.2.`` O LED possui um terminal maior, que tem polaridade positiva, e o lado do terminal menor tem polaridade negativa. Portanto, conectamos a conexão do Arduino no terminal positivo ( nodo) e o GND no terminal negativo (Catodo);
   - ``1.3.`` O Buzzer possui uma indicação se o lado é positivo ou negativo;

- ``2.`` Conectando o LDR:
  - ``2.1.`` Nesta segunda parte, mudamos o LDR para um Módulo LDR com 4 terminais no qual possui a opção da saída dos dados analógicos ou digitais. Com isso, nesse projeto, continuamos usando a entrada analógica. Então, verifique se o cabo que está conectado ao A0 do Arduino está  conectado ao A0 do LDR.
  - ``2.2.`` Conecte o VCC no terminal positivo (5V) e o GND no terminal negativo (GND);
  - ``2.3.`` Relaxe, um dos terminais do LDR ficaram sem conectar, pois esse é onde sai os dados digitais;

- ``3.`` Conectando o DHT:
  - ``3.1.`` Na simulação e na imagem acima, utilizamos o DHT22, entretanto, no [código do projeto]() utilizamos o DHT11;
    - ``3.1.1.`` Esses sensores possuem a diferença de que o DHT22 é mais preciso do que o DHT11, no qual possui uma margem de erro maior;
    - ``3.1.2.`` Para mais informações sobre o DHT22, nós fizemos um [material explicando sobre o sensor](https://drive.google.com/file/d/1xqHKRi8RzEcJZDfiAaG9nQOlKiJlPApr/view?usp=sharing).
    - ``3.1.3.`` Se quiser utilizar um DHT22, a única coisa que precisará trocar no código é o tipo do DHT para 22 nessa seguinte parte:
            
      ```cpp
      //Definindo o tipo do DHT  
      #define DHTTYPE DHT11   
      ```
      
  - ``3.2.`` É necessário ter muito cuidado na hora de conectar os cabos, pois se conecta-los errados, o DHT queimará. Segue a Imagem de quais são os terminais do DHT:
      <details>
        <summary>Imagem dos terminais do DHT11</summary>
        <img src="https://github.com/L-A-N-E/CP2_Edge_1SEM/assets/101829188/d26416fb-d639-4760-b590-593932e5a888" alt="Terminais do DHT11">
      </details>
  - ``3.3.`` Conecte o VCC no terminal positivo (5V), GND no terminal negativo (GND), o terminal dos dados no pino 2 e não conecte nada no terminal N.C.;

- ``4.`` Conectando o LCD:
  - ``4.1.`` **Atenção!** Estamos utilizando um LCD 16x2 com um módulo I2C!;
  - ``4.2.`` Conecte o VCC no terminal positivo (5V), GND no terminal negativo (GND), o SDA no pino do Arduino A4 e o SCL no A5;
  - ``4.3.`` Teste para ver se o display está funcionando, se tiver problemas com o display, pode ser algumas dessas possibilidades: o LCD está quebrado, com mal contato ou o contraste está baixo;
    - ``4.3.1.`` Para aumentar o contraste do display basta girar o trimpot de ajuste do contraste no sentido anti-horário. Por sua vez, para diminuir o contraste gire no sentido horário.
      <details>
        <summary>Imagem de onde fica o trimpot de ajuste do contraste</summary>
        <img src="https://github.com/L-A-N-E/CP2_Edge_1SEM/assets/101829188/50648d65-2402-4508-a47d-1d38bbf663e5" alt="Terminais do DHT11">
      </details>
## Reprodução :gear:

- ``1.`` Após a montagem do projeto, é necessário inserir o código por meio de um computador que possui o programa Arduino IDE instalado;
- ``2.`` Baixe as bibliotecas necessárias no Arduino IDE; 
- ``3.`` Transferir o código do computador para  o Arduino por meio do Cabo USB;
- ``4.`` Testar para ver se está funcionando;
- ``5.`` Com tudo montado e pronto, é necessário levá-lo para o ambiente em que será implementado e ligá-lo á uma fonte;

## Pessoas Desenvolvedoras do Projeto :globe_with_meridians:

| [<img src="https://avatars.githubusercontent.com/u/101829188?v=4" width=115><br><sub>Alice Santos Bulhões</sub>](https://github.com/AliceSBulhoes) |  [<img src="https://avatars.githubusercontent.com/u/163866552?v=4" width=115><br><sub>Eduardo Oliveira Cardoso Madid</sub>](https://github.com/EduardoMadid) |  [<img src="https://media.licdn.com/dms/image/D5603AQF59776BVSUSg/profile-displayphoto-shrink_800_800/0/1697337839569?e=1717632000&v=beta&t=4spOdaBAcH7gOmyEpgpyF6hk1TM14MvCJ5DI-CNdCsI" width=115><br><sub>Lucas Henzo Ide Yuki</sub>](https://github.com/LucasYuki1) | [<img src="https://avatars.githubusercontent.com/u/153787379?v=4" width=115><br><sub>Nicolas Haubricht Hainfellner</sub>](https://github.com/NicolasHaubricht) |
| :---: | :---: | :---: | :---: |
| RM:554499 | RM:556349 | RM:554865 | RM:556259 |


