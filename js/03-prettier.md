# prettier

install

```shell
npm install --save-dev --save-exact prettier
```

Use the **.prettierignore** to ignore items

Two modes

- check (f.e. 'npx prettier --check .')
- write (fix, overwrite)

[prettier install](https://prettier.io/docs/en/install.html)

[prettier quick](https://github.com/azz/pretty-quick)

example output looks like:

```shell
🔍  Finding changed files since git revision null.
🎯  Found 5 changed files.
✍️  Fixing up js/01-npm.md.
✍️  Fixing up js/02-linter.md.
✅  Everything is awesome!
```

using pre-commit hook:

```shell
git commit -m "husky test"
🔍  Finding changed files since git revision 1dd3fe9.
🎯  Found 1 changed file.
✍️  Fixing up a.json.
✅  Everything is awesome!
[master 61690d4] husky test
```

Prettier for formatting and linters for catching bugs!
