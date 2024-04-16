# IO_2024
Carte et Soft pour les actionneurs de la coupe 2024 ( recyclage de la carte servo testeur )

Board : [Nucleo L432KC](https://www.st.com/en/evaluation-tools/nucleo-l432kc.html#documentation)

Depuis le haut niveau envoyer en utilisant l'UART un mesage de la forme "actionneur valeur\n"

Exemple pour tourner le servo 2 a la valeur 1200 en utlisant pyserial on peut faire write(b'2 1200\n')

