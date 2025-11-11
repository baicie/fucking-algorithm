const data = {
  fillType: 20,
  staffList: [
    {
      staffId: "b30d2d99-a71b-11eb-8ce9-3448edf5b554",
      staffName: "孙旭",
      baseCode: "22018800713",
      fillStaffId: "57e0263102764380ab8a21d10885aa74",
      fillStaffName: "黄小文",
      fillType: 20,
      staffDataList: [
        {
          createId: "57e0263102764380ab8a21d10885aa74",
          createDate: "2023-12-05 17:16:29",
          modifyId: "57e0263102764380ab8a21d10885aa74",
          modifyDate: "2023-12-05 17:16:29",
          id: "274131d97fea44eab452fcbcfe4f80a0",
          dataTemplateId: "5c0ca7f28a7d4e2290290caca9739fb3",
          itemName: "计件工资",
          itemId: "a3771ef08f1946e29d01df38e7471bc4",
          itemCode: "itemJjgzPgeu",
          dataType: 20,
        },
        {
          createId: "57e0263102764380ab8a21d10885aa74",
          createDate: "2023-12-05 17:16:29",
          modifyId: "57e0263102764380ab8a21d10885aa74",
          modifyDate: "2023-12-05 17:16:29",
          id: "5aae1bd5f7644aa4b56fea613a8a4f8d",
          dataTemplateId: "5c0ca7f28a7d4e2290290caca9739fb3",
          itemName: "考勤工资",
          itemId: "425d4dc7627d4072a8c650488683db4a",
          itemCode: "itemKqgzIben",
          dataType: 10,
        },
        {
          createId: "57e0263102764380ab8a21d10885aa74",
          createDate: "2023-12-05 17:16:29",
          modifyId: "57e0263102764380ab8a21d10885aa74",
          modifyDate: "2023-12-05 17:16:29",
          id: "e68de66798b44bf1bcd2594643c21802",
          dataTemplateId: "5c0ca7f28a7d4e2290290caca9739fb3",
          itemName: "兼职工资",
          itemId: "2a9f97ee5dba460fa07506e25f53a964",
          itemCode: "itemJzgzPxdn",
          dataType: 10,
        },
      ],
    },
  ],
  belongMonth: 202306,
  staffName: null,
  baseCode: null,
  itemJjgzPgeu: 300,
  itemKqgzIben: 5,
  itemJzgzPxdn: 50,
  dataTemplateId: "5c0ca7f28a7d4e2290290caca9739fb3",
  dataTemplateName: "水电费5",
};

function deleteValueInclideStr(obj, string) {
  for (const key of Object.keys(obj)) {
    if (Array.isArray(obj[key])) {
      for (const item of obj[key]) {
        deleteValueInclideStr(item, string);
      }
    } else if (key.includes(string)) {
      delete obj[key];
    }
  }
}

deleteValueInclideStr(data, "item");

console.log("result: ", data);
