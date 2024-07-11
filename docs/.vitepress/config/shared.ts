import { defineConfig } from "vitepress";

export const shared = defineConfig({
  title: "algorithm",
  base: "/fucking-algorithm/",

  lastUpdated: true,
  cleanUrls: true,
  metaChunk: true,

  markdown: {
    math: true,
    codeTransformers: [
      // We use `[!!code` in demo to prevent transformation, here we revert it back.
      {
        postprocess(code) {
          return code.replace(/\[!!code/g, "[!code");
        },
      },
    ],
  },

  head: [
    ["meta", { name: "theme-color", content: "#5f67ee" }],
    ["meta", { property: "og:type", content: "website" }],
    ["meta", { property: "og:locale", content: "zh" }],
    [
      "meta",
      {
        property: "og:title",
        content: "fucking-algorithm",
      },
    ],
    ["meta", { property: "og:site_name", content: "fucking-algorithm" }],
    [
      "script",
      {
        src: "https://cdn.usefathom.com/script.js",
        "data-site": "AZBRSFGG",
        "data-spa": "auto",
        defer: "",
      },
    ],
  ],

  themeConfig: {
    logo: { src: "/logo.svg", width: 24, height: 24 },

    socialLinks: [
      { icon: "github", link: "https://github.com/baicie/fucking-algorithm" },
    ],
  },
});
