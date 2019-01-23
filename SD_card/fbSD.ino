void InitSD()
{
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    
    #ifdef DEBUG
      Serial.println("No SD card");
    #endif
    
    return;
  } else {
    
    if (!volume.init(card)) {
      #ifdef DEBUG
        Serial.println("Wrong partition");
      #endif
      return;
    };
  };

  if(SDFreeSize() > 25) {
    #ifdef DEBUG
      Serial.println("Memóriakártya ok");
    #endif
    SD.begin(chipSelect);
  } 
  else {
    #ifdef DEBUG
      Serial.println("Memóriakártyán nincs szabad hely!");
    #endif
  }
};

uint32_t SDFreeSize()
{
  uint32_t volumesize;

  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize *= 512;                         // SD card blocks are always 512 bytes - 512/
  volumesize /= 1024;
  volumesize /= 1024;
  return volumesize;
};

boolean SDCardWrite(String dest, byte datalenght)
/*
Input:  - file name, destination 
        - lenght of the telegram (plus 2 char [CF; LF])

Output: - HIGH if the command was executed succefully
        - LOW if the command was not executed
*/
{
  byte charnum = 0;
  
  File dataFile = SD.open(dest, FILE_WRITE);
  
  if (dataFile) {
    dataFile.print(millis());
    charnum = dataFile.println(dataString);
    dataFile.close();
    if (charnum == datalenght) {
      return HIGH;
    } else {
      return LOW;
    };
    
  } else {
    return LOW;
  };
}

