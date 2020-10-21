# 3.5 Edition Feat Progression Chart

## About
This project is to make a simple program in C++ which would make a Progression Tree for the Feats mechanic in Dungeons and Dragons Edition 3.5. This would achieve this by parsing a Comma-Separated Values document and outputting script that would make a UML diagram linking the Feats to their prerequisite Feats.

## Decisions
* Racial feats do not get there own category due to their only trait being mentioned in the prerequisites. They are in General or another mentioned category (i.e. Psionics).
* Feats are only added if they have a chart in a book. (i.e. Monster's Manual)
  * The benefits section is left blank if the chart in the book does not include it (i.e. Book of Vile Darkness)
* 3e feats in expansion books compatible with 3.5e are included
* Feats specifically mentioned to be described in the Player's Handbook are ignored.
* If a special claims it can be taken Multiple times, but does not specify stackable or not:
  * Mark it as stackable if it can be added to an item previously modified by the feat (i.e. spell or skill)
* Due to scarcity and amazon reviewers reporting it as an unnecessary document that merely refers to other published books, ignore the Dungeon Survival Guide
* If a book has repeated the feat in a chart under two catergories, make a page for feats in both categories.

## [The Spreadsheet of Feats](https://docs.google.com/spreadsheets/d/1vyK6-p1zFmnogHBwQxzuOMt28dXvX11lcSF1YFZkCqw/edit?usp=sharing)

## [The UML Diagram Generator](https://www.planttext.com)

## Sources of 3.5 Edition Publication Lists
* [Reddit Thread](https://www.reddit.com/r/DnD/comments/3d2ptm/complete_list_of_dnd_35_source_books/)
* [Limited Downloadable Library](http://www.fillinsheets.com/pdfs/indexco.htm)
* [List a Friend (& Experienced DM) Has Used](http://dnd.arkalseif.info/rulebooks/editions/index.html)
