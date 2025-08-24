# so\_long – Petit jeu 2D avec MinilibX

## 🚀 Introduction

`so_long` est un projet graphique de l’école 42.
L’objectif : créer un petit jeu en 2D dans lequel le joueur doit **collecter tous les objets** de la carte avant d’atteindre la sortie, le tout en utilisant la **MiniLibX** (bibliothèque graphique de 42).

Ce projet introduit :

* La **programmation événementielle** (gestion du clavier, fermeture de fenêtre).
* La **manipulation de fichiers** pour lire et valider une map.
* La **gestion d’un rendu graphique** avec des sprites.
* La **structuration d’un projet de jeu** en C.

---

## 🛠️ Fonctionnalités

* Chargement d’une carte au format `.ber`.
* Vérification stricte de la validité de la map (forme rectangulaire, murs fermés, présence d’un joueur, d’au moins un collectible et une sortie).
* Affichage graphique avec **MiniLibX**.
* Déplacement du joueur avec les touches (WASD ou flèches).
* Comptage et affichage du nombre de coups.
* Collecte des objets → la sortie devient accessible seulement une fois tous récupérés.
* Fermeture propre de la fenêtre via la croix ou la touche `ESC`.

---

## 🤓 Structure du projet

* **`so_long.c`** → point d’entrée du jeu.
* **`game/`** → logique du gameplay :

  * `init_game.c` → initialisation des variables, textures et fenêtre.
  * `move.c` → gestion des déplacements et des collisions.
  * `render.c` → affichage des sprites.
* **`map/`** → parsing et validation des maps :

  * `map_reader.c` → lecture du fichier `.ber`.
  * `validate.c` → vérification des règles.
  * `flood_fill.c` → vérification de l’accessibilité des collectibles et de la sortie.
* **`utils/`** → fonctions auxiliaires (`ft_split`, mini printf, libération mémoire…).
* **`maps/`** → exemples de maps valides et tests d’erreurs.
* **`assets/`** → sprites (au format `.xpm`).

---

## 🥸 Subtilités & enjeux du projet

### 🔹 Parsing robuste

* Vérification que la map est **rectangulaire**.
* Vérification que la map est **entourée de murs**.
* Vérification de la présence :

  * d’un seul joueur,
  * d’au moins un collectible,
  * d’au moins une sortie.

### 🔹 Accessibilité

* Utilisation d’un algorithme **flood fill** pour vérifier que le joueur peut atteindre tous les collectibles **et** la sortie.

### 🔹 Gestion graphique

* Chargement et affichage des sprites avec MiniLibX.
* Boucle de rendu (`mlx_loop`) pour gérer les events.

### 🔹 Événements clavier

* Déplacements avec `WASD` ou flèches.
* Quitter avec `ESC` ou la croix de la fenêtre.

### 🔹 Gestion mémoire

* Libération de la map et des ressources graphiques à la fermeture.
* Gestion des erreurs propres (fichier introuvable, map invalide, allocation échouée).

---

## ⚡️ Conseils pour refaire le projet

1. Commence par écrire un **parser de map** qui vérifie toutes les règles.
2. Implémente le **flood fill** pour tester la validité de la map.
3. Ajoute l’initialisation graphique avec **MiniLibX**.
4. Implémente le rendu statique (affichage de la map).
5. Ajoute la **gestion des déplacements** et du compteur de coups.
6. Ajoute les conditions de victoire (tous les collectibles + sortie atteinte).

---

## 📖 Ressources utiles

* 📌 [Documentation MiniLibX (42 Paris)](https://harm-smits.github.io/42docs/libs/minilibx)
* 📌 [Algorithme Flood Fill expliqué](https://en.wikipedia.org/wiki/Flood_fill)
* 📌 [Gestion des événements avec MiniLibX](https://qst0.github.io/ft_libgfx/man_mlx_loop.html)
* 📌 [Exemple de projet so\_long sur GitHub](https://github.com/42Paris/so_long)
* 📌 [Big O Cheat Sheet – Complexité des algorithmes](https://www.bigocheatsheet.com/)

---

## 🎯 Objectif final

À la fin de `so_long`, tu auras appris à :

* Travailler avec une **librairie graphique**.
* Gérer un projet C structuré (modules, parsing, utils, assets).
* Implémenter un **algorithme de validation** (flood fill).
* Construire un **petit jeu fonctionnel** !

