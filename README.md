# Still Alive
Hello! I'm Colin, and this is Portal's 'Still Alive' replicated in Windows cmd.
On your computer, it might not be perfect because I was too lazy to implement delta time. Sorry. Maybe I'll do that later.
I have also experienced issues with past projects of some libraries not being installed by default on your computer, so please leave an issue if it crashes or something.

[YouTube](https://youtu.be/6-cho8eZCMI?si=ahcz1tzxX0TY0ur8)

## Download
In CMD, run `git clone https://github.com/Kolin63/stillAlive`

Then, `cd stillAlive`

If you want to change your zoom or window size, you can run `./preconf.exe` for a reference of the frame size.

Finally, `./stillAlive.exe`

## Credits
The following is the contents of `/assets/credits.txt`

```
>LIST PERSONNEL
 
 
Made by Kolin63
youtube.com/@kolindev
github.com/Kolin63/stillAlive
 
 
Original:
Portal (video game)
By Valve, 2007
GlaDOS - Ellen McLain
Lyrics - Jonathan Coulton
 
 
Help From:
ChatGPT
Stack Overflow
cppreference.com
learncpp.com
learn.microsoft.com
Portal - 'Still Alive' posted by OTG:
youtube.com/watch?v=Y6ljFaKRTrI
 
 
Dev Log:
This is the ending credits
song played at the end of 
Portal, one of my favorite
games.
 
I have seen multiple adaptations
of Still Alive or Want You Gone
(from Portal 2), but not many of
them have fully replicated it. 
 
Of course, mine isn't perfect
either, but I put in a lot
of work to make it as close
as possible. 
 
In this written dev log,
I will go over the process of
how I made this, and hopefully
provide enough information if
you want to do it yourself.
 
In terms of the basics, 
this is all written in C++.
I have been learning C++ for
around a year, although I
had a lot of programming
experience before hand. 
 
The most important (non-trivial)
libraries I used are <windows.h>,
<thread>, and <chrono>. 
 
<windows.h> lets me change the
text color, move the cursor around,
and overwrite text.
Documentation at  learn.microsoft.com/
en-us/windows/console/console-functions
 
<thread> is how I achieve the
lyrics and credits writing
at different speeds. This was
really important for me to get
right, because other versions
of Still Alive that I have seen
updated the credits and lyrics 
windows during the same ticks, 
and it didn't look as cool.
<thread>, as implied by the name, 
lets you run code on more than one 
thread. In my code, I have
a default main thread, a lyrics
thread, and a credits thread.
The lyrics and credits thread
are passed variables as references
so that the three threads can share
data. The 2 threads write their
output to a string array, which
is printed in the main thread. 
 
<chrono> is only used for waiting
milliseconds in between characters,
but not much could be done without it.
The function to wait can be found
with a simple Stack Overflow search. 
 
The method I used to actually make
the lyrics was essentially a
parsing system. You can check
this out yourself by going into
/assets/lyrics.txt in the source.
So I would edit that txt and put in
the timings and the text, as well
as other commands that I needed
to implement, and it would be parsed
and executed during runtime.
For example,

!0200;
!0100;
This was a triumph

Would mean, wait two seconds, then
print "This was a triumph" over a
total of 1 second. The credits
(this) are a bit simpler, where
each line takes around 1 second
to print, without any commands. 
 
Fun fact: although Still Alive is
rendered in real time, it does not
limit itself to one monospaced
text box. Most annoyingly, the
ASCII art in the bottom right
corner is on its own grid and is
scaled down. In fact, this 
credits window should be half
the height of the lyrics
window, but the ASCII pushes
it up because I did not
scale it down (that would
be kind of impossible). 
 
I know this all scrolled really
quickly, so you can just read
this all on GitHub. 
That will be on 
github.com/Kolin63/stillAlive
 
I will conclude these credits
with the first part of the
story 'Nate the Snake' which
can be read on natethesnake.com
 
So, there's a man crawling 
through the desert.
 
He'd decided to try his SUV 
in a little bit of cross-country 
travel, had great fun zooming 
over the badlands and through 
the sand, got lost, hit a big 
rock, and then he couldn't get 
it started again. There were no 
cell phone towers anywhere near, 
so his cell phone was useless. 
He had no family, his parents 
had died a few years before in 
 
ok thats all i have time for bye
 
 
THANK YOU FOR PARTICIPATING
IN THIS
ENRICHMENT CENTER ACTIVITY!
 

```
