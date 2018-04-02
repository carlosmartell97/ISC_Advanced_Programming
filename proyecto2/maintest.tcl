#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}


#Put your test case here
eval spawn [lrange $argv 0 end]

send "4\r"
send "11 5 16 5 0 0\r"
expect "Case #1: 5" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3 1 3 2 2 0\r"
expect "Case #2: 2" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "3 1 3 2 1 0\r"
expect "Case #3: IMPOSSIBLE" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "2 1 5 1 1 1\r"
expect "Case #4: 5" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
