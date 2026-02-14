import numpy as np
import matplotlib.pyplot as plt

try:
    # IMPORTAÇÃO: Lê a matriz de ângulos que o código C salvou no arquivo
    dados = np.loadtxt("dados_cristal.txt")

    # SIMULAÇÃO DE MICROSCOPIA (POM):
    # Aplicação da Lei de Malus. A intensidade de luz que atravessa 
    # polarizadores cruzados depende do dobro do ângulo da molécula.
    # O resultado gera as famosas "franjas" ou "escovas" pretas.
    pom = np.sin(2 * dados)**2

    # VISUALIZAÇÃO GRÁFICA:
    plt.figure(figsize=(6, 5))
    
    # Exibição da matriz como uma imagem. 'inferno' é um mapa de cores térmico.(usado como paleta em astrofotografias)
    plt.imshow(pom, cmap='inferno', origin='lower')
    
    # Barra lateral para indicar a intensidade da luz
    plt.colorbar(label='Intensidade de Luz')
    
    plt.title("Teste de Conexão: C -> Python (POM)")
    plt.show()

    print("Sucesso: Dados convertidos para imagem!")

except Exception as e:
    # Captura erros (como o arquivo não ser encontrado) e avisa
    print(f"Erro: {e}")