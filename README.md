# 3.5 Edition Feat Progression Chart

## About
This project is to make a simple program in C++ which would make a Progression Tree for the Feats mechanic in Dungeons and Dragons Edition 3.5. This would achieve this by parsing a Comma-Separated Values document and outputting script that would make a UML diagram linking the Feats to their prerequisite Feats.

## How
* Completing the spreadsheet by manually reading 3.5 Edition publications
* Making the program read in Feats from CSV file
  * Placing information into a Feat structure
* Verifying doubles of Feats do not exist (Notify user of source publications and ask them which to keep)
* Seperate Feat prerequisites from other prerequisites 
* Removing duplicate feat prerequisites that may occur between one feat and another prerequisite
* Create and write to file
  * Iterate through vector and input into script

## Decisions
* Racial feats do not get there own category due to their only trait being mentioned in the prerequisites. They are in General or another mentioned category (i.e. Psionics).
* Feats are only added if they have a chart in a book. (i.e. Monster's Manual)
  * The benefits section is left blank if the chart in the book does not include it (i.e. Book of Vile Darkness)

## [The Spreadsheet of Feats](https://docs.google.com/spreadsheets/d/1vyK6-p1zFmnogHBwQxzuOMt28dXvX11lcSF1YFZkCqw/edit?usp=sharing)

## Sources of 3.5 Edition Publication Lists
* [Reddit Thread](https://www.reddit.com/r/DnD/comments/3d2ptm/complete_list_of_dnd_35_source_books/)
* [Limited Downloadable Library](http://www.fillinsheets.com/pdfs/indexco.htm)
* [List a Friend (& Experienced DM) Uses](http://dnd.arkalseif.info/rulebooks/editions/index.html)