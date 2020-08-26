#An animation of progress bar<br/>
##一根很simple的进度条的动画，使用C语言实现。<br/>(A very very simple animation of progress bar using C)<br/>
<br/>
25/08/2020:<br/>
非Windows操作系统~~应该是~~不能正常运行，原因在于使用了*windows.h*库。<br/>
同时CMD没有437代码页的操作系统~~肯定~~也无法正常运行，代码注释里准备了备用方法。<br/>
emm，差不多解释完了。至于这个玩意儿的用处，还没想好~~估计是没有了~~。<br/>
~~这里还顺便学习一下怎么用GFM。~~<br/>
(Because of using *windows.h*, this thing ~~surely~~ does not work on other OS.=-=<br/>
And... without codepage437. So I give a 'PLAN-B' in annotations.<br/>
And... well, I guess I have nothing more to say~~type~~ about it...<br/>
As to it's usage, well...~~nope~~)<br/>
追加一条：<br/>
在另一台设备上编号为219号的ASCII符号占用了两个字符长度，因此代码重新修改了。<br/>
正在查找相关原因。<br/>
(Add:<br/>
I just found another problem, ASCII no.219 takes up 2 bytes on another divice.<br/>
So that I made some small changes.<br/>
Looking for solutions.)<br/>
<br/>
26/08/2020:<br/>
经过不同编号的ASCII码输出测试，猜测原因大概是编号219的ASCII码在输出时由于字符太大~~胖~~，导致命令行处理时自动拓展了屏幕像素占用。<br/>
解决方法目前是将输出补齐的空格数增加一倍。<br/>
~~这个解决方法在不同设备上或许根本没有什么X用。吃灰去吧。~~<br/>
(After tested with other ASCII char, the problem I found could be explained like this:<br/>
When print ASCII no.219, it's too large~~fat~~ to be filled into just one space, so the CMD automatically gives 2 space.(maybe)<br/>
Current solution: dublicate the amount of blankspace.<br/>
~~This solution may has no use on other divices... R.I.P.~~)<br/>
<br/>
(PS: Oh, if you have read all of these terrible english annotations above, thanks for your patience. I'll work hard to make it better.)<br/>