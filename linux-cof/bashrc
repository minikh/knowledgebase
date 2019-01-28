export VAULT_ADDR='http://127.0.0.1:8200'
PATH=$PATH:/home/minikh/vault

# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
export HISTTIMEFORMAT="%h/%d-%H:%M:%S "
export HISTSIZE=200000
export HISTFILESIZE=200000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm|xterm-color|*-256color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
#force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    if [[ ${EUID} == 0 ]] ; then
        PS1='${debian_chroot:+($debian_chroot)}\[\033[01;31m\]\h\[\033[01;34m\] \W \$\[\033[00m\] '
    else
        PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\] \[\033[01;34m\]\w \$\[\033[00m\] '
    fi
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h \w \$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# colored GCC warnings and errors
#export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# some more ls aliases
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'
alias clr='clear'

# Add an "alert" alias for long running commands.  Use like so:
#   sleep 10; alert
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

if [ -x /usr/bin/mint-fortune ]; then
     /usr/bin/mint-fortune
fi



if [ -f /etc/bash_completion ]; then
 . /etc/bash_completion
fi

git_branch() {
 git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/\1/'
}

export PS1='\t \[\033[01;32m\]\u@\h:\[\033[01;35m\]\w '
export PS1="$PS1\[\033[01;33m\]\$(git_branch)\[\033[01;34m\] \$ \[\033[00m\]"

#export PS1='\t \[[\e[0;32m\]\u\[\e[m\]@\e[0;37m\]\h\[\e[m\] \[\e[1;34m\]\w\[\e[m\]]\[\e[0;31m\]'
#export PS1="$PS1\[\033[01;33m\]\$(git_branch)\[\033[01;34m\] \$ \[\033[00m\]"


export JAVA_HOME=/opt/java/jdk1.8.0_101/
export PATH=$PATH:$JAVA_HOME/bin/
export PATH=$PATH:/opt/node/bin/
export PATH=$PATH:/opt/gradle/bin/
export MVN_HOME=/opt/maven/
export PATH=$PATH:$MVN_HOME/bin
export M2_HOME=/home/minikh/.m2/

export GOROOT=/opt/go
export PATH=$PATH:$GOROOT/bin

[ -f ~/.fzf.bash ] && source ~/.fzf.bash

export FZF_DEFAULT_COMMAND='
  (git ls-tree -r --name-only HEAD ||
   find . -path "*/\.*" -prune -o -type f -print -o -type l -print |
      sed s/^..//) 2> /dev/null'
export LESSOPEN="| /usr/share/source-highlight/src-hilite-lesspipe.sh %s"
export LESS=' -R '

#THIS MUST BE AT THE END OF THE FILE FOR SDKMAN TO WORK!!!
#export SDKMAN_DIR="/home/minikh/.sdkman"
#[[ -s "/home/minikh/.sdkman/bin/sdkman-init.sh" ]] && source "/home/minikh/.sdkman/bin/sdkman-init.sh"

alias myip='wget -qO myip http://www.ipchicken.com/;
grep -o "[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}" myip;  rm myip'

alias ssh-arena="ssh minikh@109.73.44.94 -p33209"
alias ssh-vscale="ssh minikh@82.202.226.239 -p3251"
alias ssh-mc-vscale="mc sh://minikh@82.202.226.239:3251/home/minikh/"
alias ssh-metacards.online="ssh minikh@metacards.online -p3251"
alias ssh-mc-metacards.online="mc sh://minikh@metacards.online:3251/home/minikh/"
alias sshfs-arena="sshfs -p 33209 minikh@109.73.44.94:/home/minikh/tmp/ /home/minikh/tmp/11/ -o reconnect"
alias ssh-hetzner="ssh minikh@95.216.145.217 -p3251"
alias ssh-mc-hetzner="mc sh://minikh@95.216.145.217:3251"
alias ssh-dalprom="ssh user@83.220.37.182 -p 2200"
alias ssh-mc-dalprom="mc sh://user@83.220.37.182:2200"

alias openvpn-hetzner="sudo openvpn --config /home/minikh/openvpn/hainz.ovpn"
alias openvpn-vscale="sudo openvpn --config /home/minikh/openvpn/vscale.ovpn"

alias socks-hetzner="ssh -D 1080 -C minikh@95.216.145.217 -p3251"
alias socks-vscale="ssh -D 1080 -C minikh@82.202.226.239 -p3251"

export PATH=$PATH:/home/minikh/geckodriver/
export PATH=$PATH:/opt/idea/bin/
export PATH=$PATH:/opt/pycharm/bin/
## Tizen SDK configuration
# This is generated by Tizen SDK. Please do not modify by yourself.
export PATH=$PATH:/home/minikh/tizen-studio/platforms/tizen-5.0/common/tidl
## End Tizen SDK configuration
