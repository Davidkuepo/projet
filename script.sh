mkdir projet
cd projet
pwd
sudo apt-get update
sudo apt-get install gedit
sudo apt-get install gcc
git clone "https://github.com/Davidkuepo/projet.git"
cd projet
gcc produit.c -o produit
gedit produit.c
./produit
