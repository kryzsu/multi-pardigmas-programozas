# husky

install it in folder of project root (.git folder)

```shell
npx husky install
```

add any command to pre-commit hook:

```shell
npx husky add .husky/pre-commit "pretty-quick --staged"
```

practice

```shell
git init
npm init
npm install husky --save-dev
npm install --save-dev prettier pretty-quick
npx husky add .husky/pre-commit "npm test"
git add *
git commit -m "husky test"
```
