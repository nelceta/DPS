import serial                       # biblioteca para comunicação serial
import matplotlib.pyplot as plt     # biblioteca para plotagem de gráficos
from drawnow import *               # Função para atualizar a figura
import atexit                       # Função para limpar a porta serial

valores = []

plt.ion()                           # metodo para desenhar a tela

serialArduino = serial.Serial('COM6', 19200) # Porta da serial e frequência

# Definindo a tela
def plotvalores():
  
  plt.title('Valor de tensão')
  plt.grid(True)
  plt.ylabel('Tensões')
  plt.plot(valores, label='Tensões')
  plt.legend(loc='upper right')
  plt.xlabel(entrValores)

# Definição do encerramento da comunicação serial
def FechandoPortaSerial():
  serialArduino.close()
  print("Porta serial fechada")
  print("serialArduino.isOpen() = " + str(serialArduino.isOpen()))

# Mensagem de conexão feita
print("serialArduino.isOpen() = " + str(serialArduino.isOpen()))

# Loop para gerar o gráfico da comunicação serial
while True:
  print("Valor de Tensão")

  valoresLidos = serialArduino.readline(10)

  # Verifica se os valores são válidos
  try:
    entrValores = float(valoresLidos)
      print(entrValores)

      if entrValores >= 0:
        valores.append(entrValores)
        drawnow(plotvalores)

      else:
        print("Numero inválido")

    except ValueError:
      print("Erro de tentativa")
