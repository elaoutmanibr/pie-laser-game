# PIE Laser tag : partie raspberry pi

## `rf.py`
Ce fichier contient les fonctions de base permettant d'effectuer la communication radio avec les fusils et le reste des éléments du jeu.

Le tout est encapsulé dans une classe `Rf` qui va, à la construction d'un objeet, initialiser la connection au port de la raspberry pi et donc au module RF. Cette classe expose deux méthodes : `listen` et `send`.

## `listen`
Cette méthode va simplement afficher les messages reçus. Elle a pour vocation d'être modifiée et réutilisée pour effectuer les actions nécessaires au déroulement de la partie, comme par exemple mettre à jour les scores, ou envoyer d'autres informations à un fusil en particulier, voire à tous (pour indiquer le début ou la fin de la partie...)

## `send`
C'est cette méthode qui est chargée d'envoyer les messages radio aux fusils et autres équipements. Elle prend en argument un message (qui doit donc être construit par la partie du code qui souhaite l'envoyer).
