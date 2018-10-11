# ReasonML React Material-Ui Example

This is an attempt to produce a basic Material UI example, using the React Material-Ui library, and ReasonML, using:

- https://github.com/jsiebern/bs-material-ui (provides ReasonML bindings to the JavaScript Material-Ui React library
- https://github.com/kdkeyser/reasonml-docker (provides a Docker containing all dependencies and developemnt tools for ReasonML / React)

Goal is to recreate the example from https://medium.com/codingthesmartway-com-blog/getting-started-with-material-ui-for-react-material-design-for-react-364b2688b555 (not there yet)

## Run Project

```sh
npm install
npm start
# in another tab
npm run webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up `src/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

## Build for Production

```sh
npm run build
npm run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version.

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.
