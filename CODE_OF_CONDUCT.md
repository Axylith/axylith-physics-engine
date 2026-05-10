# Code of Conduct

This code of conduct applies to all Axylith repositories, issue
trackers, pull requests, and any communication channels associated
with the project.

---

## Principles

Axylith is built by people who care about quality, precision, and
respect. We expect the same from everyone who participates.

---

## Communication

**Be respectful.** Critique code, not people. "This function has a
bug on line 47" is fine. "You clearly don't know C++" is not.

**Be direct.** Say what you mean. Don't be passive-aggressive,
sarcastic, or dismissive. If you disagree with a decision, explain
why with technical reasoning.

**Use the right channel.**

- Technical questions about the codebase → open an issue.
- Bug reports → open an issue with reproduction steps.
- Feature requests → open an issue describing the problem it solves.
- Licensing, partnerships, private matters → email [contact email].
- Complaints about a rejected PR → email, not a public issue.

**Do not** call out maintainers or contributors publicly for not
responding, not accepting your PR, or making decisions you disagree
with. If you have a concern, send a polite email. We are a small
team and we will respond when we can.

---

## Pull Requests

**Respectful language only.** PR descriptions and code comments must
be professional. No insults, no condescension, no profanity directed
at people.

**Eligible work only.** All code must comply with the terms in
CONTRIBUTING.md. Read it before submitting.

**If your PR is not accepted:** That is our right. Do not resubmit
the same PR. Do not open issues demanding an explanation. Do not
spam maintainers. If you genuinely want to understand the decision,
send a polite email and we will explain when time permits.

**If your PR has no response:** We are a small team. Give us at
least 7 days before following up. One polite follow-up comment on
the PR is fine. Do not ping maintainers on social media, do not
open duplicate PRs, do not email repeatedly.

---

## Finding Work

If you want to contribute but don't know where to start:

1. Check open issues labeled `good first issue` or `help wanted`.
2. Read through recent issues to understand current priorities.
3. If nothing fits your skills, wait. New issues appear regularly.

**Do not** submit unsolicited refactors, rewrites, or "improvements"
without an approved issue. Open an issue first, get approval, then
write code. This saves everyone's time.

---

## AI-Assisted Contributions

AI tools (Claude, Copilot, ChatGPT, Cursor, etc.) are permitted
under the following conditions:

**You are learning, not outsourcing.** AI should help you understand
concepts, debug issues, and learn patterns. It should not write
your entire contribution.

**You must manually audit every line.** If you submit AI-generated
code, you are responsible for understanding what every line does,
why it exists, and how it fits into the architecture. "The AI
wrote it" is not an explanation.

**No vibe coding.** Contributions that are clearly generated
wholesale by AI — with no evidence that the contributor understands
the code — will be identified and flagged. Indicators include:

- Code that doesn't follow our style guide but follows AI defaults.
- Inconsistent naming conventions within the same PR.
- Comments that explain obvious things but miss the actual complexity.
- Code that works but uses patterns incompatible with our architecture.
- Inability to explain your own PR when asked.

**Three-strike policy:**

- **Strike 1:** PR rejected with explanation. You are asked to
  resubmit with evidence that you understand the code.
- **Strike 2:** PR rejected. Written warning that further
  AI-generated submissions without demonstrated understanding
  will result in a ban.
- **Strike 3:** Permanent ban from all Axylith repositories.

We are not anti-AI. We use AI tools ourselves. The line is between
"AI helped me learn and build" and "AI built it and I pasted it."
The first makes you a better developer. The second wastes our
review time and introduces code nobody understands.

---

## Spam and Harassment

**Do not:**

- Spam issues, PRs, or comments to get attention.
- Open duplicate issues or PRs after one is closed.
- Tag or ping maintainers repeatedly.
- Send unsolicited DMs on social media about contributions.
- Harass, threaten, or intimidate any participant.
- Dox or share private information about any participant.
- Use the project's communication channels for advertising,
  self-promotion, or unrelated content.

---

## Asking for Help

**Asking questions is encouraged.** Nobody knows everything. If you
don't understand something in the codebase, open an issue with
the label `question`. We'd rather explain something upfront than
review a PR built on a misunderstanding.

**Before asking:**

1. Read the relevant source code.
2. Read the CONTRIBUTING.md.
3. Search existing issues for your question.
4. If still unclear, ask. Include what you read and what confused you.

"I read vulkan_init.cpp and I don't understand why pick_gpu iterates
all families instead of stopping at the first graphics-capable one"
is a great question.

"How does the GPU stuff work?" is not. Be specific.

---

## Enforcement

Violations of this code of conduct will be handled as follows:

- **Minor violations** (tone issues, accidental spam): Private
  message from a maintainer asking you to adjust behavior.
- **Repeated minor violations:** Public warning on the relevant
  issue or PR.
- **Major violations** (harassment, malicious code, doxxing):
  Immediate and permanent ban without warning.
- **AI vibe coding:** Three-strike policy as described above.

All enforcement decisions are made by the project maintainers.
Decisions are final. Appeals can be sent via email but are not
guaranteed a response.

---

## Mentorship and Learning

Axylith is a complex codebase. Vulkan rendering, custom binary formats,
SIMD kernels, FP64 solvers — nobody walks in knowing all of this. We
don't expect you to. We expect you to be willing to learn.

### First-Time Contributors

If this is your first contribution to Axylith or to open source in
general:

1. Introduce yourself in an issue labeled `introduction`. Tell us
   what you're interested in (rendering, physics, file format, docs)
   and your experience level. No judgment — everyone starts somewhere.
2. A maintainer or experienced contributor will point you to a
   suitable first task and offer guidance.
3. Your first PR will receive detailed review with explanations,
   not just approvals or rejections.

### Buddy System

Experienced contributors can mentor newcomers:

- **If you're experienced:** When working on a larger PR, consider
  splitting off a self-contained piece and opening it as a
  `good first issue` with the label `mentored`. Include context
  on what the task is, where it fits, and what files to read.
  Volunteer to review the newcomer's PR and guide them through
  any feedback.

- **If you're new:** Look for issues labeled `mentored`. These
  have an experienced contributor attached who has agreed to help
  you through the process. They will review your code, explain
  the architecture, and help you get your first merge.

- **Pair contributions:** If you're working on something and want
  help, say so in the issue. Another contributor may join and you
  can split the work. Both contributors are credited equally.

We don't have a formal mentorship program with applications and
schedules. It's simpler than that — experienced people help newer
people when they can. If you help someone land their first PR,
that's recognized and appreciated.

### Learning Path

If you want to contribute but the codebase feels overwhelming:

1. **Read first.** Start with `types.h` (data structures),
   then `window.h/cpp` (simplest module), then `vulkan_init.h/cpp`.
2. **Build and run.** Get the project compiling on your machine.
   If you can't, open an issue — that's a valid contribution
   (our build instructions might be wrong).
3. **Read the tests.** `tests/axl_test.cpp` shows how the data
   structures work in practice.
4. **Fix a typo.** Seriously. Find a typo in a comment or doc,
   fix it, submit a PR. This gets you through the fork-branch-PR
   workflow with zero risk.
5. **Then pick a real issue.** By now you understand the workflow
   and have some familiarity with the code. Pick a `good first issue`
   and build something.

### Issue Labels for Contributors

- `good first issue` — Small, self-contained, suitable for newcomers.
- `mentored` — An experienced contributor has volunteered to guide
  whoever takes this on.
- `help wanted` — We need help but it requires some codebase familiarity.
- `question` — Ask anything about the codebase. No stupid questions.
- `discussion` — Architectural decisions open for community input.
- `blocked` — Waiting on something else. Don't start work on these.

---

## Community Values

Beyond the rules above, these are the values we build Axylith around:

**Teach, don't gatekeep.** If someone doesn't understand something,
explain it. If you don't have time, say "I can't help right now" —
don't ignore them or make them feel stupid.

**Quality over speed.** A well-tested PR that takes two weeks beats
a sloppy PR submitted in two hours. Take your time. We're building
something that lasts.

**Disagree constructively.** If you think a design decision is wrong,
explain your reasoning with technical evidence. "I think X would be
better because of Y benchmark/paper/experience" is productive.
"This is stupid" is not.

**Celebrate contributions.** When someone lands their first PR,
acknowledge it. When someone fixes a nasty bug, thank them. Small
recognition goes a long way.

**Respect boundaries.** Maintainers and contributors have lives
outside this project. Don't expect instant responses. Don't
pressure people to review faster. Don't make anyone feel guilty
for taking a break.

---

## Scope

This code of conduct applies to:

- All Axylith repositories (axylith, axylith-physics).
- Issue trackers and pull requests on GitLab and GitHub.
- Any future official communication channels (Discord, Zulip, etc.).
- Public interactions where you are representing the project.

It does not apply to your personal life, your other projects, or
your opinions outside of Axylith spaces.

---

*By participating in any Axylith repository or communication channel,
you agree to follow this code of conduct.*

*Last updated: May 2026*