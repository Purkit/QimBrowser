# Qim Browser

Qim Browser is a lightweight, keyboard-centric web browser written in **C++** using **Qt** and **QtWebEngine**. It is inspired by **qutebrowser**, a popular keyboard-driven browser, but with the goal of providing a **native application** with better performance and a smaller footprint.

## Why Qim Browser?

I created Qim Browser because I wanted a **complete keyboard-centric workflow** for browsing the web. **qutebrowser** is a great browser that already provides this experience, but it is written in **Python** and relies on many dependencies, making it somewhat bulky and slower compared to a native application.

While **qutebrowser** is a good fit for those who love Vim-like keyboard navigation, the **Python-based architecture** introduces a few challenges for me:
- The size of dependencies is large.
- Performance could be better with a native implementation.
- I don't personally enjoy Python for building a **browser**.

Thus, I wanted to build something **smaller**, **faster**, and **more efficient** while maintaining the same seamless keyboard-based browsing experience.

### Key Benefits:
- **Native Application**: Built entirely in **C++** with **Qt**, ensuring a more responsive and faster experience.
- **Lightweight**: Minimal dependencies, resulting in a much smaller application size compared to Python-based solutions.
- **Keyboard-Centric**: Like **qutebrowser**, Qim Browser allows you to navigate the web using just your keyboard, making it ideal for users who prefer keyboard shortcuts and efficiency.
- **Faster**: Since it’s built in a compiled language, Qim Browser runs faster than the Python-based version, offering improved performance.

## Features

- **Keyboard Navigation**: Full support for Vim-like keybindings for web navigation and control.
- **Command Mode**: Quickly open websites, manage tabs, and perform actions via a command bar.
- **Minimal UI**: Clean and distraction-free browsing, similar to qutebrowser's UI philosophy.
- **Web Engine**: Uses **QtWebEngine** (built on Chromium) for modern web standards and fast rendering.
- **Customizable**: Easy-to-extend, with configuration options for keybindings, behavior, and more.

## Installation

### Requirements

- **Qt 6.x** (or Qt 5.x) with the **QtWebEngine** module
- **C++17** or later

### Build Instructions

   ```bash
   git clone https://github.com/Purkit/QimBrowser.git
   cd qim-browser
   mkdir build
   cd build
   cmake ..
   make
   ```

## Acknowledgements

- Inspired by qutebrowser for its minimalist, keyboard-driven design.

- Built using Qt 6 and QtWebEngine for modern web rendering.

