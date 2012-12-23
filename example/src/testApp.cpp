#include "testApp.h"



bool compareName( const colorNameMapping& s1, const colorNameMapping& s2 ) {
    return strcasecmp( s1.name.c_str(), s2.name.c_str() ) <= 0;
}

bool compareBrightness( const colorNameMapping& s1, const colorNameMapping& s2 ) {
    return s1.color.getBrightness() < s2.color.getBrightness();
}

bool compareHue( const colorNameMapping& s1, const colorNameMapping& s2 ) {
    return s1.color.getHue() < s2.color.getHue();
}

bool compareSaturation( const colorNameMapping& s1, const colorNameMapping& s2 ) {
    return s1.color.getSaturation() < s2.color.getSaturation();
}


//--------------------------------------------------------------
void testApp::setup(){
    
    ofxNamedColors::setupColorMap();
    
    
    sortedType = 1; // by name, at the start
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // smoothing the mouse a bit over time
    
    mouseSmoothed = 0.95 * mouseSmoothed + 0.05 * ofPoint(mouseX, mouseY);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // calculate the total size needed to display all the colors
    
    float totalSize = (ceil(ofxNamedColors::colorNameMap.size()/3.0)) * 50 - ofGetHeight() + 60;
    
    // map the smoothed mouse to this:
    
    float offset = ofMap(mouseSmoothed.y, 0, ofGetHeight(), 0, totalSize, true);
    
    // draw all the colors
    // note this could be optimized, since we're drawing plenty that's offscreen here.
    
    
    
    for (int i = 0; i < ofxNamedColors::colorNames.size(); i++){
        
        int x = (i % 3) * ofGetWidth()/3.0;
        int y = (floor(i / 3)) * 50;
        
        ofSetColor( ofxNamedColors::colorNames[i].color );
        ofRect(0 + x, y - offset, (i%3 == 2) ? ofGetWidth() - x : ofGetWidth()/3.0, 50);
        
        ofDrawBitmapStringHighlight(ofxNamedColors::colorNames[i].name, 20 + x, y -offset+30, ofColor::white, ofColor::black);
        
    }
    
    
    
    ofSetColor(0);
    ofRect(0, ofGetHeight()-60, ofGetWidth(), 60);
    ofDrawBitmapStringHighlight("press '1' to sort by name, '2' to sort by hue,\n'3' to sort by brightness, '4' to sort by saturation", 20, ofGetHeight()-60 + 30, ofColor::black, ofColor::white);
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == '1'){
        if (sortedType != 1){
            sortedType = 1;
            ofSort(ofxNamedColors::colorNames, compareName);
        }
    } else if (key == '2'){
        if (sortedType != 2){
            sortedType = 2;
            ofSort(ofxNamedColors::colorNames, compareHue);
        }
    } else if (key == '3'){
        if (sortedType != 3){
            sortedType = 3;
            ofSort(ofxNamedColors::colorNames, compareBrightness);
        }
    } else if (key == '4'){
        if (sortedType != 4){
            sortedType = 4;
            ofSort(ofxNamedColors::colorNames, compareSaturation);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}