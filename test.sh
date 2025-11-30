#!/bin/sh

case "$1" in
  1)
    ./war <<EOF
Americas
Amarelo
6
Europa
Azul
5
Asia
Preto
14
Africa
Vermelho
5
Oceania
Rosa
2
EOF
    ;;
  2)
#   Check memory leaks
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./war <<EOF
Americas
Amarelo
6
Europa
Azul
5
Asia
Preto
14
Africa
Vermelho
5
Oceania
Rosa
2
EOF
    ;;
  *)
    echo "Uso: $0 {1|2}"
    exit 1
    ;;
esac
