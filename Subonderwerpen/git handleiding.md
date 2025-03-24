---
created: 2025-03-11T14:23
updated: 2025-03-11T14:33
---
# Hoe gebruik je Git en GitHub om bij te dragen aan de repository [AGV](https://github.com/Yamairo/AGV) met behulp van Code::Blocks

## Vereisten  
- **Git**: [Download hier](https://git-scm.com/)  
- **Code::Blocks**: [Download hier](http://www.codeblocks.org/downloads)  

## Stappen  

Maak eerst een [github](https://github.com/readme) account

### 1. Git configureren  

Dit moet de eerste keer bij het gebruiken van git ingevoerd worden
```sh
git config --global user.name "JouwNaam"
git config --global user.email "jouwemail@example.com"
git --version
```

### 2 . Repository klonen
```sh
cd /pad/naar/jouw/projectmap
git clone https://github.com/Yamairo/AGV.git
cd AGV
```
### 3 . Project openen in Code::Blocks
1. Open Code:: Blocks.
2. Klik op File → Open.
3. Navigeer naar de map AGV en open het projectbestand (.cbp of .workspace).

### 4 . Wijzigingen opslaan en committen
Dmv git status bekijk je de huidige status van de repository
```sh
git status
git add .
git commit -m "Beschrijf je wijziging"
```
### 5 . Wijzigingen pushen naar GitHub
```sh
git push origin main
```
### 6 . Een pull request maken
Open git
```sh
cd /pad/naar/jouw/projectmap/AGV
git pull
```

Dit moet je altijd doen voordat je begint met werken aan code zodat je geen merge error kan krijgen