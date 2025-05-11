/**
 * 投篮大赛得分计算
 *
 * 你正在记录一场采用特殊赛制的投篮比赛。这场比赛由若干回合组成，
 * 每回合的得分可能受到前几回合的影响。
 *
 * 题目描述：
 * 给定一个字符串数组 ops，表示一系列操作，每个操作遵循以下规则：
 *
 *  - 整数 x：表示本回合新获得的分数为 x。
 *  - "+"：表示本回合的得分是前两次有效得分之和。
 *  - "D"：表示本回合的得分是前一次有效得分的两倍。
 *  - "C"：表示取消前一次有效得分（移除上一次得分）。
 *
 * 请你计算并返回所有回合得分的总和。
 *
 * 输入格式：
 * - 一个字符串数组 ops，元素为整数形式的字符串，或 "+", "D", "C"。
 *
 * 输出格式：
 * - 一个整数，表示所有有效得分的总和。
 *
 * 示例：
 * 输入：["5", "2", "C", "D", "+"]
 * 输出：30
 *
 * 操作过程：
 * - "5" → [5]
 * - "2" → [5, 2]
 * - "C" → 移除 2 → [5]
 * - "D" → 2 * 5 = 10 → [5, 10]
 * - "+" → 5 + 10 = 15 → [5, 10, 15]
 * 总和为 5 + 10 + 15 = 30
 *
 * 提示：
 * - 1 <= ops.length <= 1000
 * - 所有操作合法：
 *   - "+" 操作前至少有两个得分；
 *   - "D" 和 "C" 操作前至少有一个得分。
 */
export function calculatePointsFromLine(line: string): number {
  const ops = line.trim().split(/\s+/);
  const stack: number[] = []

  for (const op of ops) {
    if (op === 'C') {
      stack.pop()
    } else if (op === 'D') {
      stack.push(stack[stack.length - 1] * 2)
    } else if (op === '+') {
      stack.push(stack[stack.length - 1] + stack[stack.length - 2])
    } else {
      stack.push(Number(op))
    }
  }

  return stack.reduce((a, b) => a + b, 0)
}
