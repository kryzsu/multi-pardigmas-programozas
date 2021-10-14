# linters

Linters have two categories of rules

- Formatting rules: eg: max-len, no-mixed-spaces-and-tabs, keyword-spacing, ...
- Code-quality rules: eg no-unused-vars, no-extra-bind, no-implicit-globals, ...

install

```shell
npm install eslint --save-dev
npx eslint --init
```

There are rules. We can ignore any of them or chage the importance of it.

- "off" or 0 - turn the rule off
- "warn" or 1 - turn the rule on as a warning (doesn't affect exit code)
- "error" or 2 - turn the rule on as an error (exit code will be 1)

[rules](https://eslint.org/docs/rules/)

Prettier for formatting and linters for catching bugs!
