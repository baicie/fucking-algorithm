type Something = string[];

type GetArrayItemType<T> = T extends (infer U)[] ? U : never;

type Result = GetArrayItemType<Something>;
