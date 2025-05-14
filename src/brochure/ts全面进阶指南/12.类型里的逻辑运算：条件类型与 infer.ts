type PropType<T, K extends keyof T> = T extends {
  [Key in K]: infer R;
}
  ? R
  : never;
type A = PropType<{ name: string }, "name">;
type B = PropType<{ name: string; age: number }, "age" | "name">;

type ReverseKeyValue<T extends Record<string, unknown>> = T extends Record<
  infer K,
  infer V
>
  ? Record<V & string, K>
  : never;
type C = ReverseKeyValue<{ key: "value" }>;

type PromiseType<T> = T extends Promise<infer U> ? U : T;

type D = PromiseType<Promise<number>>;
type E = PromiseType<number>;

// type PromiseValue<T> = T extends Promise<infer V>
//   ? V extends Promise<infer N>
//     ? N
//     : V
//   : T;
type PromiseValue<T> = T extends Promise<infer V> ? PromiseValue<V> : T;

type F = PromiseValue<Promise<Promise<Promise<boolean>>>>;
