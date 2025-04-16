# transposition_fichier_c
============================================================================
 Guide d'utilisation des programmes

 Description :
 Ce projet contient deux programmes principaux permettant de manipuler les
 fichiers via des opérations de transposition et de détransposition.

 ============================================================================
 Programme : transpose_file.c
 Ce programme permet de :
 1. Transposer un fichier : Diviser un fichier en plusieurs parties sécurisées.
 Un ordre de transposition k est requis pour ces opérations.

 ============================================================================
 1. Pour transposer un fichier :
    Commande :
        ./transpose_file.c <fichier> <k>
    Paramètres :
        <fichier> : Nom du fichier à diviser.
        <k>       : Un entier représentant l'ordre de transposition utilisé
                    pour sécuriser.

 ============================================================================


 ============================================================================
 Programme : transpose_mdp.c
 Ce programme permet de :
 1. Transposer un fichier : Diviser un fichier en plusieurs parties sécurisées.
 2. Détransposer un fichier : Reconstituer un fichier original à partir de ses
    parties.
 Un mot de passe est requis pour ces opérations.

 ============================================================================
 1. Pour transposer un fichier :
    Commande :
        ./transpose_mdp.c <fichier> <mot_de_passe>
    Paramètres :
        <fichier>      : Nom du fichier à diviser.
        <mot_de_passe> : Mot de passe utilisé pour sécuriser.

 ============================================================================
 2. Pour détransposer un fichier :
    Commande :
        ./transpose_mdp.c -d <fichier> <mot_de_passe>
    Paramètres :
        -d             : Indique que l'opération de détransposition doit être 
                         effectuée.
        <fichier>      : Nom du fichier (ou base des fragments se qui est entre -KEY- et -PART-).
        <mot_de_passe> : Mot de passe utilisé pour reconstruire le fichier.

 ============================================================================
