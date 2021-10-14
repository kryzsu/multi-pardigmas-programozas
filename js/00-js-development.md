# development mode

- application is listening in localhost
- debugging is available (source code) `node --inspect xxx.js`
- slow running http requests are proxied
- mostly ts
- fake data
- state can be deleted
- running on node.js javascript runtime built on Chrome's V8 JavaScript engine.
- small source code
- server side implementation

# production mode

- one big js
- minifying
- browserify
- always js
- the code is weird, entirely different from source code
- real data
- js running in the browser (ie, chrome, opera, brave)
- client side implementation

## simple http server (node.js)

```js
const http = require('http');

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello World');
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});
```

## browserify

"Browsers don't have the require method defined, but Node.js does.
With Browserify you can write code that uses require in the same way that you would use it in Node."

```shell
npm install -g browserify
```

`--debug` which enables debugging in the browser

## webpack

- popular
- not detect code usage
- hot module reloading support 

https://webpack.js.org/guides/getting-started/

https://webpack.js.org/

## testing

### jasmine

```shell
npm install --save-dev jasmine
```


```json
"scripts": { "test": "jasmine" }
```

https://jasmine.github.io/setup/browser.html

### jest

```shell
npm install --save-dev jest
```

## code coverage

Istanbul
https://istanbul.js.org/

- in case of mocha 'nyc'
- integrated onto jest (--coverage)

## useful npm packages

https://leanylabs.com/blog/npm-packages-for-nodejs/
https://exceed-team.com/tech/35+-awesome-npm-packages-for-productivity

https://github.com/selfrefactor/rambda
https://ramdajs.com/
https://lodash.com/
https://underscorejs.org/
https://joi.dev/
https://www.npmjs.com/package/rimraf
https://rxjs.dev/