
- [npm](#npm)
  - [run script](#run-script)

# npm

creating the npm project

```shell
npm init
```

This command will create a new **package.json**, like this:

```json
{
  "name": "tutor",
  "version": "1.0.0",
  "description": "",
  "main": "index.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "author": "",
  "license": "ISC"
}
```

Manages

- dependency
- package

install package to production

```shell
npm install PACKAGE
```

dependency (and related transitive dependency) is installed into the **node_modules** folder.
package.json ins updated

```json
"dependencies": {
    "PACKAGE": "^1.0.2"
  }
```

`--save-dev` or `-D` parameter for developer dependency (devDependency of package.json is updated).

list installed packages:

```shell
npm ls
```

run tests:

```shell
npm test
```

       1.2.3  
       ^ ^ ^  
       | | `-- Patch version. Update for every change.  
       | `---- Minor version. Update for API additions.  
       `------ Major version. Update for breaking API changes. 

update all packages

```shell
npm update
```

create new version:

npm has a special command called `npm version` which will update your  
     package.json file for you, and also commit the change to git if your  
     project is a git repository.

uninstall package: **npm rm PACKAGE** or **npm uninstall** 


## run script

```shell
npm run TASK
```

```json
{
  "scripts": {
    "watch": "webpack --watch --progress --colors --config webpack.conf.js",
    "dev": "webpack --progress --colors --config webpack.conf.js",
    "prod": "NODE_ENV=production webpack -p --config webpack.conf.js",
  }
}

```
