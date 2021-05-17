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

### Working with branches
There are 4 branches, with 3 of them designated for each one of us. The main branch will be our main reference for working code. The 3 branches are respectively named with our first name. Before you start working on your branch, first check that you have the latest branches by typing `git branch -a`. If you don't see 4 branches, type `git pull origin`.  (Note: **anytime** you do a git pull, make sure you commit any local changes!! You might have to resolve merge conflicts.)


1. To switch to your own branch, type `git checkout <your name>`. 
2. `git pull origin main`
3. `git merge origin/main` (Restore any files if needed ig lol). If this command overwrites your xcode files, go to OpenFrameworks project generator and click Update. 
5. `git checkout`. You are now on your own branch. Double check with `git branch`. Stage and commit files as usual. To check what you are pushing, type `git diff --stat --cached origin/<branch>.
6. `git push origin <current_branch>` (Remember check ur current branch with `git branch`)
7. On Github, open a new pull request and merge your commit with the main branch. 
