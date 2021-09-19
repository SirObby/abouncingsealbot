## A Bouncing Seal
It's a fun bot with leveling and funny bouncing seal videos.

### Information
[Invite](https://discord.com/oauth2/authorize?client_id=880337914528145438&permissions=3197952&scope=bot%20applications.commands)\
[Support Server](https://discord.gg/kYGUzJAYHX)

### How to run locally
Dependencies:
1. zlib and openssl (D++ Dependencies)
2. G++ (bro idk just `sudo apt-get install g++`)
3. Linux (Untested on Windows)
4. CMake
Steps: 
1. `git clone --recursive https://github.com/SirObby/abouncingsealbot.git`
2. Change `src/config.example.json` to `src/config.json` and add token.
3. Run commands below in order. (Or you can use `build.sh`)
```
mkdir build
cd build
cmake ..
cd ..
cmake --build build
```
3. Move `discord-bot` in `/build/` directory to `/src/` (Automated by `build.sh`)

### How to Contribute
1. Make a PR.
2. DM me in Discord personally. (`Sir Obsidian#2640`)

### FAQ
**Q:** Why does the bot exist?\
**A:** Because it just does.

**Q:** Is this a good bot?\
**A:** I think you already know the answer, yes.

**Q.** Wha.. How?
**A.** Wha how what? The bot works as intended idk what u mean, you saying how this works? It works by working bro **it just works** as Todd Howard would put it.