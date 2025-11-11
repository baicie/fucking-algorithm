const reg = /\【.*\】/;

const arr = [
  {
    labelCode: "1",
    labelName: "demo",
    labelType: "sal",
  },
  {
    labelCode: "1",
    labelName: "demo2",
    labelType: "sal",
  },
];

const str = "【demo】【demo3】";

function matchString(str: string) {
  const match: string[] = [];
  let temp_str = "";

  for (const chat of str) {
    if (chat === "【") {
      temp_str = "";
    } else if (chat === "】") {
      match.push(temp_str);
      temp_str = "";
    } else {
      temp_str += chat;
    }
  }

  return match;
}

function deleteArrItem(arr: any[], codes: string[]) {
  return arr.filter((item) => !codes.includes(item.labelName));
}

const codes = matchString(str);
const res = deleteArrItem(arr, codes);

console.log(codes, res);
