const demo = "【】";

function validateString(value: string): boolean {
  const stack: string[] = [];
  for (const chat of value) {
    if (chat === "【") {
      stack.push(chat);
    } else if (chat === "】") {
      stack.pop();
    }
  }
  // 是否有错误
  return stack.length > 0;
}

console.log(validateString(demo));
