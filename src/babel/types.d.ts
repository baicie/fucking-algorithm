import "@babel/types";

declare module "@babel/types" {
  interface CallExpression {
    isNew?: boolean;
  }
}
