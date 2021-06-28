<h1>IPASS - DHT11</h1>

<h2>Introduction</h2>
This repository is created for the final project of this propeadeutic year. The project is called IPASS.
<br>
<br>The goal of this project is to write a library for a hardware component of my choice,
and write this library using the OOP ways that I have learned this period.
I had to use my self-made library to communicate with the hardware.
<br>
<br>I have also created a tic-tac-toe game with physical buttons that can be used by two players.
Buttons 1 to 9 are each linked to a specific coordinate in the grid.
After pressing one of the buttons on the keypad, a circle will be drawn at the corresponding coordinate in the grid.
Using this game, I can demonstrate my library for the OLED.

<h2>Included libraries</h2>
This library uses <a href="https://github.com/wovo/hwlib">hwlib and bmptk</a>.

<h2>Used hardware</h2>
This library is developed to be used with the <a href="https://www.arduino.cc/en/Main/ArduinoBoardDue">Arduino Due</a>

I chose the <a href="https://bit.ly/3zVqiJX">SSD1331</a> driver that is combined with an RGB OLED screen.

I also used two of the <a href="https://bit.ly/3h0HOFr">foil 4x4 matrix keypads</a>

<h2>Author</h2>
<table style="width:100%">

| Name                 | Student number | Username       |
| -------------------- | ------------- | -------------- |
| Kenny van Doorn      | 1789386       | Kennyvandoorn  |
</table>


<h2>Installation</h2>

<pre style="position: relative;" lang="git"><code>git clone https://github.com/Kennyvandoorn/IPASS-Tic-Tac-Due-SSD1331.git</code></pre>
<div class="zeroclipboard-container position-absolute right-0 top-0">
    <clipboard-copy aria-label="Copy" class="ClipboardButton btn js-clipboard-copy m-2 p-0 tooltipped-no-delay" data-copy-feedback="Copied!" data-tooltip-direction="w" value="git clone https://github.com/Kennyvandoorn/IPASS-Tic-Tac-Due-SSD1331.git
" tabindex="0" role="button">
      <svg aria-hidden="true" viewBox="0 0 16 16" version="1.1" data-view-component="true" height="16" width="16" class="octicon octicon-clippy js-clipboard-clippy-icon m-2">
    <path fill-rule="evenodd" d="M5.75 1a.75.75 0 00-.75.75v3c0 .414.336.75.75.75h4.5a.75.75 0 00.75-.75v-3a.75.75 0 00-.75-.75h-4.5zm.75 3V2.5h3V4h-3zm-2.874-.467a.75.75 0 00-.752-1.298A1.75 1.75 0 002 3.75v9.5c0 .966.784 1.75 1.75 1.75h8.5A1.75 1.75 0 0014 13.25v-9.5a1.75 1.75 0 00-.874-1.515.75.75 0 10-.752 1.298.25.25 0 01.126.217v9.5a.25.25 0 01-.25.25h-8.5a.25.25 0 01-.25-.25v-9.5a.25.25 0 01.126-.217z"></path>
</svg>
      <svg aria-hidden="true" viewBox="0 0 16 16" version="1.1" data-view-component="true" height="16" width="16" class="octicon octicon-check js-clipboard-check-icon color-text-success d-none m-2">
    <path fill-rule="evenodd" d="M13.78 4.22a.75.75 0 010 1.06l-7.25 7.25a.75.75 0 01-1.06 0L2.22 9.28a.75.75 0 011.06-1.06L6 10.94l6.72-6.72a.75.75 0 011.06 0z"></path>
</svg>
    </clipboard-copy>
  </div>
  </div>

<h2>Instructions</h2>
1. Make sure you have downloaded and included <a href="https://github.com/wovo/hwlib">hwlib</a> into your project. 
<br>2. Build using the included makefile, or run the run.bat file from your terminal.

<h2>Extra notes</h2>
The included main.cpp shows you how to create pins and objects.
You can use the predefined variables to test the OLED and key matrix.
The predefined variables allow players to start and play a game of Tic-Tac-Due!

<h2>License</h2>

Copyright © Kenny van Doorn (kenny.vandoorn@student.hu.nl), 2021

Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

Note: See license file for a detailed description.
