<!DOCTYPE html>
<html lang="" class="">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title></title>


  <style>
    /* ================================================================
       CYBER TERMINAL THEME  v3  —  All-in-One Pandoc Template
       Base: #1e1e1e  |  Overlays: grain + grid + scanlines + vignette + noise
       Themes: Cyber Cyan (default)  |  Cyber Green (.theme-green on <html>)
       Fixes v3: copy button, collapsible sections, theme var scope, grain layer
    ================================================================ */

    /* ── THEME TOKENS ─────────────────────────────────────────────── */
    :root {
      --bg-base:        #050D0C;
      --bg-surface:     #000000;
      --bg-raised:      #2d2d2d;
      --text-primary:   #d4d4d4;
      --text-muted:     #6a7a76;

      /* Cyan (default) */
      --accent:         #00d9ff;
      --accent-dim:     rgba(0,217,255,0.12);
      --accent-glow:    rgba(0,217,255,0.22);
      --accent-soft:    rgba(0,217,255,0.55);
      --grid-line:      rgba(0,190,160,0.13);
      --grid-blur:      rgba(0,190,160,0.07);
      --noise-color:    rgba(0,180,140,0.18);
      --grid-size:      48px;

      --h1-c:  #00d9ff;
      --h2-c:  #ff9d00;
      --h3-c:  #ffd700;
      --h4-c:  #ff00ff;
      --h5-c:  #00ff41;
      --h6-c:  #a277ff;

      --c-green:   #00ff41;
      --c-orange:  #ff9d00;
      --c-yellow:  #ffd700;
      --c-magenta: #ff00ff;
      --c-red:     #ff4757;
      --c-purple:  #a277ff;
      --c-blue:    #61afef;
      --c-link:    #00d9ff;
      --c-link-hv: #ff00ff;
      --c-hr:      #ff00ff;
    }

    /* ── GREEN THEME ──────────────────────────────────────────────── */
    html.theme-green {
      --accent:         #00ff41;
      --accent-dim:     rgba(0,255,65,0.10);
      --accent-glow:    rgba(0,255,65,0.20);
      --accent-soft:    rgba(0,255,65,0.55);
      --grid-line:      rgba(0,210,80,0.13);
      --grid-blur:      rgba(0,210,80,0.07);
      --noise-color:    rgba(0,220,80,0.17);

      --h1-c:  #00ff41;
      --h2-c:  #b8ff6e;
      --h3-c:  #39ff14;
      --h4-c:  #00ffa3;
      --h5-c:  #57ff8f;
      --h6-c:  #00d4aa;

      --c-orange:  #b8ff6e;
      --c-yellow:  #39ff14;
      --c-magenta: #00ffa3;
      --c-purple:  #57ff8f;
      --c-blue:    #00d4aa;
      --c-link:    #00ff41;
      --c-link-hv: #b8ff6e;
      --c-hr:      #39ff14;
      --text-muted: #3a7050;
    }

    /* ── RESET ─────────────────────────────────────────────────────── */
    *, *::before, *::after { margin: 0; padding: 0; box-sizing: border-box; }

    /* ── HTML BASE ─────────────────────────────────────────────────── */
    html { min-height: 100%; background-color: var(--bg-base); position: relative; }

    /* ── OVERLAY A: sharp grid ─────────────────────────────────────── */
    html::before {
      content: '';
      position: fixed; inset: 0;
      pointer-events: none; z-index: 1;
      background-image:
        linear-gradient(var(--grid-line) 1px, transparent 1px),
        linear-gradient(90deg, var(--grid-line) 1px, transparent 1px);
      background-size: var(--grid-size) var(--grid-size);
      transition: background-image 0.5s;
    }

    /* ── OVERLAY B: blurred grid glow ─────────────────────────────── */
    html::after {
      content: '';
      position: fixed; inset: 0;
      pointer-events: none; z-index: 2;
      background-image:
        linear-gradient(var(--grid-blur) 1px, transparent 1px),
        linear-gradient(90deg, var(--grid-blur) 1px, transparent 1px);
      background-size: var(--grid-size) var(--grid-size);
      filter: blur(1.2px);
      transition: background-image 0.5s;
    }

    /* ── OVERLAY C: grain texture (SVG feTurbulence, no external files) */
    #grain {
      position: fixed; inset: 0;
      pointer-events: none; z-index: 3;
      opacity: 0.16;
      background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='300' height='300'%3E%3Cfilter id='n'%3E%3CfeTurbulence type='fractalNoise' baseFrequency='0.72' numOctaves='4' stitchTiles='stitch'/%3E%3CfeColorMatrix type='saturate' values='0'/%3E%3C/filter%3E%3Crect width='300' height='300' filter='url(%23n)'/%3E%3C/svg%3E");
      background-repeat: repeat;
      background-size: 300px 300px;
      mix-blend-mode: overlay;
    }

    /* ── OVERLAY D: scanlines ──────────────────────────────────────── */
    #scanlines {
      position: fixed; inset: 0;
      pointer-events: none; z-index: 4;
      background: repeating-linear-gradient(
        to bottom,
        transparent, transparent 3px,
        rgba(0,0,0,0.07) 3px, rgba(0,0,0,0.07) 4px
      );
    }

    /* ── OVERLAY E: vignette ───────────────────────────────────────── */
    #vignette {
      position: fixed; inset: 0;
      pointer-events: none; z-index: 5;
      background: radial-gradient(ellipse at center, transparent 45%, rgba(0,0,0,0.62) 100%);
    }

    /* ── OVERLAY F: floating terminal text ─────────────────────────── */
    #bg-noise {
      position: fixed; inset: 0;
      pointer-events: none; z-index: 9;
      overflow: visible;
      font-family: 'Consolas','Monaco','Courier New',monospace;
      user-select: none;
    }
    #bg-noise span {
      position: absolute; white-space: nowrap;
      letter-spacing: 0.10em; filter: blur(0.5px);
      transition: color 0.10s;
    }

    /* ── THEME TOGGLE BUTTON ───────────────────────────────────────── */
    #theme-toggle {
      position: fixed; top: 1rem; right: 1.2rem; z-index: 500;
      background: rgba(20,20,20,0.82);
      border: 1px solid var(--accent);
      color: var(--accent);
      font-family: 'Consolas','Monaco','Courier New',monospace;
      font-size: 0.72rem; padding: 0.3rem 0.75rem; border-radius: 3px;
      cursor: pointer; text-shadow: 0 0 6px var(--accent);
      box-shadow: 0 0 10px var(--accent-dim);
      letter-spacing: 0.06em;
      transition: border-color 0.3s, color 0.3s, text-shadow 0.3s, box-shadow 0.3s;
      backdrop-filter: blur(6px);
    }
    #theme-toggle:hover { background: var(--accent-dim); box-shadow: 0 0 20px var(--accent-glow); }

    /* ── BODY ──────────────────────────────────────────────────────── */
    body {
      position: relative; z-index: 10;
      background: transparent;
      color: var(--text-primary);
      font-family: 'Consolas','Monaco','Courier New',monospace;
      line-height: 1.65;
      padding: 2.5rem 2rem 5rem;
      max-width: 940px; margin: 0 auto;
    }

    /* ── HEADINGS ──────────────────────────────────────────────────── */
    h1 {
      color: var(--h1-c); font-size: 2.4rem; margin: 2.2rem 0 1rem;
      text-shadow: 0 0 12px var(--h1-c);
      border-bottom: 2px solid var(--h1-c); padding-bottom: 0.45rem;
      animation: flicker 0.6s ease-in-out;
    }
    h2 { color: var(--h2-c); font-size: 1.9rem;  margin: 2rem 0 0.8rem;   text-shadow: 0 0 8px var(--h2-c); }
    h3 { color: var(--h3-c); font-size: 1.55rem; margin: 1.6rem 0 0.7rem; text-shadow: 0 0 6px var(--h3-c); }
    h4 { color: var(--h4-c); font-size: 1.28rem; margin: 1.4rem 0 0.6rem; }
    h5 { color: var(--h5-c); font-size: 1.1rem;  margin: 1.2rem 0 0.5rem; }
    h6 { color: var(--h6-c); font-size: 1rem;    margin: 1rem  0 0.5rem; }
    h1:hover, h2:hover { animation: glow 2s ease-in-out infinite; }

    /* ── TITLE BLOCK ───────────────────────────────────────────────── */
    header#title-block-header {
      border-bottom: 1px solid var(--accent-dim);
      margin-bottom: 2rem; padding-bottom: 1rem;
    }
    .title    { color: var(--h1-c); font-size: 2.6rem; text-shadow: 0 0 14px var(--h1-c); display: block; }
    .subtitle { color: var(--h2-c); font-size: 1.3rem; margin-top: 0.4rem; display: block; }
    .author   { color: var(--text-muted); font-size: 0.9rem; margin-top: 0.5rem; display: block; }
    .date     { color: var(--text-muted); font-size: 0.85rem; display: block; }

    /* ── PARAGRAPHS ────────────────────────────────────────────────── */
    p { margin-bottom: 1rem; color: var(--text-primary); }

    /* ── LINKS ─────────────────────────────────────────────────────── */
    a { color: var(--c-link); text-decoration: none; border-bottom: 1px dotted var(--c-link); transition: all 0.3s; }
    a:hover { color: var(--c-link-hv); border-bottom-color: var(--c-link-hv); text-shadow: 0 0 8px var(--c-link-hv); }
    a[href^="http"]::after { content: ' ↗'; font-size: 0.75em; opacity: 0.6; }

    /* ── LISTS ─────────────────────────────────────────────────────── */
    ul, ol { margin: 1rem 0; padding-left: 2rem; }
    li { margin: 0.45rem 0; color: var(--text-primary); }
    ul li::marker          { color: var(--c-green);  font-size: 1.2em; }
    ul ul li::marker       { color: var(--accent); }
    ul ul ul li::marker    { color: var(--c-yellow); }
    ol li::marker          { color: var(--c-orange); font-weight: bold; }

    ul.task-list { list-style: none; padding-left: 0; }
    ul.task-list li { position: relative; padding-left: 2rem; margin: 0.65rem 0; }
    ul.task-list li input[type="checkbox"] {
      position: absolute; left: 0; top: 0.2rem;
      width: 1.15rem; height: 1.15rem;
      cursor: pointer; appearance: none;
      background: transparent;
      border: 2px solid var(--accent); border-radius: 3px; transition: all 0.3s;
    }
    ul.task-list li input[type="checkbox"]:hover {
      border-color: var(--c-magenta); box-shadow: 0 0 10px rgba(255,0,255,0.4);
    }
    ul.task-list li input[type="checkbox"]:checked {
      background-color: var(--c-green); border-color: var(--c-green);
      box-shadow: 0 0 10px rgba(0,255,65,0.45);
    }
    ul.task-list li input[type="checkbox"]:checked::after {
      content: "✓"; position: absolute;
      color: var(--bg-base); font-size: 0.85rem; font-weight: bold;
      left: 50%; top: 50%; transform: translate(-50%,-50%);
    }
    ul.task-list li input[type="checkbox"]:checked ~ * {
      color: var(--text-muted); text-decoration: line-through;
    }

    /* ── CODE BLOCKS ───────────────────────────────────────────────── */
    pre {
      background-color: rgba(13,17,23,0.85);
      border: 1px solid var(--accent);
      border-left: 3px solid var(--c-green);
      padding: 1.4rem;
      overflow-x: auto;
      margin: 1.5rem 0;
      border-radius: 6px;
      box-shadow: 0 0 20px var(--accent-dim);
      position: relative;
      line-height: 1.55;
    }
    pre code {
      color: var(--text-primary); font-size: 0.94em;
      background: none; border: none; padding: 0;
      display: block;
      /* Pad right so text doesn't hide under copy button */
      padding-right: 3.8rem;
    }
    code { font-family: 'Consolas','Monaco','Courier New',monospace; }

    /* ── COPY BUTTON (injected by JS, NOT a pseudo-element) ────────── */
    .copy-btn {
      position: absolute; top: 0.55rem; right: 0.65rem;
      background: transparent;
      border: 1px solid var(--accent); border-radius: 3px;
      padding: 0.12rem 0.5rem;
      font-family: 'Consolas','Monaco','Courier New',monospace;
      font-size: 0.68rem; color: var(--accent);
      cursor: pointer; opacity: 0;
      transition: opacity 0.2s, background 0.2s, color 0.2s, border-color 0.2s;
      line-height: 1.5; letter-spacing: 0.04em;
    }
    pre:hover .copy-btn         { opacity: 0.8; }
    .copy-btn:hover             { background: var(--accent-dim); opacity: 1 !important; }
    .copy-btn.copied            { opacity: 1 !important; color: var(--c-green); border-color: var(--c-green); }

    /* ── INLINE CODE ───────────────────────────────────────────────── */
    :not(pre) > code {
      background-color: rgba(13,17,23,0.75);
      padding: 0.18rem 0.48rem; border-radius: 4px;
      color: var(--c-yellow); font-size: 0.9em;
      border: 1px solid rgba(255,215,0,0.28);
    }

    /* ── PANDOC SYNTAX HIGHLIGHT SPANS ────────────────────────────── */
    code span.kw                      { color: var(--c-magenta); }
    code span.fu                      { color: var(--c-yellow); }
    code span.st, code span.vs        { color: var(--c-green); }
    code span.co, code span.an,
    code span.cv, code span.in,
    code span.do                      { color: var(--text-muted); font-style: italic; }
    code span.dv, code span.fl,
    code span.pp                      { color: var(--c-orange); }
    code span.op, code span.at        { color: var(--accent); }
    code span.va                      { color: var(--c-blue); }
    code span.dt, code span.cn        { color: var(--c-purple); }
    code span.ch, code span.sc,
    code span.ss                      { color: var(--c-yellow); }
    code span.er, code span.al        { color: var(--c-red); font-weight: bold; }
    code span.wa                      { color: var(--c-orange); font-style: italic; }
    code span.im, code span.bu,
    code span.ex                      { color: var(--c-blue); }

    /* ── BLOCKQUOTES ───────────────────────────────────────────────── */
    blockquote {
      border-left: 4px solid var(--c-purple);
      margin: 1.2rem 0; padding: 0.9rem 1.2rem;
      color: var(--c-purple); font-style: italic;
      background-color: rgba(162,119,255,0.05);
      border-radius: 0 4px 4px 0;
    }

    /* ── TABLES ────────────────────────────────────────────────────── */
    table {
      width: 100%; border-collapse: separate; border-spacing: 0;
      margin: 1.5rem 0;
      border: 2px solid var(--accent);
      box-shadow: 0 0 18px var(--accent-dim);
      border-radius: 4px; overflow: hidden;
    }
    th {
      background-color: rgba(37,37,38,0.92); color: var(--accent);
      padding: 0.75rem 0.9rem; text-align: left;
      border-right: 1px solid var(--accent); border-bottom: 2px solid var(--accent);
      text-shadow: 0 0 5px var(--accent); font-size: 0.95em;
    }
    th:last-child { border-right: none; }
    td {
      padding: 0.7rem 0.9rem;
      border-right: 1px solid var(--accent-dim); border-bottom: 1px solid var(--accent-dim);
      color: var(--accent-soft); transition: color 0.2s;
    }
    td:last-child { border-right: none; }
    tr:last-child td { border-bottom: none; }
    tr:nth-child(even) { background-color: rgba(255,255,255,0.02); }
    tr:hover { background-color: var(--accent-dim); }
    tr:hover td { color: var(--accent); }

    /* ── HR ────────────────────────────────────────────────────────── */
    hr { border: none; border-top: 1px solid var(--c-hr); margin: 2.2rem 0; box-shadow: 0 0 8px var(--c-hr); opacity: 0.55; }

    /* ── INLINE FORMATTING ─────────────────────────────────────────── */
    strong, b { color: var(--c-orange); font-weight: bold; }
    em, i     { color: var(--c-yellow); font-style: italic; }
    del, s    { color: var(--c-red); text-decoration: line-through; opacity: 0.7; }
    mark      { background-color: rgba(255,215,0,0.18); color: var(--c-yellow); padding: 0.1rem 0.32rem; border-radius: 2px; }
    sub, sup  { color: var(--c-magenta); }
    kbd {
      background-color: var(--bg-surface); border: 1px solid var(--accent); border-radius: 3px;
      padding: 0.18rem 0.48rem; font-family: inherit; color: var(--accent);
      box-shadow: 0 2px 0 var(--accent), 0 0 8px var(--accent-dim); font-size: 0.88em;
    }

    /* ── DEFINITION LISTS ──────────────────────────────────────────── */
    dl  { margin: 1rem 0; }
    dt  { color: var(--c-orange); font-weight: bold; margin-top: 0.8rem; }
    dd  { margin-left: 2rem; padding-left: 0.9rem; border-left: 2px solid var(--c-green); color: var(--text-primary); }

    /* ── IMAGES ────────────────────────────────────────────────────── */
    img {
      max-width: 100%; height: auto; display: block;
      border: 2px solid var(--accent); border-radius: 4px;
      margin: 1rem 0; box-shadow: 0 0 20px var(--accent-dim);
    }
    figure { margin: 1.5rem 0; text-align: center; }
    figcaption { color: var(--c-purple); font-style: italic; margin-top: 0.5rem; font-size: 0.88em; }

    /* ── FOOTNOTES ─────────────────────────────────────────────────── */
    .footnotes { border-top: 1px solid var(--accent-dim); margin-top: 3rem; padding-top: 1rem; font-size: 0.88em; color: var(--text-muted); }
    .footnotes ol li::marker { color: var(--accent); }

    /* ── ABSTRACT ──────────────────────────────────────────────────── */
    div.abstract { border-left: 3px solid var(--accent); padding-left: 1rem; margin: 1.5rem 0; }
    div.abstract p.abstract-title { color: var(--accent); font-weight: bold; margin-bottom: 0.4rem; }

    /* ── TOC ───────────────────────────────────────────────────────── */
    nav#TOC {
      background: rgba(13,17,23,0.72);
      border: 1px solid var(--accent-dim); border-left: 3px solid var(--accent);
      border-radius: 6px; padding: 1.2rem 1.5rem; margin: 0 0 2.5rem;
      box-shadow: 0 0 16px var(--accent-dim);
    }
    nav#TOC::before {
      content: '// TABLE OF CONTENTS'; display: block;
      color: var(--accent); font-size: 0.76rem; letter-spacing: 0.1em;
      margin-bottom: 0.8rem; text-shadow: 0 0 6px var(--accent);
    }
    nav#TOC ul    { list-style: none; padding-left: 0; margin: 0; }
    nav#TOC ul ul { padding-left: 1.2rem; }
    nav#TOC li    { margin: 0.28rem 0; }
    nav#TOC li::before { content: '> '; color: var(--c-green); }
    nav#TOC a     { color: var(--text-primary); border-bottom: none; font-size: 0.9rem; transition: color 0.2s; }
    nav#TOC a:hover { color: var(--accent); text-shadow: 0 0 6px var(--accent); }
    nav#TOC a::after { content: none; }

    /* ── COLLAPSIBLE SECTIONS ──────────────────────────────────────── */
    .section-toggle { cursor: pointer; user-select: none; }
    .section-toggle::before {
      content: '▼'; font-size: 0.6em; opacity: 0.65;
      display: inline-block; margin-right: 0.45rem;
      transition: transform 0.25s ease; vertical-align: middle;
    }
    .section-toggle.collapsed::before { transform: rotate(-90deg); }
    .section-body { overflow: hidden; transition: max-height 0.32s ease; }

    /* ── SCROLLBARS ────────────────────────────────────────────────── */
    ::-webkit-scrollbar { width: 10px; height: 10px; }
    ::-webkit-scrollbar-track { background: var(--bg-surface); }
    ::-webkit-scrollbar-thumb { background: var(--accent); border-radius: 5px; }
    ::-webkit-scrollbar-thumb:hover { background: var(--c-magenta); }

    /* ── SELECTION ─────────────────────────────────────────────────── */
    ::selection { background-color: var(--accent-glow); color: var(--accent); }

    /* ── ANIMATIONS ────────────────────────────────────────────────── */
    @keyframes glow {
      0%,100% { text-shadow: 0 0 5px currentColor; }
      50%      { text-shadow: 0 0 24px currentColor, 0 0 42px currentColor; }
    }
    @keyframes flicker {
      0%,100% { opacity: 1; }
      41%,43% { opacity: 0.78; }
      45%,47% { opacity: 0.92; }
    }
  </style>
</head>
<body>

<!-- OVERLAY LAYERS (z-index 1–6, behind body z-index 10) -->
<div id="grain"     aria-hidden="true"></div>
<div id="scanlines" aria-hidden="true"></div>
<div id="vignette"  aria-hidden="true"></div>
<div id="bg-noise"  aria-hidden="true"></div>
<button id="theme-toggle" aria-label="Toggle color theme">[ THEME: CYAN ]</button>

<!-- PANDOC DOCUMENT -->


<h1 id="umass-ctf-2026-write-up">UMass CTF 2026 Write-Up</h1>
<h2 id="click-here-for-free-bricks">Click Here For Free Bricks</h2>
<p><strong><em>Category: Forensics</em></strong></p>
<p><strong><em>Level: Medium</em></strong></p>
<p><strong><em>File: click-here-for-free-bricks.zip</em></strong></p>
<hr />
<h3 id="challenge-description">Challenge Description</h3>
<blockquote>
<p>A man was caught with malware on his PC in Lego City. Luckily, we
were able to get a packet capture of his device during the download.
Help Lego City Police figure out the source of this malicious
download.</p>
</blockquote>
<p>The flag is in the format <code>UMASS{[String]_[Sha256 Hash]}</code>
of the malicious download.</p>
<hr />
<h3 id="extracting-the-archive">Extracting the Archive</h3>
<p>Start by unzipping the provided archive to get the packet capture
file:</p>
<div class="sourceCode" id="cb1"><pre
class="sourceCode bash"><code class="sourceCode bash"><span id="cb1-1"><a href="#cb1-1" aria-hidden="true" tabindex="-1"></a><span class="fu">unzip</span> click-here-for-free-bricks.zip</span>
<span id="cb1-2"><a href="#cb1-2" aria-hidden="true" tabindex="-1"></a><span class="co"># Archive:  click-here-for-free-bricks.zip</span></span>
<span id="cb1-3"><a href="#cb1-3" aria-hidden="true" tabindex="-1"></a><span class="co">#   inflating: thedamage.pcapng</span></span></code></pre></div>
<hr />
<h3 id="opening-the-pcap-in-wireshark">Opening the PCAP in
Wireshark</h3>
<p>Open the capture file in Wireshark:</p>
<div class="sourceCode" id="cb2"><pre
class="sourceCode bash"><code class="sourceCode bash"><span id="cb2-1"><a href="#cb2-1" aria-hidden="true" tabindex="-1"></a><span class="ex">┌──</span><span class="er">(</span><span class="ex">kali㉿kali</span><span class="kw">)</span><span class="ex">-[~/Desktop/uma/uma2]</span></span>
<span id="cb2-2"><a href="#cb2-2" aria-hidden="true" tabindex="-1"></a><span class="ex">└─$</span> wireshark thedamage.pcapng</span></code></pre></div>
<p>Apply an <strong>HTTP display filter</strong> to narrow down the
traffic:</p>
<p><img src="images/http_display_filter.png" /></p>
<hr />
<h3 id="exporting-http-objects">Exporting HTTP Objects</h3>
<p>Navigate to <strong>File → Export Objects → HTTP</strong> to extract
all files transferred over HTTP from the capture.</p>
<p><img src="images/export_object_http.png" /> <img
src="images/exported_http_objects.png" /></p>
<hr />
<h3 id="hashing-the-downloaded-files">Hashing the Downloaded Files</h3>
<p>Once exported, compute the SHA256 hashes of all downloaded files:</p>
<div class="sourceCode" id="cb3"><pre
class="sourceCode bash"><code class="sourceCode bash"><span id="cb3-1"><a href="#cb3-1" aria-hidden="true" tabindex="-1"></a><span class="ex">┌──</span><span class="er">(</span><span class="ex">kali㉿kali</span><span class="kw">)</span><span class="ex">-[~/Desktop/uma/http</span> output]</span>
<span id="cb3-2"><a href="#cb3-2" aria-hidden="true" tabindex="-1"></a><span class="ex">└─$</span> sha256sum <span class="pp">*</span></span>
<span id="cb3-3"><a href="#cb3-3" aria-hidden="true" tabindex="-1"></a><span class="ex">c47301469f98b505e0bad828433099021142fafcc607dd3e8cd367c80ee906be</span>  cooldog.jpeg</span>
<span id="cb3-4"><a href="#cb3-4" aria-hidden="true" tabindex="-1"></a><span class="ex">444e6d5782d28e96ab7e50f00bec05a9f1a7508671f9dd839a1c9ab72b62923a</span>  fungame.jpg</span>
<span id="cb3-5"><a href="#cb3-5" aria-hidden="true" tabindex="-1"></a><span class="ex">5045f6c84b7290069ec899639a3106746d7da95d5f1aa381b2ac69d81da6e8de</span>  installer.py</span>
<span id="cb3-6"><a href="#cb3-6" aria-hidden="true" tabindex="-1"></a><span class="ex">695b3eeeb8a4a4d22405d78732f19c6e42527d374ae3b23ba1c4e4b757e10359</span>  launcher</span>
<span id="cb3-7"><a href="#cb3-7" aria-hidden="true" tabindex="-1"></a><span class="ex">999831df24ef9b984dd12eb28580a84c5b5617ef54410e87f3e9f6fb06b3ec35</span>  literallyme.jpeg</span></code></pre></div>
<p>Five files were downloaded: three JPEG images (likely decoys), a
Python script, and a binary.</p>
<hr />
<h3 id="analysing-the-attack-vector">Analysing the Attack Vector</h3>
<p><img src="images/attack_vector.png" /></p>
<p>Looking at the full picture in Wireshark, here is what happened in
the capture:</p>
<ul>
<li>The victim’s machine (<code>10.0.0.10</code>) downloaded several
files from <code>156.234.52.16</code> over plain <strong>HTTP</strong>:
<ul>
<li><code>fungame.jpg</code>, <code>cooldog.jpeg</code>,
<code>literallyme.jpeg</code> — decoy images</li>
<li><strong><code>installer.py</code></strong> — the malware dropper
(Python script)</li>
<li><strong><code>launcher</code></strong> — an encrypted binary
payload</li>
</ul></li>
<li>Shortly after the downloads, <strong>ICMP ping traffic</strong> to
<code>76.54.32.144</code> appears — this is the C2 callback triggered by
<code>installer.py</code></li>
</ul>
<hr />
<h3 id="inspecting-the-malware-installer.py">Inspecting the Malware:
<code>installer.py</code></h3>
<p>Reading the script reveals exactly what it does:</p>
<div class="sourceCode" id="cb4"><pre
class="sourceCode bash"><code class="sourceCode bash"><span id="cb4-1"><a href="#cb4-1" aria-hidden="true" tabindex="-1"></a><span class="ex">┌──</span><span class="er">(</span><span class="ex">kali㉿kali</span><span class="kw">)</span><span class="ex">-[~/Desktop/uma/http</span> output]</span>
<span id="cb4-2"><a href="#cb4-2" aria-hidden="true" tabindex="-1"></a><span class="ex">└─$</span> cat installer.py</span></code></pre></div>
<div class="sourceCode" id="cb5"><pre
class="sourceCode python"><code class="sourceCode python"><span id="cb5-1"><a href="#cb5-1" aria-hidden="true" tabindex="-1"></a><span class="im">import</span> subprocess</span>
<span id="cb5-2"><a href="#cb5-2" aria-hidden="true" tabindex="-1"></a><span class="im">import</span> hashlib</span>
<span id="cb5-3"><a href="#cb5-3" aria-hidden="true" tabindex="-1"></a><span class="im">import</span> nacl.secret</span>
<span id="cb5-4"><a href="#cb5-4" aria-hidden="true" tabindex="-1"></a></span>
<span id="cb5-5"><a href="#cb5-5" aria-hidden="true" tabindex="-1"></a><span class="kw">def</span> fix_error():</span>
<span id="cb5-6"><a href="#cb5-6" aria-hidden="true" tabindex="-1"></a>    seed <span class="op">=</span> <span class="st">&quot;38093248092rsjrwedoaw3&quot;</span></span>
<span id="cb5-7"><a href="#cb5-7" aria-hidden="true" tabindex="-1"></a>    key <span class="op">=</span> hashlib.sha256(seed.encode()).digest()</span>
<span id="cb5-8"><a href="#cb5-8" aria-hidden="true" tabindex="-1"></a>    box <span class="op">=</span> nacl.secret.SecretBox(key)</span>
<span id="cb5-9"><a href="#cb5-9" aria-hidden="true" tabindex="-1"></a>    <span class="cf">with</span> <span class="bu">open</span>(<span class="st">&quot;./launcher&quot;</span>, <span class="st">&quot;rb&quot;</span>) <span class="im">as</span> f:</span>
<span id="cb5-10"><a href="#cb5-10" aria-hidden="true" tabindex="-1"></a>        data <span class="op">=</span> f.read()</span>
<span id="cb5-11"><a href="#cb5-11" aria-hidden="true" tabindex="-1"></a>    decrypted <span class="op">=</span> box.decrypt(data)</span>
<span id="cb5-12"><a href="#cb5-12" aria-hidden="true" tabindex="-1"></a>    <span class="cf">with</span> <span class="bu">open</span>(<span class="st">&quot;./launcher&quot;</span>, <span class="st">&quot;wb&quot;</span>) <span class="im">as</span> f:</span>
<span id="cb5-13"><a href="#cb5-13" aria-hidden="true" tabindex="-1"></a>        f.write(decrypted)</span>
<span id="cb5-14"><a href="#cb5-14" aria-hidden="true" tabindex="-1"></a></span>
<span id="cb5-15"><a href="#cb5-15" aria-hidden="true" tabindex="-1"></a><span class="bu">print</span>(<span class="st">&quot;Hello World&quot;</span>)</span>
<span id="cb5-16"><a href="#cb5-16" aria-hidden="true" tabindex="-1"></a><span class="cf">try</span>:</span>
<span id="cb5-17"><a href="#cb5-17" aria-hidden="true" tabindex="-1"></a>    fix_error()</span>
<span id="cb5-18"><a href="#cb5-18" aria-hidden="true" tabindex="-1"></a>    <span class="bu">print</span>(<span class="st">&quot;Installed Correctly&quot;</span>)</span>
<span id="cb5-19"><a href="#cb5-19" aria-hidden="true" tabindex="-1"></a>    result <span class="op">=</span> subprocess.run([<span class="st">&quot;ping&quot;</span>, <span class="st">&quot;-c&quot;</span>, <span class="st">&quot;2&quot;</span>, <span class="st">&quot;76.54.32.144&quot;</span>])</span>
<span id="cb5-20"><a href="#cb5-20" aria-hidden="true" tabindex="-1"></a>    <span class="bu">print</span>(result)</span>
<span id="cb5-21"><a href="#cb5-21" aria-hidden="true" tabindex="-1"></a><span class="cf">except</span> <span class="pp">Exception</span> <span class="im">as</span> e:</span>
<span id="cb5-22"><a href="#cb5-22" aria-hidden="true" tabindex="-1"></a>    <span class="bu">print</span>(<span class="ss">f&quot;Installation failed, please try again </span><span class="sc">{</span>e<span class="sc">}</span><span class="ss">&quot;</span>)</span></code></pre></div>
<p><strong>What <code>installer.py</code> does:</strong></p>
<ul>
<li><p>Derives an AES key by SHA256-hashing a hardcoded seed
string</p></li>
<li><p>Uses <code>nacl.secret.SecretBox</code> (NaCl symmetric
encryption) to <strong>decrypt the <code>launcher</code> binary</strong>
in-place</p></li>
<li><p>Executes a ping to <code>76.54.32.144</code> — the <strong>C2
(Command &amp; Control) callback</strong></p></li>
</ul>
<hr />
<h3 id="checking-virustotal-for-installer.py-and-launcher">Checking
VirusTotal for <code>installer.py</code> and <code>launcher</code></h3>
<p>Searching both hashes on VirusTotal initially returns clean results —
the encrypted payload evades detection:</p>
<table>
<colgroup>
<col style="width: 15%" />
<col style="width: 72%" />
<col style="width: 11%" />
</colgroup>
<thead>
<tr>
<th>File</th>
<th>SHA256</th>
<th>VT Result</th>
</tr>
</thead>
<tbody>
<tr>
<td><code>installer.py</code></td>
<td><code>5045f6c84b7290069ec899639a3106746d7da95d5f1aa381b2ac69d81da6e8de</code></td>
<td>Clean</td>
</tr>
<tr>
<td><code>launcher</code></td>
<td><code>695b3eeeb8a4a4d22405d78732f19c6e42527d374ae3b23ba1c4e4b757e10359</code></td>
<td>Clean</td>
</tr>
</tbody>
</table>
<p>This is expected — the launcher is <strong>encrypted on
disk</strong>, so AV engines can’t identify it.</p>
<hr />
<h3 id="decrypting-the-launcher-binary">Decrypting the
<code>launcher</code> Binary</h3>
<p>We need to replicate the decryption from <code>installer.py</code>
manually.</p>
<ul>
<li><strong>Extract the decryption key:</strong></li>
</ul>
<div class="sourceCode" id="cb6"><pre
class="sourceCode bash"><code class="sourceCode bash"><span id="cb6-1"><a href="#cb6-1" aria-hidden="true" tabindex="-1"></a><span class="ex">┌──</span><span class="er">(</span><span class="ex">kali㉿kali</span><span class="kw">)</span><span class="ex">-[~/Desktop/uma/http</span> output]</span>
<span id="cb6-2"><a href="#cb6-2" aria-hidden="true" tabindex="-1"></a><span class="ex">└─$</span> python3 <span class="at">-c</span> <span class="st">&quot;</span></span>
<span id="cb6-3"><a href="#cb6-3" aria-hidden="true" tabindex="-1"></a><span class="st">import hashlib</span></span>
<span id="cb6-4"><a href="#cb6-4" aria-hidden="true" tabindex="-1"></a><span class="st">seed = &#39;38093248092rsjrwedoaw3&#39;</span></span>
<span id="cb6-5"><a href="#cb6-5" aria-hidden="true" tabindex="-1"></a><span class="st">key = hashlib.sha256(seed.encode()).digest()</span></span>
<span id="cb6-6"><a href="#cb6-6" aria-hidden="true" tabindex="-1"></a><span class="st">print(&#39;Key:&#39;, key.hex())</span></span>
<span id="cb6-7"><a href="#cb6-7" aria-hidden="true" tabindex="-1"></a><span class="st">&quot;</span> <span class="op">&gt;</span> launcher_decrypted</span>
<span id="cb6-8"><a href="#cb6-8" aria-hidden="true" tabindex="-1"></a><span class="ex">Key:</span> ba61a153eada267fcd3378aa20bb468e4be4e90a584c69669e52b1c4189f1758</span></code></pre></div>
<blockquote>
<p>Alternatively, you can derive the key using
<strong>CyberChef</strong>: Hash the seed string with SHA256 to get the
raw 32-byte key.</p>
</blockquote>
<ul>
<li><strong>Decrypt the binary:</strong></li>
</ul>
<div class="sourceCode" id="cb7"><pre
class="sourceCode bash"><code class="sourceCode bash"><span id="cb7-1"><a href="#cb7-1" aria-hidden="true" tabindex="-1"></a><span class="ex">┌──</span><span class="er">(</span><span class="ex">kali㉿kali</span><span class="kw">)</span><span class="ex">-[~/Desktop/uma/http</span> output]</span>
<span id="cb7-2"><a href="#cb7-2" aria-hidden="true" tabindex="-1"></a><span class="ex">└─$</span> python3 <span class="at">-c</span> <span class="st">&quot;</span></span>
<span id="cb7-3"><a href="#cb7-3" aria-hidden="true" tabindex="-1"></a><span class="st">import hashlib</span></span>
<span id="cb7-4"><a href="#cb7-4" aria-hidden="true" tabindex="-1"></a><span class="st">import nacl.secret</span></span>
<span id="cb7-5"><a href="#cb7-5" aria-hidden="true" tabindex="-1"></a></span>
<span id="cb7-6"><a href="#cb7-6" aria-hidden="true" tabindex="-1"></a><span class="st">seed = &#39;38093248092rsjrwedoaw3&#39;</span></span>
<span id="cb7-7"><a href="#cb7-7" aria-hidden="true" tabindex="-1"></a><span class="st">key = hashlib.sha256(seed.encode()).digest()</span></span>
<span id="cb7-8"><a href="#cb7-8" aria-hidden="true" tabindex="-1"></a><span class="st">box = nacl.secret.SecretBox(key)</span></span>
<span id="cb7-9"><a href="#cb7-9" aria-hidden="true" tabindex="-1"></a><span class="st">with open(&#39;launcher&#39;, &#39;rb&#39;) as f:</span></span>
<span id="cb7-10"><a href="#cb7-10" aria-hidden="true" tabindex="-1"></a><span class="st">    data = f.read()</span></span>
<span id="cb7-11"><a href="#cb7-11" aria-hidden="true" tabindex="-1"></a><span class="st">decrypted = box.decrypt(data)</span></span>
<span id="cb7-12"><a href="#cb7-12" aria-hidden="true" tabindex="-1"></a><span class="st">with open(&#39;launcher_decrypted&#39;, &#39;wb&#39;) as f:</span></span>
<span id="cb7-13"><a href="#cb7-13" aria-hidden="true" tabindex="-1"></a><span class="st">    f.write(decrypted)</span></span>
<span id="cb7-14"><a href="#cb7-14" aria-hidden="true" tabindex="-1"></a><span class="st">print(&#39;Decrypted size:&#39;, len(decrypted))</span></span>
<span id="cb7-15"><a href="#cb7-15" aria-hidden="true" tabindex="-1"></a><span class="st">print(&#39;First bytes (hex):&#39;, decrypted[:16].hex())</span></span>
<span id="cb7-16"><a href="#cb7-16" aria-hidden="true" tabindex="-1"></a><span class="st">&quot;</span></span>
<span id="cb7-17"><a href="#cb7-17" aria-hidden="true" tabindex="-1"></a><span class="ex">Decrypted</span> size: 13182</span>
<span id="cb7-18"><a href="#cb7-18" aria-hidden="true" tabindex="-1"></a><span class="ex">First</span> bytes <span class="er">(</span><span class="ex">hex</span><span class="kw">)</span><span class="bu">:</span> cc008680002000000010000000000000</span></code></pre></div>
<ul>
<li><strong>Identify the decrypted binary:</strong></li>
</ul>
<div class="sourceCode" id="cb8"><pre
class="sourceCode bash"><code class="sourceCode bash"><span id="cb8-1"><a href="#cb8-1" aria-hidden="true" tabindex="-1"></a><span class="ex">┌──</span><span class="er">(</span><span class="ex">kali㉿kali</span><span class="kw">)</span><span class="ex">-[~/Desktop/uma/http</span> output]</span>
<span id="cb8-2"><a href="#cb8-2" aria-hidden="true" tabindex="-1"></a><span class="ex">└─$</span> file launcher_decrypted <span class="kw">&amp;&amp;</span> <span class="fu">sha256sum</span> launcher_decrypted</span>
<span id="cb8-3"><a href="#cb8-3" aria-hidden="true" tabindex="-1"></a><span class="ex">launcher_decrypted:</span> FreeBSD/i386 compact demand paged dynamically linked executable not stripped</span>
<span id="cb8-4"><a href="#cb8-4" aria-hidden="true" tabindex="-1"></a><span class="ex">e7a09064fc40dd4e5dd2e14aa8dad89b328ef1b1fdb3288e4ef04b0bd497ccae</span>  launcher_decrypted</span></code></pre></div>
<p>The decrypted launcher is a <strong>FreeBSD i386 executable</strong>
— the actual malware payload.</p>
<blockquote>
<p><strong>SHA256 of decrypted launcher:</strong>
<code>e7a09064fc40dd4e5dd2e14aa8dad89b328ef1b1fdb3288e4ef04b0bd497ccae</code></p>
</blockquote>
<hr />
<h3 id="identifying-the-malware-on-virustotal">Identifying the Malware
on VirusTotal</h3>
<p>Search the decrypted hash on VirusTotal: 🔗 <a
href="https://www.virustotal.com/gui/file/e7a09064fc40dd4e5dd2e14aa8dad89b328ef1b1fdb3288e4ef04b0bd497ccae/details">View
on VirusTotal</a></p>
<p><img src="images/sha256_virustotal.png" /></p>
<p>Navigate to the <strong>Details</strong> tab to find the malware
name:</p>
<p><img src="images/sha256_name_virustotal.png" /></p>
<p>The malware is identified under the name <code>TheZoo</code>, giving
us the flag in the correct format: <code>UMASS{[sha256sum]}</code></p>
<pre><code>TheZoo_e7a09064fc40dd4e5dd2e14aa8dad89b328ef1b1fdb3288e4ef04b0bd497ccae</code></pre>
<hr />
<blockquote>
<p><strong>FLAG</strong> 🚩:
<strong>UMASS{TheZoo_e7a09064fc40dd4e5dd2e14aa8dad89b328ef1b1fdb3288e4ef04b0bd497ccae}</strong></p>
</blockquote>
<hr />
<p><em>Written for UMassCTF 2026 — Forensics</em></p>
<p><em>By Errorcode14</em></p>


<script>
(function () {
  'use strict';

  var html = document.documentElement;
  function cssVar(n) { return getComputedStyle(html).getPropertyValue(n).trim(); }

  /* ── 1. FLOATING TERMINAL NOISE ── */
  var SNIPPETS = [
    '01101100 01100011','> ./exploit.py','[SYSTEM DEBL] Connection...',
    '> chmod +x script.sh','0011010l','int main() {','[INF0] Kernel...',
    '0x1F43','void process_data','log [null]','> ls -la /var/log',
    '0x6F42','> ssh-keygen -t rsa','0x1A2B3C','std::cout <<',
    '1011011001','[ERROR] SegFault at 0x0...','> ps aux | grep root',
    '6v4AEB8DEF8C','ACCESS DENIED','HANDSHAKE INIT','0xdeadbeef',
    '0xcafebabe','SIGNAL_04.CTF','> nmap -sV --script vuln',
    'ROP chain','ret2libc','> base64 -d flag.txt','KEY EXCHANGE',
    'PAYLOAD STAGED','> cat /etc/shadow','[WARN] Buffer overflow',
    '> ./run_exploit.sh','[CTF] flag{...}','int *ptr = NULL;',
    '> strings binary | grep flag','#include <stdio.h>',
    '> objdump -d binary','SIGILL at 0x4010f3',' id && whoami'
  ];

  var noiseEl = document.getElementById('bg-noise');
  var spans   = [];

  function buildNoise() {
    noiseEl.innerHTML = '';
    spans = [];
    var W = window.innerWidth, H = window.innerHeight;
    var count = Math.floor((W * H) / 15000);
    var color = cssVar('--noise-color');
    for (var i = 0; i < count; i++) {
      var s = document.createElement('span');
      s.textContent    = SNIPPETS[Math.floor(Math.random() * SNIPPETS.length)];
      s.style.left     = (Math.random() * 93) + '%';
      s.style.top      = (Math.random() * 93) + '%';
      s.style.fontSize = (7.5 + Math.random() * 3.5).toFixed(1) + 'px';
      s.style.opacity  = (5 + Math.random() * 0.17).toFixed(2);
      s.style.transform= 'scale(' + (0.5 + Math.random() * 0.55).toFixed(2) + ')';
      s.style.color    = color;
      noiseEl.appendChild(s);
      spans.push(s);
    }
  }

  function retintNoise() {
    var color = cssVar('--noise-color');
    for (var i = 0; i < spans.length; i++) spans[i].style.color = color;
  }

  buildNoise();

  /* ── 2. THEME TOGGLE
     Class applied only to <html> so :root vars cascade correctly. ── */
  var themeBtn = document.getElementById('theme-toggle');
  var isGreen  = html.classList.contains('theme-green');

  function applyTheme(green) {
    isGreen = green;
    html.classList.toggle('theme-green', green);
    themeBtn.textContent       = green ? '[ THEME: GREEN ]' : '[ THEME: CYAN ]';
    var a = cssVar('--accent');
    themeBtn.style.borderColor = a;
    themeBtn.style.color       = a;
    themeBtn.style.textShadow  = '0 0 6px ' + a;
    setTimeout(retintNoise, 20);
    try { localStorage.setItem('cyber-theme', green ? 'green' : 'cyan'); } catch(e){}
  }

  try {
    var saved = localStorage.getItem('cyber-theme');
    if (saved === 'green' && !isGreen)  applyTheme(true);
    else if (saved === 'cyan' && isGreen) applyTheme(false);
  } catch(e){}

  themeBtn.addEventListener('click', function () { applyTheme(!isGreen); });

  /* ── 3. COPY BUTTONS ON CODE BLOCKS
     One real <button> per <pre>. Uses IIFE to close over each `pre`
     so there are no shared-variable bugs. Falls back to execCommand
     for non-HTTPS contexts. Never captures button's own text. ── */
  document.querySelectorAll('pre').forEach(function (pre) {
    (function (pre) {
      var btn      = document.createElement('button');
      btn.textContent = 'copy';
      btn.className   = 'copy-btn';
      btn.setAttribute('aria-label', 'Copy code to clipboard');
      pre.appendChild(btn);

      pre.addEventListener('mouseenter', function () { btn.style.opacity = '0.8'; });
      pre.addEventListener('mouseleave', function () {
        if (!btn.classList.contains('copied')) btn.style.opacity = '0';
      });

      btn.addEventListener('click', function (e) {
        e.stopPropagation();
        var codeEl = pre.querySelector('code');
        var text;
        if (codeEl) {
          /* Use textContent — not innerText — to avoid layout/style reads */
          text = codeEl.textContent;
        } else {
          /* Temporarily detach button so its text isn't captured */
          pre.removeChild(btn);
          text = pre.textContent;
          pre.appendChild(btn);
        }

        function onSuccess() {
          btn.textContent = 'copied!';
          btn.classList.add('copied');
          btn.style.opacity = '1';
          setTimeout(function () {
            btn.textContent = 'copy';
            btn.classList.remove('copied');
            btn.style.opacity = '0';
          }, 1800);
        }

        if (navigator.clipboard && window.isSecureContext) {
          navigator.clipboard.writeText(text).then(onSuccess).catch(function(){});
        } else {
          /* execCommand fallback */
          var ta = document.createElement('textarea');
          ta.value = text;
          ta.style.cssText = 'position:fixed;top:0;left:0;opacity:0;';
          document.body.appendChild(ta);
          ta.focus(); ta.select();
          try { document.execCommand('copy'); onSuccess(); } catch(err){}
          document.body.removeChild(ta);
        }
      });
    })(pre);
  });

  /* ── 4. EXTERNAL LINKS → new tab ── */
  document.querySelectorAll('a[href^="http"]').forEach(function (a) {
    a.target = '_blank';
    a.rel    = 'noopener noreferrer';
  });

  /* ── 5. COLLAPSIBLE H2–H6 SECTIONS
     Fixed: no RegExp.$1, proper double-rAF collapse, correct
     max-height restore on expand, nested sections work. ── */
  var headings = Array.prototype.slice.call(
    document.querySelectorAll('h2,h3,h4,h5,h6')
  );

  headings.forEach(function (h) {
    var level    = parseInt(h.tagName.charAt(1), 10);
    var siblings = [];
    var el       = h.nextElementSibling;
    while (el) {
      var m = el.tagName.match(/^H([1-6])$/);
      if (m && parseInt(m[1], 10) <= level) break;
      siblings.push(el);
      el = el.nextElementSibling;
    }
    if (!siblings.length) return;

    h.classList.add('section-toggle');
    h.setAttribute('title', 'Click to collapse / expand');

    var wrap      = document.createElement('div');
    wrap.className = 'section-body';
    h.parentNode.insertBefore(wrap, siblings[0]);
    siblings.forEach(function (s) { wrap.appendChild(s); });

    requestAnimationFrame(function () {
      wrap.style.maxHeight = wrap.scrollHeight + 'px';
    });

    h.addEventListener('click', function () {
      if (wrap.classList.contains('collapsed')) {
        /* Expand */
        wrap.classList.remove('collapsed');
        h.classList.remove('collapsed');
        wrap.style.maxHeight = wrap.scrollHeight + 'px';
        /* After transition, set to 'none' so inner content can grow */
        wrap.addEventListener('transitionend', function onEnd() {
          wrap.removeEventListener('transitionend', onEnd);
          if (!wrap.classList.contains('collapsed'))
            wrap.style.maxHeight = wrap.scrollHeight + 'px';
        });
      } else {
        /* Collapse — lock current height, then zero on next frame */
        wrap.style.maxHeight = wrap.scrollHeight + 'px';
        requestAnimationFrame(function () {
          requestAnimationFrame(function () {
            wrap.classList.add('collapsed');
            h.classList.add('collapsed');
            wrap.style.maxHeight = '0px';
          });
        });
      }
    });
  });

})();
</script>
</body>
</html>
