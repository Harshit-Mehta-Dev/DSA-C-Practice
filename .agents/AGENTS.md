# Repository Branching Strategy

- **Isolated Branches**: When creating a new file or folder for a specific topic (e.g., sorting, linear search, functions), you MUST create a separate, isolated Git branch for that topic.
- **Orphan Branches**: If it is a completely new topic, create an orphan branch (`git checkout --orphan <branch-name>`), remove all unrelated files (`git rm -rf .`), add ONLY the relevant files/folders for that topic, commit, and push. **IMPORTANT: ALWAYS checkout and include the `README.md` file from `main` branch when creating a new orphan branch!** (`git checkout main -- README.md`).
- **Updating Existing Branches**: If modifying an existing file or adding a file that belongs to an already created topic branch, check out that specific branch, make the changes, commit, and push, rather than combining all files into one branch.
- Do NOT merge unrelated files into topic branches. Each topic branch should strictly contain its own material.
