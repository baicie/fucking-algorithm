import { describe, it, expect } from "vitest";
import { createSignal, createEffect } from "../reactive";

describe("Solid.js Reactive 系统测试", () => {
  it("createSignal 应该正确创建信号并能读写值", () => {
    const [count, setCount] = createSignal(0);
    expect(count()).toBe(0);

    setCount(1);
    expect(count()).toBe(1);
  });

  it("createEffect 应该在依赖变化时自动执行", () => {
    const [count, setCount] = createSignal(0);
    let effectCount = 0;

    createEffect(() => {
      count(); // 订阅count信号
      effectCount++;
    });

    expect(effectCount).toBe(1); // 初始执行一次

    setCount(1);
    expect(effectCount).toBe(2); // 值变化后重新执行
  });

  it("effect 应该只在依赖变化时执行", () => {
    const [count1, setCount1] = createSignal(0);
    const [count2, setCount2] = createSignal(0);
    let effectCount = 0;

    createEffect(() => {
      count1(); // 只订阅 count1
      effectCount++;
    });

    setCount2(1); // 不应触发 effect
    expect(effectCount).toBe(1);

    setCount1(1); // 应该触发 effect
    expect(effectCount).toBe(2);
  });
});
