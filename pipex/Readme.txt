# Pipex

Recreation du comportement de pipe dans Shell.


## Utilisation 

pour le test :
./pipex infile "cmd1" "cmd2" outfile
equivalent bash :
< infile cmd1 | cmd2 > outfile


### Exemple

./pipex infile.txt "grep hello" "wc -l" outfile.txt


#### Concepts 

- Pipes : Communication entre les commandes
- Fork : Duplication de processus (creer les process enfants)
- Dup2 : Redirection de file descriptors
- Execve : Remplacement de processus
- Waitpid : Attente des processus enfants


##### Fonctionnement

1. Ouvre le infile et outfile
2. Creation du pipe pour la communication
3. Fork les deux enfants  :
			Child1 : lit le infile et execute cmd1 et ecrit dans le pipe
			Child2 : lit le pipe et execute cmd2 et ecrit dans le outfile
4. Processus parent aui attend le retour des enfants


###### Auteur

Maximilien Musquer