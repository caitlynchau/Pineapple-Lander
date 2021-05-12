# Pineapple Lander 🍍
### Caitlyn Chau, Swati Chayapathi, Iman Ereiqat

CS 134 Computer Game Design Final Project

Spring 2021

---
### Setting up Git on your openFrameworks project
1. To add git to your openFrameworks project, navigate to your `myApps/PineappleLander` folder and type `git init`.
2. Add your modified files to staging and commit as normal. `git commit -m "discovered secret formula"` Add any unnecessary files (xcode environments or auto generated files) to the .gitignore file and commit that as well. 
    - Make sure you are on the main branch. If your git bash is outdated like mine, always rename the master branch to "main" by typing `git branch -m master main`.
4. Add the remote from this repository to your local one. `git remote add origin https://github.com/caitlynchau/Pineapple-Lander.git`
5. Pull in the changes from the remote repository by typing `git pull origin main --allow-unrelated-histories`. There will probably be a merge conflict so be sure to resolve those and commit. (I use VS Code to look at the differences). 
