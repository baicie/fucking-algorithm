const files = require("./macros/files.macro.js");

console.log("src files:");
console.log(files("./src"));
console.log("macro files:");
console.log(files("./macros"));
