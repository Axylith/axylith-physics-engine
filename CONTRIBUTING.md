# Contributing to Axylith

Thank you for your interest in contributing to Axylith. This document
applies to all repositories under the Axylith organization.

Read this entire document before submitting a pull request. Contributions
that do not follow these guidelines will be closed without review.

---

## Repositories

Axylith is split across two public repositories:

**axylith** — The notebook application.
Renderer, .axl file format, observer, AI annotation, UI.
License: AGPL v3.

**axylith-physics** — The physics and simulation engine.
FP64 PDE solvers, structural mechanics, heat transfer, fluid dynamics.
License: AGPL v3.

Both repositories follow identical contribution terms. This document
governs contributions to either repository. If a rule refers to
"Axylith" it means both repositories unless stated otherwise.

---

## Contributor License Agreement (CLA)

By submitting a pull request to any Axylith repository, you agree
to the following:

### 1. License

Your contribution will be licensed under AGPL v3, the same license
as the repository you are contributing to. This is non-negotiable.
All code in Axylith repositories is AGPL v3.

### 2. Copyright

You retain full copyright of your contribution. You are free to use
your own code in other projects under any terms you choose.

### 3. Originality

You confirm that:

- The contribution is your original work.
- You have the legal right to submit it.
- The contribution is not copied from proprietary, patented, or
  incompatibly-licensed sources.
- The contribution does not contain code from any project whose
  license is incompatible with AGPL v3.

### 4. Commercial Use

Axylith operates an open-core model. The AGPL-licensed repositories
are freely available. Axylith also offers commercial licenses for
organizations that cannot comply with AGPL requirements. By default,
your contribution may be included in commercially-licensed versions
of Axylith. This helps sustain the project and fund continued open
source development.

**You may opt out of commercial inclusion.** To do so, the very
first line of your pull request description must be exactly:

```
COMMERCIAL-USE: NO
```

This must be:

- The **first line** of the pull request description.
- Written **exactly** as shown above — all caps, exact format.
- Present **before** any other text, description, or commentary.

Any other format, location, or phrasing will not be recognized
as a valid opt-out. This includes but is not limited to:

- Opt-out language buried anywhere else in the PR description.
- Informal statements such as "I don't want this used commercially."
- Retroactive opt-out requests after a PR has been merged.
- Opt-out language added in PR comments rather than the description.
- Variations in capitalization, spacing, or wording.

If the first line of your PR description is not exactly
`COMMERCIAL-USE: NO`, commercial use is permitted. No exceptions.

If you opt out, your contribution will remain in the AGPL repository
and will not be included in any commercially-licensed release. This
will be documented in our records and respected permanently.

### 5. Employer Authorization

Contributions submitted on behalf of an employer require that the
employer has authorized the contribution and agrees to these terms.
If you are unsure, get written permission before submitting.

### 6. Finality

Once a pull request is merged, the terms stated at the time of merge
are final. You cannot retroactively change the commercial use
permission of a merged contribution.

**By submitting a pull request, you confirm that you have read,
understood, and agree to all terms above.**

---

## What We Accept

Axylith has a clear technical vision. We accept contributions that
align with it. Before writing any code, open an issue describing
what you want to do and wait for approval from a maintainer.

### We welcome

- Bug fixes with tests that reproduce the issue.
- Performance improvements with before/after benchmarks.
- Documentation improvements and typo fixes.
- Test coverage improvements.
- Platform support (Wayland, macOS Cocoa, Windows Win32).
- Accessibility improvements.
- Localization and translation.

### We will likely accept (with discussion first)

For **axylith** (notebook):

- New .axl format features that maintain backward compatibility.
- New compute block types following the subkind system.
- Renderer optimizations that do not increase GPU usage above 5%.
- Observer integrations for new file watchers or terminal capture.
- New annotation types following the existing color system.

For **axylith-physics** (physics engine):

- New solver implementations (FEA, CFD, structural, thermal).
- Mesh generation improvements.
- Sparse matrix solver optimizations.
- New material models.
- Benchmark suites for solver validation.
- Integration with the notebook's FP64 computation engine.

### We will NOT accept

The following applies to both repositories:

- **External dependencies.** Axylith has one dependency: stb_truetype.h.
  The physics engine has zero. Do not add npm packages, pip packages,
  Boost, Qt, SDL, GLFW, Eigen, PETSc, or any other library. If you
  need functionality, implement it.

- **Electron, web views, or browser-based components** of any kind.

- **Changes that break the .axl binary format** without a migration path.

- **Features that require an internet connection.** Core functionality
  must work fully offline. No exceptions.

- **Telemetry, analytics, tracking, or any code that transmits user
  data.** This includes crash reporting that phones home. If code
  sends any data anywhere without explicit user action, it will be
  rejected and the contributor may be banned.

- **AI features that send user content to external servers** without
  explicit user action. BYOK (user provides their own API key) is
  acceptable because the user chose to connect.

- **Proprietary protocol dependencies.**

- **"Refactors" that restructure the project** without solving a
  specific, measurable problem.

- **Code that introduces floating-point precision below FP64** in
  any computation path. All calculations in Axylith are FP64.
  No FP32 shortcuts in solvers or evaluators.

---

## Code Standards

### Architecture

Both repositories:

- **Language:** C++20. No exceptions (`-fno-exceptions`). No RTTI (`-fno-rtti`).
- **Dependencies:** Zero external dependencies beyond stb_truetype.h (notebook only) and OS APIs.
- **Build:** CMake 3.20+. Must compile with both GCC and Clang.
- **Warnings:** Code must compile clean with `-Wall -Wextra -Wpedantic -Wshadow`.

Notebook specific:

- **Rendering:** Vulkan 1.3+ with dynamic rendering. No OpenGL. No legacy Vulkan.
- **Windowing:** Direct OS APIs (X11, Win32, Cocoa). No GLFW, no SDL.
- **GPU usage:** Under 5% during normal editing.

Physics engine specific:

- **Precision:** All solvers must use FP64. No FP32 approximations.
- **Solvers:** Must include convergence tests and validation against known analytical solutions.
- **Memory:** Preallocate where possible. No allocations in solver hot paths.

### Style

- 4-space indentation, no tabs.
- Braces on same line for functions and control flow.
- `snake_case` for functions and variables.
- `PascalCase` for structs.
- No `using namespace std;`. Prefix with `std::` explicitly.
- Minimize includes. Use forward declarations in headers where possible.
- Every `.h` file uses `#pragma once`.
- Every `.cpp` file includes its own `.h` first.

### Performance Targets

- CPU usage at idle: under 0.5%.
- RAM usage: under 20MB without models loaded.
- GPU usage during editing: under 5%.
- Solver startup: under 100ms for problems under 10,000 elements.
- .axl file load: under 1ms per page via mmap.

Include benchmark results in your PR description for any change
that affects performance.

### Testing

- All changes to the .axl format must include tests.
- All new solvers must include validation tests against known solutions.
- Tests must pass on both GCC and Clang.
- Tests must be deterministic. No random data, no timing-dependent assertions.
- CI/CD runs across GitLab CI, GitHub Actions, and CircleCI. All three
  must pass before merge.

---

## How to Contribute

### Small fixes (typos, docs, single-file bugs)

1. Fork the repository.
2. Create a branch: `git checkout -b fix/description`.
3. Make your change.
4. Run tests: `cd build && cmake .. && make -j$(nproc) && ctest`.
5. Submit a pull request with a clear description of what and why.

### Larger changes (features, new solvers, architecture)

1. **Open an issue first.** Describe what you want to build and why.
2. Wait for a maintainer to approve the direction.
3. Fork and create a branch: `git checkout -b feature/description`.
4. Implement in small commits with clear messages.
5. Include tests and benchmarks.
6. Submit a pull request referencing the approved issue.

**Do not submit large unsolicited pull requests.** They will be closed.
We value your time — discuss first so we can align on approach.

---

## Private and Custom Contributions

If you or your organization want to contribute code that is not
published in the open source repositories — proprietary integrations,
custom modules, or white-label features — contact us at
[contact email].

We offer custom licensing arrangements for private contributions.
This is available to everyone: individuals, companies, and institutions.
Pricing depends on scope and complexity.

---

## For Organizations and Competitors

Axylith is AGPL v3 licensed. This means:

- You **can** use Axylith internally, modify it, and run it on your
  servers.
- You **must** release your modifications under AGPL v3 if you
  distribute the modified software or provide it as a network service
  to others.
- You **cannot** take Axylith code, close-source it, and sell it as
  your own product.

If your organization needs a license that does not require publishing
modifications, contact us for a commercial license.

We welcome corporate sponsorship. If you want to fund specific features,
solvers, or integrations, we are happy to discuss arrangements that
benefit both your organization and the Axylith community.

---

## Enforcement

We reserve the right to:

- Close any pull request without explanation.
- Revert any merged contribution that introduces regressions, security
  vulnerabilities, or architectural violations.
- Ban contributors who act in bad faith.

Bad faith includes but is not limited to:

- Submitting code designed to introduce vulnerabilities or backdoors.
- Submitting code that communicates with external servers without
  explicit user consent.
- Submitting deliberately obfuscated or unmaintainable code.
- Repeatedly submitting rejected changes without addressing feedback.
- Using contribution history to claim ownership or control over
  the project.
- Competitive intelligence gathering disguised as contributions.
- Attempting to circumvent the CLA through creative phrasing,
  after-the-fact amendments, or social pressure.

We take security seriously. Any contribution that introduces a
vulnerability — whether intentional or accidental — will be reverted
immediately. Intentional security violations will result in a
permanent ban and may be reported to relevant authorities.

---

## Recognition

All contributors are credited in CONTRIBUTORS.md. Significant
contributions may be recognized on the Axylith website.

We value every contribution — from fixing a typo to implementing
a new FEA solver. Thank you for helping build a tool that respects
its users.

---

*This document applies to all repositories under the Axylith
organization. By submitting a pull request to any Axylith repository,
you confirm that you have read, understood, and agree to all terms
in this document.*

*Last updated: May 2026*
