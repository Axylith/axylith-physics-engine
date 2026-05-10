# Axylith

[![License: AGPL v3](https://img.shields.io/badge/License-AGPL_v3-blue.svg)](https://www.gnu.org/licenses/agpl-3.0)
[![Snyk](https://snyk.io/test/github/Axylith/axel/badge.svg)](https://snyk.io/test/github/Axylith/axel)
[![SonarCloud](https://img.shields.io/badge/Quality-SonarCloud-F3702A?logo=sonarcloud)](https://sonarcloud.io/)
[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://isocpp.org/)
[![Vulkan 1.3](https://img.shields.io/badge/Vulkan-1.3-red.svg)](https://www.vulkan.org/)
[![Zero Dependencies](https://img.shields.io/badge/Dependencies-0-brightgreen.svg)](#)
[![Open Collective](https://img.shields.io/opencollective/all/axylith?label=Backers&color=brightgreen)](https://opencollective.com/axylith)
[![GitHub Sponsors](https://img.shields.io/github/sponsors/Axylith?label=Sponsors&color=ea4aaa)](https://github.com/sponsors/Axylith)

A local-first computational research workbench. Notebook + physics engine + FP64 computation + local AI in one binary. Zero external dependencies. Offline by default. AGPL v3.

**Axylith replaces $7,000/year of proprietary tools with a single free binary.**

---

## What is Axylith?

Axylith is a research workbench that combines note-taking, verified computation, physics simulation, and AI annotation in one offline C++ binary. Every computation is FP64 and traceable. Every AI output is verified against local sources. Your data never leaves your machine unless you choose to sync.

It is not a note-taking app. It is an IDE for thinking.

## Why?

Researchers are locked into proprietary tools that cost thousands per year and depend on license servers that go down. In May 2025, a ransomware attack took MATLAB offline for 5 million users for over a week. Students couldn't submit theses. Researchers couldn't work. One user pirated the software they already paid for because the license server was unreachable.

Axylith eliminates this dependency entirely. No license server. No internet requirement. No subscription to use any feature. One binary, works offline, forever.

## Key Technical Decisions

- **Language:** C++20, zero external dependencies (one header: stb_truetype.h)
- **Rendering:** Vulkan 1.3 with dynamic rendering — not Electron
- **File format:** Custom .axl binary format, 12-byte blocks, two-stage compression (dictionary + Huffman). An entire research career fits in 9.8MB
- **AI:** Custom inference engine with hand-written SIMD ASM (SSE4.2/AVX2/AVX-512/NEON). Runs locally on consumer hardware
- **Computation:** FP64 recursive descent evaluator. Every number is computed, never hallucinated
- **Windowing:** Direct OS APIs (X11, Win32, Cocoa). No GLFW, no SDL
- **Observation:** Watches file changes, terminal output, render results. Correlates them with your notes automatically

## Current Progress

- 27/27 tests passing on .axl binary format
- Vulkan 1.3 initialization through swapchain creation
- Threaded init (window appears in 0.3ms, Vulkan loads in background)
- Resource monitoring (CPU, RAM, GPU tracking per session)
- CI/CD across three providers (GitLab CI, GitHub Actions, CircleCI)
- Sanitizer builds (AddressSanitizer, UBSanitizer) and static analysis (clang-tidy)

## Building

```bash
git clone https://github.com/Axylith/axel.git
cd axel
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j$(nproc)
./axylith
```

Requirements: C++20 compiler (GCC 13+ or Clang 16+), Vulkan SDK, X11 dev headers.

```bash
# Ubuntu/Debian
sudo apt install g++ cmake libvulkan-dev libx11-dev vulkan-validationlayers

# Arch
sudo pacman -S gcc cmake vulkan-devel libx11 vulkan-validation-layers
```

## Running Tests

```bash
cd build
ctest --output-on-failure
```

## Project Structure

```
src/
  main.cpp           — entry point, event loop, threaded init
  window.cpp/.h      — X11 windowing
  vulkan_init.cpp/.h  — Vulkan instance, surface, GPU, device
  swapchain.cpp/.h   — swapchain creation and image views
  renderer.cpp/.h    — command pool, sync objects, render loop
  monitor.h          — CPU/RAM/GPU resource tracking
  types.h            — shared structs, timer, format types
tests/
  axl_test.cpp       — .axl format tests (27/27 passing)
```

## Repositories

| Repository | Description | License |
|-----------|-------------|---------|
| [axylith](https://github.com/Axylith/axel) | Notebook application | AGPL v3 |
| [axylith-physics](https://gitlab.com/axylith/axylith-physics) | Physics and simulation engine | AGPL v3 |

## Contributing

Read [CONTRIBUTING.md](CONTRIBUTING.md) before submitting a pull request. All contributions require agreement to our CLA. First-time contributors are welcome — look for issues labeled `good first issue` or `mentored`.

## License

AGPL v3. See [LICENSE](LICENSE) for the full text.

The software is free for everyone — students, researchers, individuals. Commercial licenses are available for organizations that cannot comply with AGPL. Contact founders@axylith.com.

---

## Powered By

[![Snyk](https://img.shields.io/badge/Security-Snyk-4C4A73?logo=snyk)](https://snyk.io/)
[![SonarCloud](https://img.shields.io/badge/Quality-SonarCloud-F3702A?logo=sonarcloud)](https://sonarcloud.io/)
[![Fastly](https://img.shields.io/badge/CDN-Fastly-FF282D?logo=fastly)](https://www.fastly.com/)
[![Cloudflare](https://img.shields.io/badge/Edge-Cloudflare-F38020?logo=cloudflare)](https://www.cloudflare.com/)
[![GitLab](https://img.shields.io/badge/CI-GitLab-FC6D26?logo=gitlab)](https://gitlab.com/)
[![CircleCI](https://img.shields.io/badge/CI-CircleCI-343434?logo=circleci)](https://circleci.com/)

## Sponsors & Backers

[[Become a sponsor](https://opencollective.com/axylith)] [[Become a backer](https://github.com/sponsors/Axylith)]

<a href="https://opencollective.com/axylith"><img src="https://opencollective.com/axylith/sponsors.svg?width=890" /></a>
<a href="https://opencollective.com/axylith"><img src="https://opencollective.com/axylith/backers.svg?width=890" /></a>