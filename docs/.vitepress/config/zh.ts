import { defineConfig } from "vitepress";
import type { DefaultTheme } from "vitepress";
import sidebar from "./sidebar";

export const search: DefaultTheme.AlgoliaSearchOptions["locales"] = {
  zh: {
    placeholder: "搜索文档",
    translations: {
      button: {
        buttonText: "搜索文档",
        buttonAriaLabel: "搜索文档",
      },
      modal: {
        searchBox: {
          resetButtonTitle: "清除查询条件",
          resetButtonAriaLabel: "清除查询条件",
          cancelButtonText: "取消",
          cancelButtonAriaLabel: "取消",
        },
        startScreen: {
          recentSearchesTitle: "搜索历史",
          noRecentSearchesText: "没有搜索历史",
          saveRecentSearchButtonTitle: "保存至搜索历史",
          removeRecentSearchButtonTitle: "从搜索历史中移除",
          favoriteSearchesTitle: "收藏",
          removeFavoriteSearchButtonTitle: "从收藏中移除",
        },
        errorScreen: {
          titleText: "无法获取结果",
          helpText: "你可能需要检查你的网络连接",
        },
        footer: {
          selectText: "选择",
          navigateText: "切换",
          closeText: "关闭",
          searchByText: "搜索提供者",
        },
        noResultsScreen: {
          noResultsText: "无法找到相关结果",
          suggestedQueryText: "你可以尝试查询",
          reportMissingResultsText: "你认为该查询应该有结果？",
          reportMissingResultsLinkText: "点击反馈",
        },
      },
    },
  },
};
export const zh = defineConfig({
  lang: "zh",
  description: "fucking-algorithm",

  themeConfig: {
    logo: "/logo.svg",

    nav: [
      {
        text: "算法笔记",
        link: "/algorithm/algorithm",
        activeMatch: "/algorithm/",
      },
      {
        text: "vuejs设计与实现",
        link: "/vuejs-design",
        activeMatch: "/vuejs-design/",
      },
    ],

    sidebar: {
      "/algorithm/": {
        base: "/algorithm/",
        items: [
          {
            text: "简介",
            link: "algorithm",
          },
          ...sidebar,
        ],
      },
      "/vuejs-design/": {
        base: "/vuejs-design/",
        items: [
          {
            text: "1.权衡一下",
            link: "/1.权衡一下",
          },
          {
            text: "2.框架设计的核心要素",
            link: "/2.框架设计的核心要素",
          },
          {
            text: "3.Vue.js 3 的设计思路",
            link: "/3.Vue.js 3 的设计思路",
          },
          {
            text: "4.响应系统的作用与实现",
            link: "/4.响应系统的作用与实现",
          },
          {
            text: "5.非原始值的响应式方案",
            link: "/5.非原始值的响应式方案",
          },
        ],
      },
    },

    footer: {
      message: "基于 MIT 许可发布",
      copyright: `版权所有 © 2024-${new Date().getFullYear()}`,
    },

    docFooter: {
      prev: "上一页",
      next: "下一页",
    },

    outline: {
      label: "页面导航",
    },

    lastUpdated: {
      text: "最后更新于",
      formatOptions: {
        dateStyle: "short",
        timeStyle: "medium",
      },
    },

    langMenuLabel: "多语言",
    returnToTopLabel: "回到顶部",
    sidebarMenuLabel: "菜单",
    darkModeSwitchLabel: "主题",
    lightModeSwitchTitle: "切换到浅色模式",
    darkModeSwitchTitle: "切换到深色模式",
  },
});
