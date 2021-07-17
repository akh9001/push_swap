mkdir ~/goinfre/Code
#mkdir ~/goinfre/Google
mkdir ~/goinfre/discord
mkdir ~/goinfre/Caches

rm -rf ~/Library/Application\ Support/Code
#rm -rf ~/Library/Application\ Support/Google
rm -rf ~/Library/Application\ Support/discord

ln -s ~/goinfre/Code ~/Library/Application\ Support/Code
#ln -s ~/goinfre/Google ~/Library/Application\ Support/Google
ln -s ~/goinfre/discord ~/Library/Application\ Support/discord

rm -rf ~/Library/Caches
ln -s ~/goinfre/Caches ~/Library/Caches
