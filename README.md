<h1 align="center">PEFixer Extreme</h1>
<p align="center">My personal PE Fixer that allows you to patch a raw PE dump to a fully patched and working PE dump that will help your analysis.</p>
<img src="https://github.com/keowu/pefixerextreme/blob/main/Resources/logo.jpg?raw=true">

<h2 align="center">What is a PE file?</h2>

In an abstract way, a PE file is a structure that encapsulates information necessary for the loader (NTDLL), also affectionately called the operating system loader, it is he who manages all the information necessary to execute the executable code, this includes references to libraries ( IAT), and for export tables(EAT), manage resources(TLS) among other features, the format is commonly used in .exe(Executable File), DLL(Dynamic-link library) and SYS(Device Driver) and our program was lovingly thought of in each of them.

<h2 align="center">How can this project help me?</h2>

This project can fix a raw file, as an example of usage, think you unpacked a malware or something similar, maybe it works to fix commercial protectors (although not the idea), many times several protectors or packers destroy the PE, or your dump is done wrong, so that's where this software comes in (it doesn't do magic) so don't expect to take a solution like Themida or something and dump the memory, you can have access to some dirty content, but you really need to find a lot of information like IAT and Entrypoint, in addition to taking care of virtualized code (which personally is complex), our project will rebuild a PE so that it is parsable but you need to provide something decent too, or improve and leave this project the way you think is best for you and if you do I really want to see it :)

<h2 align="center">I want to see it working</h2>

<img src="https://github.com/keowu/pefixerextreme/blob/main/Resources/screenshots/demo.gif?raw=true">
<img src="https://github.com/keowu/pefixerextreme/blob/main/Resources/screenshots/scr1.PNG?raw=true">
<img src="https://github.com/keowu/pefixerextreme/blob/main/Resources/screenshots/scr2.PNG?raw=true">
<img src="https://github.com/keowu/pefixerextreme/blob/main/Resources/screenshots/scr3.PNG?raw=true">

<h2 align="center">I want to collaborate, how can I help?</h2>

I am very much appreciated with any contribution no matter how simple, don't be afraid to make a contribution or suggest something, rest assured that you will be answered with the utmost politeness and argumentation to really discuss ideas.

I seek help for the following topics:

<ul>
  <li>Localized translation ie you translate from my language to your language providing greater access.</li>
  <li>Find BUGS and fix.</li>
  <li>Present and code improvements.</li>
  <li>Discuss ideas (as humans)</li>
</ul>

if you meet any of the requirements let's work together, open an issue explain your idea.

<h2 align="center">Special thanks</h2>

<p align="center"> <a href="https://github.com/AkkoS2">AkkoS2</a> - For testing your RAW files and all support for testing during development.</p>
<p align="center"> <a href="https://github.com/Joao-Aschenbrenner">Joao-Aschenbrenner</a> - By taking care of the UI and all the image design, if you are looking for a good guy with UI he is the right choice.</p>
<p align="center">And thanks to documentation and other people's work like the publication by (Albertini, 2014) that can be <a href="https://github.com/keowu/pefixerextreme/blob/main/Resources/inspirations/awelsomepehelp.png"> seen here </a>, of explaining every detail of the PE header that certainly improved my understanding a lot, no one built knowledge alone!</p>
<p align="center">Finally, if you are an antivirus company and are looking for a reverse engineer, give me an opportunity I believe you would not regret it.</p>
<p align="center">and thank you very much for viewing my repository :)</p>

