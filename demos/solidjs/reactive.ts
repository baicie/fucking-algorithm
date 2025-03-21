export type Getter<T> = () => T;

export type Setter<in out T> = {
  <U extends T>(
    ...args: undefined extends T
      ? []
      : [value: Exclude<U, Function> | ((prev: T) => U)]
  ): undefined extends T ? undefined : U;
  <U extends T>(value: (prev: T) => U): U;
  <U extends T>(value: Exclude<U, Function>): U;
  <U extends T>(value: Exclude<U, Function> | ((prev: T) => U)): U;
};

export type Signal<T> = [get: Getter<T>, set: Setter<T>];

export interface SignalOptions<T> extends Me

export function createSignal<T>(): Signal<T | undefined>;
export function createSignal<T>(value: T,options?: SignalOptions): Signal<T>;