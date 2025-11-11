// const std = @import("std");

// pub fn main() void {
//     std.debug.print("Hello, World!\n", .{});
// }

// const std = @import("std");

// pub fn main() !void {
//     const variable: u16 = 666;
//     std.debug.print("fmt: []const u8{}\n", .{variable});
// }

// const @"demo what" = 0xff;
// const @"demo what2" = 123312312;

// const c = @import("std").c;

// pub extern "c" fn @"error"() void;
// pub extern "c" fn @"fstat$INODE64"(fd: c.fd_t, buf: *c.Stat) c_int;

// const Color = enum {
//     red,
//     @"really red",
// };

// const color: Color = .@"really red";

// const std = @import("std");

// pub fn main() !void {
//     const a: u16 = undefined;
//     a = 1;
//     std.debug.print("a: {}\n", .{a});
// }

// const one_billion = 1_000_000_000;
// const binary_mask = 0b1_1111_1111;
// var permissions = 0o7_5_5;
// const big_address: u65535 = 0xFF80_0000_0000_0000;
// const bri = 0b1001;

// comptime {
//     const a: i32 = 1;
//     const b: i32 = 0;
//     const c = a / b;
//     _ = c;
// }

const print = @import("std").debug.print;

// pub fn main() !void {
//     const char: u8 = 'h';
//     const char_num: u8 = 104;
//     print("{c}\n", .{char});
//     print("{c}\n", .{char_num});
// }

// pub fn add(a: u8, b: u8) u8 {
//     return a + b;
// }

// pub fn max(comptime T: type, a: T, b: T) T {
//     return if (a > b) a else b;
// }

// pub fn main() !void {
//     const c = add(1, 2);
//     print("c: {}\n", .{c});
// }

// fn addForttyTwo(x: anytype) @TypeOf(x) {
//     return x + 42;
// }

// pub fn main() !void {
//     const message = [5]u8{ 104, 101, 108, 108, 111 };
//     print("{s}\n", .{message});
//     print("{c}\n", .{message[0]});
// }

// pub fn main() !void {
//     const matrix = [3][3]f32{
//         [_]f32{ 1.0, 2.0, 3.0 },
//         [_]f32{ 4.0, 5.0, 6.0 },
//         [_]f32{ 7.0, 8.0, 9.0 },
//     };

//     for (matrix, 0..) |arr_val, arr_index| {
//         for (arr_val, 0..) |val, index| {
//             print("元素{}-{}是: {}\n", .{ arr_index, index, val });
//         }
//     }
// }

// pub fn main() !void {
//     const small = [5]i32{ 1, 2, 3, 4, 5 };
//     const big: [15]i32 = small ** 3;
//     print("{any}\n", .{big});
// }

// pub fn main() !void {
//     const a = [5]i32{ 1, 2, 3, 4, 5 };
//     const b = [_]i32{ 1, 2, 3, 4, 5, 6 };
//     const c = a ++ b;
//     print("{any}\n", .{c});
// }

// pub fn main() !void {
//     const hello_world_in_c =
//         \\#include <stdio.h>
//         \\
//         \\int main(int argc, char **argv) {
//         \\    printf("hello world\n");
//         \\    return 0;
//         \\}
//     ;
//     print("{s}\n", .{hello_world_in_c});
// }

// pub fn main() !void {
//     const arr = [_]i32{make(3)} ** 10;
//     print("{any}\n", .{arr});
// }

// pub fn make(x: i32) i32 {
//     return x + 1;
// }

// pub fn main() !void {
//     const ele_4 = @Vector(4, i32);

//     const a = ele_4{ 1, 2, 3, 4 };
//     const b = ele_4{ 5, 6, 7, 8 };
//     const c = a + b;
//     print("Vector c is {any}\n", .{c});
//     print("the third element of Vector c is {}\n", .{c[2]});

//     const arr = [_]f32{ 1.0, 2.0, 3.0, 4.0, 5.0 };
//     const vec: @Vector(5, f32) = arr;
//     print("Vector vec is {any}\n", .{vec});

//     const vec2: @Vector(2, f32) = arr[0..2].*;
//     print("Vector vec2 is {any}\n", .{vec2});
// }

// pub fn main() !void {
//     const bytes = "hello";
//     print("{}\n", .{@TypeOf(bytes)});
//     print("{d}\n", .{bytes.len});
//     print("{c}\n", .{bytes[1]});
//     print("{d}\n", .{bytes[5]});
//     print("{}\n", .{'e' == '\x65'});
//     print("{d}\n", .{'\u{1f4a9}'});
// }

pub fn mmain() !void {
    const scalar: u32 = 5;
    const result: @Vector(4, u32) = @splat(scalar);
    _ = result;
}
