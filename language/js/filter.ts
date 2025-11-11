const arr = [
  {
    objId: "c1f0e4e1-1cdd-11eb-8ce9-3448edf5b554",
    objName: "程荣珍",
    objType: 10,
  },
  {
    objId: "c1f0e4e1-1cdd-11eb-8ce9-3448edf5b554",
    objName: "梁玉华",
    objType: 10,
  },
  {
    objId: "309b6f3f-3def-11eb-8ce9-3448edf5b554",
    objName: "罗玲",
    objType: 10,
  },
];

function filterByCode(arr: Record<string, unknown>[], code: string) {
  return arr.filter((value, index, _arr) => {
    const find_index = _arr.findIndex((_item) => _item[code] === value[code]);

    return find_index === index;
  });
}

const res1 = filterByCode(arr, "objId");

console.log("res", res1);
