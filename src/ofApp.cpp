#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  

    
//    mask.load("/Users/maxfowler/Desktop/masks/sfpc_person.png");
//     mask.load("/Users/maxfowler/Desktop/masks/sfpc.png");
//     mask.load("/Users/maxfowler/Desktop/masks/zach.png");
//     mask.load("/Users/maxfowler/Desktop/masks/min_and_tayeoon.png");
     mask.load("/Users/maxfowler/Desktop/masks/plant.jpg");
         regionMask.load("/Users/maxfowler/Desktop/masks/computer_regions.png");
        regionMask.resize(imgsize, imgsize);
    mask.resize(imgsize, imgsize);
    
    
    img.allocate(imgsize, imgsize, OF_IMAGE_COLOR);
    
    for (int i = 0; i < imgsize; i++){
        for (int j = 0; j < imgsize; j++){
            
            img.getPixels().setColor(i,j, ofColor(0));
            
        }
    }
    
    img.update();
    
}

//--------------------------------------------------------------
void ofApp::update(){

//    float now = ofGetElapsedTimef()  * 0.1;
//    float timeFactor = ofMap(mouseX, 0, ofGetScreenWidth(), 0, 10);
//    cout << "timefactor: " << timeFactor << endl;
    float timeFactor= 0.84;
    now += 0.0166*timeFactor;
    float nowMod = fmod(now, 255);
    if (nowMod == 0) {
        nowMod = 1;
    }
    
    for (int i = 0; i < imgsize; i++){
        for (int j = 0; j < imgsize; j++){
            
            int gray = (int)(i*j * 0.01) % 255;
            
//            float ii = i*0.1;
//            float jj = j*0.1;
            
            float ii = i;
            float jj = j;
            
     
//            float r = ofMap(i % 13, 0, 13, 0, 255);
//            float g = ofMap(j % 13, 0, 13, 0, 255);
            float r = ofMap(sin(ii*jj*0.1*now) + now, -1, 1, 0, 255);
            
            int brightness = mask.getPixels().getColor(i, j).getBrightness();
//            cout << "brightness: " << brightness << endl;
//            float g = ofMap(sin((jj) / 20) + cos((ii-imgsize/2.0) / 20), -2, 2, 0, 255);
            float g = brightness;
//            if (brightness < 235) {
//                r = 0;
//                g = 255;
//            }
            
            ofColor maskCol = mask.getPixels().getColor(i, j);
            ofColor regionCol = regionMask.getPixels().getColor(i, j);
            
//            cout << "regionCol: " << to_string(regionCol.r) << " " << to_string(regionCol.g) << " " << to_string(regionCol.b) << endl;
            
            if (regionCol.r == 177 && regionCol.g == 35 && regionCol.b == 126) {
                img.getPixels().setColor(i, j, ofColor(100, 0, 0));
            }
            else {
                img.getPixels().setColor(i, j, ofColor(r, g, 255));
            }
            
            
            
            
            //            float dist = ofDist(mouseX, mouseY, i, j);
            //            if (dist < 200){
            //
            //                img.getPixels().setColor(i,j, ofColor(ofMap(dist, 0, 200, 255, 0)));
            //            } else {
            //                 img.getPixels().setColor(i,j, ofColor(0));
            //            }
            
            //            float dist = ofDist(mouseX, mouseY, i, j);
            //            if (dist < 100){
            //                int color= img.getPixels().getColor(i, j).getBrightness();
            //                img.getPixels().setColor(i,j, ofColor(color + 8));
            //            }
            
            
            
        }
    }
    
    img.update();
    
    
}

//--------------------------------------------------------------


void ofApp::draw(){
    
        img.draw(0,0);
    
    
    if (ofGetMousePressed()) {
        ofSaveScreen( "/Users/maxfowler/Desktop/of_frames/" + to_string(ofGetFrameNum()) + ".png");
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
