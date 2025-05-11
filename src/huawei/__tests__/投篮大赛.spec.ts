// calculatePoints.test.ts
import { describe, it, expect } from "vitest";
import { calculatePointsFromLine } from "../投篮大赛";

describe("calculatePoints", () => {
  it("示例 1: [5, 2, C, D, +] => 30", () => {
    expect(calculatePointsFromLine("5 2 C D +")).toBe(30);
  });

  it("只有数字的情况", () => {
    expect(calculatePointsFromLine("5 3 7")).toBe(15);
  });

  it("连续使用 D 操作", () => {
    expect(calculatePointsFromLine("5 D D")).toBe(5 + 10 + 20); // [5, 10, 20]
  });

  it("连续使用 C 操作", () => {
    expect(calculatePointsFromLine("5 3 C C")).toBe(0);
  });

  it("使用 + 操作", () => {
    expect(calculatePointsFromLine("1 2 + +")).toBe(1 + 2 + 3 + 5); // [1, 2, 3, 5]
  });

  it("混合所有操作", () => {
    expect(calculatePointsFromLine("1 C 2 D 3 +")).toBe(16); // [2, 4, 3, 7]
  });
});
