const name1: string = "linbudu";
const age: number = 24;
const male: boolean = false;
const undef: undefined = undefined;
const nul: null = null;
const obj: object = { name1, age, male };
const bigintVar1: bigint = 9007199254740991n;
const bigintVar2: bigint = BigInt(9007199254740991);
const symbolVar: symbol = Symbol("unique");

//null undefined 在没有开启 strictNullChecks 检查的情况下，会被视作其他类型的子类型
const arr6: [string, number?, boolean?] = ["linbudu"];
type TypeLength = typeof arr6.length;
