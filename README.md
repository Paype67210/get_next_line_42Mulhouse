<picture>
<img alt="Entête du dépôt Get_Next_Line." src="https://github.com/Paype67210/get_next_line_42Mulhouse/blob/main/Tools/cover-get_next_line-bonus.png">
</picture>

Le projet **GetNextLine** est un exercice clé dans le cursus de l'école 42, conçu pour renforcer les compétences en gestion de mémoire et en manipulation de fichiers en langage C. Le but est de coder une fonction permettant de lire le contenu d'un fichier ligne par ligne, en utilisant des variables statiques et en garantissant une gestion optimale de la mémoire.

### Objectifs du projet

- **Codage de la fonction get_next_line()** : Cette fonction doit permettre de lire un fichier texte référencé par son descripteur, une ligne à la fois.
- **Gestion des fichiers et des entrées standard** : La fonction doit pouvoir lire non seulement des fichiers mais aussi l'entrée standard (stdin).
- **Retour d'une ligne complète** : Chaque appel à la fonction doit retourner une ligne, y compris avec le caractère `\n` final, sauf si le fichier est à la fin et ne se termine pas par un `\n`.
- **Retour en cas d'erreur** : En cas d'erreur de lecture ou d'absence de données, la fonction doit retourner `NULL`.

### Compétences acquises

- **Gestion de la mémoire** : Utilisation des variables statiques pour gérer efficacement la mémoire tout au long de la lecture.
- **Optimisation des lectures de fichiers** : Implémentation de techniques pour limiter les appels système tout en assurant une lecture fluide.
- **Développement de fonctions robustes** : Création de fonctions capables de gérer divers cas d'erreurs et de fonctionner dans un environnement contraint.

### Concept clé : Variables statiques

Les variables statiques permettent de conserver des informations d'un appel à l'autre de la fonction, ce qui est essentiel pour pouvoir lire progressivement un fichier, ligne par ligne, sans perdre les données intermédiaires.

### Commandes clés et aspects techniques

- **Lecture de fichiers en C** : Utilisation des fonctions système comme `read()`, ainsi que des descripteurs de fichiers pour accéder aux données.
- **Gestion de la mémoire dynamique** : Utilisation de `malloc()` et `free()` pour allouer et libérer la mémoire utilisée par les lignes lues.
- **Manipulation des buffers** : Optimisation du processus de lecture en utilisant des buffers pour limiter les appels système et accélérer le traitement.

### Conclusion

Le projet **GetNextLine** est un excellent exercice pour perfectionner les compétences en C, en particulier en matière de gestion des ressources et de lecture de fichiers. C'est un projet fondamental pour tout développeur souhaitant maîtriser le C et les concepts de bas niveau en informatique.

### Ressources supplémentaires

- [Documentation POSIX sur les descripteurs de fichiers](https://pubs.opengroup.org/onlinepubs/9699919799/functions/open.html)
- [Tutoriel sur la gestion de la mémoire en C](https://www.learn-c.org/en/Memory_management)

