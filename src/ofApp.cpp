#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // load our image
    image.loadImage("goldfish.jpg");
    
    
    
    // for speedz sake, quantize a smaller copy of the image
    ofImage imageCopy;
    
    imageCopy.loadImage("goldfish.jpg");
    
    imageCopy.resize(imageCopy.getWidth()/2, imageCopy.getHeight()/2);
    
    
    // get our colors
    colorQuantizer.setNumColors(23);
    colorQuantizer.quantize(imageCopy.getPixelsRef());
    
    
    
    vector<ofColor> myColors = colorQuantizer.getColors();
    
    
    for(int i = 0; i < myColors.size(); i++) {
        cout << "i = " << i << ", color = " << (int)myColors[i].r << ", "  << (int)myColors[i].g << ", "  << (int)myColors[i].b << endl;
    }
    
    
    
    
    // resize the window to match the image
    ofSetWindowShape(image.getWidth(), image.getHeight());
    
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    quality = OF_IMAGE_QUALITY_WORST;
    reset();

}


//--------------------------------------------------------------
void ofApp::reset() {
    img.loadImage("goldfish.jpg");
    //    img.loadImage("tulips.jpg");
}


//--------------------------------------------------------------
void ofApp::update(){
    string compressedFilename = "compressed.jpg";
    img.saveImage(compressedFilename, quality);
    ofBuffer file = ofBufferFromFile(compressedFilename);
    int fileSize = file.size();
    char * buffer = file.getBinaryBuffer();
    int whichByte = (int) ofRandom(fileSize);
    int whichBit = ofRandom(8);
    char bitMask = 1 << whichBit;
    buffer[whichByte] |= bitMask;
    ofBufferToFile(compressedFilename, file);
    img.loadImage(compressedFilename);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofBackground(100,100,100);
//    
//    ofSetColor(255);
//    
//    image.draw(0, 0);
    
    colorQuantizer.draw(ofPoint(0, image.getHeight()-20));
    
    ofSetColor(255,255,255);
    img.draw(0, 0);
    
    
    
}


//--------------------------------------------------------------
void ofApp::kMeansTest(){
    
    cv::Mat samples = (cv::Mat_<float>(8, 1) << 31 , 2 , 10 , 11 , 25 , 27, 2, 1);
    cv::Mat labels;
    
    // double kmeans(const Mat& samples, int clusterCount, Mat& labels,
    cv::TermCriteria termcrit;
    int attempts, flags;
    cv::Mat centers;
    double compactness = cv::kmeans(samples, 3, labels, cv::TermCriteria(), 2, cv::KMEANS_PP_CENTERS, centers);
    
    cout<<"labels:"<<endl;
    for(int i = 0; i < labels.rows; ++i)
    {
        cout<<labels.at<int>(0, i)<<endl;
    }
    
    cout<<"\ncenters:"<<endl;
    for(int i = 0; i < centers.rows; ++i)
    {
        cout<<centers.at<float>(0, i)<<endl;
    }
    
    cout<<"\ncompactness: "<<compactness<<endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    reset();

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    reset();

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
