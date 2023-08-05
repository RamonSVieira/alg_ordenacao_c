#!/bin/bash

# Nome do arquivo que armazenará todas as saídas
output_file="saida_total.txt"

# Limpa o arquivo de saída antes de iniciar
> "$output_file"

# Loop pelas pastas (caso01, caso02, ..., caso05)
for dir in caso*/; do
  # Loop pelos arquivos em cada pasta
  for file in "$dir"exemplo-*.txt; do
    # Obtém o nome do arquivo (exemplo-10000-1.txt, exemplo-20000-2.txt, etc.)
    filename=$(basename "$file")

    # Executa o programa teste_ordenacao para cada arquivo de entrada
    # O resultado é concatenado ao arquivo de saída total
    echo "Teste: $file" >> "$output_file" # Modificação feita aqui
    ./atividade/teste_ordenacao -m < "$file" >> "$output_file"
    echo "" >> "$output_file" # Adiciona uma linha em branco entre cada teste
  done
done
