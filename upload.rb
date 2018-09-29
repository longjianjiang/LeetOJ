#!/usr/bin/env ruby
puts "enter commit message"
commit_msg = gets.chomp
commit_command = "git commit -m '#{commit_msg}' "

`git add .`
`#{commit_command}`
`git push origin master`
