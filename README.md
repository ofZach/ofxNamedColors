ofxNamedColors
==============

this comes from

http://en.wikipedia.org/wiki/List_of_colors_(compact)

with some modifications to the names to let them work as variable names.  there's about 900+ named colors.

usage: 

  #include "ofxNamedColors.h"

	ofSetColor(ofxNamedColors::alloyOrange);
	ofSetColor(ofxNamedColors::classicRose);

everything is static inside the class.  you can also use some helper functions for iterating through the whole list 

	setupColorMap();  // allocates the static map of name to ofColor and populated a vector of color/name mappings
	ofxNamedColors::colorNames  // the vector of mappings. 

etc.
